# Tree-Sitter Actions Parser

**Purpose:** Parse `.actions` plaintext files into Abstract Syntax Trees (AST)

**Status:** Phase 2 Complete - Grammar generation working, ready for testing

---

## Quick Start

```bash
# Generate parser from ontology
npm run generate && npm run build:parser

# Test parser
tree-sitter parse examples/with_priority.actions

# See full architecture
cat ARCHITECTURE.md
```

---

## Architecture Overview

This parser uses **ontology-driven generation** with a direct syntax mapping approach:

```
parser-ontology.ttl (syntax annotations)
    ↓ [JavaScript parser]
syntax_mapping.json (generated intermediate)
    ↓ [JavaScript template generator]
grammar-generated.js (generated rules)
    ↓ [grammar.js merges with hand-maintained]
Complete grammar
    ↓ [tree-sitter generate]
Parser (C code + .so binary)
```

### Key Principles

1. **Ontology as source of truth** - `parser-ontology.ttl` defines syntax
2. **Hybrid grammar** - Generated rules + hand-maintained structure
3. **Repository independence** - No Python dependencies, self-contained
4. **Standard integration** - CLI uses `node-types.json` → Rust via type-sitter

---

## File Structure

### Source Files (Hand-Maintained)

```
parser-ontology.ttl          # Syntax annotations (EDIT THIS)
grammar.js                   # Structure + utilities (EDIT THIS)
src/grammar_generator.js     # Generation logic (EDIT THIS)
scripts/generate-syntax-mapping.js  # Ontology parser (EDIT THIS)
examples/*.actions           # Test files (EDIT THIS)
```

### Generated Files (DO NOT EDIT)

```
syntax_mapping.json          # Generated from parser-ontology.ttl
grammar-generated.js         # Generated grammar rules
src/parser.c                 # tree-sitter generates
src/node-types.json          # tree-sitter generates
actions.so                   # Compiled parser binary
```

---

## Development Workflow

### Adding a New Property

1. **Update parser-ontology.ttl:**
   ```turtle
   actions:hasUrgency
       parser:symbol "^" ;
       parser:grammarRuleName "urgency" ;
       parser:ruleType "choice" ;
       parser:formatHint "1=low, 5=critical" ;
       parser:example "^3" .
   ```

2. **Regenerate:**
   ```bash
   npm run generate && npm run build:parser
   ```

3. **Test:**
   ```bash
   tree-sitter parse examples/with_urgency.actions
   ```

That's it! The pipeline handles the rest.

### Modifying Existing Syntax

1. **Update parser-ontology.ttl** (change symbol, rule type, etc.)
2. **Run `npm run generate && npm run build:parser`**
3. **Update test examples** if syntax changed
4. **Run tests:** `npm test`

### Debugging Generation Issues

If generation fails:

1. **Check syntax_mapping.json** - Was it generated correctly?
2. **Check grammar-generated.js** - Do the rules look right?
3. **Check grammar.js** - Are generated rules imported correctly?
4. **Run `tree-sitter generate --debug`** for detailed errors

---

## Integration with CLI

The CLI gets Rust types via standard tree-sitter tooling:

```
tree-sitter-actions/src/node-types.json (auto-generated)
    ↓ [Jakobeha/type-sitter]
clearhead-cli/src/generated/actions.rs (type-safe Rust)
```

**No custom integration needed** - uses tree-sitter's standard node-types format.

---

## Testing

### Corpus Tests (Phase 3 - TODO)

```
test/corpus/
  basics.txt           # Simple actions
  properties.txt       # All property types
  hierarchy.txt        # Nested children
  edge_cases.txt       # Special syntax
```

### Example Files (Current)

```
examples/
  minimal.actions           # [ ] test
  with_priority.actions     # [x] task !1
  with_children.actions     # Parent > child >> grandchild
```

### Running Tests

```bash
# Parse examples
tree-sitter parse examples/*.actions

# Run test suite (Phase 3)
npm test
```

---

## Common Tasks

### Generate mapping only

```bash
npm run generate:mapping
# Output: syntax_mapping.json
```

### Generate grammar only

```bash
npm run generate:grammar
# Output: grammar-generated.js
```

### Full pipeline

```bash
npm run generate
# Runs both mapping + grammar generation
```

### Build parser

```bash
npm run build:parser
# Compiles C parser and binary
```

### Parse a file

```bash
tree-sitter parse path/to/file.actions
```

### Debug parsing

```bash
tree-sitter parse --debug path/to/file.actions
```

---

