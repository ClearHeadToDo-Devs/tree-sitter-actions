#!/usr/bin/env node
/**
 * @fileoverview Grammar Generator from Ontology JSON Schemas
 * 
 * This tool generates tree-sitter grammar rules from the ontology JSON schemas
 * using the syntax mapping configuration. It demonstrates how semantic constraints
 * from SHACL shapes can automatically generate precise grammar rules.
 * 
 * Usage:
 *   node src/grammar_generator.js --generate-rules
 *   node src/grammar_generator.js --validate-current
 * 
 * @author primary_desktop
 */

const fs = require('fs');
const path = require('path');
const { SYNTAX_MAPPING, RuleType, getPropertiesBySymbol } = require('./syntax_mapping.js');

/**
 * Load JSON schema from ontology project
 * @param {string} schemaName - Name of schema (e.g., 'action')
 * @returns {Object|null} Parsed JSON schema
 */
function loadOntologySchema(schemaName) {
    const schemaPath = `../ontology/schemas/${schemaName}.schema.json`;
    try {
        const content = fs.readFileSync(schemaPath, 'utf8');
        return JSON.parse(content);
    } catch (error) {
        console.error(`❌ Could not load schema ${schemaName}: ${error.message}`);
        return null;
    }
}

/**
 * Generate tree-sitter grammar rule from property constraints
 * @param {string} propertyName - Name of the property
 * @param {Object} propertySchema - JSON schema for the property
 * @param {Object} syntaxRule - Syntax rule from mapping
 * @returns {Object} Tree-sitter grammar rule
 */
function generatePropertyRule(propertyName, propertySchema, syntaxRule) {
    const ruleName = syntaxRule.grammarRuleName;
    
    switch (syntaxRule.ruleType) {
        case RuleType.CHOICE:
            // Generate choice rule from SHACL constraints or predefined values
            let choices = syntaxRule.values;
            
            // If JSON schema has enum, use that
            if (propertySchema.enum) {
                choices = propertySchema.enum.map(String);
            }
            // If it has min/max integer constraints, generate range
            else if (propertySchema.type === 'integer' && 
                     propertySchema.minimum !== undefined && 
                     propertySchema.maximum !== undefined) {
                choices = [];
                for (let i = propertySchema.minimum; i <= propertySchema.maximum; i++) {
                    choices.push(String(i));
                }
            }
            
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    {
                        type: 'CHOICE',
                        members: choices.map(choice => ({ type: 'STRING', value: choice }))
                    }
                ]
            };
            
        case RuleType.PATTERN:
            // Use pattern from SHACL shape or syntax mapping
            const pattern = propertySchema.pattern || syntaxRule.pattern;
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'PATTERN', value: pattern }
                ]
            };
            
        case RuleType.INTEGER:
            // Generate integer rule with optional min/max validation
            let integerRule = { type: 'PATTERN', value: '/\\\\d+/' };
            
            // If we have constraints from JSON schema, we could add validation
            // but tree-sitter focuses on parsing, not validation
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    integerRule
                ]
            };
            
        case RuleType.UUID_V7:
            // Reference existing UUID rule
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'SYMBOL', name: 'uuid' }
                ]
            };
            
        case RuleType.DATE_TIME:
            // Reference existing date/time rules
            return {
                type: 'SEQ',
                members: [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'SYMBOL', name: 'extended_date_spec' }
                ]
            };
            
        case RuleType.TEXT:
            // Use safe_text rule
            return {
                type: 'SEQ',
                members: syntaxRule.symbol ? [
                    { type: 'STRING', value: syntaxRule.symbol },
                    { type: 'SYMBOL', name: 'safe_text' }
                ] : [
                    { type: 'SYMBOL', name: 'safe_text' }
                ]
            };
            
        default:
            console.warn(`⚠️  Unknown rule type: ${syntaxRule.ruleType} for ${propertyName}`);
            return { type: 'STRING', value: 'UNKNOWN' };
    }
}

/**
 * Generate core_properties rule from all mapped properties
 * @param {Object} schema - JSON schema object
 * @returns {Object} Tree-sitter grammar rule for core_properties
 */
