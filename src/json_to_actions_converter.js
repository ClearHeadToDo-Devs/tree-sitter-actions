#!/usr/bin/env node

/**
 * @fileoverview Convert JSON Schema examples to .actions syntax
 * 
 * This tool demonstrates the syntax mapping by converting JSON action examples
 * from the ontology project into .actions file syntax that can be parsed by 
 * the tree-sitter grammar.
 * 
 * Usage:
 *   node src/json_to_actions_converter.js path/to/example.json
 *   node src/json_to_actions_converter.js --test-all
 * 
 * @author primary_desktop
 */

const fs = require('fs');
const path = require('path');
const {
    jsonToActionsSyntax,
    getPropertySyntax,
    validateSyntaxMapping
} = require('./syntax_mapping_utils.js');

/**
 * Load and convert a JSON example to actions syntax
 * @param {string} jsonFilePath - Path to JSON file
 * @returns {Object} Conversion result
 */
function convertJsonExample(jsonFilePath) {
    try {
        const jsonContent = fs.readFileSync(jsonFilePath, 'utf8');
        const jsonAction = JSON.parse(jsonContent);

        // Remove schema reference as it's not part of the action data
        delete jsonAction.$schema;

        const actionsSyntax = jsonToActionsSyntax(jsonAction);

        return {
            success: true,
            jsonPath: jsonFilePath,
            jsonAction,
            actionsSyntax,
            filename: path.basename(jsonFilePath, '.json')
        };
    } catch (error) {
        return {
            success: false,
            jsonPath: jsonFilePath,
            error: error.message
        };
    }
}

/**
 * Generate tree-sitter test case from conversion result
 * @param {Object} result - Conversion result
 * @returns {string} Tree-sitter test case
 */
function generateTreeSitterTest(result) {
    if (!result.success) return '';

    const testName = result.filename.replace(/[-_]/g, ' ');

    return `================
${testName}
================
${result.actionsSyntax}

---

(action_list
 (root_action
  (core_properties
   (state
    (opening)
    (icon)
    (closing))
   (name)
   ; TODO: Add expected parse tree structure
   )))`;
}

/**
 * Find all JSON example files in ontology directory
 * @returns {Array<string>} Paths to JSON example files
 */
function findJsonExamples() {
    const ontologyExamplesPath = '../ontology/examples';
    const exampleFiles = [];

    try {
        const files = fs.readdirSync(ontologyExamplesPath);
        for (const file of files) {
            if (file.endsWith('.json') && file.startsWith('valid-')) {
                exampleFiles.push(path.join(ontologyExamplesPath, file));
            }
        }
    } catch (error) {
        console.error(`❌ Could not read ontology examples: ${error.message}`);
        console.log('   Make sure you run this from the tree-sitter-actions directory');
        console.log('   and that the ontology project is in ../ontology/');
    }

    return exampleFiles;
}

/**
 * Main CLI function
 */
function main() {
    const args = process.argv.slice(2);

    if (args.length === 0 || args[0] === '--help' || args[0] === '-h') {
        console.log('🔄 JSON to Actions Syntax Converter');
        console.log('');
        console.log('Usage:');
        console.log('  node src/json_to_actions_converter.js <json-file>');
        console.log('  node src/json_to_actions_converter.js --test-all');
        console.log('  node src/json_to_actions_converter.js --validate');
        console.log('');
        console.log('Examples:');
        console.log('  node src/json_to_actions_converter.js ../ontology/examples/valid-action.json');
        console.log('  node src/json_to_actions_converter.js --test-all');
        return;
    }

    if (args[0] === '--validate') {
        console.log('🧪 Validating Syntax Mapping...');
        const issues = validateSyntaxMapping();
        if (issues.length > 0) {
            console.log('\n⚠️  Issues found:');
            for (const issue of issues) {
                console.log(`   ${issue}`);
            }
        } else {
            console.log('✅ No validation issues found');
        }
        return;
    }

    if (args[0] === '--test-all') {
        console.log('🔄 Converting all JSON examples to .actions syntax...');
        console.log('');

        const jsonFiles = findJsonExamples();
        if (jsonFiles.length === 0) {
            console.log('❌ No JSON example files found');
            return;
        }

        const results = [];
        for (const jsonFile of jsonFiles) {
            const result = convertJsonExample(jsonFile);
            results.push(result);

            if (result.success) {
                console.log(`✅ ${path.basename(result.jsonPath)}:`);
                console.log(`   ${result.actionsSyntax}`);
                console.log('');
            } else {
                console.log(`❌ ${path.basename(result.jsonPath)}: ${result.error}`);
            }
        }

        // Generate summary
        const successful = results.filter(r => r.success);
        const failed = results.filter(r => !r.success);

        console.log('📊 Summary:');
        console.log(`   ✅ ${successful.length} successful conversions`);
        if (failed.length > 0) {
            console.log(`   ❌ ${failed.length} failed conversions`);
        }

        // Optionally generate test cases
        if (successful.length > 0) {
            console.log('\n🧪 Generated Tree-sitter Test Cases:');
            console.log('(Add these to your test/corpus/ files)');
            console.log('='.repeat(50));

            for (const result of successful) {
                console.log(generateTreeSitterTest(result));
                console.log('');
            }
        }

        return;
    }

    // Single file conversion
    const jsonFilePath = args[0];
    if (!fs.existsSync(jsonFilePath)) {
        console.error(`❌ File not found: ${jsonFilePath}`);
        return;
    }

    console.log(`🔄 Converting ${jsonFilePath} to .actions syntax...`);
    console.log('');

    const result = convertJsonExample(jsonFilePath);

    if (result.success) {
        console.log('📄 Original JSON:');
        console.log(JSON.stringify(result.jsonAction, null, 2));
        console.log('');

        console.log('🎯 Actions Syntax:');
        console.log(result.actionsSyntax);
        console.log('');

        console.log('🧪 Tree-sitter Test Case:');
        console.log(generateTreeSitterTest(result));

        // Show property breakdown
        console.log('\n🔍 Property Mapping:');
        for (const [prop, value] of Object.entries(result.jsonAction)) {
            const syntaxRule = getPropertySyntax(prop);
            if (syntaxRule) {
                console.log(`   ${prop}: "${value}" → ${syntaxRule.symbol}${value} (${syntaxRule.rule_type})`);
            } else {
                console.log(`   ${prop}: "${value}" → (no syntax mapping)`);
            }
        }
    } else {
        console.error(`❌ Conversion failed: ${result.error}`);
    }
}

// Run if called directly
if (require.main === module) {
    main();
}

module.exports = {
    convertJsonExample,
    generateTreeSitterTest,
    findJsonExamples
};
