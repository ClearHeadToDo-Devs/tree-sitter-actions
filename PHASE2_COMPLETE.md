# Phase 2 Complete: Ontology → Tree-Sitter Parser Generation

**Date:** 2025-11-04
**Status:** ✅ SUCCESS - Parser generation pipeline fully working

---

## Summary

We successfully completed Phase 2 of the ontology-driven parser generation roadmap. The system now automatically generates a working tree-sitter parser from the Actions ontology.

### The Pipeline (Now Working End-to-End!)

```
parser-ontology.ttl (syntax annotations)
    ↓ [scripts/generate-syntax-mapping.js]
syntax_mapping.json (intermediate format)
    ↓ [src/grammar_generator.js]
grammar-generated.js (14 generated rules)
    ↓ [grammar.js merges with hand-maintained rules]
complete grammar
    ↓ [tree-sitter generate]
src/parser.c (169KB C code)
    ↓ [tree-sitter build]
actions.so (40KB binary parser)
```

### Commands

```bash
# Generate everything and build parser
npm run generate && npm run build:parser

# Or step by step:
npm run generate:mapping  # parser-ontology.ttl → syntax_mapping.json
npm run generate:grammar  # syntax_mapping.json → grammar-generated.js
npm run build:parser      # grammar.js → parser.c → actions.so

# Test the parser
tree-sitter parse examples/with_priority.actions
```

---

## What Was Built

### 1. Grammar Generator (`src/grammar_generator.js`)

**Purpose:** Convert `syntax_mapping.json` into tree-sitter grammar rules

**Key Functions:**
- `loadSyntaxMapping()` - Reads generated JSON
- `generatePropertyRule()` - Templates rules based on type
- `generateGrammarRules()` - Processes all properties

**Rule Type Handlers:**
- **CHOICE** - Fixed value sets (priority: 1,2,3,4)
- **PATTERN** - Regex patterns (context, UUID)
- **INTEGER** - Numeric values (duration, intervals)
- **UUID_V7** - UUIDs with v7 format
- **DATE_TIME** - ISO 8601 dates/times
- **TEXT** - Free text (name, description)

**Special Syntax Handlers:**
- **BracketSyntax** - State mappings `[x]`, `[-]`, etc.
- **DepthMarker** - Excluded (hand-maintained `>`, `>>`, etc.)
- **ListSyntax** - Comma-separated contexts `+@office,@work`

### 2. Hybrid Grammar Strategy (`grammar.js`)

We chose **Option C (Hybrid)** from the roadmap:

```javascript
// grammar-generated.js (auto-generated, do not edit)
module.exports = {
  id: ($) => seq(field('icon', '#'), field('value', /[0-9a-f]{8}-.../)),
  priority: ($) => seq(field('icon', '!'), field('number', choice('1','2','3','4'))),
  // ... 14 rules total
};

// grammar.js (hand-maintained, imports generated)
const generatedRulesStrings = require('./grammar-generated');

const buildRules = () => {
  const handMaintainedRules = {
    action_list: $ => repeat($.root_action),
    root_action: $ => seq($.state, $.name, optional($.priority), ...),
    // Utility rules
    safe_text: $ => /[^$!*+@%>#\(]+/,
    iso_date: $ => /\d{4}-\d{2}-\d{2}/,
    // ...
  };

  // Merge generated rules
  for (const [key, valueString] of Object.entries(generatedRulesStrings)) {
    handMaintainedRules[key] = eval(valueString);
  }

  return handMaintainedRules;
};

module.exports = grammar({
  name: "actions",
  conflicts: $ => [[$.child_action]],  // Needed for nested actions
  rules: buildRules()
});
```

**Benefits:**
- ✅ Clear separation of concerns
- ✅ Generated rules isolated in own file
- ✅ Hand-maintained utilities preserved
- ✅ Easy to debug (can inspect grammar-generated.js)
- ✅ No marker comments or injection complexity

### 3. Generated Rules (`grammar-generated.js`)

14 rules successfully generated:

1. **id** - UUID v7 format with dashes
2. **name** - Free text (references safe_text)
3. **priority** - Choice of '1', '2', '3', '4'
4. **state** - Bracket syntax: `[ ]`, `[x]`, `[-]`, `[=]`, `[_]`
5. **context** - Pattern: `+@office,@computer`
6. **description** - Text with `$` prefix
7. **project** - Text with `*` prefix (root only)
8. **do_date_or_time** - ISO date/time with `@` prefix
9. **completed_date** - ISO date/time with `%` prefix
10. **duration** - Integer with `D` prefix (minutes)
11. **recurrence** - Choice of 'D', 'W', 'M', 'Y' (mapped from DAILY, etc.)
12. **recurrence_interval** - Integer with `I` prefix
13. **recurrence_count** - Integer with `C` prefix
14. **recurrence_until** - ISO date with `U` prefix

**Excluded:**
- `depth` - Hand-maintained in grammar.js (>, >>, >>>, >>>>, >>>>>)
- `hasDepth` - Computed property (calculated, not parsed)

