# Parser Generation Roadmap

This document outlines the phases of building the complete ontology-driven parser generation pipeline.

## Architecture Decision (2025-11-04)

**Decision:** Use direct syntax mapping approach (parser-ontology.ttl → syntax_mapping.json → grammar)

**Rationale:**
- 3p3r/type-sitter (TypeScript→grammar) not maintained since 2023
- Jakobeha/type-sitter (node-types→Rust) solves CLI integration regardless of approach
- Current approach working now with complete control over grammar
- Can add TypeScript types later from node-types.json if needed

**See:** [ARCHITECTURE.md](./ARCHITECTURE.md) for full details

---

## ✅ Phase 1: Syntax Mapping Generation (COMPLETE)

**Goal:** Generate `syntax_mapping.json` from `parser-ontology.ttl`

**Status:** ✅ Complete (commit 58a2892)

**What Was Built:**
- `parser-ontology.ttl` - Parser extension ontology with syntax annotations
- `scripts/generate-syntax-mapping.js` - JavaScript generator
- `syntax_mapping.json` - Generated intermediate format
- `npm run generate:mapping` - Generation script
- `ONTOLOGY_DRIVEN.md` - Documentation

**Output Quality:**
- 16 properties mapped with symbols, rule types, grammar names
- 5 state-to-bracket mappings
- SHACL-derived constraints (priority 1-4, duration min/max)
- Value mappings (DAILY→D, etc.)

**Validation Method:** Manual inspection of generated JSON

---

## 🚧 Phase 2: Grammar Rule Generation (NEXT)

**Goal:** Generate tree-sitter grammar rules from `syntax_mapping.json`

**Input:** `syntax_mapping.json` (generated)
**Output:** Grammar rule objects → eventually full `grammar.js`

**Tasks:**

### 2.1: Enhance grammar_generator.js to Read Generated Mapping

Current `src/grammar_generator.js` reads `syntax_mapping.js` (JavaScript module).
Need to update it to read `syntax_mapping.json` (generated file).

```javascript
// Before
const { SYNTAX_MAPPING } = require('./syntax_mapping.js');

// After
const syntaxMapping = JSON.parse(fs.readFileSync('syntax_mapping.json'));
```

**Files to modify:**
- `src/grammar_generator.js`

**Test:** Verify it can load and parse the generated JSON

### 2.2: Template Tree-Sitter DSL from Rule Types

For each property in syntax_mapping, generate tree-sitter rule based on `rule_type`:

**Choice Rules** (e.g., priority):
```javascript
// Input: { symbol: "!", rule_type: "choice", values: ["1","2","3","4"] }
// Output:
priority: $ => seq(
  field('icon', '!'),
  field('number', choice('1', '2', '3', '4'))
)
```

**Pattern Rules** (e.g., context):
```javascript
// Input: { symbol: "+", rule_type: "pattern", pattern: "@[a-zA-Z0-9_-]+" }
// Output:
context: $ => seq(
  field('icon', '+'),
  field('value', /@[a-zA-Z0-9_-]+/)
)
```

**Integer Rules** (e.g., duration):
```javascript
// Input: { symbol: "D", rule_type: "integer" }
// Output:
duration: $ => seq(
  field('icon', 'D'),
  field('minutes', /\d+/)
)
```

**Text Rules** (e.g., name, description):
```javascript
// Input: { symbol: "", rule_type: "text" }
// Output:
name: $ => field('text', $.safe_text),
description: $ => seq(field('icon', '$'), field('text', $.safe_text))
```

**UUID Rules**:
```javascript
uuid: $ => seq(
  field('icon', '#'),
  field('value', /[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}/)
)
```

**Date/Time Rules**:
```javascript
do_date_or_time: $ => seq(
  field('icon', '@'),
  field('value', choice(
    $.iso_date_time,
    $.iso_date,
    $.iso_time
  ))
)
```

**Implementation:**
- Create `generateRule(property, mapping)` function
- Map `rule_type` to template functions
- Handle `special_syntax` cases (brackets, depth markers, lists)

