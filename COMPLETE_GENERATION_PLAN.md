# Complete Generation Plan: Zero Hand-Maintained Code

**Goal:** Generate 100% of grammar from ontology + SHACL shapes
**Status:** 📋 PLANNING
**Priority:** CRITICAL for true ontology-driven development

## Current State: What's Hand-Maintained

### ❌ grammar.js - 95 lines of hand-maintained code

| Rule | Lines | Source Needed | Notes |
|------|-------|---------------|-------|
| `action_list` | 15 | File structure ontology | `repeat($.root_action)` |
| `root_action` | 17-32 | ✅ Already in ontology! | Lines 131-151 in parser-ontology.ttl |
| `child_action` | 34-49 | ✅ Already in ontology! | Lines 153-173 in parser-ontology.ttl |
| `do_date_or_time` | 53-57 | SHACL composition | Duration as optional child |
| `duration` | 60 | ✅ Already generated! | Just needs to stay generated |
| `safe_text` | 65 | SHACL pattern | Derive from name/description constraints |
| `iso_date` | 66 | SHACL pattern | ISO 8601 date pattern |
| `iso_time` | 67 | SHACL pattern | ISO 8601 time pattern |
| `iso_date_time` | 68 | SHACL pattern | ISO 8601 datetime pattern |
| `depth` | 71-77 | SHACL + ontology | Generate from maxDepth=5 |
| `extras` | 82-84 | Grammar metadata | Whitespace handling |
| `conflicts` | 86-88 | Grammar metadata | May be derivable |

### ✅ grammar-generated.js - 16 lines, all generated correctly

Working rules that don't need changes:
- `id`, `name`, `priority`, `state`, `context`, `description`, `project`
- `completed_date`, `recurrence`, `recurrence_interval`, `recurrence_count`, `recurrence_until`

## The Missing Pieces

### 1. Structure Generation (ALREADY IN ONTOLOGY!)

**Location:** `parser-ontology.ttl` lines 131-173

```turtle
parser:RootActionGrammarStructure a owl:Class ;
    parser:hasOrderedProperty (
        [ parser:grammarRuleName "state" ; parser:isRequired "true"^^xsd:boolean ]
        [ parser:grammarRuleName "name" ; parser:isRequired "true"^^xsd:boolean ]
        [ parser:grammarRuleName "description" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "priority" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "project" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "context" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "do_date_or_time" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "completed_date" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "duration" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "recurrence" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "recurrence_interval" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "recurrence_count" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "recurrence_until" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "id" ; parser:isRequired "false"^^xsd:boolean ]
        [ parser:grammarRuleName "children" ; parser:isRequired "false"^^xsd:boolean ]
    ) .

parser:ChildActionGrammarStructure a owl:Class ;
    parser:hasOrderedProperty (
        [ parser:grammarRuleName "depth" ; parser:isRequired "true"^^xsd:boolean ]
        [ parser:grammarRuleName "state" ; parser:isRequired "true"^^xsd:boolean ]
        [ parser:grammarRuleName "name" ; parser:isRequired "true"^^xsd:boolean ]
        # ... same as root, minus project
    ) .
```

**Status:** ✅ Defined, ❌ Not being used by generator

**Fix:** Update `grammar_generator.js` to read `mapping.structures` and generate sequences

### 2. File-Level Structure

**Need to add to ontology:**

```turtle
parser:ActionsFileGrammar a owl:Class ;
    rdfs:label "Actions File Grammar" ;
    rdfs:comment "Top-level grammar structure for .actions files" ;
    parser:entryPoint "action_list" ;
    parser:rootRule "root_action" ;
    parser:repeatMode "repeat" .  # Allow zero or more root actions
```

**Generate:**
```javascript
action_list: $ => repeat($.root_action)
```

### 3. Composition Rules (Duration in do_date_or_time)

**Option A: In parser-ontology.ttl**
```turtle
actions:hasDoDateTime
    parser:hasOptionalChild actions:hasDurationMinutes ;
    parser:childOrder 1 .  # After the datetime value
```

