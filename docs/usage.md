# Usage Guide

## Command line

```bash
tree-sitter generate
tree-sitter parse ../specifications/examples/actions/with_priority.actions
CLEARHEAD_SPEC_DIR=../specifications npm run test:grammar
```

The specification repository owns `.actions` examples. This parser package does
not bundle them; clone `specifications` or use your own source files.

## Rust

```toml
[dependencies]
tree-sitter = "0.26"
tree-sitter-actions = "0.10"
```

```rust
use tree_sitter::Parser;
use tree_sitter_actions::LANGUAGE;

let source = "[ ] Buy milk !1\n";
let mut parser = Parser::new();
parser.set_language(&LANGUAGE.into()).unwrap();
let tree = parser.parse(source, None).unwrap();
assert!(!tree.root_node().has_error());
println!("{}", tree.root_node().to_sexp());
```

Use Tree-sitter's cursor or query APIs to traverse the CST. The reviewed expected
node shapes in `test/trees/` are implementation examples; the semantic DSL
contract lives in the
[`specifications`](https://github.com/ClearHeadToDo-Devs/specifications)
repository.

## JavaScript

Install `tree-sitter-actions` and use the exported language with Tree-sitter.
The canonical JSON Schema is not bundled by this parser; obtain
`schemas/actions.schema.json` from `specifications`. Storage projections belong
to consuming applications and are not exported by the grammar package.

## Editors

Tree-sitter grammars can provide highlighting, folding, and indentation.
Neovim users can configure the parser source:

```lua
local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
parser_config.actions = {
  install_info = {
    url = "https://github.com/ClearHeadToDo-Devs/tree-sitter-actions",
    files = { "src/parser.c", "src/scanner.c" },
    branch = "master",
  },
  filetype = "actions",
}
```

Other editors can use the same generated parser through their Tree-sitter
integration.

## Syntax validation

A parser consumer can reject syntax recovery at a strict boundary:

```rust
fn has_valid_syntax(parser: &mut tree_sitter::Parser, source: &str) -> bool {
    parser
        .parse(source, None)
        .is_some_and(|tree| !tree.root_node().has_error())
}
```

Semantic validation and canonical JSON projection belong to consumers such as
`clearhead-core`; this crate exposes concrete syntax rather than a second domain
model.

## Further reading

- [README](../README.md)
- [Contributing](contributing.md)
- [Canonical specification](https://github.com/ClearHeadToDo-Devs/specifications)
- [Tree-sitter query patterns](../queries/actions/README.md)
