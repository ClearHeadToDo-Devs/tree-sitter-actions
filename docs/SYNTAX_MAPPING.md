# Syntax Mapping: Bridging Ontology and Parser

This document describes the syntax mapping system that bridges semantic properties from the Actions Ontology (JSON Schema) with syntactic representation in `.actions` files parsed by tree-sitter.

## 🎯 Purpose

The syntax mapping implements the **boundary between semantic and syntactic worlds**:

- **Ontology/SHACL**: Defines what properties CAN exist and what constraints they MUST satisfy
- **Tree-sitter Grammar**: Defines HOW those properties are written and parsed in `.actions` files
- **Syntax Mapping**: Bridges the two, allowing automatic grammar generation from ontology changes

## 🏗️ Architecture

```
┌─────────────────────────┐    ┌─────────────────────────┐
│ JSON Schema             │    │ SHACL Constraints       │
│ (Ontology Output)       │    │ (Validation Rules)      │
│                         │    │                         │
│ "priority": {           │    │ sh:minInclusive 1       │
│   "type": "integer",    │    │ sh:maxInclusive 4       │
│   "minimum": 1,         │    │ sh:minCount 1           │
│   "maximum": 4          │    │                         │
│ }                       │    │                         │
└─────────┬───────────────┘    └─────────┬───────────────┘
          │                              │
          └─────────────┬──────────────────┘
                        │
            ┌───────────▼────────────┐
            │ SYNTAX MAPPING         │
            │                        │
            │ priority: {            │
            │   symbol: '!',         │
            │   ruleType: 'choice',  │
            │   values: ['1','2','3','4'] │
            │   example: '!2'        │
            │ }                      │
            └───────────┬────────────┘
                        │
     ┌──────────────────┼──────────────────┐
     │                  │                  │
┌────▼────┐   ┌────────▼────────┐   ┌─────▼─────┐
│ Grammar │   │ Parser Tests    │   │ Conversion│
│ Rules   │   │ From Examples   │   │ Tools     │
└─────────┘   └─────────────────┘   └───────────┘
```

## 📋 Syntax Mapping Configuration

### Core Structure

Each property in the ontology maps to a syntax rule:

```javascript
SYNTAX_MAPPING = {
  propertyName: {
    symbol: '!',              // Character that introduces property
    ruleType: RuleType.CHOICE, // How to parse the value
    grammarRuleName: 'priority', // Name in grammar
    context: PropertyContext.ANY_LEVEL, // Where it can appear
    
    // Rule-specific configuration
    values: ['1', '2', '3', '4'],  // For CHOICE rules
    pattern: /regex/,              // For PATTERN rules
    minValue: 1,                   // For INTEGER rules
    maxValue: 4,                   // For INTEGER rules
    
    // Examples and documentation
    formatHint: 'Priority 1-4 based on Eisenhower matrix',
    example: '!2'
  }
}
```

### Symbol Assignments

| Symbol | Property | Example | Description |
|--------|----------|---------|-------------|
| `!` | priority | `!2` | Priority level (1-4) |
| `#` | uuid | `#01951111-cfa6-718d-b303-d7107f4005b3` | Version 7 UUID |
| `$` | description | `$ Extended description text` | Long description |
| `%` | completedDateTime | `%2025-01-19T10:30` | Completion timestamp |
| `*` | project | `*Run Errands` | Project/story name (root only) |
| `+` | context | `+@office,@computer` | GTD contexts |
| `@` | doDateTime/dueDateTime | `@2025-01-20T14:30` | Date/time scheduling |
| `>` | parentAction (depth) | `> Child action` | Hierarchical nesting |
| `D` | durationMinutes | `D90` | Duration in minutes |
| `R` | recurrenceFrequency | `RW` | Recurrence (D/W/M/Y) |

### Rule Types

**CHOICE**: Fixed set of values from constraints
```javascript
priority: {
  symbol: '!',
  ruleType: RuleType.CHOICE,
  values: ['1', '2', '3', '4']  // From SHACL min/max constraints
}
```

**PATTERN**: Regex validation from SHACL shapes
```javascript
context: {
  symbol: '+',
  ruleType: RuleType.PATTERN,
  pattern: /@[a-zA-Z0-9_-]+/  // From SHACL pattern constraint
}
```

**UUID_V7**: Special handling for UUIDs
```javascript
uuid: {
  symbol: '#',
  ruleType: RuleType.UUID_V7,
  pattern: /^[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}$/
}
```

## 🔄 Conversion Examples

### JSON Schema → Actions Syntax

**Input** (from `valid-action.json`):
```json
{
  "name": "Review quarterly reports",
  "state": "active", 
  "priority": 2,
  "context": "@office",
  "durationMinutes": 90,
  "uuid": "01936194-d5b0-7890-8000-123456789abc"
}
```

**Output** (`.actions` syntax):
```
[ ] Review quarterly reports !2 +@office D90 #01936194-d5b0-7890-8000-123456789abc
```

### Property-by-Property Mapping