**Option B: From SHACL (better!)**
```turtle
# In actions-shapes-v3.ttl
actions:DoDateTimeShape
    sh:property [
        sh:path actions:hasDoDateTime ;
        sh:node actions:DateTimeValue ;
    ] ;
    sh:property [
        sh:path actions:hasDurationMinutes ;
        sh:minCount 0 ;
        sh:maxCount 1 ;
        sh:order 1 ;  # Comes after datetime
    ] .
```

**Generate:**
```javascript
do_date_or_time: $ => seq(
    field('icon', '@'),
    field('value', choice($.iso_date_time, $.iso_date, $.iso_time)),
    optional($.duration)
)
```

### 4. Utility Patterns from SHACL

**Add to actions-shapes-v3.ttl:**

```turtle
actions:NameShape
    sh:property [
        sh:path schema:name ;
        sh:pattern "^[^$!*+@%>#\\(\\)\\n]+$" ;  # Safe text
        sh:minLength 1 ;
    ] .

actions:DateTimeShapes
    sh:property [
        sh:path actions:hasDoDateTime ;
        sh:or (
            [ sh:pattern "^\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}$" ]  # iso_date_time
            [ sh:pattern "^\\d{4}-\\d{2}-\\d{2}$" ]               # iso_date
            [ sh:pattern "^\\d{2}:\\d{2}$" ]                      # iso_time
        )
    ] .
```

**Generate:**
```javascript
safe_text: $ => repeat1(/[^$!*+@%>#\(\)\n\s]+/)
iso_date: $ => /\d{4}-\d{2}-\d{2}/
iso_time: $ => /\d{2}:\d{2}/
iso_date_time: $ => /\d{4}-\d{2}-\d{2}T\d{2}:\d{2}/
```

### 5. Depth Generation from SHACL

**In actions-shapes-v3.ttl:**

```turtle
actions:DepthShape
    sh:property [
        sh:path actions:hasDepth ;
        sh:minInclusive 0 ;
        sh:maxInclusive 5 ;
        sh:datatype xsd:integer ;
    ] .
```

**In parser-ontology.ttl:**

```turtle
actions:hasParentPlan
    parser:depthSymbol ">" ;
    parser:maxDepth 5 .
```

**Generate:**
```javascript
depth: $ => choice('>', '>>', '>>>', '>>>>', '>>>>>')
```

### 6. Grammar Metadata

**Add to parser-ontology.ttl:**

```turtle
parser:ActionsGrammarMetadata
    parser:whitespaceHandling "extras" ;  # or "ignore", "significant"
    parser:conflictRules ( "child_action" ) .
```

**Generate:**
```javascript
extras: [/\s/],
conflicts: [$.child_action]
```

## Implementation Plan

### Phase 4A: Structure Generation (2 hours)

**Goal:** Eliminate hand-maintained `root_action` and `child_action`

**Tasks:**
1. ✅ Structure already defined in ontology (lines 131-173)
2. Update `generate-syntax-mapping.js`:
   - Improve structure parsing (current regex is basic)
   - Extract all properties from ordered lists
3. Update `grammar_generator.js`:
   - Add `generateActionStructure(structureName, properties)` function
   - Generate `seq()` with required/optional based on `isRequired`
   - Generate `field("children", repeat1($.child_action))` for nesting
4. Test: Ensure generated structures match current hand-maintained ones

**Validation:**
- Parse all examples successfully
- AST structure unchanged
- Zero hand-maintained action sequences

### Phase 4B: SHACL Integration (3 hours)

**Goal:** Fetch and parse SHACL shapes for patterns and constraints

**Tasks:**
1. Fetch SHACL shapes:
   - Option A: Load from `../ontology/actions-shapes-v3.ttl` (submodule)
   - Option B: Fetch from web (independence)
   - Decision: Start with submodule, add web fetch later
2. Add SHACL parser to `generate-syntax-mapping.js`:
   - Parse `sh:pattern` for text/date patterns
   - Parse `sh:minInclusive`/`sh:maxInclusive` for ranges
   - Parse `sh:order` for composition
   - Parse `sh:node` for nested structures
3. Merge SHACL constraints with parser annotations
4. Remove hardcoded constraints from generator

**Validation:**
- Priority still generates `choice('1', '2', '3', '4')`
- Duration still has 1-10080 range
- But now from SHACL, not hardcoded

