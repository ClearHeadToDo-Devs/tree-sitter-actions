const { test, describe } = require('node:test');
const assert = require('node:assert');
const fs = require('fs');
const path = require('path');
const Ajv = require('ajv');
const ActionsParser = require('../parser.js');

describe('ActionsParser', () => {
  let parser;
  let ajv;
  let schema;

  // Setup before tests
  test('setup', () => {
    parser = new ActionsParser();
    ajv = new Ajv();
    
    // Load schema
    const schemaPath = path.join(__dirname, '..', 'schema.json');
    schema = JSON.parse(fs.readFileSync(schemaPath, 'utf8'));
  });

  test('should parse simple actions file and conform to schema', () => {
    const filePath = path.join(__dirname, 'files', 'simple.actions');
    const result = parser.parseFile(filePath);
    
    // Validate against schema
    const validate = ajv.compile(schema);
    const valid = validate(result);
    
    if (!valid) {
      console.error('Schema validation errors:', validate.errors);
    }
    
    assert.strictEqual(valid, true, 'Parser output should conform to schema');
    
    // Additional specific assertions
    assert.strictEqual(typeof result, 'object', 'Result should be an object');
    assert.ok(result.actions, 'Result should have actions property');
    assert.ok(result.root_actions, 'Result should have root_actions property');
    assert.strictEqual(Array.isArray(result.root_actions), true, 'root_actions should be an array');
    
    // Check that we have the expected actions
    assert.strictEqual(result.root_actions.length, 2, 'Should have 2 root actions');
    
    // Verify action structure
    const firstActionId = result.root_actions[0];
    const firstAction = result.actions[firstActionId];
    
    assert.strictEqual(firstAction.depth, 0, 'Root action should have depth 0');
    assert.strictEqual(firstAction.state, ' ', 'Action should have not started state');
    assert.strictEqual(firstAction.name, 'Hello', 'Action should have correct name');
    assert.strictEqual(firstAction.story, 'Story 1', 'Action should have correct story');
    assert.strictEqual(firstAction.parent_id, null, 'Root action should have null parent_id');
    assert.strictEqual(Array.isArray(firstAction.children), true, 'Action should have children array');
    assert.strictEqual(firstAction.children.length, 0, 'Simple action should have no children');
    assert.strictEqual(typeof firstAction.order, 'number', 'Action should have numeric order');
  });

  test('should generate valid IDs when none provided', () => {
    const filePath = path.join(__dirname, 'files', 'simple.actions');
    const result = parser.parseFile(filePath);
    
    // Check that generated IDs follow the pattern
    result.root_actions.forEach(actionId => {
      const action = result.actions[actionId];
      if (action.generated_id) {
        assert.match(action.generated_id, /^generated_\d+$/, 'Generated ID should match pattern');
      }
    });
  });

  test('should handle empty actions file', () => {
    // Create a temporary empty file
    const tempFile = path.join(__dirname, 'temp_empty.actions');
    fs.writeFileSync(tempFile, '', 'utf8');
    
    try {
      const result = parser.parseFile(tempFile);
      
      // Validate against schema
      const validate = ajv.compile(schema);
      const valid = validate(result);
      
      assert.strictEqual(valid, true, 'Empty file result should conform to schema');
      assert.strictEqual(Object.keys(result.actions).length, 0, 'Should have no actions');
      assert.strictEqual(result.root_actions.length, 0, 'Should have no root actions');
    } finally {
      // Clean up temp file
      if (fs.existsSync(tempFile)) {
        fs.unlinkSync(tempFile);
      }
    }
  });

  test('should maintain action order', () => {
    const filePath = path.join(__dirname, 'files', 'simple.actions');
    const result = parser.parseFile(filePath);
    
    // Check that actions maintain their order
    const firstAction = result.actions[result.root_actions[0]];
    const secondAction = result.actions[result.root_actions[1]];
    
    assert.strictEqual(firstAction.order, 0, 'First action should have order 0');
    assert.strictEqual(secondAction.order, 1, 'Second action should have order 1');
    assert.strictEqual(firstAction.name, 'Hello', 'First action should be Hello');
    assert.strictEqual(secondAction.name, 'Goodbye', 'Second action should be Goodbye');
  });
});