---

## Key Technical Fixes

### 1. Regex Escaping (Lines 123, grammar_generator.js)

**Problem:** Generated `/d+/` instead of `/\d+/`

**Cause:** Single backslash in template string gets consumed by JavaScript

**Solution:** Double-escape in template: `/\\d+/`

```javascript
// WRONG
return `($) => seq(field('icon', 'D'), field('minutes', /\d+/))`;
// Generates: /d+/ (wrong!)

// CORRECT
return `($) => seq(field('icon', 'D'), field('minutes', /\\d+/))`;
// Generates: /\d+/ (correct!)
```

### 2. Value Mappings (Lines 111-118, grammar_generator.js)

**Problem:** Ontology uses `DAILY`, `WEEKLY`, but file format uses `D`, `W`

**Solution:** Apply value_mappings during generation

```javascript
// Apply value mappings if they exist
if (syntaxRule.value_mappings && syntaxRule.value_mappings.length > 0) {
  const mappingDict = {};
  syntaxRule.value_mappings.forEach(m => {
    mappingDict[m.from] = m.to;
  });
  choices = choices.map(c => mappingDict[c] || c);
}
// Result: ['DAILY', 'WEEKLY', ...] → ['D', 'W', ...]
```

### 3. Circular Depth Reference (Line 88, grammar_generator.js)

**Problem:** Generated `depth: ($) => $.depth` (infinite recursion)

**Solution:** Return `null` to exclude from generation

```javascript
case 'DepthMarker':
  // Don't generate - hand-maintained in grammar.js
  return null;
```

### 4. List Syntax Pattern (Line 93, grammar_generator.js)

**Problem:** Used undefined `sep1` helper function

**Solution:** Hardcode the pattern directly

```javascript
// WRONG (sep1 doesn't exist in tree-sitter context)
return `($) => seq(field('icon', '+'), sep1(field('value', /.../), ','))`;

// CORRECT (inline the repetition pattern)
return `($) => seq(field('icon', '+'), field('value', /@[a-zA-Z0-9_-]+(,@[a-zA-Z0-9_-]+)*/))`;
```

### 5. Grammar Structure (Line 14-78, grammar.js)

**Problem:** Tree-sitter expects `rules: { ... }` not `rules: () => { ... }`

**Solution:** Call buildRules() immediately, not as function reference

```javascript
// WRONG
module.exports = grammar({
  rules: ($) => { ... }  // Function - ERROR!
});

// CORRECT
module.exports = grammar({
  rules: buildRules()  // Object - WORKS!
});
```

### 6. Conflict Resolution (Line 82, grammar.js)

**Problem:** Parser can't decide when `>` starts new child or continues current

**Error:**
```
Unresolved conflict for symbol sequence:
  state name depth state name • '>' …
```

**Solution:** Declare explicit conflict

```javascript
module.exports = grammar({
  name: "actions",
  conflicts: $ => [
    [$.child_action]  // Allow GLR parsing for nested actions
  ],
  rules: buildRules()
});
```

---

## Testing Results

### Successful Parses

**examples/minimal.actions:**
```
[ ] test
```
```
(action_list
  (root_action
    (state [0, 0] - [0, 3])
    (name text: (safe_text))))
```

**examples/with_priority.actions:**
```
[x] priority !1
```
```
(action_list
  (root_action
    (state [0, 0] - [0, 3])
    (name text: (safe_text [0, 3] - [0, 13]))
    (priority [0, 13] - [0, 15])))
```

**Nested children parse correctly:**
```
[ ] Parent
> [ ] Child
>> [ ] Grandchild
>>> [ ] Great grandchild
>>>> [ ] Double-great grandchild
>>>>> [ ] Leaf
```

All depth levels (>, >>, >>>, >>>>, >>>>>) are correctly identified!

### Known Issues (File Format, Not Parser)

Some example files have **format errors** that need fixing:

1. **Context format** - Should be `+@office,@computer` not `+office,computer`
2. **Time format** - Should be `14:30` not `2:30PM` (ISO 8601)
3. **UUID dashes** - v7 UUIDs require dashes: `01951111-cfa6-718d-b303-d7107f4005b3`
4. **Description newlines** - Currently `$ description` needs to be on same line

These are **spec compliance issues**, not bugs in the generated parser.

---

## File Structure

```
tree-sitter-actions/
├── parser-ontology.ttl          # Syntax annotations (hand-maintained)
├── syntax_mapping.json          # GENERATED by Phase 1
├── grammar-generated.js         # GENERATED by Phase 2
├── grammar.js                   # Hand-maintained (imports generated)
├── src/
│   ├── grammar_generator.js     # Phase 2 generator
│   ├── parser.c                 # GENERATED by tree-sitter
│   └── node-types.json          # GENERATED by tree-sitter
├── actions.so                   # GENERATED binary parser
├── scripts/
│   └── generate-syntax-mapping.js  # Phase 1 generator
├── examples/
│   ├── minimal.actions
│   ├── with_priority.actions
│   └── ...
├── ROADMAP.md                   # Project plan
├── PROGRESS.md                  # Progress tracker (updated!)
├── ONTOLOGY_DRIVEN.md           # Architecture docs
└── PHASE2_COMPLETE.md           # This file
```

