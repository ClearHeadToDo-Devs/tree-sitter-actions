# Tree-Sitter Actions Parser

**Ontology-driven parser for `.actions` plaintext task files**

**Status:** Phase 2 Complete - Parser generation working, ready for testing

---

## Quick Start

```bash
# Generate parser from ontology
npm run generate && npm run build:parser

# Test
tree-sitter parse examples/with_priority.actions
```

## Documentation

**Start here:**
- **[CLAUDE.md](./CLAUDE.md)** - Developer guide, how to use
- **[ARCHITECTURE.md](./ARCHITECTURE.md)** - Complete technical architecture
- **[docs/action_specification.md](./docs/action_specification.md)** - File format specification

**Project planning:**
- **[ROADMAP.md](./ROADMAP.md)** - Development phases
- **[PROGRESS.md](./PROGRESS.md)** - Current status
- **[PHASE2_COMPLETE.md](./PHASE2_COMPLETE.md)** - Phase 2 details

**Archive:**
- **[docs/archive/](./docs/archive/)** - Architecture decision records

---

## What This Is

A tree-sitter parser for `.actions` files - a plaintext task format that's:

- **Human-readable** - Edit with any text editor
- **Machine-parseable** - Structured AST for tooling
- **Ontology-driven** - Generated from semantic definitions
- **Flexible** - Use standalone or within larger frameworks

### Use Cases

- Alternative to `todo.txt` with richer structure
- Task children within ClearHead Framework stories
- GTD-style project task lists
- Integration with calendars (iCal format support)
- Neovim text objects and highlighting

---

## How It Works

This parser is **generated from ontology annotations**:

```
parser-ontology.ttl → syntax_mapping.json → grammar.js → C parser
```

When you change the ontology, the parser automatically updates. See [ARCHITECTURE.md](./ARCHITECTURE.md) for details.

## Roadmap
While I am trying to be relatively minimal with the parser, only supporting what is needed, there is still a need to support features that may be needed by others to increase longevity in the future:
- [x] Status
- [x] Name
- [x] Description
- [x] Priority
- [x] Context (Tags)
- [x] Story 
    - (or Priority if thats what you want to use this for, but the parent)
- [-] Do Date/Time with Recurrance
    - [x] Do Date
    - [x] Do Time
    - [-] Recurrance
        - [x] Daily
        - [x] Weekly
        - [-] Monthly
        - [-] Yearly
        - [-] Custom
- [-] Due date/time
- [x] Completed Date/time
- [x] ID (UUID v7) 
    - (simply checks if its a valid UUID, version validation left to clients)
- [x] up to 5 layers of children with all above properties

## Deployment Targets
So far, there are two usecases i know I will be using this for:
- [-] Within Neovim to give various features for text editing including:
    - [-] Highlighting
    - [-] indentation
    - [-] folding
    - [-] hiding rules
    - [-] text objects
- [-] as a library within the cli for:
    - [-] structured analysis of documents
    - [-] ease in type-serialization and deserialization

## Testing
All features of the parser should be covered by tests within the `tests` folder and can be run using the standard `tree-sitter test` if you have the cli installed locally

One deviation we have made from other implementations is that tests actually reside split between three files:
1. the `test/test_descriptions.json` file which contains 3 layers:
  1. The file name of the corpus test each test belongs to
  2. the name of the test
  3. the description
2. an actions file within the `examples` file of the same name of the test
3. a sexp file within `test/sexp` which shows the expected output tree in s-exp format

we use `scripts/generate_tests` to read these files and generate the corpus tests themselves
- this is why the test folder itself is not only empty, but ignored in git as this is required to keep things tidy
- this was ultimately intended to make these tests and files more reuasable in other contexts

## Ontology Development
One core part of how we do this work is that we first created an ontology that semantically understands the domain of actions, and even lines to text to some degree as well as understanding how the specification should be written.

Think of this ontology as the formal definition of all the rules and concepts outlined in the primary specification.

The core part of this application is ACTUALLY the ontology itself, which is extending the action ontology hosted at [my site](https://clearhead.us/vocab/actions/v3/) where we pull:
- the core ontology itself
- the SHACL shapes that define the constraints on the ontology
- the example data that we generate our example files from

### Next Steps
1. while the domain ontology we pull is strictly concerned with the concepts, this ontology can be seen as an application ontology that encodes the standards set out within the ontology and SHACL shapes themselves.
2. From there, we use this extended ontology and SHACL to generate JSON Type Definition (JTD) schemas 
3. JTD schemas can be used to automatically GENERATE the tree-sitter grammar types using [json-typedef-codegen](https://github.com/jsontypedef/json-typedef-codegen) which will create our `grammar.ts` file from the JTD schemas 
4. using [3p3r/type-sitter](https://github.com/3p3r/type-sitter), we create our `grammar.js` file from the `grammar.ts` file.
5. Finally, tree-sitter itself can be used to generate the parser from our grammar file, which is what ultimately will be exported.
