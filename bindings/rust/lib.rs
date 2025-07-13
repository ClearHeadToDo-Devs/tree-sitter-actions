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

/// Include the generated test data for reuse by other implementations
/// This is primarily used get the generated test data that can be used as actual data at runtime
/// to dynamically create tests against the very same structure that the main parsing library, this
/// eliminates the risk that downstream dependencies need to test against a subset of data from my
/// end instead they can pull the entire contents of the example files and use them in whatever
/// tests they may need to use
pub mod generated_tests;

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

// NOTE: uncomment these to include any queries that this grammar contains:

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    use super::*;
    use generated_tests::get_test_data;

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&LANGUAGE.into())
            .expect("Error loading ClearHead Actions parser");
    }

    #[test]
    fn test_load_json_tests_structure() {
        let test_data = get_test_data();

        let actions = &test_data["actions"];
        let with_everything = &actions["with_everything"];

        assert_eq!(with_everything["description"], "With Everything");
        assert!(with_everything["content"].contains("(x) Mega Action"));
        assert!(with_everything["content"].contains("$ descriptions"));
    }
}
