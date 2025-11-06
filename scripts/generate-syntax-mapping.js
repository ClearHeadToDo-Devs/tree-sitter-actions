#!/usr/bin/env node
/**
 * Generate syntax_mapping.json from parser-ontology.ttl using N3.js
 *
 * This version uses proper RDF parsing instead of regex to query the ontology.
 * Much more robust and maintainable!
 */

const fs = require('fs');
const N3 = require('n3');
const { DataFactory } = N3;
const { namedNode, literal, quad } = DataFactory;

// Namespace prefixes
const PREFIXES = {
    parser: 'https://vocab.clearhead.io/parser#',
    actions: 'https://clearhead.us/vocab/actions/v3#',
    schema: 'http://schema.org/',
    rdf: 'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
    rdfs: 'http://www.w3.org/2000/01/rdf-schema#',
    owl: 'http://www.w3.org/2002/07/owl#',
    xsd: 'http://www.w3.org/2001/XMLSchema#',
    sh: 'http://www.w3.org/ns/shacl#'
};

/**
 * Load and parse Turtle file into RDF store
 */
async function loadOntology(filePath) {
    console.log(`📖 Loading ontology from ${filePath}...`);

    const content = fs.readFileSync(filePath, 'utf8');
    const parser = new N3.Parser({ baseIRI: PREFIXES.parser });
    const store = new N3.Store();

    return new Promise((resolve, reject) => {
        parser.parse(content, (error, quad, prefixes) => {
            if (error) {
                reject(error);
            } else if (quad) {
                store.addQuad(quad);
            } else {
                // Parsing complete
                console.log(`   Loaded ${store.size} triples`);
                resolve(store);
            }
        });
    });
}

/**
 * Get the local name from a URI
 */
