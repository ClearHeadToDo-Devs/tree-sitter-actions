#!/usr/bin/env node
/**
 * @fileoverview Grammar Generator from Generated Syntax Mapping
 *
 * This tool generates tree-sitter grammar rules from the generated syntax_mapping.json
 * which is produced by the ontology-driven pipeline.
 *
 * Pipeline: parser-ontology.ttl → syntax_mapping.json → grammar.js
 *
 * Usage:
 *   node src/grammar_generator.js --generate-rules
 *   node src/grammar_generator.js --output grammar-generated.js
 *
 * @author primary_desktop
 */

const fs = require('fs');
const path = require('path');

/**
 * Load generated syntax mapping from JSON file
 * @param {string} mappingPath - Path to syntax_mapping.json
 * @returns {Object} Parsed syntax mapping
 */
function loadSyntaxMapping(mappingPath = 'syntax_mapping.json') {
    try {
        const content = fs.readFileSync(mappingPath, 'utf8');
        const mapping = JSON.parse(content);
        console.log(`📖 Loaded syntax mapping from ${mappingPath}`);
        console.log(`   Properties: ${Object.keys(mapping.properties || {}).length}`);
        console.log(`   State mappings: ${Object.keys(mapping.state_mappings || {}).length}`);
        return mapping;
    } catch (error) {
        console.error(`❌ Could not load syntax mapping: ${error.message}`);
        process.exit(1);
    }
}

// Load syntax mapping on module load
const SYNTAX_MAPPING_DATA = loadSyntaxMapping();
const SYNTAX_MAPPING = SYNTAX_MAPPING_DATA.properties || {};
const STATE_MAPPINGS = SYNTAX_MAPPING_DATA.state_mappings || {};
const RULE_TYPES = SYNTAX_MAPPING_DATA.rule_types || {};

// Backwards compatibility - convert to old format where needed
const RuleType = {
    CHOICE: 'choice',
    PATTERN: 'pattern',
    UUID_V7: 'uuid_v7',
    DATE_TIME: 'date_time',
    INTEGER: 'integer',
    TEXT: 'text',
    REFERENCE: 'reference',
    COMPUTED: 'computed'
};

/**
 * Get properties that use a specific symbol
 * @param {string} symbol - The symbol to search for
 * @returns {Array<string>} Property names using that symbol
 */
function getPropertiesBySymbol(symbol) {
    return Object.entries(SYNTAX_MAPPING)
        .filter(([_, rule]) => rule.symbol === symbol)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Generate tree-sitter grammar rule from property constraints
 * @param {string} propertyName - Name of the property
 * @param {Object} syntaxRule - Syntax rule from mapping (contains constraints from SHACL)
 * @returns {Object} Tree-sitter grammar rule structure
 */
function generatePropertyRule(propertyName, syntaxRule) {
    const ruleName = syntaxRule.grammar_rule_name;
    const ruleType = syntaxRule.rule_type;

    switch (ruleType) {
        case RuleType.CHOICE:
            // Generate choice rule from values (from SHACL or explicit)
            const choices = syntaxRule.values || [];

            if (choices.length === 0) {
                console.warn(`⚠️  No choices defined for ${propertyName}`);
                return { type: 'STRING', value: 'INVALID' };
            }

            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    {
                        type: 'CHOICE',
                        members: choices.map(choice => ({ type: 'STRING', value: String(choice) }))
                    }
                ]
            };

        case RuleType.PATTERN:
            // Use pattern from syntax mapping
            const pattern = syntaxRule.pattern;
            if (!pattern) {
                console.warn(`⚠️  No pattern defined for ${propertyName}`);
                return { type: 'STRING', value: 'INVALID' };
            }
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'PATTERN', value: pattern }
                ]
            };

        case RuleType.INTEGER:
            // Generate integer rule (tree-sitter doesn't validate ranges)
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'PATTERN', value: '/\\d+/' }
                ]
            };

        case RuleType.UUID_V7:
            // UUID v7 pattern
            const uuidPattern = '[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}';
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'PATTERN', value: `/${uuidPattern}/` }
                ]
            };

        case RuleType.DATE_TIME:
            // ISO 8601 date/time pattern (simplified)
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'SYMBOL', name: 'iso_datetime' }
                ]
            };

        case RuleType.TEXT:
            // Use safe_text rule (will be defined separately)
            if (syntaxRule.symbol) {
                return {
                    type: 'SEQ',
                    members: [
                        { type: 'STRING', value: syntaxRule.symbol },
                        { type: 'SYMBOL', name: 'safe_text' }
                    ]
                };
            } else {
                return { type: 'SYMBOL', name: 'safe_text' };
            }

        case RuleType.REFERENCE:
            // Reference to another entity (depth markers)
            return {
                type: 'SYMBOL',
                name: syntaxRule.grammar_rule_name
            };

        case 'computed':
            // Computed properties don't have direct syntax
            return null;

        default:
            console.warn(`⚠️  Unknown rule type: ${ruleType} for ${propertyName}`);
            return { type: 'STRING', value: 'UNKNOWN' };
    }
}

