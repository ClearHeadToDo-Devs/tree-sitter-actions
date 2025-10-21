# Syntax Mapping Tools

This directory contains tools for bridging the Actions Ontology with the tree-sitter grammar through a systematic syntax mapping.

## 🚀 Quick Start

```bash
# Validate syntax mapping
node src/syntax_mapping.js

# Convert ontology examples to .actions syntax
node src/json_to_actions_converter.js --test-all

# Validate current grammar against mapping
node src/grammar_generator.js --validate-current
```

## 📁 Files

- **`src/syntax_mapping.js`** - Core syntax mapping configuration
- **`src/json_to_actions_converter.js`** - Convert JSON examples to .actions syntax
- **`src/grammar_generator.js`** - Generate/validate grammar rules from ontology
- **`docs/SYNTAX_MAPPING.md`** - Comprehensive documentation

## 🎯 Key Features

### Automatic Conversion
Convert JSON Schema examples to .actions file syntax:

```json
// Input
{"name": "Task", "priority": 2, "context": "@office"}

// Output  
[ ] Task !2 +@office
```

### Constraint Propagation
SHACL constraints automatically become grammar rules:

```javascript
// From JSON Schema: "minimum": 1, "maximum": 4
// Becomes grammar: choice('1', '2', '3', '4')
```

### Test Generation
Generate tree-sitter test cases from ontology examples:

```
================
priority example
================
[ ] High priority task !1

---

(action_list (root_action (core_properties ...)))
```

## 🧪 Testing Workflow

1. **Ontology Changes**: Update properties in `../ontology/`
2. **Generate Schemas**: Run `uv run invoke generate-schemas` 
3. **Validate Mapping**: Run `node src/syntax_mapping.js`
4. **Test Conversion**: Run `node src/json_to_actions_converter.js --test-all`
5. **Update Grammar**: Use output to enhance `grammar.js`
6. **Run Parser Tests**: Test with new syntax

## 🔧 Development Commands

```bash
# Full validation pipeline
node src/syntax_mapping.js                          # Validate mapping
node src/json_to_actions_converter.js --validate    # Test conversions  
node src/grammar_generator.js --validate-current    # Check grammar

# Generate new test cases
node src/json_to_actions_converter.js --test-all > new_tests.txt

# Generate enhanced grammar rules
node src/grammar_generator.js --generate-rules > new_rules.json
```

## 📊 Current Status

- ✅ 20 properties mapped to syntax
- ✅ 3/3 JSON examples convert successfully  
- ✅ Tree-sitter test case generation working
- ⚠️ Some symbols missing from current grammar (+, $, I, C, U)
- ⚠️ Parser tests require build dependencies

See `docs/SYNTAX_MAPPING.md` for complete documentation.