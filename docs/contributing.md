# Contributing Guide

This repository implements the concrete syntax tree for the `.actions` DSL. The
[`specifications`](https://github.com/ClearHeadToDo-Devs/specifications) repository
owns the language contract, example source, canonical formatting forms, lint
codes, and JSON Schema. This repository owns `grammar.js`, generated parser
artifacts, Tree-sitter queries, and parser-specific expected S-expressions.

## Test data boundary

The grammar deliberately does not ship a second `.actions` example corpus.
Tests read inert oracle data from a specifications checkout:

- `test/test_descriptions.json` maps each grammar case to a spec-relative source
  path and a parser-specific expected tree;
- `test/trees/*.sexp` contains reviewed CST expectations owned by the grammar;
- `test/spec_sources_test.js` parses each registered specification file directly
  and compares its CST without rewriting the source bytes;
- `test/corpus/*.txt` is a generated Tree-sitter presentation of those cases and
  is ignored;
- `specifications/examples/formatting/` contains the formatter's input/expected
  byte pairs.

Set `CLEARHEAD_SPEC_DIR` when the specification is not checked out as the
repository's sibling. The default is `../specifications`.

## Running tests

```bash
CLEARHEAD_SPEC_DIR=../specifications npm run test:grammar
CLEARHEAD_SPEC_DIR=../specifications npm run test:formatting
CLEARHEAD_SPEC_DIR=../specifications npm run test:all
cargo test
```

The GitHub workflow checks out the specification explicitly and sets the same
environment variable. The specification remains inert: the implementation pulls
in oracle data and proves itself against it.

## Regenerating parser expectations

```bash
CLEARHEAD_SPEC_DIR=../specifications npm run regen:verify
```

`regen:trees` parses every source registered in `test/test_descriptions.json` and
rewrites its `.sexp`. `regen:corpus` combines the spec source, description, and
expected tree into Tree-sitter corpus files. Review tree changes; regeneration
is not itself evidence that a changed tree is correct.

## Adding a grammar case

1. Add or reuse the smallest suitable `.actions` fixture in `specifications`.
   Byte-level parser/recovery cases belong under
   `examples/conformance/syntax/`; ordinary valid examples belong under
   `examples/actions/`.
2. Add an object to `test/test_descriptions.json` with `description` and the
   spec-relative `source` path.
3. Run `npm run regen:verify` with `CLEARHEAD_SPEC_DIR` set.
4. Review the new `test/trees/<name>.sexp` and commit changes in both owning
   repositories.

Do not copy the fixture into this repository. Expected S-expressions stay here
because CST node shape is a grammar implementation detail, not part of the DSL
specification.

## Schemas and examples

The canonical JSON Schema is
`specifications/schemas/actions.schema.json`; this grammar does not generate or
publish a competing copy. `patterns.js` remains the source used to construct the
parser's lexical rules only. Storage schemas belong to consuming applications.

The Rust and npm packages contain the parser and queries, not specification
fixtures. `bindings/rust/build.rs` compiles the generated C parser; it does not
generate an examples API.

## Publishing checklist

1. Run `CLEARHEAD_SPEC_DIR=../specifications npm run regen:verify`.
2. Run `CLEARHEAD_SPEC_DIR=../specifications npm run test:all`.
3. Run `cargo test` and `cargo doc`.
4. Inspect `npm pack --dry-run` and `cargo package --list`.
5. Update versions and changelog, then tag and publish through the release
   process.

## Project structure

```text
tree-sitter-actions/
├── bindings/              # language bindings and Rust build script
├── grammar.js             # grammar definition
├── patterns.js            # parser lexical patterns
├── queries/               # Tree-sitter and Topiary queries
├── scripts/               # corpus/expectation generation and checks
├── src/                   # generated parser source
└── test/
    ├── trees/             # reviewed CST expectations
    ├── corpus/            # generated, ignored Tree-sitter corpus
    └── test_descriptions.json
```
