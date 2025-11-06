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
        console.log(`📚 Loaded syntax mapping from ${mappingPath}`);
        console.log(`   Properties: ${Object.keys(mapping.properties || {}).length}`);
        console.log(`   State mappings: ${Object.keys(mapping.state_mappings || {}).length}`);
        return mapping;
    } catch (error) {
        console.error(`🚫 Could not load syntax mapping: ${error.message}`);
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
 * @returns {string} Tree-sitter grammar rule as a string (function body)
 */
function generatePropertyRule(propertyName, syntaxRule) {
    const ruleName = syntaxRule.grammar_rule_name;
    const specialSyntax = syntaxRule.special_syntax;

    if (specialSyntax) {
        switch (specialSyntax) {
            case 'ParenthesisSyntax':
                const stateChoices = Object.entries(STATE_MAPPINGS).map(([stateName, symbol]) => {
                    return `seq('(', '${symbol}', ')')`;
                });
                return `($) => choice(${stateChoices.join(', ')})`;
            case 'DepthMarker':
                // Depth markers are handled by a separate rule in the main grammar
                // Don't generate this - it's hand-maintained in grammar.js
                return null;
            case 'ListSyntax':
                // Context uses list syntax like: +Driving,Store,Market
                // We need to match the symbol followed by comma-separated values
                // The pattern in the mapping already handles the full list pattern
                return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('value', /${syntaxRule.pattern || '[a-zA-Z0-9_-]+(,[a-zA-Z0-9_-]+)*'}/))`;

            default:
                console.warn(`🛡️  Unknown special syntax: ${specialSyntax} for ${propertyName}`);
                return `($) => '// Unknown special syntax for ${ruleName}'`;
        }
    }

    const ruleType = syntaxRule.rule_type;

    switch (ruleType) {
        case RuleType.CHOICE:
            let choices = syntaxRule.values || [];
            if (choices.length === 0) {
                console.warn(`🛡️  No choices defined for ${propertyName}`);
                return `($) => '// No choices for ${ruleName}'`;
            }

            // Apply value mappings if they exist (e.g., DAILY → D)
            if (syntaxRule.value_mappings && syntaxRule.value_mappings.length > 0) {
                const mappingDict = {};
                syntaxRule.value_mappings.forEach(m => {
                    mappingDict[m.from] = m.to;
                });
                choices = choices.map(c => mappingDict[c] || c);
            }

            const choiceStrings = choices.map(c => `'${String(c)}'`).join(', ');
            return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('number', choice(${choiceStrings})))`;

        case RuleType.PATTERN:
            const pattern = syntaxRule.pattern;
            if (!pattern) {
                console.warn(`🛡️  No pattern defined for ${propertyName}`);
                return `($) => '// No pattern for ${ruleName}'`;
            }
            return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('value', /${pattern}/))`;

        case RuleType.INTEGER:
            return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('minutes', /\\d+/))`;

        case RuleType.UUID_V7:
            const uuidPattern = '[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}';
            return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('value', /${uuidPattern}/))`;

        case RuleType.DATE_TIME:
            return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('value', choice($.iso_date_time, $.iso_date, $.iso_time)))`;

        case RuleType.TEXT:
            if (syntaxRule.symbol) {
                return `($) => seq(field('icon', '${syntaxRule.symbol}'), field('text', $.safe_text))`;
            } else {
                return `($) => field('text', $.safe_text)`;
            }

        case 'computed':
            return null; // Skip computed properties

        default:
            console.warn(`🛡️  Unknown rule type: ${ruleType} for ${propertyName}`);
            return `($) => '// Unknown rule type for ${ruleName}'`;
    }
}

/**
 * Generate grammar rules from syntax mapping
 * @returns {Object} Generated grammar rules as an object of ruleName: ruleString
 */
function generateGrammarRules() {
    console.log('\n🌋  Generating grammar rules from syntax mapping...');

    const generatedRules = {};

    console.log('\n🔍  Processing properties:');

    // Generate individual property rules
    for (const [propName, syntaxRule] of Object.entries(SYNTAX_MAPPING)) {
        // Skip computed properties
        if (syntaxRule.computed) {
            console.log(`   ➡️  ${propName}: Computed property (skipped)`);
            continue;
        }

        const ruleName = syntaxRule.grammar_rule_name;
        console.log(`   ✅ ${propName}: ${syntaxRule.symbol} → ${ruleName}`);

        const ruleString = generatePropertyRule(propName, syntaxRule);

        if (ruleString) {
            generatedRules[ruleName] = ruleString;

            // Show constraint information
            if (syntaxRule.min_value !== undefined || syntaxRule.max_value !== undefined) {
                console.log(`      📈 Range: ${syntaxRule.min_value || 'none'}-${syntaxRule.max_value || 'none'}`);
            }
            if (syntaxRule.pattern) {
                console.log(`      🌋 Pattern: ${syntaxRule.pattern}`);
            }
            if (syntaxRule.values) {
                console.log(`      🍁 Values: ${syntaxRule.values.join(', ')}`);
            }
            if (syntaxRule.value_mappings) {
                const mappings = syntaxRule.value_mappings.map(m => `${m.from}↗️${m.to}`).join(', ');
                console.log(`      ↺ Mappings: ${mappings}`);
            }
        }
    }

    console.log(`\n✅ Generated ${Object.keys(generatedRules).length} grammar rules`);

    return generatedRules;
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
        console.log('');
        console.log('Commands:');
        console.log('  --generate-rules   Generate new grammar rules from ontology');
        return;
    }
    
    switch (args[0]) {
        case '--generate-rules':
            const rulesObject = generateGrammarRules();
            const outputPath = 'grammar-generated.js';
            
            // Format the output as a JavaScript object literal
            const outputContent = `module.exports = {\n${Object.entries(rulesObject).map(([key, value]) => `  ${key}: ${value}`).join(',\n')}\n};`;

            fs.writeFileSync(outputPath, outputContent);
            console.log(`\n✅ Generated grammar rules to ${outputPath}`);
            break;
            
default:
            console.error(`🚫 Unknown command: ${args[0]}`);
            console.log('Use --help for usage information');
    }
}

// Run if called directly
if (require.main === module) {
    main();
}

module.exports = {
    generatePropertyRule,
    generateGrammarRules,
};
