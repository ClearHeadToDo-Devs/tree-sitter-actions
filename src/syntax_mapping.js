/**
 * @fileoverview Syntax Mapping Configuration for Actions Language
 * 
 * This module defines the bridge between semantic properties (from ontology/SHACL) 
 * and syntactic representation (in .actions files parsed by tree-sitter).
 *
 * It maps:
 * - Ontology properties → Grammar symbols and parsing rules
 * - SHACL constraints → Grammar validation patterns  
 * - JSON Schema types → Tree-sitter rule types
 *
 * This enables automatic generation of tree-sitter grammar from ontology changes.
 * 
 * @author primary_desktop
 * @license MIT
 */

/**
 * Types of grammar rules that can be generated
 */
const RuleType = {
    CHOICE: 'choice',           // Fixed set of values: priority !1 !2 !3 !4
    PATTERN: 'pattern',         // Regex pattern: context +@office
    UUID_V7: 'uuid_v7',         // Special UUID v7 format: #01234567-89ab-7def-8123-456789abcdef
    DATE_TIME: 'date_time',     // ISO date/time: @2025-01-20T14:30
    INTEGER: 'integer',         // Numeric value: D120 (duration)
    TEXT: 'text',               // Free text: safe_text
    BOOLEAN: 'boolean',         // Boolean values
    REFERENCE: 'reference',     // Reference to another object
    OPTIONAL: 'optional'        // Optional wrapper around other rules
};

/**
 * Context where property appears - affects syntax
 */
const PropertyContext = {
    ROOT_ONLY: 'root_only',     // Only on root actions: project *MyProject
    CHILD_ONLY: 'child_only',   // Only on child actions: parentAction
    ANY_LEVEL: 'any_level'      // Any hierarchical level
};

/**
 * Core syntax mapping: property_name -> syntax configuration
 * 
 * Each property defines:
 * - symbol: Character that introduces property (!, +, @, etc.)
 * - ruleType: How to parse the value
 * - grammarRuleName: Name of the grammar rule
 * - context: Where this property can appear
 * - Additional constraints and formatting hints
 */