**Files to modify:**
- `src/grammar_generator.js` - Add templating logic

**Test:** Generate individual rules and verify valid tree-sitter DSL

### 2.3: Handle Special Syntax Patterns

Three special cases need custom handling:

**1. Bracket Syntax (State)**
```javascript
// Use state_mappings from JSON
state: $ => choice(
  seq('[', ' ', ']'),  // NotStarted
  seq('[', 'x', ']'),  // Completed
  seq('[', '-', ']'),  // InProgress
  seq('[', '=', ']'),  // Blocked
  seq('[', '_', ']')   // Cancelled
)
```

**2. Depth Markers (Hierarchy)**
```javascript
// > >> >>> >>>> >>>>>
depth_marker_1: $ => '>',
depth_marker_2: $ => '>>',
// ...
```

**3. List Syntax (Context)**
```javascript
// +@office,@computer,@phone
context_list: $ => seq(
  '+',
  sep1($.context_value, ',')
)
```

**Implementation:**
- Check `special_syntax` field in mapping
- Call specialized template functions
- Use `state_mappings` object for bracket generation

**Files to modify:**
- `src/grammar_generator.js` - Add special syntax handlers

**Test:** Generate bracket, depth, and list rules

### 2.4: Generate Complete Grammar Module

Combine all generated rules into a complete `grammar.js`:

```javascript
module.exports = grammar({
  name: 'actions',

  rules: {
    action_list: $ => repeat($.root_action),

    root_action: $ => seq(
      $.state,
      $.name,
      // ... generated property rules
    ),

    // GENERATED RULES START
    priority: $ => seq(field('icon', '!'), field('number', choice('1','2','3','4'))),
    context: $ => ...,
    // ... all other rules
    // GENERATED RULES END

    // UTILITY RULES (hand-maintained)
    safe_text: $ => /[^!*+@%>#$\n]+/,
    iso_date: $ => /\d{4}-\d{2}-\d{2}/,
    iso_time: $ => /\d{2}:\d{2}/,
    iso_date_time: $ => /\d{4}-\d{2}-\d{2}T\d{2}:\d{2}/,
  }
});
```

**Strategy Options:**

**Option A: Full Generation**
- Generate entire `grammar.js` from template
- Keep hand-written utility rules in template
- Overwrite file on each generation

**Option B: Marker-Based Injection**
- Keep hand-written structure in `grammar.js`
- Use comments like `// BEGIN GENERATED` and `// END GENERATED`
- Inject generated rules between markers
- Preserve hand-written parts

**Option C: Hybrid (Recommended for MVP)**
- Generate rules to `grammar-generated.js`
- Keep main `grammar.js` hand-written
- Import generated rules: `const rules = require('./grammar-generated.js')`
- Merge in hand-written grammar

**Files to create/modify:**
- `src/grammar_generator.js` - Add full grammar templating
- `grammar.js` (if Option A/B) or `grammar-generated.js` (if Option C)

**Test:** Run `tree-sitter generate` and verify no errors

### 2.5: npm Scripts

Update package.json:

```json
{
  "scripts": {
    "generate:mapping": "node scripts/generate-syntax-mapping.js",
    "generate:grammar": "node src/grammar_generator.js --output grammar-generated.js",
    "generate": "npm run generate:mapping && npm run generate:grammar",
    "build:parser": "tree-sitter generate && tree-sitter build",
    "build": "npm run generate && npm run build:parser"
  }
}
```

**Validation Method:**
- `npm run generate` completes without errors
- Generated grammar compiles with tree-sitter
- No validation of parse correctness yet (Phase 3)

---

## 📋 Phase 3: Parser Integration & Testing (FUTURE)

**Goal:** Integrate generated grammar with tree-sitter and validate against examples

**Tasks:**

### 3.1: Example Test Files

Create test `.actions` files matching the file format spec:

```
test/examples/valid/
  minimal.actions          # [ ] Buy milk
  properties.actions       # With priority, context, dates
  hierarchy.actions        # Root > Child >> Grandchild
  recurrence.actions       # Recurring tasks
  complete.actions         # All features combined

test/examples/invalid/
  bad-priority.actions     # !5 (out of range)
  bad-state.actions        # [z] (invalid symbol)
  bad-depth.actions        # >>>>>> (too deep)
```

