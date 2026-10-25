const assert = require('node:assert/strict');
const { test } = require('node:test');
const fs = require('node:fs');
const path = require('node:path');
const { execFileSync } = require('node:child_process');
const Parser = require('tree-sitter');
const registry = require('../../test/test_descriptions.json');

const root = path.resolve(__dirname, '../..');
const specRoot = process.env.CLEARHEAD_SPEC_DIR
  ? path.resolve(process.env.CLEARHEAD_SPEC_DIR)
  : path.resolve(root, '../specifications');
const parser = new Parser();
parser.setLanguage(require('.'));

// Preserve named CST structure, field ownership and leaf values, excluding only
// source positions and boundary whitespace that formatting is allowed to change.
function semanticCst(source) {
  const tree = parser.parse(source);
  assert.equal(tree.rootNode.hasError, false, tree.rootNode.toString());
  function project(node) {
    return {
      type: node.type,
      ...(node.namedChildCount === 0 ? { text: node.text.trim() } : {}),
      children: node.namedChildren.map((child, index) => ({
        field: node.fieldNameForNamedChild(index),
        node: project(child),
      })),
    };
  }
  return project(tree.rootNode);
}

function format(source) {
  return execFileSync('topiary', [
    'format', '--language', 'actions', '--query',
    path.join(root, 'queries/actions/formatting.scm'),
  ], {
    cwd: root,
    env: { ...process.env, TOPIARY_CONFIG_FILE: path.join(root, '.topiary/languages.ncl') },
    input: source,
    encoding: 'utf8',
  });
}

for (const [name, fixture] of [
  ['daily_review_habit', '01_daily_review'],
  ['weekly_review_habit', '02_weekly_review'],
]) {
  test(`${name}: shared canonical bytes, semantic CST round-trip and idempotence`, () => {
    const source = fs.readFileSync(path.join(specRoot, registry.dates[name].source), 'utf8');
    const directory = path.join(specRoot, 'examples/formatting/habits', fixture);
    const input = fs.readFileSync(path.join(directory, 'input.actions'), 'utf8');
    const expected = fs.readFileSync(path.join(directory, 'expected.actions'), 'utf8');
    assert.equal(expected, source, 'formatting oracle must retain the approved canonical source');
    assert.ok(expected.endsWith('\n'), 'canonical source must end in a newline');
    const actual = format(input);
    assert.equal(actual, expected, 'Topiary output must match exact canonical bytes');
    assert.deepEqual(semanticCst(input), semanticCst(source), 'only whitespace may vary');
    assert.deepEqual(semanticCst(actual), semanticCst(input), 'formatting must preserve fields and child structure');
    assert.equal(format(actual), actual, 'canonical formatting must be idempotent');
    assert.equal(format(source), source, 'approved source must already be canonical');
  });
}
