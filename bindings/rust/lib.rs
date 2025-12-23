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
//! # Schemas for Validation and Storage
//!
//! ## JSON Schema (Validation)
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
//! The JSON schema is generated from the same patterns used by the parser, ensuring consistency.
//!
//! ## SQL Schema (Reference Implementation)
//!
//! The [ACTIONS_SQL_SCHEMA] constant provides a reference SQL schema for applications that
//! need persistent storage. Use it as a starting point and customize as needed:
//!
//! ```rust,ignore
//! // Initialize a database with the reference schema
//! let conn = rusqlite::Connection::open("tasks.db")?;
//! conn.execute_batch(tree_sitter_actions::ACTIONS_SQL_SCHEMA)?;
//! ```
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

/// Reference SQL schema for storing `.actions` data in relational databases.
///
/// This schema provides a canonical relational mapping as documented in
/// the [action specification](https://github.com/clearheadtodo-devs/tree-sitter-actions/blob/master/docs/action_specification.md#sql-storage-schema).
///
/// The schema is designed for SQLite but can be adapted for PostgreSQL, MySQL, or other
/// relational databases. It represents a proven, normalized approach to storing actions data.
///
/// # Example: Initializing a Database
///
/// ```rust,ignore
/// use rusqlite::Connection;
///
/// // Create a new SQLite database
/// let conn = Connection::open("tasks.db")?;
///
/// // Apply the reference schema
/// conn.execute_batch(tree_sitter_actions::ACTIONS_SQL_SCHEMA)?;
/// ```
///
/// # Use Case
///
/// When building applications that need persistent storage (like task management apps or CLIs),
/// use this schema as a starting point. You can customize it by adding fields like:
/// - `user_id` for multi-user systems
/// - `created_at`/`updated_at` timestamps
/// - `deleted_at` for soft deletes
/// - Custom indexes for your query patterns
///
/// This is a **reference implementation** - feel free to adapt it to your needs while maintaining
/// the core structure for interoperability.
pub const ACTIONS_SQL_SCHEMA: &str = include_str!("../../schema/actions.sql");

include!(concat!(env!("OUT_DIR"), "/generated_tests.rs"));

// NOTE: uncomment these to include any queries that this grammar contains:

pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/actions/highlights.scm");
pub const FOLDS_QUERY: &str = include_str!("../../queries/actions/folds.scm");
pub const INDENTS_QUERY: &str = include_str!("../../queries/actions/indents.scm");

/// Standard queries for filtering actions.
///
/// These are the "Business Logic" queries that define concepts like "P1 Actions", "Completed Actions", etc.
/// Shared across CLI, Editors, and other tools to ensure consistent behavior.
pub mod queries {
    pub const P1_ACTIONS: &str = include_str!("../../queries/actions/p1-actions.scm");
    pub const COMPLETED_ACTIONS: &str = include_str!("../../queries/actions/completed-actions.scm");
    pub const IN_PROGRESS_ACTIONS: &str = include_str!("../../queries/actions/in-progress.scm");
    pub const BLOCKED_ACTIONS: &str = include_str!("../../queries/actions/blocked-actions.scm");
    pub const NOT_STARTED_ACTIONS: &str = include_str!("../../queries/actions/not-started.scm");
    pub const WITH_CHILDREN: &str = include_str!("../../queries/actions/with-children.scm");
}

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

    #[test]
    fn test_sql_schema_is_accessible() {
        // Test that the SQL schema is embedded and contains expected content
        let schema = super::ACTIONS_SQL_SCHEMA;
        assert!(!schema.is_empty(), "SQL schema should not be empty");

        // Verify it contains the expected table definitions
        assert!(schema.contains("CREATE TABLE actions"), "Schema should define actions table");
        assert!(schema.contains("CREATE TABLE action_contexts"), "Schema should define action_contexts table");
        assert!(schema.contains("CREATE TABLE action_recurrence"), "Schema should define action_recurrence table");

        // Verify it has key constraints and indexes
        assert!(schema.contains("state TEXT NOT NULL"), "Schema should define state field");
        assert!(schema.contains("'not_started'"), "Schema should have not_started state");
        assert!(schema.contains("CREATE INDEX"), "Schema should have indexes");
    }
}
