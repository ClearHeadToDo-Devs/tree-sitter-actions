const assert = require("node:assert");
const { test } = require("node:test");

const Parser = require("tree-sitter");

const language = require(".");

function parse(source) {
  const parser = new Parser();
  parser.setLanguage(language);
  return parser.parse(source);
}

test("can load grammar", () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(language));
});

test("description prose accepts lone brackets while preserving links", () => {
  const tree = parse(
    "[ ] brackets $reserved !@%+{} and lone [ or [wrapped] are prose; " +
      "[[label|https://example.com]] and [[target]] are links$"
  );

  assert.equal(tree.rootNode.hasError, false);
  assert.equal(tree.rootNode.descendantsOfType("description_lone_open_bracket").length, 2);
  assert.equal(tree.rootNode.descendantsOfType("link").length, 2);
});

test("an incomplete link does not consume the following action", () => {
  const tree = parse(
    "[ ] incomplete $before [[target$\n" +
      "[ ] following $still a separate action$"
  );
  const actions = tree.rootNode.namedChildren.filter((node) => node.type === "root_action");

  assert.equal(tree.rootNode.hasError, true);
  assert.equal(actions.length, 2);
  assert.equal(actions[1].startPosition.row, 1);
});
