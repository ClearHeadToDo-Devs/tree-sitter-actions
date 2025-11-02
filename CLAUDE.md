# Tree-Sitter Actions Parser

**Purpose:** Parse `.actions` plaintext files into Abstract Syntax Trees (AST)

**Status:** In development - grammar will be GENERATED from TypeScript types

---

## Architecture

This parser follows an **ontology-driven generation** approach:

```
V3 Ontology + SHACL
(from ../ontology/)
       ↓
   JTD Schemas
       ↓
TypeScript Types
       ↓
Parser Ontology Extension
(adds symbol mappings: priority → "!")
       ↓
  [type-sitter]
       ↓
  grammar.js (GENERATED!)
       ↓
Tree-Sitter Parser
```

### Key Principle: Ontology Extension

**We DON'T use separate config files** (like `syntax_mapping.json`).

**We DO extend the V3 ontology** with parser-specific concepts:

```turtle
# parser-ontology.ttl

@prefix actions: <https://vocab.clearhead.io/actions/v3#> .
@prefix parser: <https://vocab.clearhead.io/parser#> .

# Import base V3 ontology
owl:imports <https://vocab.clearhead.io/actions/v3> .

# Extend properties with parser annotations
actions:hasPriority
    parser:symbol "!" ;
    parser:grammarRule "choice" ;
    parser:validValues (1 2 3 4) ;
    parser:contextLevel "any" ;
    parser:example "!2" .

actions:hasContext
    parser:symbol "+" ;
    parser:grammarRule "pattern" ;
    parser:pattern "@[a-zA-Z0-9_-]+" ;
    parser:example "+@office" .
```

**Benefits:**
- Single source of truth (ontology)
- Can reason over parser rules
- Generate grammar AND documentation
- No drift between semantic model and syntax

---

## Current Status

### ✅ Complete
- Parser project structure
- Test infrastructure
- Example `.actions` files
- Syntax mapping data structure (will migrate to ontology)

### 🚧 In Progress
- **Parser ontology creation** (extends V3 with file format concepts)
- **Grammar generation** via type-sitter

### ⏳ Not Started
- TypeScript type generation from JTD
- Corpus test generation
- Integration with clearhead-cli

---

## Development Workflow

### Phase 1: Create Parser Ontology (Current)

```bash
# 1. Create parser ontology that extends V3
cat > parser-ontology.ttl << 'EOF'
@prefix actions: <https://vocab.clearhead.io/actions/v3#> .
@prefix parser: <https://vocab.clearhead.io/parser#> .

owl:imports <https://vocab.clearhead.io/actions/v3> .

# Add parser-specific concepts
parser:FileFormat a owl:Class .
parser:Line a owl:Class .

# Extend existing properties with syntax annotations
actions:hasPriority parser:symbol "!" .
# ... more mappings
EOF

# 2. Validate ontology
uv run pytest  # In ontology directory
```

### Phase 2: Generate TypeScript Types

```bash
# Generate JTD schemas from V3 + SHACL
cd ../ontology
uv run python scripts/generate_jtd.py

# Generate TypeScript types from JTD
cd ../tree-sitter-actions
jtd-codegen ../ontology/schemas/jtd/actionplan.jtd.json \
  --typescript-out src/types/
```

### Phase 3: Generate Grammar

```bash
# Use type-sitter to generate grammar.js from types + ontology
type-sitter generate \
  --input src/types/ \
  --ontology parser-ontology.ttl \
  --output grammar.js

# grammar.js is now GENERATED!
```

### Phase 4: Build and Test

```bash
# Build parser
npm run build

# Run corpus tests
npm test

# Test against examples
tree-sitter parse examples/*.actions
```

---

## Key Files and Folders

### Source Files
- `parser-ontology.ttl` - **(To create)** Extends V3 with parser concepts
- `src/types/` - **(Generated)** TypeScript types from JTD
- `grammar.js` - **(Generated)** Tree-sitter grammar from types
- `src/node-types.json` - **(Generated)** AST node type definitions

### Test Files
- `test/corpus/` - Parser corpus tests
- `examples/` - Example `.actions` files
- `test/trees/` - Expected S-expression parse trees

### Documentation
- `docs/actions-fileformat-spec.md` - File format specification
- `docs/action_specification.md` - Action semantics
- `README.md` - Project overview
- `CLAUDE.md` - This file

---

## Important Notes

### Grammar is Generated, Not Hand-Written

**Do NOT manually edit `grammar.js`** - it's generated from TypeScript types.

**To change grammar:**
1. Update V3 ontology or SHACL shapes
2. OR update parser ontology annotations
3. Regenerate JTD → TypeScript → Grammar

### Tests Are Hand-Written

**DO manually write corpus tests** in `test/corpus/`:
- Input `.actions` files can be generated from ontology examples
- Expected parse trees must be hand-written (automated generation would propagate bugs)

### Ontology Extension Pattern

**Parser ontology extends V3, doesn't modify it:**
- ✅ `actions:hasPriority parser:symbol "!"`  (annotation)
- ❌ Changing `actions:hasPriority` definition in V3

This ensures:
- V3 remains canonical
- Parser-specific concepts are clearly separated
- Other tools can use V3 without parser concepts

---

## Tooling

### Tree-Sitter CLI

```bash
# Generate parser
tree-sitter generate

# Build parser
tree-sitter build

# Test parser
tree-sitter test

# Parse a file
tree-sitter parse examples/simple.actions

# Show parse tree
tree-sitter parse examples/simple.actions --debug

# Run specific test
tree-sitter test -f "test name"
```

### NPM Scripts

```bash
# Install dependencies
npm install

# Build parser
npm run build

# Run tests
npm test

# Generate bindings
npm run generate
```

---

## Integration Points

### With Ontology
- Fetches V3 ontology from `https://vocab.clearhead.io/actions/v3`
- Falls back to bundled copy if URL unavailable
- Extends V3 with parser ontology

### With CLI
- Parser published as npm package: `@clearhead/tree-sitter-actions`
- CLI imports parser: `import parser from '@clearhead/tree-sitter-actions'`
- CLI uses type-sitter to generate Rust structs from AST nodes

---

## Decision Rationale

### Why Generate Grammar Instead of Hand-Writing?

**Previous approach:** Hand-write grammar.js, manually keep in sync with ontology

**Current approach:** Generate from TypeScript types

**Benefits:**
- Guaranteed consistency with semantic model
- Automatic updates when ontology changes
- Less manual maintenance
- Types drive both parsing and code generation

**Trade-offs:**
- Less fine-grained control over grammar
- Requires understanding of type-sitter
- But: automation and consistency win

### Why TypeScript as Intermediate?

**Why not generate grammar directly from ontology?**

Because tree-sitter and type-sitter work well with TypeScript:
- type-sitter is designed for TypeScript → grammar conversion
- TypeScript type system maps well to AST node types
- Existing tooling and ecosystem

The flow ontology → JTD → TypeScript → grammar leverages existing tools rather than building custom ones.

---

## References

- **[V3 Ontology](../ontology/)** - Semantic foundation
- **[Tree-Sitter Documentation](https://tree-sitter.github.io/tree-sitter/)** - Parser framework
- **[type-sitter](https://github.com/3p3r/type-sitter)** - TypeScript to grammar
- **[JTD Specification](https://jsontypedef.com/)** - JSON Type Definition
- **[Platform README](../README.md)** - Overall vision

---

## Questions?

See main [README.md](../README.md) for overall architecture or [ARCHITECTURE.md](../ARCHITECTURE.md) for detailed technical design.