const SYNTAX_MAPPING = {
    // === IDENTIFICATION ===
    uuid: {
        symbol: '#',
        ruleType: RuleType.UUID_V7,
        grammarRuleName: 'id',
        context: PropertyContext.ANY_LEVEL,
        pattern: /^[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}$/,
        formatHint: 'Version 7 UUID with optional dashes',
        example: '#01951111-cfa6-718d-b303-d7107f4005b3'
    },
    
    name: {
        symbol: '',  // No symbol - name comes after state
        ruleType: RuleType.TEXT,
        grammarRuleName: 'name',
        context: PropertyContext.ANY_LEVEL,
        isRequired: true,
        formatHint: 'Free text, escape special chars with backslash',
        example: 'Review quarterly reports'
    },
    
    // === CORE PROPERTIES ===
    priority: {
        symbol: '!',
        ruleType: RuleType.CHOICE,
        grammarRuleName: 'priority',
        context: PropertyContext.ANY_LEVEL,
        values: ['1', '2', '3', '4'],
        minValue: 1,
        maxValue: 4,
        formatHint: 'Eisenhower matrix: 1=urgent+important, 4=neither',
        example: '!2'
    },
    
    state: {
        symbol: '',  // Enclosed in brackets [x]
        ruleType: RuleType.CHOICE,
        grammarRuleName: 'state',
        context: PropertyContext.ANY_LEVEL,
        values: [' ', 'x', '-', '=', '_'],  // not_started, completed, in_progress, blocked, cancelled
        isRequired: true,
        defaultValue: ' ',
        formatHint: '[ ]=not started, [x]=completed, [-]=in progress, [=]=blocked, [_]=cancelled',
        example: '[x]'
    },
    
    context: {
        symbol: '+',
        ruleType: RuleType.PATTERN,
        grammarRuleName: 'context',
        context: PropertyContext.ANY_LEVEL,
        pattern: /@[a-zA-Z0-9_-]+/,
        canRepeat: true,
        formatHint: 'GTD contexts: +@office,@computer,@phone',
        example: '+@office,@computer'
    },
    
    description: {
        symbol: '$',
        ruleType: RuleType.TEXT,
        grammarRuleName: 'description', 
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Extended description text',
        example: '$ Make sure you get the stuff from the butcher directly'
    },
    
    // === HIERARCHICAL ===
    project: {
        symbol: '*',
        ruleType: RuleType.TEXT,
        grammarRuleName: 'story',  // Called "story" in current grammar
        context: PropertyContext.ROOT_ONLY,
        formatHint: 'Project/story name for root actions only',
        example: '*Run Errands'
    },
    
    parentAction: {
        symbol: '>',  // Depth markers: >, >>, >>>, >>>>
        ruleType: RuleType.REFERENCE,
        grammarRuleName: 'depth',
        context: PropertyContext.CHILD_ONLY,
        formatHint: 'Hierarchical depth: > child, >> grandchild, etc.',
        example: '> Child action'
    },
    
    depth: {
        symbol: '',  // Calculated from > markers
        ruleType: RuleType.INTEGER,
        grammarRuleName: 'calculated_depth',
        context: PropertyContext.ANY_LEVEL,
        minValue: 0,
        maxValue: 5,
        formatHint: 'Auto-calculated from nesting level',
        computed: true
    },
    
    // === SCHEDULING ===
    doDateTime: {
        symbol: '@',
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'do_date_or_time',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'ISO 8601: @2025-01-20T14:30 or @2025-01-20 or @14:30',
        example: '@2025-01-20T14:30'
    },
    
    doDate: {
        symbol: '@',
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'do_date_or_time',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Date only: @2025-01-20',
        example: '@2025-01-20'
    },
    
    doTime: {
        symbol: '@', 
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'do_date_or_time',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Time only: @14:30',
        example: '@14:30'
    },
    
    dueDateTime: {
        symbol: '@',  // Same symbol as doDateTime - disambiguation by context
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'due_date_or_time',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Due date/time - syntax same as do date',
        example: '@2025-01-30T17:00'
    },
    
    completedDateTime: {
        symbol: '%',
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'completed_date',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Auto-generated completion timestamp',
        example: '%2025-01-19T10:30'
    },
    
    durationMinutes: {
        symbol: 'D',  // Follows date/time: @2025-01-20T14:30D90
        ruleType: RuleType.INTEGER,
        grammarRuleName: 'duration',
        context: PropertyContext.ANY_LEVEL,
        minValue: 1,
        maxValue: 10080,  // 1 week in minutes
        formatHint: 'Duration in minutes: D90',
        example: 'D30'
    },
    
    // === RECURRENCE === 
    recurrenceFrequency: {
        symbol: 'R',  // Follows date/time: @2025-01-20RD (daily)
        ruleType: RuleType.CHOICE,
        grammarRuleName: 'recurrance',  // Note: grammar has typo "recurrance"
        context: PropertyContext.ANY_LEVEL,
        values: ['D', 'W', 'M', 'Y'],  // Daily, Weekly, Monthly, Yearly
        formatHint: 'Recurrence: RD=daily, RW=weekly, RM=monthly, RY=yearly',
        example: 'RW'
    },
    
    byDay: {
        symbol: '',  // Part of recurrence rule: RW Mon Tue
        ruleType: RuleType.CHOICE,
        grammarRuleName: 'weekly_recurrance_days', 
        context: PropertyContext.ANY_LEVEL,
        values: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'],
        canRepeat: true,
        formatHint: 'Days for weekly recurrence',
        example: 'Mon Tue'
    },
    
    recurrenceInterval: {
        symbol: 'I',  // RI2 = every 2 intervals
        ruleType: RuleType.INTEGER,
        grammarRuleName: 'recurrence_interval',
        context: PropertyContext.ANY_LEVEL,
        minValue: 1,
        defaultValue: '1',
        formatHint: 'Recurrence interval: I2 = every 2nd occurrence',
        example: 'I2'
    },
    
    recurrenceCount: {
        symbol: 'C',  // RC10 = max 10 occurrences
        ruleType: RuleType.INTEGER,
        grammarRuleName: 'recurrence_count',
        context: PropertyContext.ANY_LEVEL,
        minValue: 1,
        formatHint: 'Max recurrence count: C10',
        example: 'C10'
    },
    
    recurrenceUntil: {
        symbol: 'U',  // RU2025-12-31 = until end of year
        ruleType: RuleType.DATE_TIME,
        grammarRuleName: 'recurrence_until',
        context: PropertyContext.ANY_LEVEL,
        formatHint: 'Recurrence end date: U2025-12-31',
        example: 'U2025-12-31'
    },
};

/**
 * State mapping for the special bracket syntax
 * Maps semantic state values to bracket symbols
 */
const STATE_MAPPING = {
    'not_started': ' ',
    'active': ' ',        // Map active to not_started for now
    'completed': 'x',
    'in_progress': '-',
    'blocked': '=',
    'cancelled': '_'
};

/**
 * Properties that don't have direct syntax representation (computed or internal)
 */
const COMPUTED_PROPERTIES = new Set([
    'depth',           // Calculated from > nesting
    'parentAction',    // Implicit from hierarchy
]);

/**
 * Properties that are represented in JSON but not directly in .actions syntax
 * These might be covered by other properties or be advanced features
 */
