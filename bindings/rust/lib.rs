//! Tree-sitter parser for the `.actions` file format.
//!
//! # Parsing
//!
//! Use the [LANGUAGE] constant to parse `.actions` files:
//!
//! ```
//! let code = "[ ] Buy milk\n!1\n";
//! let mut parser = tree_sitter::Parser::new();
//! parser
//!     .set_language(&tree_sitter_actions::LANGUAGE.into())
//!     .expect("Error loading Actions parser");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
//! ```
//!
//! # Testing with Examples
//!
//! The [examples] module provides example `.actions` files organized by category:
//!
//! ```
//! use tree_sitter_actions::examples;
//!
//! let priority_example = examples::properties::WITH_PRIORITY;
//! let children_example = examples::children::WITH_CHILDREN;
//! ```
//!
//! All examples are embedded at compile time, so there's no runtime I/O.
//!
//! # JSON Schema Validation
//!
//! The [ACTIONS_SCHEMA] constant provides a JSON Schema for validating serialized data.
//! Use this when exporting parsed `.actions` data to JSON format:
//!
//! ```rust,ignore
//! // Parse .actions file, convert to JSON, then validate
//! let schema: serde_json::Value =
//!     serde_json::from_str(tree_sitter_actions::ACTIONS_SCHEMA)?;
//! let validator = jsonschema::JSONSchema::compile(&schema)?;
//! validator.validate(&your_json_data)?;
//! ```
//!
//! The schema is generated from the same patterns used by the parser, ensuring consistency.
//!
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_actions() -> *const ();
}

/// The tree-sitter [`LanguageFn`][LanguageFn] for this grammar.
///
/// [LanguageFn]: https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html
pub const LANGUAGE: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_actions) };

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers/6-static-node-types
pub const NODE_TYPES: &str = include_str!("../../src/node-types.json");

/// JSON Schema for validating serialized `.actions` data.
///
/// This schema validates the canonical JSON serialization format as documented in
/// the [action specification](https://github.com/clearheadtodo-devs/tree-sitter-actions/blob/master/docs/action_specification.md#json-serialization-format).
///
/// The schema is generated from the same regex patterns used by the tree-sitter grammar,
/// ensuring parsing rules and validation rules stay in sync.
///
/// # Example: Validating Serialized Data
///
/// ```rust,ignore
/// use serde_json::json;
/// use jsonschema::JSONSchema;
///
/// // Get the schema
/// let schema_value: serde_json::Value =
///     serde_json::from_str(tree_sitter_actions::ACTIONS_SCHEMA)
///         .expect("Schema should be valid JSON");
///
/// // Compile the schema
/// let compiled = JSONSchema::compile(&schema_value)
///     .expect("Schema should compile");
///
/// // Validate your serialized actions data
/// let data = json!({
///     "actions": [{
///         "state": "completed",
///         "name": "Example task"
///     }]
/// });
///
/// compiled.validate(&data).expect("Data should validate");
/// ```
///
/// # Use Case
///
/// When building tools that export `.actions` data to JSON (like CLIs or APIs),
/// use this schema to validate your output matches the canonical format.
pub const ACTIONS_SCHEMA: &str = include_str!("../../schema/actions.schema.json");

include!(concat!(env!("OUT_DIR"), "/generated_tests.rs"));

// NOTE: uncomment these to include any queries that this grammar contains:

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading ClearHead Actions parser");
    }

    #[test]
    fn test_generated_data_is_accessible() {
        let test_data = super::get_test_data();
        assert!(!test_data.is_empty(), "Test data should not be empty");

        // Check for a specific category and test case to ensure data is loaded correctly
        let actions_category = test_data
            .get("actions")
            .expect("Actions category should exist");
        let with_everything_test = actions_category
            .get("with_everything")
            .expect("with_everything test should exist in actions category");

        assert_eq!(
            with_everything_test.get("description"),
            Some(&"With Everything".to_string()),
            "Description for with_everything should be correct"
        );

        assert!(
            with_everything_test.contains_key("content"),
            "Content for with_everything should exist"
        );
    }

    #[test]
    fn test_examples_module_accessible() {
        // Test that the examples module constants are accessible and contain content
        let priority_example = super::examples::properties::WITH_PRIORITY;
        assert!(!priority_example.is_empty(), "Priority example should not be empty");
        assert!(priority_example.contains("!1"), "Priority example should contain priority marker");

        let children_example = super::examples::children::WITH_CHILDREN;
        assert!(!children_example.is_empty(), "Children example should not be empty");
        assert!(children_example.contains(">"), "Children example should contain child marker");

        let everything_example = super::examples::actions::WITH_EVERYTHING;
        assert!(!everything_example.is_empty(), "Everything example should not be empty");
        assert!(everything_example.contains("Mega Action"), "Everything example should contain action text");
    }

    #[test]
    fn test_schema_is_accessible() {
        // Test that the JSON Schema is embedded and valid
        let schema = super::ACTIONS_SCHEMA;
        assert!(!schema.is_empty(), "Schema should not be empty");

        // Verify it's valid JSON
        let parsed: serde_json::Value = serde_json::from_str(schema)
            .expect("Schema should be valid JSON");

        // Verify it has the expected structure
        assert_eq!(
            parsed.get("$schema").and_then(|v| v.as_str()),
            Some("http://json-schema.org/draft-07/schema#"),
            "Schema should have correct $schema field"
        );

        assert_eq!(
            parsed.get("title").and_then(|v| v.as_str()),
            Some("Actions File Serialization Format"),
            "Schema should have correct title"
        );

        // Verify it has the action definition
        assert!(
            parsed.get("definitions")
                .and_then(|d| d.get("action"))
                .is_some(),
            "Schema should define action type"
        );
    }
}