### Phase 4C: Utility Pattern Generation (2 hours)

**Goal:** Generate `safe_text`, `iso_date`, `iso_time`, `iso_date_time`, `depth`

**Tasks:**
1. Extract text patterns from SHACL name/description shapes
2. Extract date patterns from datetime shape alternatives
3. Generate depth choices from maxDepth constraint
4. Add pattern generation to `grammar_generator.js`:
   - `generateUtilityPatterns(shapes)` function
   - Return object with `safe_text`, `iso_*`, `depth` rules

**Validation:**
- Multi-word names still parse
- Dates validate correctly
- Depth markers (> through >>>>>) work

### Phase 4D: Composition Rules (2 hours)

**Goal:** Generate `do_date_or_time` with nested `duration`

**Tasks:**
1. Add composition annotations to parser-ontology.ttl:
   ```turtle
   actions:hasDoDateTime
       parser:hasOptionalChild actions:hasDurationMinutes ;
       parser:childOrder 1 .
   ```
2. Or extract from SHACL `sh:node` and `sh:order`
3. Update grammar generator to handle composition:
   - Check for `hasOptionalChild` annotations
   - Generate `optional($.duration)` after datetime value
4. Remove hand-maintained `do_date_or_time` override

**Validation:**
- `@2025-01-19T08:30 D30` still parses
- Duration nested inside do_date_or_time
- AST structure unchanged

### Phase 4E: File Structure & Metadata (1 hour)

**Goal:** Generate `action_list`, `extras`, `conflicts`

**Tasks:**
1. Add file-level metadata to parser-ontology.ttl:
   ```turtle
   parser:ActionsFileGrammar
       parser:entryPoint "action_list" ;
       parser:rootRule "root_action" ;
       parser:repeatMode "repeat" ;
       parser:whitespaceHandling "extras" ;
       parser:conflictRules ( "child_action" ) .
   ```
2. Update grammar generator:
   - Generate `action_list` rule from entryPoint
   - Generate `extras` array from whitespaceHandling
   - Generate `conflicts` array from conflictRules
3. Generate complete grammar file structure

**Validation:**
- File-level parsing unchanged
- Whitespace handling identical
- Conflict resolution working

### Phase 4F: Complete Generation (1 hour)

**Goal:** Eliminate grammar.js entirely, generate everything

**Tasks:**
1. Update `grammar_generator.js` to output complete grammar:
   ```javascript
   // Generate complete grammar.js file
   const fullGrammar = `
   module.exports = grammar({
     name: "actions",
     extras: [${generateExtras()}],
     conflicts: [${generateConflicts()}],
     rules: {
       ${generateAllRules()}
     }
   });
   `;
   fs.writeFileSync('grammar.js', fullGrammar);
   ```
2. Move current `grammar.js` to `grammar.js.template` (backup)
3. Update `npm run generate:grammar` to write `grammar.js` directly
4. Add generation header comment with timestamp and sources

**Validation:**
- `tree-sitter generate` compiles successfully
- All examples parse identically
- Zero hand-maintained code in grammar.js
- Grammar.js shows "Generated - DO NOT EDIT" header

### Phase 4G: Validation & Documentation (1 hour)

**Goal:** Prove 100% generation works

**Tasks:**
1. Delete grammar.js
2. Run `npm run generate`
3. Verify grammar.js is regenerated identically
4. Run all tests
5. Update documentation:
   - Mark Phase 4 complete
   - Document generation sources (ontology + SHACL)
   - Update architecture diagrams
   - Add "Zero Hand-Maintained Code" badge

**Success Criteria:**
- ✅ Zero hand-maintained grammar code
- ✅ All rules generated from ontology/SHACL
- ✅ All examples parse correctly
- ✅ AST structure unchanged
- ✅ Can regenerate grammar.js from scratch

## Total Time Estimate: 12 hours

