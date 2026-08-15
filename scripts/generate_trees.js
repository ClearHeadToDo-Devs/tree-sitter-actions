const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const ROOT = path.join(__dirname, '..');
const SPEC_ROOT = process.env.CLEARHEAD_SPEC_DIR
  ? path.resolve(process.env.CLEARHEAD_SPEC_DIR)
  : path.resolve(ROOT, '..', 'specifications');
const TREES_DIR = path.join(ROOT, 'test', 'trees');

function loadRegistry() {
  try {
    return JSON.parse(
      fs.readFileSync(path.join(ROOT, 'test', 'test_descriptions.json'), 'utf8'),
    );
  } catch (error) {
    console.error(`Failed to read test descriptions: ${error.message}`);
    process.exit(1);
  }
}

const registry = loadRegistry();
console.log('Generating tree files from specification fixtures...\n');

for (const tests of Object.values(registry)) {
  for (const [testName, test] of Object.entries(tests)) {
    const examplePath = path.join(SPEC_ROOT, test.source);
    const treePath = path.join(TREES_DIR, `${testName}.sexp`);
    if (!fs.existsSync(examplePath)) {
      console.error(`Registered specification fixture not found: ${examplePath}`);
      process.exit(1);
    }

    const result = spawnSync('tree-sitter', ['parse', '--no-ranges', examplePath], {
      encoding: 'utf8',
      cwd: ROOT,
    });

    // Parse errors are valid expected trees for negative grammar tests. A real
    // invocation failure has no source tree and must still fail regeneration.
    if (!result.stdout.includes('(source_file')) {
      console.error(`Failed to generate: ${testName}.sexp`);
      console.error(result.stderr || result.stdout);
      process.exit(1);
    }

    const cleanedOutput = result.stdout
      .trim()
      .replace(/\n[^\n]*\tParse:.*$/, '')
      .trim();

    fs.writeFileSync(treePath, cleanedOutput);
    console.log(`Generated test/trees/${testName}.sexp`);
  }
}

console.log('\nTree generation complete!');