function generateCorePropertiesRule(schema) {
    const propertyChoices = [];
    const requiredFields = [];
    
    // Start with required state and name
    requiredFields.push(
        { type: 'SYMBOL', name: 'state' },
        { type: 'SYMBOL', name: 'name' }
    );
    
    // Add optional properties
    for (const [propName, propSchema] of Object.entries(schema.properties || {})) {
        const syntaxRule = SYNTAX_MAPPING[propName];
        
        // Skip properties without syntax mapping or already handled
        if (!syntaxRule || propName === 'name' || propName === 'state') {
            continue;
        }
        
        // Generate rule for this property
        const rule = generatePropertyRule(propName, propSchema, syntaxRule);
        propertyChoices.push({
            type: 'SYMBOL',
            name: syntaxRule.grammarRuleName
        });
    }
    
    return {
        type: 'SEQ',
        members: [
            ...requiredFields,
            {
                type: 'REPEAT',
                content: {
                    type: 'CHOICE',
                    members: propertyChoices
                }
            }
        ]
    };
}

/**
 * Generate enhanced grammar rules from ontology schemas
 * @returns {Object} Generated grammar rules
 */
function generateGrammarRules() {
    console.log('🏗️  Generating grammar rules from ontology schemas...');
    
    // Load main action schema
    const actionSchema = loadOntologySchema('action');
    if (!actionSchema) {
        console.error('❌ Could not load action schema');
        return {};
    }
    
    const generatedRules = {};
    
    console.log('\n🔍 Processing properties:');
    
    // Generate individual property rules
    for (const [propName, propSchema] of Object.entries(actionSchema.properties)) {
        const syntaxRule = SYNTAX_MAPPING[propName];
        
        if (!syntaxRule) {
            console.log(`   ⏭️  ${propName}: No syntax mapping`);
            continue;
        }
        
        console.log(`   ✅ ${propName}: ${syntaxRule.symbol} → ${syntaxRule.grammarRuleName}`);
        
        const rule = generatePropertyRule(propName, propSchema, syntaxRule);
        generatedRules[syntaxRule.grammarRuleName] = rule;
        
        // Show constraint information
        if (propSchema.minimum !== undefined || propSchema.maximum !== undefined) {
            console.log(`      📏 Range: ${propSchema.minimum}-${propSchema.maximum}`);
        }
        if (propSchema.pattern) {
            console.log(`      🎭 Pattern: ${propSchema.pattern}`);
        }
        if (propSchema.enum) {
            console.log(`      🎯 Enum: ${propSchema.enum.join(', ')}`);
        }
    }
    
    // Generate core_properties rule
    console.log('\\n🏗️  Generating core_properties rule...');
    generatedRules.core_properties = generateCorePropertiesRule(actionSchema);
    
    console.log(`\\n✅ Generated ${Object.keys(generatedRules).length} grammar rules`);
    
    return generatedRules;
}

/**
 * Compare generated rules with current grammar
 * @param {Object} generatedRules - Rules generated from ontology
 */
function compareWithCurrentGrammar(generatedRules) {
    console.log('\\n🔍 Comparing with current grammar...');
    
    try {
        const grammarPath = 'grammar.js';
        const grammarContent = fs.readFileSync(grammarPath, 'utf8');
        
        console.log('   📄 Current grammar loaded');
        
        // Basic analysis - count rules
        const currentRuleMatches = grammarContent.match(/\\w+:\\s*\\$\\s*=>/g) || [];
        console.log(`   📊 Current grammar has ~${currentRuleMatches.length} rules`);
        console.log(`   📊 Generated ${Object.keys(generatedRules).length} enhanced rules`);
        
        // Check for specific improvements
        const improvements = [];
        
        // Priority rule enhancement
        if (generatedRules.priority) {
            improvements.push('🎯 Priority: Limited to 1-4 from SHACL constraints');
        }
        
        // Context pattern enforcement
        if (generatedRules.context) {
            improvements.push('🎭 Context: Pattern validation from ontology');
        }
        
        // UUID validation
        if (generatedRules.id) {
            improvements.push('🆔 UUID: Version 7 validation from schema');
        }
        
        if (improvements.length > 0) {
            console.log('\\n📈 Potential improvements:');
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