| Phase | Hours | Risk |
|-------|-------|------|
| 4A: Structure Generation | 2 | LOW (already defined) |
| 4B: SHACL Integration | 3 | MEDIUM (new parsing) |
| 4C: Utility Patterns | 2 | LOW (straightforward) |
| 4D: Composition Rules | 2 | MEDIUM (complex nesting) |
| 4E: File Structure | 1 | LOW (simple metadata) |
| 4F: Complete Generation | 1 | LOW (assembly) |
| 4G: Validation | 1 | LOW (testing) |
| **TOTAL** | **12** | **MEDIUM** |

## Dependencies

### Required in Ontology Repo
- `actions-shapes-v3.ttl` with complete SHACL constraints
- Pattern definitions for text, dates
- Composition rules (sh:node, sh:order)

### Required in Parser Repo
- Updated parser-ontology.ttl with:
  - Composition annotations (hasOptionalChild)
  - File structure metadata
  - Grammar metadata (extras, conflicts)

### Tools Needed
- SHACL parser in JavaScript (or simple regex for our subset)
- Template generation for full grammar file
- Validation that generated = hand-maintained

## Architecture After Phase 4

```
[Ontology Repo]
├── actions-ontology-v3.ttl (domain semantics)
└── actions-shapes-v3.ttl (SHACL constraints + patterns)
        ↓ [git submodule or web fetch]

[Parser Repo]
├── parser-ontology.ttl (syntax annotations + structure)
        ↓ [generate-syntax-mapping.js]
├── syntax_mapping.json (intermediate)
        ↓ [grammar_generator.js + SHACL shapes]
├── grammar.js (FULLY GENERATED - DO NOT EDIT)
        ↓ [tree-sitter generate]
└── src/parser.c (tree-sitter output)
```

**Key:** Every line in grammar.js traceable to ontology/SHACL source

## Benefits of Complete Generation

1. **Single Source of Truth**
   - Change format in ontology → regenerate parser
   - No manual sync needed

2. **Extensibility**
   - Users can extend ontology
   - Parser automatically includes new properties

3. **Maintainability**
   - Update patterns in SHACL
   - Regenerate, done

4. **Validation**
   - SHACL constraints = parser constraints
   - Perfect alignment

5. **Documentation**
   - Ontology IS the documentation
   - Parser behavior derivable from formal semantics

## Risks & Mitigations

### Risk: SHACL shapes don't have all needed patterns
**Mitigation:** Start by documenting what we need, add to SHACL shapes incrementally

### Risk: Generated grammar doesn't compile
**Mitigation:** Keep template grammar.js, diff against generated, iterate

### Risk: Breaking changes in generation
**Mitigation:** Comprehensive test suite, version control, can rollback

### Risk: Performance of generated grammar
**Mitigation:** Benchmark, optimize patterns, tree-sitter is very fast

### Risk: Complex composition rules hard to express
**Mitigation:** Start simple (duration in datetime), generalize pattern

## Success Metrics

- ✅ 0 lines of hand-maintained grammar code
- ✅ 100% of rules generated from ontology/SHACL
- ✅ All examples parse identically before/after
- ✅ Generation completes in < 5 seconds
- ✅ Grammar.js can be deleted and regenerated perfectly
- ✅ Documentation traces every rule to source

## Next Steps

1. **Commit this plan** to repository
2. **Review with stakeholders** - is this the right approach?
3. **Start Phase 4A** - Structure generation (lowest risk)
4. **Iterate through phases** methodically
5. **Validate at each step** - no breaking changes

## Open Questions

1. Should SHACL shapes be in separate file or integrated into parser-ontology.ttl?
   - **Recommendation:** Separate, from ontology repo via submodule

2. How to handle tree-sitter specific features (conflicts, extras)?
   - **Recommendation:** Parser-specific metadata in parser-ontology.ttl

3. What if SHACL constraints conflict with parser needs?
   - **Recommendation:** Parser-ontology.ttl overrides for syntax-specific cases

4. Should we version the generation pipeline?
   - **Recommendation:** Yes, track in metadata, allow schema evolution

5. How to test SHACL integration without full ontology repo?
   - **Recommendation:** Mock SHACL shapes for testing, validate with real shapes later

---

**Status:** Planning complete, ready to begin implementation
**Owner:** To be assigned
**Target:** Phase 4 complete within 2-3 development days
**Success:** Zero hand-maintained grammar code, fully ontology-driven
