#!/usr/bin/env node
/**
 * @fileoverview Syntax Mapping Utilities
 * 
 * Pure functions that work with the syntax mapping data file.
 * This separates the data (syntax_mapping.json) from the logic.
 * 
 * @author primary_desktop  
 */

const fs = require('fs');
const path = require('path');

// Load syntax mapping data
let syntaxMapping = null;

function loadSyntaxMapping() {
    if (!syntaxMapping) {
        const mappingPath = path.join(__dirname, '../syntax_mapping.json');
        const content = fs.readFileSync(mappingPath, 'utf8');
        syntaxMapping = JSON.parse(content);
    }
    return syntaxMapping;
}

/**
 * Get syntax rule for a property
 * @param {string} propertyName - Name of the property
 * @returns {Object|null} Syntax rule or null if not found
 */
function getPropertySyntax(propertyName) {
    const mapping = loadSyntaxMapping();
    return mapping.properties[propertyName] || null;
}

/**
 * Get all properties that use a specific symbol
 * @param {string} symbol - The symbol to search for  
 * @returns {Array<string>} Property names using that symbol
 */
function getPropertiesBySymbol(symbol) {
    const mapping = loadSyntaxMapping();
    return Object.entries(mapping.properties)
        .filter(([_, rule]) => rule.symbol === symbol)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Get properties available in a specific context
 * @param {string} context - The context to filter by
 * @returns {Array<string>} Property names available in that context
 */
function getPropertiesByContext(context) {
    const mapping = loadSyntaxMapping();
    return Object.entries(mapping.properties)
        .filter(([_, rule]) => 
            rule.context === context || rule.context === 'any_level')
        .map(([propertyName, _]) => propertyName);
}

/**
 * Get properties that are required in the syntax
 * @returns {Array<string>} Required property names
 */
function getRequiredProperties() {
    const mapping = loadSyntaxMapping();
    return Object.entries(mapping.properties)
        .filter(([_, rule]) => rule.is_required)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Convert JSON property value to actions syntax
 * @param {string} propertyName - Name of the property
 * @param {*} value - Value from JSON
 * @returns {string} Formatted syntax string
 */
function formatPropertyValue(propertyName, value) {
    const mapping = loadSyntaxMapping();
    const rule = mapping.properties[propertyName];
    if (!rule) return '';
    
    // Special handling for different property types
    switch (propertyName) {
        case 'state':
            return `[${mapping.state_mapping[value] || ' '}]`;
        case 'context':
            // Handle multiple contexts
            if (Array.isArray(value)) {
                return `+${value.join(',')}`;
            }
            return `+${value}`;
        case 'priority':
            return `!${value}`;
        case 'uuid':
            return `#${value}`;
        case 'description':
            return `$ ${value}`;
        case 'project':
            return `*${value}`;
        case 'durationMinutes':
            return `D${value}`;
        default:
            return rule.symbol ? `${rule.symbol}${value}` : String(value);
    }
}

/**
 * Convert JSON action to actions file syntax
 * @param {Object} jsonAction - Action in JSON format
 * @returns {string} Action in .actions file syntax
 */
function jsonToActionsSyntax(jsonAction) {
    const parts = [];
    
    // State and name are required and come first
    const state = formatPropertyValue('state', jsonAction.state || 'not_started');
    parts.push(state);
    parts.push(jsonAction.name || 'Untitled Action');
    
    // Add other properties in logical order
    const propertyOrder = [
        'description', 'priority', 'project', 'context', 
        'doDateTime', 'durationMinutes', 'completedDateTime', 'uuid'
    ];
    
    for (const propertyName of propertyOrder) {
        if (jsonAction[propertyName] !== undefined && jsonAction[propertyName] !== null) {
            const formatted = formatPropertyValue(propertyName, jsonAction[propertyName]);
            if (formatted && formatted !== '') {
                parts.push(formatted);
            }
        }
    }
    
    return parts.join(' ');
}

/**
 * Validate the syntax mapping for consistency
 * @returns {Array<string>} List of validation issues
 */
function validateSyntaxMapping() {
    const mapping = loadSyntaxMapping();
    const issues = [];
    
    // Check for symbol conflicts
    const symbolUsage = {};
    for (const [propertyName, rule] of Object.entries(mapping.properties)) {
        if (rule.symbol && rule.symbol !== '') {
            if (symbolUsage[rule.symbol]) {
                issues.push(`Symbol '${rule.symbol}' used by both ${symbolUsage[rule.symbol]} and ${propertyName}`);
            } else {
                symbolUsage[rule.symbol] = propertyName;
            }
        }
    }
    
    // Check for missing required properties
    const required = getRequiredProperties();
    if (!required.includes('name')) {
        issues.push("'name' should be marked as required");
    }
    if (!required.includes('state')) {
        issues.push("'state' should be marked as required");
    }
        
    return issues;
}

/**
 * Get summary statistics about the syntax mapping
 * @returns {Object} Statistics object
 */
function getSyntaxMappingStats() {
    const mapping = loadSyntaxMapping();
    
    const stats = {
        total_properties: Object.keys(mapping.properties).length,
        required_properties: getRequiredProperties().length,
        computed_properties: mapping.computed_properties.length,
        internal_properties: mapping.internal_properties.length,
        unique_symbols: new Set(
            Object.values(mapping.properties)
                .map(rule => rule.symbol)
                .filter(symbol => symbol && symbol !== '')
        ).size,
        rule_types: {}
    };
    
    // Count rule types
    for (const rule of Object.values(mapping.properties)) {
        const ruleType = rule.rule_type;
        stats.rule_types[ruleType] = (stats.rule_types[ruleType] || 0) + 1;
    }
    
    return stats;
}

module.exports = {
    loadSyntaxMapping,
    getPropertySyntax,
    getPropertiesBySymbol,
    getPropertiesByContext,
    getRequiredProperties,
    formatPropertyValue,
    jsonToActionsSyntax,
    validateSyntaxMapping,
    getSyntaxMappingStats
};

// CLI interface
if (require.main === module) {
    console.log('🔧 Actions Syntax Mapping Utilities');
    console.log('='.repeat(50));
    
    const stats = getSyntaxMappingStats();
    
    console.log(`\n📊 Summary:`);
    console.log(`   • ${stats.total_properties} properties mapped`);
    console.log(`   • ${stats.required_properties} required properties`);
    console.log(`   • ${stats.computed_properties} computed properties`);
    console.log(`   • ${stats.internal_properties} internal properties`);
    console.log(`   • ${stats.unique_symbols} unique symbols`);
    
    console.log(`\n🔤 Symbol Usage:`);
    const mapping = loadSyntaxMapping();
    const symbols = {};
    for (const [propertyName, rule] of Object.entries(mapping.properties)) {
        if (rule.symbol && rule.symbol !== '') {
            symbols[rule.symbol] = propertyName;
        }
    }
    
    for (const [symbol, prop] of Object.entries(symbols).sort()) {
        console.log(`   ${symbol} → ${prop}`);
    }
    
    console.log(`\n🏗️  Rule Types:`);
    for (const [ruleType, count] of Object.entries(stats.rule_types).sort()) {
        console.log(`   ${ruleType}: ${count} properties`);
    }
    
    console.log(`\n🧪 Validation:`);
    const issues = validateSyntaxMapping();
    if (issues.length > 0) {
        for (const issue of issues) {
            console.log(`   ⚠️  ${issue}`);
        }
    } else {
        console.log('   ✅ No issues found');
    }
    
    console.log(`\n🎯 Example Conversion:`);
    const exampleJson = {
        name: 'Review quarterly reports',
        state: 'completed',
        priority: 2,
        context: '@office',
        project: 'Q1 Planning',
        durationMinutes: 90,
        uuid: '01936194-d5b0-7890-8000-123456789abc'
    };
    
    console.log('   JSON:', JSON.stringify(exampleJson, null, 2));
    console.log('   Actions:', jsonToActionsSyntax(exampleJson));
}