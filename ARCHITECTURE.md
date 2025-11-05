# Tree-Sitter Actions Parser Architecture

**Status:** Production-Ready (Phase 2 Complete)
**Last Updated:** 2025-11-04
**Version:** 1.0

---

## TL;DR

We generate a tree-sitter parser from ontology annotations using a **direct syntax mapping approach**. The parser repo is independent, generates clean grammar, and integrates with the CLI via tree-sitter's standard node-types.json format.

**Pipeline:**
```
parser-ontology.ttl → syntax_mapping.json → grammar.js → parser → Rust types
```

---

## Table of Contents

1. [Core Principles](#core-principles)
2. [Architecture Overview](#architecture-overview)
3. [The Generation Pipeline](#the-generation-pipeline)
4. [CLI Integration](#cli-integration)
5. [What's Generated vs Hand-Written](#whats-generated-vs-hand-written)
6. [Architecture Decisions](#architecture-decisions)
7. [Future Enhancements](#future-enhancements)

---

## Core Principles

### 1. Ontology-Driven Generation

**Single source of truth:** `parser-ontology.ttl` with syntax annotations

```turtle
@prefix actions: <https://clearhead.us/vocab/actions/v3#> .
@prefix parser: <https://vocab.clearhead.io/parser#> .

actions:hasPriority
    parser:symbol "!" ;
    parser:grammarRuleName "priority" ;
    parser:ruleType "choice" ;
    parser:formatHint "1=urgent+important, 4=neither" ;
    parser:example "!2" .
```

**Benefits:**
- Changes to ontology automatically propagate
- Syntax and semantics stay aligned
- Can reason over parser rules
- Generate grammar AND documentation

### 2. Parser Repository Independence

**Self-contained:** No dependency on ontology Python code

- Ontology file is local and hand-maintained
- JavaScript-based generators (no Python dependency)
- Can be cloned and built standalone
- Fast iteration cycle

### 3. Hybrid Grammar Strategy

**Generated + Hand-Maintained:**

- Generated rules: Property-specific (priority, context, etc.)
- Hand-maintained: Structure (action_list, root_action) and utilities (regex patterns)
- Clean separation enables customization where needed

### 4. Standards Where It Matters

**Use tree-sitter's standard outputs:**

- `node-types.json` - Standard AST node definitions
- CLI uses standard tools (type-sitter) to generate Rust
- No custom intermediate formats for cross-language integration

---

## Architecture Overview

### The Three Repositories

```
┌─────────────────────────────────────┐
│ ontology/                           │
│ - V3 domain ontology (BFO/CCO)     │
│ - SHACL validation shapes          │
│ - Publishes to web                 │
└──────────────┬──────────────────────┘
               │ (semantic concepts)
               ↓
┌─────────────────────────────────────┐
│ tree-sitter-actions/                │
│ - parser-ontology.ttl (extends V3)│
│ - Syntax mapping generator         │
│ - Grammar generator                │
│ - Tree-sitter parser               │
│ - node-types.json (output)         │
└──────────────┬──────────────────────┘
               │ (AST types)
               ↓
┌─────────────────────────────────────┐
│ clearhead-cli/                      │
│ - Rust implementation              │
│ - Uses type-sitter for Rust types │
│ - Business logic                   │
└─────────────────────────────────────┘
```

**Key insight:** Parser repo extends V3 concepts with file format details, but remains independent.

---

## The Generation Pipeline

### Full Pipeline

```
┌────────────────────────────────────────┐
│ 1. parser-ontology.ttl                 │
│                                        │
│ Hand-maintained ontology file with:   │
│ - V3 property references              │
│ - Syntax symbols (!,+,@,etc.)         │
│ - Grammar rule types                  │
│ - Examples and hints                  │
└──────────────┬─────────────────────────┘
               ↓
    [scripts/generate-syntax-mapping.js]
               ↓
┌────────────────────────────────────────┐
│ 2. syntax_mapping.json                 │
│                                        │
│ GENERATED intermediate format:        │
│ {                                      │
│   "hasPriority": {                    │
│     "symbol": "!",                    │
│     "rule_type": "choice",            │
│     "values": ["1","2","3","4"]       │
│   }                                    │
│ }                                      │
└──────────────┬─────────────────────────┘
               ↓
    [src/grammar_generator.js]
               ↓
┌────────────────────────────────────────┐
│ 3. grammar-generated.js                │
│                                        │
│ GENERATED tree-sitter rules:          │
│ module.exports = {                     │
│   priority: ($) => seq(               │
│     field('icon', '!'),               │
│     field('number', choice(           │
│       '1','2','3','4'                 │
│     ))                                 │
│   )                                    │
│ }                                      │
└──────────────┬─────────────────────────┘
               ↓
    [grammar.js imports and merges]
               ↓
┌────────────────────────────────────────┐
│ 4. grammar.js (complete)               │
│                                        │
│ Hand-maintained structure +            │
│ Generated rules merged via require()   │
│                                        │
│ Includes:                              │
│ - action_list, root_action, etc.      │
│ - Utility rules (safe_text, iso_date) │
│ - Generated property rules             │
└──────────────┬─────────────────────────┘
               ↓
    [tree-sitter generate]
               ↓
┌────────────────────────────────────────┐
│ 5. src/parser.c + node-types.json      │
│                                        │
│ tree-sitter generates:                 │
│ - C parser code (169KB)               │
│ - node-types.json (AST metadata)      │
│ - actions.so (compiled binary)        │
└──────────────┬─────────────────────────┘
               ↓
    [tree-sitter build]
               ↓
┌────────────────────────────────────────┐
│ 6. Working Parser                      │
│                                        │
│ Can parse .actions files to AST        │
└────────────────────────────────────────┘
```

### Commands

```bash
# Generate everything
npm run generate

# Step by step:
npm run generate:mapping  # parser-ontology.ttl → syntax_mapping.json
npm run generate:grammar  # syntax_mapping.json → grammar-generated.js
npm run build:parser      # grammar.js → parser.c → actions.so

# Test
tree-sitter parse examples/with_priority.actions
```

---

## CLI Integration

### How CLI Gets Rust Types

```
tree-sitter-actions repo:
  grammar.js → [tree-sitter generate] → node-types.json
                                            ↓
                              [Jakobeha/type-sitter]
                                            ↓
clearhead-cli repo:
  src/generated/actions.rs (type-safe Rust structs)
```

### Key Tool: Jakobeha/type-sitter

**What it is:** Generates type-safe Rust wrappers from tree-sitter's `node-types.json`

**Why it's perfect:**
- ✅ Works with ANY tree-sitter parser
- ✅ Actively maintained (alpha but updating)
- ✅ Generates 30k+ lines of type-safe Rust
- ✅ Standard tool in tree-sitter ecosystem

**Usage:**
```bash
# In clearhead-cli repo
type-sitter-cli generate \
  ../tree-sitter-actions/src/node-types.json \
  --output src/generated/
```

**Result:**
```rust
pub struct RootAction<'tree> { ... }
pub struct Priority<'tree> { ... }
pub struct State<'tree> { ... }
// Full type safety for AST traversal
```

**Important:** This is NOT `3p3r/type-sitter` (TypeScript→grammar). This is `Jakobeha/type-sitter` (node-types→Rust).

---

## What's Generated vs Hand-Written

| Artifact | Generated | Hand-Written | Rationale |
|----------|-----------|--------------|-----------|
| **parser-ontology.ttl** | ❌ | ✅ | Human decisions on syntax mapping |
| **syntax_mapping.json** | ✅ | ❌ | Mechanical extraction from ontology |
| **grammar-generated.js** | ✅ | ❌ | Templated from syntax mapping |
| **grammar.js structure** | ❌ | ✅ | Parser architecture needs judgment |
| **grammar.js utilities** | ❌ | ✅ | Regex patterns, depth markers |
| **src/parser.c** | ✅ | ❌ | tree-sitter generates C code |
| **node-types.json** | ✅ | ❌ | tree-sitter generates metadata |
| **Rust structs (CLI)** | ✅ | ❌ | type-sitter generates from node-types |
| **Rust impl blocks (CLI)** | ❌ | ✅ | Business logic is hand-written |
| **Tests** | ❌ | ✅ | Test cases require human judgment |

**Golden Rule:** Generate **structure and types**, hand-write **behavior and business logic**.

---

## Architecture Decisions

### Decision 1: Syntax Mapping Over TypeScript→Grammar

**Chosen:** Direct `ontology → syntax_mapping → grammar` pipeline

**Rejected:** `ontology → JTD → TypeScript → type-sitter → grammar` pipeline

**Rationale:**

1. **3p3r/type-sitter unmaintained** - Last updated 2023 (2 years ago)
2. **Unknown capability** - Unclear if it supports our complex grammar:
   - Bracket syntax: `[x]`, `[-]`, etc.
   - Depth markers: `>`, `>>`, `>>>`, etc.
   - Regex patterns and value mappings
3. **CLI doesn't need it** - Jakobeha/type-sitter solves Rust generation differently
4. **Working now vs risky later** - Current approach proven, TypeScript approach uncertain
5. **Complete control** - Can handle ANY tree-sitter construct

**Trade-off:** No TypeScript types for AST manipulation in JS (but CLI gets Rust types)

**Future:** Can add TypeScript types from `node-types.json` if JS tooling needs it

### Decision 2: Hybrid Grammar (Generated + Hand-Maintained)

**Chosen:** Import generated rules into hand-maintained structure

**Alternative rejected:** Fully generated grammar

**Rationale:**

1. **Utilities need customization** - Regex patterns for `safe_text`, `iso_date` hard to generate
2. **Structure needs judgment** - `action_list`, conflict resolution require human decisions
3. **Clean separation** - Easy to see what's generated vs maintained
4. **Flexibility** - Can override or extend generated rules

**Implementation:**
```javascript
// grammar.js
const generatedRules = require('./grammar-generated');

const handMaintainedRules = {
  action_list: $ => repeat($.root_action),
  safe_text: $ => /[^$!*+@%>#\(]+/,
  // ...
};

// Merge
for (const [key, valueString] of Object.entries(generatedRules)) {
  handMaintainedRules[key] = eval(valueString);  // TODO: replace eval
}

module.exports = grammar({
  name: "actions",
  conflicts: $ => [[$.child_action]],
  rules: handMaintainedRules
});
```

### Decision 3: Parser Repo Independence

**Chosen:** Self-contained JavaScript generation in parser repo

**Alternative rejected:** Depend on ontology repo Python generators

**Rationale:**

1. **Fast iteration** - Change ontology, regenerate, test (seconds not minutes)
2. **No cross-repo dependencies** - Parser builds without ontology repo
3. **Language consistency** - tree-sitter ecosystem is JavaScript
4. **Clear ownership** - Parser concerns stay in parser repo

**Trade-off:** Some duplication (both repos have ontology processing logic)

### Decision 4: syntax_mapping.json Intermediate Format

**Chosen:** Generate explicit JSON intermediate format

**Alternative rejected:** Direct ontology → grammar (no intermediate)

**Rationale:**

1. **Debuggability** - Can inspect mapping before grammar generation
2. **Separation of concerns** - Ontology parsing vs grammar templating
3. **Extensibility** - Other tools can consume syntax_mapping.json
4. **Clarity** - Makes generation pipeline explicit

**Trade-off:** Extra file to maintain (but auto-generated)

---

## Future Enhancements

### Phase 4: SHACL Constraint Fetching

**Current:** Priority values 1-4 hardcoded in generator

**Future:** Fetch from SHACL shapes

```javascript
// Fetch constraints from web
const shapes = await fetch('https://clearhead.us/vocab/actions/v3/shapes.ttl');
const constraints = parseSHACL(shapes);

// Extract min/max for priority
const priorityValues = range(
  constraints.hasPriority.minInclusive,  // 1
  constraints.hasPriority.maxInclusive   // 4
);
```

**Benefit:** Changes to V3 SHACL automatically update parser

### Optional: TypeScript Types from node-types.json

**If TypeScript needed for JS tooling:**

```bash
# Generate TypeScript interfaces
dts-tree-sitter src/node-types.json --output src/types/
```

**Use case:** Type-safe AST manipulation in JavaScript

**Note:** CLI doesn't need this (uses Rust types)

### Optional: JTD Schema Generation

**For multi-language code generation:**

```
parser-ontology.ttl
    ↓
JTD schemas
    ↓
Python/Go/Java types
```

**Use case:** If we need parsers in other languages

**Note:** Not needed for current CLI (Rust types from node-types.json)

### Security: Replace eval()

**Current:** `eval(valueString)` to convert string to function

**Issue:** Security risk, harder to debug

**Solution:**
```javascript
// Option 1: new Function()
handMaintainedRules[key] = new Function('$', 'return ' + valueString.replace('($) =>', ''))($);

// Option 2: Generate actual .js file
const content = `module.exports = {\n${
  Object.entries(generatedRules)
    .map(([k, v]) => `  ${k}: ${v}`)
    .join(',\n')
}\n};`;
fs.writeFileSync('grammar-generated.js', content);
// Then require() normally (no eval)
```

---

## Related Documentation

**In this repo:**
- [ROADMAP.md](./ROADMAP.md) - Development phases
- [PROGRESS.md](./PROGRESS.md) - Current status
- [PHASE2_COMPLETE.md](./PHASE2_COMPLETE.md) - Phase 2 completion details
- [docs/action_specification.md](./docs/action_specification.md) - File format spec

**In platform repo:**
- [../ARCHITECTURE.md](../ARCHITECTURE.md) - Overall platform architecture
- [../ontology/](../ontology/) - V3 domain ontology

**External:**
- [Tree-Sitter Docs](https://tree-sitter.github.io/tree-sitter/)
- [Jakobeha/type-sitter](https://github.com/Jakobeha/type-sitter)

---

## Conclusion

This architecture provides:

1. **Ontology-driven** - Single source of truth with propagating changes
2. **Independence** - Parser repo is self-contained
3. **Working now** - Parser compiles and parses real files
4. **CLI integration** - Standard tool generates Rust types
5. **Maintainable** - Clear separation of generated vs hand-written
6. **Extensible** - Can add features without breaking existing structure

**Status:** Production-ready for Phase 3 (testing)

---

**Version:** 1.0
**Last Updated:** 2025-11-04
**Authors:** Clearhead Platform Team