function getLocalName(uri) {
    if (!uri) return null;
    if (typeof uri === 'object' && uri.value) uri = uri.value;

    for (const [prefix, namespace] of Object.entries(PREFIXES)) {
        if (uri.startsWith(namespace)) {
            return uri.substring(namespace.length);
        }
    }

    // Fallback: get everything after last # or /
    const match = uri.match(/[#\/]([^#\/]+)$/);
    return match ? match[1] : uri;
}

/**
 * Get literal value from an RDF term
 */
function getValue(term) {
    if (!term) return null;
    if (term.value) return term.value;
    return term;
}

/**
 * Extract property annotations (symbols, grammar rules, etc.)
 */
function extractPropertyAnnotations(store) {
    console.log('\n🔍 Extracting property annotations...');

    const properties = {};

    // Find all subjects that have parser: annotations
    const subjects = new Set();

    // Look for properties with parser:symbol
    for (const quad of store.match(null, namedNode(PREFIXES.parser + 'symbol'), null)) {
        subjects.add(quad.subject.value);
    }

    // Look for properties with parser:grammarRuleName
    for (const quad of store.match(null, namedNode(PREFIXES.parser + 'grammarRuleName'), null)) {
        subjects.add(quad.subject.value);
    }

    console.log(`   Found ${subjects.size} annotated properties`);

    // Extract all annotations for each property
    for (const subjectUri of subjects) {
        const subject = namedNode(subjectUri);
        const propName = getLocalName(subjectUri);
        const propData = {};

        // Get all parser: predicates for this subject
        const predicates = [
            'symbol', 'grammarRuleName', 'ruleType', 'contextLevel',
            'formatHint', 'example', 'canRepeat', 'isComputed', 'usesSyntax',
            'pattern', 'parenSymbol', 'depthSymbol', 'minDepth', 'maxDepth'
        ];

        for (const pred of predicates) {
            const matches = store.getQuads(subject, namedNode(PREFIXES.parser + pred), null);
            if (matches.length > 0) {
                propData[pred] = getValue(matches[0].object);
            }
        }

        if (Object.keys(propData).length > 0) {
            properties[propName] = propData;
        }
    }

    return properties;
}

/**
 * Extract structure definitions (root_action, child_action)
 */
function extractStructures(store) {
    console.log('\n🏗️  Extracting grammar structures...');

    const structures = {};

    // Find RootActionGrammarStructure and ChildActionGrammarStructure
    const structureClasses = [
        PREFIXES.parser + 'RootActionGrammarStructure',
        PREFIXES.parser + 'ChildActionGrammarStructure'
    ];

    for (const structureUri of structureClasses) {
        const structureNode = namedNode(structureUri);
        const structureName = getLocalName(structureUri).includes('Root') ? 'root_action' : 'child_action';

        // Get the ordered property list
        const orderedPropQuads = store.getQuads(structureNode, namedNode(PREFIXES.parser + 'hasOrderedProperty'), null);

        if (orderedPropQuads.length > 0) {
            const listNode = orderedPropQuads[0].object;
            const properties = parseRdfList(store, listNode);
            structures[structureName] = properties;
            console.log(`   Found ${structureName}: ${properties.length} properties`);
        }
    }

    return structures;
}

/**
 * Parse an RDF list (rdf:first, rdf:rest chain)
 */
function parseRdfList(store, listNode) {
    const items = [];
    let current = listNode;

    while (current && current.value !== PREFIXES.rdf + 'nil') {
        // Get rdf:first (the item)
        const firstQuads = store.getQuads(current, namedNode(PREFIXES.rdf + 'first'), null);
        if (firstQuads.length > 0) {
            const itemNode = firstQuads[0].object;

            // Extract rule name and required status from the blank node
            const ruleNameQuads = store.getQuads(itemNode, namedNode(PREFIXES.parser + 'grammarRuleName'), null);
            const isRequiredQuads = store.getQuads(itemNode, namedNode(PREFIXES.parser + 'isRequired'), null);

            if (ruleNameQuads.length > 0) {
                items.push({
                    rule: getValue(ruleNameQuads[0].object),
                    required: isRequiredQuads.length > 0 && getValue(isRequiredQuads[0].object) === 'true'
                });
            }
        }

        // Get rdf:rest (next item)
        const restQuads = store.getQuads(current, namedNode(PREFIXES.rdf + 'rest'), null);
        if (restQuads.length > 0) {
            current = restQuads[0].object;
        } else {
            break;
        }
    }

    return items;
}

/**
 * Extract state mappings (parenthesis symbols)
 */
function extractStateMappings(store) {
    console.log('\n🔘 Extracting state mappings...');

    const mappings = {};

    for (const quad of store.match(null, namedNode(PREFIXES.parser + 'parenSymbol'), null)) {
        const stateName = getLocalName(quad.subject.value);
        const symbol = getValue(quad.object);
        mappings[stateName] = symbol;
    }

    console.log(`   Found ${Object.keys(mappings).length} state symbols`);
    return mappings;
}

/**
 * Extract utility patterns from parser-shapes.ttl
 */
function extractUtilityPatterns(store) {
    console.log('\n🛠️  Extracting utility patterns...');

    const patterns = {};

    // Find all sh:NodeShape subjects that have parser:grammarRuleName
    const patternShapes = new Set();

    for (const quad of store.match(null, namedNode(PREFIXES.parser + 'grammarRuleName'), null)) {
        const subject = quad.subject;

        // Check if this is a NodeShape (pattern definition)
        const typeQuads = store.getQuads(subject, namedNode(PREFIXES.rdf + 'type'), namedNode(PREFIXES.sh + 'NodeShape'));

        if (typeQuads.length > 0) {
            patternShapes.add(subject.value);
        }
    }

    // Extract pattern data from each shape
    for (const shapeUri of patternShapes) {
        const subject = namedNode(shapeUri);
        const patternData = {};

        // Get grammar rule name to use as key
        const ruleNameQuads = store.getQuads(subject, namedNode(PREFIXES.parser + 'grammarRuleName'), null);
        if (ruleNameQuads.length === 0) continue;

        const ruleName = getValue(ruleNameQuads[0].object);

        // Extract all parser: properties
        const props = ['grammarRuleName', 'pattern', 'ruleType', 'repeatMode', 'exclude', 'computedFrom'];
        for (const prop of props) {
            const quads = store.getQuads(subject, namedNode(PREFIXES.parser + prop), null);
            if (quads.length > 0) {
                patternData[prop] = getValue(quads[0].object);
            }
        }

        // Also check for sh:property [ sh:path parser:pattern ; sh:hasValue "..." ]
        const propertyQuads = store.getQuads(subject, namedNode(PREFIXES.sh + 'property'), null);
        for (const propQuad of propertyQuads) {
            const blankNode = propQuad.object;

            // Get sh:hasValue for pattern
            const hasValueQuads = store.getQuads(blankNode, namedNode(PREFIXES.sh + 'hasValue'), null);
            if (hasValueQuads.length > 0 && !patternData.pattern) {
                patternData.pattern = getValue(hasValueQuads[0].object);
            }

            // Get sh:hasValue for exclude
            const pathQuads = store.getQuads(blankNode, namedNode(PREFIXES.sh + 'path'), namedNode(PREFIXES.parser + 'exclude'));
            if (pathQuads.length > 0) {
                const excludeValueQuads = store.getQuads(blankNode, namedNode(PREFIXES.sh + 'hasValue'), null);
                if (excludeValueQuads.length > 0) {
                    patternData.exclude = getValue(excludeValueQuads[0].object);
                }
            }
        }

        if (Object.keys(patternData).length > 0) {
            patterns[ruleName] = patternData;
        }
    }

    console.log(`   Found ${Object.keys(patterns).length} utility patterns`);
    return patterns;
}

/**
 * Extract depth constraint from parser-shapes.ttl
 */
function extractDepthConstraint(store) {
    console.log('\n📏 Extracting depth constraint...');

    const depthNode = namedNode(PREFIXES.parser + 'ActionDepthShape');
    const constraint = {};

    const props = ['minDepth', 'maxDepth', 'depthSymbol', 'grammarRuleName'];
    for (const prop of props) {
        const quads = store.getQuads(depthNode, namedNode(PREFIXES.parser + prop), null);
        if (quads.length > 0) {
            const value = getValue(quads[0].object);
            constraint[prop] = prop.includes('Depth') ? parseInt(value) : value;
        }
    }

    if (constraint.maxDepth) {
        console.log(`   Found depth constraint: ${constraint.minDepth}-${constraint.maxDepth}`);
    }

    return constraint;
}

/**
 * Extract grammar metadata from parser-shapes.ttl
 */
function extractGrammarMetadata(store) {
    console.log('\n⚙️  Extracting grammar metadata...');

    const metadataNode = namedNode(PREFIXES.parser + 'GrammarMetadataShape');
    const metadata = {};

    const props = ['entryPoint', 'rootRule', 'repeatMode', 'whitespaceHandling', 'conflictRules'];
    for (const prop of props) {
        const quads = store.getQuads(metadataNode, namedNode(PREFIXES.parser + prop), null);
        if (quads.length > 0) {
            metadata[prop] = getValue(quads[0].object);
        }
    }

    if (metadata.entryPoint) {
        console.log(`   Found metadata: entry=${metadata.entryPoint}, conflicts=${metadata.conflictRules}`);
    }

    return metadata;
}

/**
 * Generate the complete syntax mapping
 */
function generateMapping(propertyAnnotations, structures, stateMappings, utilityPatterns, depthConstraint, grammarMetadata) {
    console.log('\n🔧 Building syntax mapping...');

    const mapping = {
        metadata: {
            generated_from: 'parser-ontology.ttl',
            imports: 'https://clearhead.us/vocab/actions/v3',
            version: '1.0.0',
            generated_at: new Date().toISOString(),
            parser: 'N3.js (proper RDF parsing)'
        },
        rule_types: {
            choice: 'Fixed set of values from constraints',
            pattern: 'Regex pattern validation',
            uuid_v7: 'Version 7 UUID format',
            date_time: 'ISO 8601 date/time format',
            integer: 'Numeric value with optional constraints',
            text: 'Free text with escaping rules',
            reference: 'Reference to another object',
            computed: 'Calculated from other properties'
        },
        properties: {},
        structures: structures,
        state_mappings: stateMappings,
        utility_patterns: utilityPatterns,
        depth_constraint: depthConstraint,
        grammar_metadata: grammarMetadata,
        special_syntax: {}
    };

    // Process property annotations into mapping format
    for (const [propName, data] of Object.entries(propertyAnnotations)) {
        const propEntry = {
            symbol: data.symbol || '',
            rule_type: data.ruleType || 'text',
            grammar_rule_name: data.grammarRuleName || propName,
            context: data.contextLevel || 'any_level'
        };

        if (data.formatHint) propEntry.format_hint = data.formatHint;
        if (data.example) propEntry.example = data.example;
        if (data.canRepeat === 'true') propEntry.can_repeat = true;
        if (data.isComputed === 'true') propEntry.computed = true;
        if (data.usesSyntax) propEntry.special_syntax = getLocalName(data.usesSyntax);
        if (data.pattern) propEntry.pattern = data.pattern;

        mapping.properties[propName] = propEntry;
    }

    console.log(`   Generated ${Object.keys(mapping.properties).length} property mappings`);
    console.log(`   Generated ${Object.keys(mapping.structures).length} structure mappings`);

    return mapping;
}

/**
 * Load multiple ontology files into a single store
 */
async function loadMultipleOntologies(files) {
    console.log(`📖 Loading ${files.length} ontology files...`);

    const store = new N3.Store();

    for (const file of files) {
        console.log(`   Loading ${file}...`);
        const content = fs.readFileSync(file, 'utf8');
        const parser = new N3.Parser({ baseIRI: PREFIXES.parser });

        await new Promise((resolve, reject) => {
            parser.parse(content, (error, quad, prefixes) => {
                if (error) {
                    reject(error);
                } else if (quad) {
                    store.addQuad(quad);
                } else {
                    resolve();
                }
            });
        });
    }

    console.log(`   Loaded ${store.size} total triples`);
    return store;
}

/**
 * Main execution
 */
async function main() {
    console.log('🚀 Syntax Mapping Generator (N3.js-based)');
    console.log('=' + '='.repeat(59));

    try {
        // Load both ontology and parser-specific shapes
        const store = await loadMultipleOntologies([
            'parser-ontology.ttl',
            'parser-shapes.ttl'
        ]);

        // Extract all components using semantic queries
        const propertyAnnotations = extractPropertyAnnotations(store);
        const structures = extractStructures(store);
        const stateMappings = extractStateMappings(store);
        const utilityPatterns = extractUtilityPatterns(store);
        const depthConstraint = extractDepthConstraint(store);
        const grammarMetadata = extractGrammarMetadata(store);

        // Generate mapping
        const mapping = generateMapping(
            propertyAnnotations,
            structures,
            stateMappings,
            utilityPatterns,
            depthConstraint,
            grammarMetadata
        );

        // Add hardcoded SHACL constraints (TODO: fetch from SHACL shapes)
        if (mapping.properties.hasPriority) {
            mapping.properties.hasPriority.values = ['1', '2', '3', '4'];
            mapping.properties.hasPriority.min_value = 1;
            mapping.properties.hasPriority.max_value = 4;
        }

        if (mapping.properties.hasRecurrenceFrequency) {
            mapping.properties.hasRecurrenceFrequency.values = ['DAILY', 'WEEKLY', 'MONTHLY', 'YEARLY'];
            mapping.properties.hasRecurrenceFrequency.value_mappings = [
                { from: 'DAILY', to: 'D' },
                { from: 'WEEKLY', to: 'W' },
                { from: 'MONTHLY', to: 'M' },
                { from: 'YEARLY', to: 'Y' }
            ];
        }

        if (mapping.properties.hasDurationMinutes) {
            mapping.properties.hasDurationMinutes.min_value = 1;
            mapping.properties.hasDurationMinutes.max_value = 10080;
        }

        // Generate state values from state_mappings
        if (mapping.properties.hasState) {
            mapping.properties.hasState.values = Object.values(mapping.state_mappings);
        }

        // Add default pattern for context
        if (mapping.properties.hasContext && !mapping.properties.hasContext.pattern) {
            mapping.properties.hasContext.pattern = '[a-zA-Z0-9_-]+(,[a-zA-Z0-9_-]+)*';
        }

        // Write output
        const outputPath = 'syntax_mapping.json';
        console.log(`\n💾 Writing to ${outputPath}...`);
        fs.writeFileSync(outputPath, JSON.stringify(mapping, null, 2));

        console.log(`✅ Generated ${outputPath}`);
        console.log(`\n📊 Summary:`);
        console.log(`   • ${Object.keys(mapping.properties).length} properties mapped`);
        console.log(`   • ${Object.keys(mapping.structures).length} structures defined`);
        console.log(`   • ${Object.keys(mapping.utility_patterns).length} utility patterns`);
        console.log(`   • ${Object.keys(mapping.state_mappings).length} state symbols`);

        console.log('\n✨ Done! (Using proper RDF parsing)');

    } catch (error) {
        console.error(`\n❌ Error: ${error.message}`);
        console.error(error.stack);
        process.exit(1);
    }
}

// Run if called directly
if (require.main === module) {
    main();
}

module.exports = { loadOntology, extractPropertyAnnotations, extractStructures };