const INTERNAL_PROPERTIES = new Set([
    'byMinute', 'byHour', 'byMonthDay', 'byMonth',  // Advanced recurrence
    'dueDate', 'dueTime',                          // Covered by dueDateTime 
]);

// === UTILITY FUNCTIONS ===

/**
 * Get syntax rule for a property
 * @param {string} propertyName - Name of the property
 * @returns {Object|null} Syntax rule or null if not found
 */
function getPropertySyntax(propertyName) {
    return SYNTAX_MAPPING[propertyName] || null;
}

/**
 * Get all properties that use a specific symbol
 * @param {string} symbol - The symbol to search for
 * @returns {Array<string>} Property names using that symbol
 */
function getPropertiesBySymbol(symbol) {
    return Object.entries(SYNTAX_MAPPING)
        .filter(([_, rule]) => rule.symbol === symbol)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Get properties available in a specific context
 * @param {string} context - The context to filter by
 * @returns {Array<string>} Property names available in that context
 */
function getPropertiesByContext(context) {
    return Object.entries(SYNTAX_MAPPING)
        .filter(([_, rule]) => 
            rule.context === context || rule.context === PropertyContext.ANY_LEVEL)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Get properties that are required in the syntax
 * @returns {Array<string>} Required property names
 */
function getRequiredProperties() {
    return Object.entries(SYNTAX_MAPPING)
        .filter(([_, rule]) => rule.isRequired)
        .map(([propertyName, _]) => propertyName);
}

/**
 * Convert JSON property value to actions syntax
 * @param {string} propertyName - Name of the property
 * @param {*} value - Value from JSON
 * @returns {string} Formatted syntax string
 */
function formatPropertyValue(propertyName, value) {
    const rule = getPropertySyntax(propertyName);
    if (!rule) return '';
    
    // Special handling for different property types
    switch (propertyName) {
        case 'state':
            return `[${STATE_MAPPING[value] || ' '}]`;
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
    const issues = [];
    
    // Check for symbol conflicts
    const symbolUsage = {};
    for (const [propertyName, rule] of Object.entries(SYNTAX_MAPPING)) {
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

// Export for Node.js/CommonJS
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        RuleType,
        PropertyContext,
        SYNTAX_MAPPING,
        STATE_MAPPING,
        COMPUTED_PROPERTIES,
        INTERNAL_PROPERTIES,
        getPropertySyntax,
        getPropertiesBySymbol,
        getPropertiesByContext,
        getRequiredProperties,
        formatPropertyValue,
        jsonToActionsSyntax,
        validateSyntaxMapping
    };
}

// For browser/ES6 modules
if (typeof window !== 'undefined') {
    window.ActionsSyntaxMapping = {
        RuleType,
        PropertyContext,
        SYNTAX_MAPPING,
        STATE_MAPPING,
        COMPUTED_PROPERTIES,
        INTERNAL_PROPERTIES,
        getPropertySyntax,
        getPropertiesBySymbol,
        getPropertiesByContext,
        getRequiredProperties,
        formatPropertyValue,
        jsonToActionsSyntax,
        validateSyntaxMapping
    };
}

// CLI usage for testing/validation
if (require.main === module) {
    console.log('🔧 Actions Syntax Mapping Configuration');
    console.log('='.repeat(50));
    
    console.log(`\n📊 Summary:`);
    console.log(`   • ${Object.keys(SYNTAX_MAPPING).length} properties mapped`);
    console.log(`   • ${getRequiredProperties().length} required properties`);
    console.log(`   • ${COMPUTED_PROPERTIES.size} computed properties`);
    console.log(`   • ${INTERNAL_PROPERTIES.size} internal properties`);
    
    console.log(`\n🔤 Symbol Usage:`);
    const symbols = {};
    for (const [propertyName, rule] of Object.entries(SYNTAX_MAPPING)) {
        if (rule.symbol && rule.symbol !== '') {
            symbols[rule.symbol] = propertyName;
        }
    }
    
    for (const [symbol, prop] of Object.entries(symbols).sort()) {
        console.log(`   ${symbol} → ${prop}`);
    }
    
    console.log(`\n🏗️  Rule Types:`);
    const ruleCounts = {};
    for (const rule of Object.values(SYNTAX_MAPPING)) {
        const ruleType = rule.ruleType;
        ruleCounts[ruleType] = (ruleCounts[ruleType] || 0) + 1;
    }
    
    for (const [ruleType, count] of Object.entries(ruleCounts).sort()) {
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
    
    console.log(`\n📋 Context Usage:`);
    for (const context of Object.values(PropertyContext)) {
        const props = getPropertiesByContext(context);
        if (context !== PropertyContext.ANY_LEVEL) {
            console.log(`   ${context}: ${props.length} properties`);
        }
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