Each example should have:
- `.actions` file (input)
- `.expected.json` (expected AST structure)
- `.expected.md` (human-readable expected output)

### 3.2: Parser Test Suite

```javascript
// test/parser-generation.test.js
const Parser = require('tree-sitter');
const Actions = require('..');

describe('Generated Parser', () => {
  it('parses minimal action', () => {
    const source = '[ ] Buy milk';
    const tree = parser.parse(source);
    expect(tree.rootNode.type).toBe('action_list');
    // ... assertions
  });

  it('parses priority', () => {
    const source = '[ ] Important task !1';
    // ... verify priority node exists with value '1'
  });

  // ... test each property type
});
```

### 3.3: AST Validation

Compare generated parse trees to expected structures:

```javascript
function validateAST(actual, expected) {
  expect(actual.type).toBe(expected.type);
  expect(actual.childCount).toBe(expected.children.length);
  // ... deep comparison
}
```

### 3.4: Round-Trip Testing

```javascript
function roundTrip(input) {
  const tree = parser.parse(input);
  const reconstructed = astToActions(tree);
  expect(reconstructed).toBe(input);
}
```

**Validation Method:**
- All valid examples parse without errors
- AST structure matches expectations
- Invalid examples produce appropriate errors
- Round-trip preserves input

---

## 🔬 Phase 4: SHACL Integration (FUTURE)

**Goal:** Fetch SHACL shapes from web and extract constraints automatically

Currently, constraints (priority 1-4, duration min/max) are hardcoded in generator.

**Tasks:**

### 4.1: Fetch shapes.ttl from Web

```javascript
const shapesUrl = 'https://clearhead.us/vocab/actions/v3/shapes.ttl';
const shapesContent = await fetchUrl(shapesUrl);
```

### 4.2: Parse SHACL Shapes

Options:
- Use `n3.js` library for robust Turtle parsing
- Or extend current regex-based parser

```javascript
// Extract constraints for a property
function extractSHACLConstraints(propertyUri, shapesGraph) {
  // Find sh:property with sh:path = propertyUri
  // Extract sh:minInclusive, sh:maxInclusive
  // Extract sh:pattern
  // Extract sh:in (enums)
  // Return constraints object
}
```

### 4.3: Merge with Parser Annotations

```javascript
const parserAnnotations = loadParserOntology('parser-ontology.ttl');
const shaclConstraints = parseSHACL(shapesContent);
const merged = mergeAnnotationsWithConstraints(parserAnnotations, shaclConstraints);
```

### 4.4: Generate Values from Constraints

```javascript
// priority: sh:minInclusive 1, sh:maxInclusive 4
// → values: ['1', '2', '3', '4']

// recurrenceFrequency: sh:in ("DAILY" "WEEKLY" "MONTHLY" "YEARLY")
// → values: ['DAILY', 'WEEKLY', 'MONTHLY', 'YEARLY']
```

**Validation Method:**
- No more hardcoded constraints in generator
- Values automatically sync with SHACL shapes
- Changes to V3 shapes propagate without code changes

---

## 🚀 Phase 5: Advanced Features (FUTURE)

### 5.1: TypeScript Type Generation

Generate TypeScript interfaces from syntax_mapping.json:

```typescript
interface ActionPlan {
  name: string;
  state: 'NotStarted' | 'Completed' | 'InProgress' | 'Blocked' | 'Cancelled';
  priority?: 1 | 2 | 3 | 4;
  context?: string[];
  // ... all properties
}
```

Use with `type-sitter` for fully typed AST nodes.

### 5.2: Multi-Format Support

Generate parsers for other formats from same ontology:

- YAML parser
- TOML parser
- JSON parser (for API)

Each format gets its own syntax annotations in parser ontology.

### 5.3: LSP Server

Generate Language Server Protocol server from ontology:

