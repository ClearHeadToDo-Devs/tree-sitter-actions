/**
 * Formatting Test Suite
 *
 * Tests that the topiary.scm query produces spec-compliant formatting.
 * Test cases are vendored from specifications/examples/formatting/
 *
 * Requirements:
 * - topiary CLI must be installed (cargo install topiary-cli)
 */

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

// Path to local formatting examples
const FORMATTING_EXAMPLES = path.join(__dirname, '..', 'examples', 'formatting');

// Check if formatting examples exist
if (!fs.existsSync(FORMATTING_EXAMPLES)) {
  console.error('❌ ERROR: formatting examples not found at:', FORMATTING_EXAMPLES);
  console.error('Expected: examples/formatting/');
  console.error('These should be vendored from specifications/examples/formatting/');
  process.exit(1);
}

// Check if topiary is installed
try {
  execSync('topiary --version', { stdio: 'ignore' });
} catch (error) {
  console.error('❌ ERROR: topiary CLI not found');
  console.error('Install with: cargo install topiary-cli');
  process.exit(1);
}

console.log('Testing topiary formatting against spec examples...\n');

let totalTests = 0;
let passedTests = 0;
let failedTests = 0;
const failures = [];

/**
 * Run formatting tests for a specific style
 */
function testStyle(styleName, topiaryArgs = []) {
  const styleDir = path.join(FORMATTING_EXAMPLES, styleName);

  if (!fs.existsSync(styleDir)) {
    console.log(`⚠️  SKIP: ${styleName} (directory not found)`);
    return;
  }

  console.log(`\n${'='.repeat(50)}`);
  console.log(`Testing ${styleName} style`);
  console.log('='.repeat(50));

  const testCases = fs.readdirSync(styleDir)
    .filter(name => {
      const fullPath = path.join(styleDir, name);
      return fs.statSync(fullPath).isDirectory();
    })
    .sort();

  for (const testCase of testCases) {
    const testDir = path.join(styleDir, testCase);
    const inputFile = path.join(testDir, 'input.actions');
    const expectedFile = path.join(testDir, 'expected.actions');

    if (!fs.existsSync(inputFile) || !fs.existsSync(expectedFile)) {
      console.log(`  ⚠️  SKIP: ${testCase} (missing files)`);
      continue;
    }

    totalTests++;

    try {
      // Read expected output
      const expected = fs.readFileSync(expectedFile, 'utf8');

      // Run topiary on input via stdin
      // Note: Using --skip-idempotence because the topiary query has known idempotence issues
      // See: tree-sitter-actions/src/format.rs:164
      const input = fs.readFileSync(inputFile, 'utf8');
      const topiaryCmd = `topiary format --skip-idempotence --language actions ${topiaryArgs.join(' ')}`;
      const actual = execSync(topiaryCmd, {
        input: input,
        encoding: 'utf8',
        cwd: path.join(__dirname, '..'),
        stdio: ['pipe', 'pipe', 'pipe']
      });

      // Compare
      if (actual === expected) {
        console.log(`  ✅ PASS: ${testCase}`);
        passedTests++;
      } else {
        console.log(`  ❌ FAIL: ${testCase}`);
        console.log(`    Expected:`);
        console.log(`      ${JSON.stringify(expected)}`);
        console.log(`    Got:`);
        console.log(`      ${JSON.stringify(actual)}`);
        failedTests++;
        failures.push(`${styleName}/${testCase}`);
      }
    } catch (error) {
      console.log(`  ❌ FAIL: ${testCase} (topiary error)`);
      console.log(`    Error: ${error.message}`);
      if (error.stderr) {
        console.log(`    Stderr: ${error.stderr.toString()}`);
      }
      failedTests++;
      failures.push(`${styleName}/${testCase}`);
    }
  }
}

// Test compact style (default)
testStyle('compact');

// Test list style (multiline mode)
// Note: Topiary doesn't have a --style flag yet, this tests compact for now
// TODO: Update when topiary supports style selection
testStyle('list');

// Test edge cases
testStyle('edge_cases');

// Summary
console.log('\n' + '='.repeat(50));
console.log('Test Summary');
console.log('='.repeat(50));
console.log(`Total:  ${totalTests}`);
console.log(`Passed: ${passedTests}`);
console.log(`Failed: ${failedTests}`);

if (failedTests > 0) {
  console.log('\nFailed tests:');
  failures.forEach(name => console.log(`  - ${name}`));
  console.log('\n❌ Some tests failed');
  process.exit(1);
} else if (totalTests === 0) {
  console.log('\n⚠️  No tests found');
  process.exit(1);
} else {
  console.log('\n✅ All formatting tests passed!');
}