| JSON Property | JSON Value | Actions Syntax | Rule Applied |
|---------------|------------|----------------|--------------|
| `state: "active"` | `"active"` | `[ ]` | Maps to not-started bracket |
| `name: "Review..."` | `"Review..."` | `Review...` | Direct text after state |
| `priority: 2` | `2` | `!2` | Choice rule with `!` symbol |
| `context: "@office"` | `"@office"` | `+@office` | Pattern rule with `+` symbol |
| `durationMinutes: 90` | `90` | `D90` | Integer rule with `D` symbol |
| `uuid: "019..."` | `"019..."` | `#019...` | UUID rule with `#` symbol |

## 🛠️ Tools and Usage

### 1. Syntax Mapping Validator

Validate the mapping configuration:

```bash
cd tree-sitter-actions
node src/syntax_mapping.js
```

**Output**:
- Summary statistics (20 properties mapped, 2 required, etc.)
- Symbol usage analysis 
- Rule type distribution
- Validation warnings (e.g., symbol conflicts)
- Example conversions

### 2. JSON to Actions Converter

Convert ontology examples to tree-sitter test cases:

```bash
# Convert all JSON examples
node src/json_to_actions_converter.js --test-all

# Convert specific file
node src/json_to_actions_converter.js ../ontology/examples/valid-action.json

# Validate mapping only
node src/json_to_actions_converter.js --validate
```

**Features**:
- Converts JSON examples to `.actions` syntax
- Generates tree-sitter test cases
- Shows property-by-property breakdown
- Validates all conversions

### 3. Grammar Generator

Generate grammar rules from ontology constraints:

```bash
# Generate new rules from ontology
node src/grammar_generator.js --generate-rules

# Validate current grammar against mapping
node src/grammar_generator.js --validate-current

# Compare generated vs current rules
node src/grammar_generator.js --compare
```

**Features**:
- Reads JSON schemas from ontology project
- Applies SHACL constraints to grammar rules
- Compares with existing grammar.js
- Shows improvement opportunities

## 🧪 Testing Integration

### Generated Test Cases

The converter automatically generates tree-sitter test cases from ontology examples:

```
================
valid action
================
[ ] Review quarterly reports $ Analyze Q4 performance metrics !2 +@office D90

---

(action_list
 (root_action
  (core_properties
   (state (opening) (icon) (closing))
   (name)
   (description (icon) (text))
   (priority (icon) (number))
   (context (icon) (list))
   (duration (designator) (value)))))
```

### Validation Pipeline

```bash
# 1. Validate ontology generates valid JSON schemas
cd ontology && uv run invoke generate-schemas

# 2. Validate syntax mapping consistency  
cd tree-sitter-actions && node src/syntax_mapping.js

# 3. Convert examples to actions syntax
node src/json_to_actions_converter.js --test-all

# 4. Test tree-sitter parsing (requires dependencies)
npm test

# 5. Validate round-trip conversion
# (Future: actions → JSON → actions should be identical)
```

## 🔮 Benefits and Future

### Current Benefits

1. **Single Source of Truth**: Ontology drives both validation and parsing
2. **Constraint Propagation**: SHACL min/max → grammar choices automatically  
3. **Test Synchronization**: Same examples validate both JSON and actions formats
4. **Clear Boundary**: Semantic (ontology) vs syntactic (parser) concerns separated
5. **Evolution Support**: Add properties → automatic grammar updates

### Future Enhancements

1. **Full Grammar Generation**: Generate complete `grammar.js` from ontology
2. **Bidirectional Conversion**: Parse `.actions` files back to JSON
3. **Advanced Constraints**: Date ranges, cross-property validation
4. **IDE Integration**: Syntax highlighting, autocomplete from ontology
5. **Multi-format Support**: Generate parsers for YAML, TOML, etc.

## 📊 Current Status

### ✅ Working

- Syntax mapping configuration (20 properties)
- JSON to actions conversion (3/3 examples pass)
- Tree-sitter test case generation
- Grammar validation against mapping
- Symbol conflict detection
- Property context analysis

### 🚧 Partial

- Grammar rule generation (needs integration with current grammar.js)
- Tree-sitter test execution (requires build dependencies)
- Advanced recurrence syntax (some symbols missing from current grammar)

### 🎯 Next Steps

1. **Integrate with build system**: Add syntax mapping validation to CI/CD
2. **Enhance current grammar**: Add missing symbols (+, $, I, C, U) 
3. **Bidirectional parsing**: Convert actions syntax back to JSON
4. **Documentation sync**: Keep ontology docs in sync with grammar changes

## 🧩 Integration Points

### With Ontology Project

- Reads JSON schemas from `../ontology/schemas/`
- Uses examples from `../ontology/examples/`
- Validates against SHACL patterns and constraints
- Syncs property additions/changes automatically

### With Tree-sitter Grammar

- Maps to existing `grammar.js` field names
- Generates enhanced rules with constraint validation
- Provides test cases for `test/corpus/` files
- Validates symbol usage and rule completeness

### With Clearhead CLI

- Provides conversion utilities for file processing
- Enables bidirectional JSON ↔ actions transformation
- Supports validation of both formats
- Allows format-agnostic action manipulation

---

The syntax mapping serves as the crucial bridge between your semantic domain model and concrete file syntax, enabling the "small waist" architecture where ontology changes automatically flow through to grammar and parsing improvements.