- Autocomplete property symbols
- Validate constraints in real-time
- Hover documentation from formatHint
- Code actions (add missing properties, fix invalid values)

### 5.4: Documentation Generation

Auto-generate documentation from ontology:

- Property reference (symbol, type, constraints)
- Examples from parser ontology
- Syntax diagrams
- Migration guides between versions

---

## Development Workflow

### When Ontology Changes

1. V3 ontology publishes new version
2. Update `parser-ontology.ttl` with syntax annotations for new properties
3. Run `npm run generate`
4. Run `npm test` to validate
5. Commit generated files
6. Publish new parser version

### When Syntax Changes

1. Update `parser-ontology.ttl` (change symbols, rule types, etc.)
2. Run `npm run generate`
3. Review changes in `syntax_mapping.json`
4. Run `npm run build:parser`
5. Run tests
6. Update examples if needed
7. Commit

### When Adding Tests

1. Create `.actions` file in `test/examples/`
2. Run parser and capture AST
3. Create `.expected.json` with expected structure
4. Add test case in `test/parser-generation.test.js`
5. Run `npm test`
6. Commit test files

---

## Success Criteria

### Phase 2 Complete When:
- [ ] `npm run generate:grammar` produces valid tree-sitter DSL
- [ ] Generated grammar compiles with `tree-sitter generate`
- [ ] All property types have rule templates
- [ ] Special syntax (brackets, depth, lists) handled
- [ ] Can build parser: `npm run build:parser`

### Phase 3 Complete When:
- [ ] Test suite with 10+ valid examples
- [ ] Test suite with 5+ invalid examples
- [ ] All valid examples parse correctly
- [ ] AST structure matches expectations
- [ ] Parser handles all property types from spec
- [ ] Invalid inputs produce appropriate errors

### Phase 4 Complete When:
- [ ] Fetches shapes.ttl from web
- [ ] Extracts all SHACL constraints
- [ ] No hardcoded constraints in generator
- [ ] Constraints auto-sync with V3 changes

### Phase 5 Complete When:
- [ ] TypeScript types generated and working
- [ ] LSP server provides autocompletion
- [ ] Documentation auto-generated
- [ ] Multi-format support (at least 2 formats)

---

## Risk Mitigation

### Risk: Grammar Too Complex

**Mitigation:** Start with subset of properties, expand incrementally

### Risk: Tree-Sitter Limitations

**Mitigation:** Prototype tricky patterns early, have fallback hand-written rules

### Risk: SHACL Parsing Difficult

**Mitigation:** Use established library (n3.js), not regex

### Risk: Breaking Changes in V3

**Mitigation:** Version parser ontology, support multiple V3 versions

---

## Notes for Future Developers

### Why JavaScript, Not Python?

Parser repo must be independent. JavaScript is already required for tree-sitter. Adding Python would create unnecessary coupling and dependencies.

### Why Not Fetch Ontology from Web Yet?

Phase 1 focused on local generation to prove the concept. Phase 4 adds web fetching once we know the pipeline works end-to-end.

### Why Hybrid Grammar Generation?

Full generation is risky - one bug breaks everything. Hybrid approach lets us generate rules incrementally while keeping hand-written scaffolding.

### Why SHACL Integration Last?

Get the pipeline working with hardcoded constraints first. Proves the concept before adding complexity of fetching/parsing SHACL.

---

## Timeline Estimate

Assuming 1-2 days per phase with testing:

- **Phase 2:** 3-5 days (grammar generation is complex)
- **Phase 3:** 2-3 days (test suite creation)
- **Phase 4:** 2 days (SHACL fetching/parsing)
- **Phase 5:** 5-7 days (advanced features are optional)

**Minimum Viable:** Phases 1-3 = ~7-10 days
**Full Featured:** All phases = ~14-19 days

Current Progress: Phase 1 ✅ Complete (~2 days)

---

## References

- [File Format Spec](./docs/actions-fileformat-spec.md)
- [Ontology-Driven Docs](./ONTOLOGY_DRIVEN.md)
- [Tree-Sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Actions Vocabulary V3](https://clearhead.us/vocab/actions/v3)
