#!/usr/bin/env node

/**
 * @fileoverview Integration test for syntax mapping system
 * Tests the full pipeline from ontology JSON to actions syntax
 */

const {
    jsonToActionsSyntax,
    validateSyntaxMapping,
    getPropertySyntax,
    loadSyntaxMapping
} = require('./src/syntax_mapping_utils.js');
const {
    convertJsonExample
} = require('./src/json_to_actions_converter.js');

console.log('🧪 Testing Syntax Mapping System');
console.log('='.repeat(40));

let testsPassed = 0;
let testsFailed = 0;

function test(name, testFn) {
    try {
        console.log(`\n🔍 ${name}`);
        testFn();
        console.log('   ✅ PASS');
        testsPassed++;
    } catch (error) {
        console.log(`   ❌ FAIL: ${error.message}`);
        testsFailed++;
    }
}

// Test 1: Syntax mapping validation
test('Syntax mapping validation', () => {
    const issues = validateSyntaxMapping();
    // We expect the @ symbol conflicts but those are by design
    const realIssues = issues.filter(issue => !issue.includes("Symbol '@'"));
    if (realIssues.length > 0) {
        throw new Error(`Validation issues: ${realIssues.join(', ')}`);
    }
});

// Test 2: Basic JSON to actions conversion
test('Basic JSON to actions conversion', () => {
    const json = {
        name: 'Test Task',
        state: 'active',
        priority: 1
    };

    const result = jsonToActionsSyntax(json);
    const expected = '[ ] Test Task !1';

    if (result !== expected) {
        throw new Error(`Expected "${expected}", got "${result}"`);
    }
});

// Test 3: Complex JSON to actions conversion
test('Complex JSON to actions conversion', () => {
    const json = {
        name: 'Complex Task',
        state: 'completed',
        priority: 2,
        description: 'A long description',
        context: '@office',
        durationMinutes: 90,
        uuid: '01234567-89ab-7def-8123-456789abcdef'
    };

    const result = jsonToActionsSyntax(json);

    // Check individual components are present
    if (!result.includes('[x]')) throw new Error('Missing completed state');
    if (!result.includes('Complex Task')) throw new Error('Missing name');
    if (!result.includes('!2')) throw new Error('Missing priority');
    if (!result.includes('$ A long description')) throw new Error('Missing description');
    if (!result.includes('+@office')) throw new Error('Missing context');
    if (!result.includes('D90')) throw new Error('Missing duration');
    if (!result.includes('#01234567-89ab-7def-8123-456789abcdef')) throw new Error('Missing UUID');
});

// Test 4: Property symbol mapping
test('Property symbol mapping', () => {
    const expectedMappings = {
        'priority': '!',
        'context': '+',
        'description': '$',
        'uuid': '#',
        'completedDateTime': '%',
        'project': '*',
        'durationMinutes': 'D'
    };

    for (const [prop, expectedSymbol] of Object.entries(expectedMappings)) {
        const rule = getPropertySyntax(prop);
        if (!rule) {
            throw new Error(`Missing mapping for ${prop}`);
        }
        if (rule.symbol !== expectedSymbol) {
            throw new Error(`${prop} should use symbol '${expectedSymbol}', got '${rule.symbol}'`);
        }
    }
});

// Test 5: File conversion (if ontology examples exist)
test('File conversion', () => {
    try {
        const result = convertJsonExample('../ontology/examples/valid-action.json');
        if (!result.success) {
            throw new Error(`Conversion failed: ${result.error}`);
        }

        // Basic checks on the converted syntax
        if (!result.actionsSyntax.includes('Review quarterly reports')) {
            throw new Error('Missing expected action name');
        }
        if (!result.actionsSyntax.includes('!2')) {
            throw new Error('Missing priority conversion');
        }
    } catch (error) {
        if (error.code === 'ENOENT') {
            console.log('   ⏭️  SKIP: Ontology examples not found');
            return;
        }
        throw error;
    }
});

// Test 6: State mapping
test('State mapping', () => {
    const stateTests = [{
            json: {
                name: 'Test',
                state: 'active'
            },
            expected: '[ ]'
        },
        {
            json: {
                name: 'Test',
                state: 'completed'
            },
            expected: '[x]'
        },
        {
            json: {
                name: 'Test',
                state: 'not_started'
            },
            expected: '[ ]'
        }
    ];

    for (const {
            json,
            expected
        }
        of stateTests) {
        const result = jsonToActionsSyntax(json);
        if (!result.startsWith(expected)) {
            throw new Error(`State ${json.state} should map to ${expected}`);
        }
    }
});

console.log('\n' + '='.repeat(40));
console.log(`📊 Test Results:`);
console.log(`   ✅ Passed: ${testsPassed}`);
console.log(`   ❌ Failed: ${testsFailed}`);
console.log(`   📊 Total:  ${testsPassed + testsFailed}`);

if (testsFailed > 0) {
    process.exit(1);
} else {
    console.log('\n🎉 All tests passed!');
    console.log('\n📋 Next steps:');
    console.log('   1. Run tree-sitter parser tests with generated syntax');
    console.log('   2. Update grammar.js with missing symbols (+, $, I, C, U)');
    console.log('   3. Add bidirectional parsing (actions → JSON)');
}