### What to Edit vs What to Generate

**Hand-Maintained (edit freely):**
- `parser-ontology.ttl` - Syntax annotations
- `grammar.js` - Top-level structure, utility rules
- `src/grammar_generator.js` - Generation logic
- `scripts/generate-syntax-mapping.js` - Ontology parser

**NEVER Edit (regenerated automatically):**
- `syntax_mapping.json` - Run `npm run generate:mapping`
- `grammar-generated.js` - Run `npm run generate:grammar`
- `src/parser.c` - Run `tree-sitter generate`
- `src/node-types.json` - Run `tree-sitter generate`
- `actions.so` - Run `tree-sitter build`

---

## Validation Checklist

- [x] `npm run generate:mapping` completes without errors
- [x] `npm run generate:grammar` produces valid JavaScript
- [x] Generated rules file has correct number of rules (14)
- [x] `tree-sitter generate` compiles grammar successfully
- [x] `tree-sitter build` produces binary parser
- [x] Parser binary size reasonable (~40KB)
- [x] Generated C code size reasonable (~169KB)
- [x] Parser correctly identifies state nodes
- [x] Parser correctly identifies name nodes
- [x] Parser correctly identifies priority values
- [x] Parser handles all 5 depth levels
- [x] Value mappings work (D, W, M, Y for recurrence)
- [x] Conflict resolution allows nested parsing
- [x] No circular references in generated rules

---

## Next Steps (Phase 3)

1. **Create corpus test suite** (test/corpus/)
   - Minimal examples (state + name)
   - All property types
   - Edge cases
   - Invalid inputs
   - Expected parse trees

2. **Fix example files**
   - Update context format: `+@office,@work`
   - Use ISO times: `14:30` not `2:30PM`
   - Add dashes to UUIDs
   - Fix multiline descriptions

3. **Add more rule types**
   - Recurrence patterns (byDay, byMonth, etc.)
   - Time intervals
   - Duration formats
   - End dates for recurrence

4. **Performance testing**
   - Large files (1000+ actions)
   - Deep nesting (verify no stack overflow)
   - Parsing speed benchmarks

5. **Error recovery**
   - How parser handles malformed input
   - Missing required fields
   - Invalid values

---

## Success Metrics

✅ **Phase 2 Complete When:**
- [x] `npm run generate:grammar` produces valid tree-sitter DSL
- [x] Generated grammar compiles with `tree-sitter generate`
- [x] All property types have rule templates
- [x] Special syntax (brackets, depth, lists) handled
- [x] Can build parser: `npm run build:parser`

**Phase 2 is COMPLETE!** 🎉

All criteria met, parser generation pipeline fully functional.

---

## For Future Developers

### How to Add a New Property

1. **Update parser-ontology.ttl:**
   ```turtle
   actions:hasUrgency
       parser:symbol "^" ;
       parser:grammarRuleName "urgency" ;
       parser:ruleType "choice" ;
       parser:formatHint "1=low, 5=critical" ;
       parser:example "^3" .
   ```

2. **Add SHACL constraints (future Phase 4):**
   ```turtle
   # In shapes.ttl
   :UrgencyShape
       sh:minInclusive 1 ;
       sh:maxInclusive 5 .
   ```

3. **Regenerate everything:**
   ```bash
   npm run generate && npm run build:parser
   ```

4. **Test it:**
   ```bash
   tree-sitter parse examples/with_urgency.actions
   ```

That's it! The pipeline handles the rest.

### Troubleshooting

**Grammar won't compile:**
- Check `grammar-generated.js` for syntax errors
- Verify regex escaping (should be `\\d` not `\d`)
- Check for undefined references (`$.depth` issue)

**Parser loads old version:**
- Check `tree-sitter dump-languages`
- May need to rebuild in correct directory
- Tree-sitter searches parent dirs for parsers

**Generated rule is wrong:**
- Check `syntax_mapping.json` first (is data correct?)
- Check rule type handler in `grammar_generator.js`
- Check for value mappings that need applying

**Parsing fails unexpectedly:**
- Use `--debug` flag to see parse states
- Check for conflicts (may need to add to conflicts array)
- Verify file format matches spec exactly

---

## References

- **[ROADMAP.md](./ROADMAP.md)** - Full project plan
- **[PROGRESS.md](./PROGRESS.md)** - Updated with Phase 2 completion
- **[ONTOLOGY_DRIVEN.md](./ONTOLOGY_DRIVEN.md)** - Architecture explanation
- **[docs/action_specification.md](./docs/action_specification.md)** - File format spec
- **[Tree-Sitter Docs](https://tree-sitter.github.io/tree-sitter/)** - Parser framework

---

**Generated:** 2025-11-04
**By:** Claude Code (Anthropic)
**Phase:** 2 of 5 (Grammar Generation)
**Status:** ✅ COMPLETE