## Grammar Rule Types

The generator supports these rule types:

### CHOICE - Fixed value sets

```turtle
parser:ruleType "choice" ;
parser:values ("1" "2" "3" "4") .
```

Generates:
```javascript
choice('1', '2', '3', '4')
```

### PATTERN - Regex patterns

```turtle
parser:ruleType "pattern" ;
parser:pattern "@[a-zA-Z0-9_-]+" .
```

Generates:
```javascript
/@[a-zA-Z0-9_-]+/
```

### INTEGER - Numeric values

```turtle
parser:ruleType "integer" .
```

Generates:
```javascript
/\d+/
```

### UUID_V7 - UUIDs

```turtle
parser:ruleType "uuid_v7" .
```

Generates:
```javascript
/[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}/
```

### DATE_TIME - ISO 8601

```turtle
parser:ruleType "date_time" .
```

Generates:
```javascript
choice($.iso_date_time, $.iso_date, $.iso_time)
```

### TEXT - Free text

```turtle
parser:ruleType "text" .
```

Generates:
```javascript
$.safe_text
```

### Special Syntax

- **BracketSyntax** - State: `[x]`, `[-]`, etc.
- **DepthMarker** - Hierarchy: `>`, `>>`, etc. (hand-maintained)
- **ListSyntax** - Lists: `+@office,@work`

---

## Troubleshooting

### Parser won't compile

**Symptom:** `tree-sitter generate` fails

**Check:**
1. Is `grammar.js` valid JavaScript?
2. Run `node grammar.js` to test
3. Check `grammar-generated.js` for syntax errors
4. Look for unbalanced parentheses, missing commas

### Generated rules are wrong

**Symptom:** Rules don't match expected grammar

**Check:**
1. Inspect `syntax_mapping.json` - is data correct?
2. Check rule type in parser-ontology.ttl
3. Verify generator handles that rule type
4. Check for value mappings (e.g., DAILY→D)

### Parser doesn't recognize syntax

**Symptom:** Parse errors on valid `.actions` files

**Check:**
1. Does grammar.js have the rule?
2. Is rule imported from grammar-generated.js?
3. Check conflicts array (may need to add)
4. Verify file format matches spec exactly

---

## Documentation

**Core docs:**
- [ARCHITECTURE.md](./ARCHITECTURE.md) - Complete architecture guide
- [ROADMAP.md](./ROADMAP.md) - Development phases and timeline
- [PROGRESS.md](./PROGRESS.md) - Current status and completed work
- [PHASE2_COMPLETE.md](./PHASE2_COMPLETE.md) - Phase 2 technical details

**Specifications:**
- [docs/action_specification.md](./docs/action_specification.md) - File format spec
- [docs/actions-fileformat-spec.md](./docs/actions-fileformat-spec.md) - Detailed syntax

**External:**
- [Tree-Sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Jakobeha/type-sitter](https://github.com/Jakobeha/type-sitter) - Rust type generation

---

## Current Status

### ✅ Phase 1 Complete - Syntax Mapping Generation
- parser-ontology.ttl with 16 annotated properties
- JavaScript-based ontology parser
- syntax_mapping.json generation working
- npm scripts configured

### ✅ Phase 2 Complete - Grammar Rule Generation
- grammar_generator.js templating all rule types
- Hybrid grammar strategy (generated + hand-maintained)
- Parser compiles successfully
- Parses real .actions files correctly

### 🚧 Phase 3 Next - Parser Integration & Testing
- Create corpus test suite
- Test all property types
- Validate edge cases
- Performance testing

### 📋 Phase 4 Planned - SHACL Integration
- Fetch constraints from V3 SHACL shapes
- Auto-update value ranges
- Remove hardcoded constraints

### 📋 Phase 5 Future - Advanced Features
- Optional: TypeScript types from node-types.json
- Optional: Multi-format support (YAML, JSON)
- Security: Replace eval() with safer alternative

---

## Contributing

When contributing:

1. **Don't edit generated files** - Edit source (parser-ontology.ttl)
2. **Always regenerate** - Run `npm run generate` after changes
3. **Test thoroughly** - Parse examples and run tests
4. **Document rationale** - Why this syntax change?
5. **Update tests** - Add examples for new features

---

## Questions?

See [ARCHITECTURE.md](./ARCHITECTURE.md) for detailed technical architecture or [ROADMAP.md](./ROADMAP.md) for project planning.

---

**Version:** 1.0 (Phase 2 Complete)
**Status:** Production-ready for testing
**Last Updated:** 2025-11-04