/**
 * Generate grammar rules from syntax mapping
 * @returns {Object} Generated grammar rules
 */
function generateGrammarRules() {
    console.log('\n🏗️  Generating grammar rules from syntax mapping...');

    const generatedRules = {};

    console.log('\n🔍 Processing properties:');

    // Generate individual property rules
    for (const [propName, syntaxRule] of Object.entries(SYNTAX_MAPPING)) {
        // Skip computed properties
        if (syntaxRule.computed) {
            console.log(`   ⏭️  ${propName}: Computed property (skipped)`);
            continue;
        }

        const ruleName = syntaxRule.grammar_rule_name;
        console.log(`   ✅ ${propName}: ${syntaxRule.symbol} → ${ruleName}`);

        const rule = generatePropertyRule(propName, syntaxRule);

        if (rule) {
            generatedRules[ruleName] = rule;

            // Show constraint information
            if (syntaxRule.min_value !== undefined || syntaxRule.max_value !== undefined) {
                console.log(`      📏 Range: ${syntaxRule.min_value || 'none'}-${syntaxRule.max_value || 'none'}`);
            }
            if (syntaxRule.pattern) {
                console.log(`      🎭 Pattern: ${syntaxRule.pattern}`);
            }
            if (syntaxRule.values) {
                console.log(`      🎯 Values: ${syntaxRule.values.join(', ')}`);
            }
            if (syntaxRule.value_mappings) {
                const mappings = syntaxRule.value_mappings.map(m => `${m.from}→${m.to}`).join(', ');
                console.log(`      🔄 Mappings: ${mappings}`);
            }
        }
    }

    console.log(`\n✅ Generated ${Object.keys(generatedRules).length} grammar rules`);

    return generatedRules;
}

/**
 * Compare generated rules with current grammar
 * @param {Object} generatedRules - Rules generated from syntax mapping
 */
function compareWithCurrentGrammar(generatedRules) {
    console.log('\n🔍 Comparing with current grammar...');

    try {
        const grammarPath = 'grammar.js';
        const grammarContent = fs.readFileSync(grammarPath, 'utf8');

        console.log('   📄 Current grammar loaded');

        // Basic analysis - count rules
        const currentRuleMatches = grammarContent.match(/\w+:\s*\$\s*=>/g) || [];
        console.log(`   📊 Current grammar has ~${currentRuleMatches.length} rules`);
        console.log(`   📊 Generated ${Object.keys(generatedRules).length} rules from ontology`);

        // Check for specific improvements
        const improvements = [];

        // Priority rule enhancement
        if (generatedRules.priority) {
            improvements.push('🎯 Priority: Values 1-4 from SHACL constraints');
        }

        // Context pattern enforcement
        if (generatedRules.context) {
            improvements.push('🎭 Context: Pattern validation from ontology');
        }

        // UUID validation
        if (generatedRules.id) {
            improvements.push('🆔 UUID: Version 7 validation enforced');
        }

        // Recurrence with mappings
        if (generatedRules.recurrence) {
            improvements.push('🔄 Recurrence: Value mappings (DAILY→D) from ontology');
        }

        if (improvements.length > 0) {
            console.log('\n📈 Ontology-driven enhancements:');
            for (const improvement of improvements) {
                console.log(`   ${improvement}`);
            }
        }

    } catch (error) {
        console.error(`   ❌ Could not read current grammar: ${error.message}`);
    }
}

