const assert = require('assert');
const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const root = path.join(__dirname, '..');
const specRoot = process.env.CLEARHEAD_SPEC_DIR
  ? path.resolve(process.env.CLEARHEAD_SPEC_DIR)
  : path.resolve(root, '..', 'specifications');
function loadRegistry() {
  try {
    return JSON.parse(
      fs.readFileSync(path.join(root, 'test', 'test_descriptions.json'), 'utf8'),
    );
  } catch (error) {
    throw new Error(`failed to read test registry: ${error.message}`);
  }
}

const registry = loadRegistry();
let checked = 0;
for (const tests of Object.values(registry)) {
  for (const [name, test] of Object.entries(tests)) {
    const sourcePath = path.join(specRoot, test.source);
    const expectedPath = path.join(root, 'test', 'trees', `${name}.sexp`);
    const result = spawnSync('tree-sitter', ['parse', '--no-ranges', sourcePath], {
      cwd: root,
      encoding: 'utf8',
    });
    assert.match(result.stdout, /\(source_file/, result.stderr || `failed to parse ${sourcePath}`);
    const actual = result.stdout
      .trim()
      .replace(/\n[^\n]*\tParse:.*$/, '')
      .trim();
    const expected = fs.readFileSync(expectedPath, 'utf8').trim();
    assert.strictEqual(actual, expected, `${test.source} changed its reviewed CST`);
    checked++;
  }
}

assert.ok(checked > 0, 'no specification sources were registered');
console.log(`Parsed ${checked} specification fixtures directly from their exact files`);
