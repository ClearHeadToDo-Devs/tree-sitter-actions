//! This crate provides Actions language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [LANGUAGE][] constant to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! let code = r#"
//! "#;
//! let mut parser = tree_sitter::Parser::new();
//! let language = tree_sitter_actions::LANGUAGE;
//! parser
//!     .set_language(&language.into())
//!     .expect("Error loading ClearHead Actions parser");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
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
}