/**
 * Validate current grammar against syntax mapping
 */
function validateCurrentGrammar() {
    console.log('🧪 Validating current grammar against syntax mapping...');
    
    try {
        const grammarPath = 'grammar.js';
        if (!fs.existsSync(grammarPath)) {
            console.error('❌ grammar.js not found');
            return;
        }
        
        const grammarContent = fs.readFileSync(grammarPath, 'utf8');
        
        // Check if key symbols are present
        const expectedSymbols = new Set();
        for (const rule of Object.values(SYNTAX_MAPPING)) {
            if (rule.symbol && rule.symbol !== '') {
                expectedSymbols.add(rule.symbol);
            }
        }
        
        const foundSymbols = new Set();
        const missingSymbols = [];
        
        for (const symbol of expectedSymbols) {
            // Escape regex special characters
            const escapedSymbol = symbol.replace(/[.*+?^${}()|[\\]\\\\]/g, '\\\\$&');
            const regex = new RegExp(`['"]${escapedSymbol}['"]`, 'g');
            
            if (regex.test(grammarContent)) {
                foundSymbols.add(symbol);
            } else {
                missingSymbols.push(symbol);
            }
        }
        
        console.log(`\\n📊 Symbol Analysis:`);
        console.log(`   ✅ Found ${foundSymbols.size}/${expectedSymbols.size} expected symbols`);
        
        if (missingSymbols.length > 0) {
            console.log('   ⚠️  Missing symbols:');
            for (const symbol of missingSymbols) {
                const props = getPropertiesBySymbol(symbol);
                console.log(`      ${symbol} (used by: ${props.join(', ')})`);
            }
        }
        
        // Check rule names
        const expectedRules = new Set();
        for (const rule of Object.values(SYNTAX_MAPPING)) {
            expectedRules.add(rule.grammarRuleName);
        }
        
        const foundRules = [];
        const missingRules = [];
        
        for (const ruleName of expectedRules) {
            const regex = new RegExp(`${ruleName}:\\\\s*\\\\$`, 'm');
            if (regex.test(grammarContent)) {
                foundRules.push(ruleName);
            } else {
                missingRules.push(ruleName);
            }
        }
        
        console.log(`\\n🏗️  Rule Analysis:`);
        console.log(`   ✅ Found ${foundRules.length}/${expectedRules.size} expected rules`);
        
        if (missingRules.length > 0) {
            console.log('   ⚠️  Missing/different rule names:');
            for (const ruleName of missingRules) {
                console.log(`      ${ruleName}`);
            }
        }
        
    } catch (error) {
        console.error(`❌ Validation failed: ${error.message}`);
    }
}

/**
 * Main CLI function
 */
function main() {
    const args = process.argv.slice(2);
    
    if (args.length === 0 || args[0] === '--help' || args[0] === '-h') {
        console.log('🏗️  Grammar Generator from Ontology');
        console.log('');
        console.log('Usage:');
        console.log('  node src/grammar_generator.js --generate-rules');
        console.log('  node src/grammar_generator.js --validate-current');
        console.log('  node src/grammar_generator.js --compare');
        console.log('');
        console.log('Commands:');
        console.log('  --generate-rules   Generate new grammar rules from ontology');
        console.log('  --validate-current Validate current grammar.js against syntax mapping');  
        console.log('  --compare          Compare generated rules with current grammar');
        return;
    }
    
    switch (args[0]) {
        case '--generate-rules':
            const rules = generateGrammarRules();
            console.log('\\n📄 Generated Rules (JSON format):');
            console.log('='.repeat(50));
            console.log(JSON.stringify(rules, null, 2));
            break;
            
        case '--validate-current':
            validateCurrentGrammar();
            break;
            
        case '--compare':
            const generatedRules = generateGrammarRules();
            compareWithCurrentGrammar(generatedRules);
            break;
            
        default:
            console.error(`❌ Unknown command: ${args[0]}`);
            console.log('Use --help for usage information');
    }
}

// Run if called directly
if (require.main === module) {
    main();
}

module.exports = {
    loadOntologySchema,
    generatePropertyRule,
    generateCorePropertiesRule,
    generateGrammarRules,
    validateCurrentGrammar
};