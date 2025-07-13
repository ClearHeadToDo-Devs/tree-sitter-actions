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

use std::{collections::HashMap, fs};

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

/// Load test descriptions and example file contents into a nested HashMap structure.
///
/// Returns a HashMap with the structure:
/// category -> test_name -> {"description": "...", "content": "..."}
///
/// For example:
/// - "actions" -> "with_everything" -> {"description": "With Everything", "content": "(x) Mega Action\n..."}
/// - "properties" -> "with_description" -> {"description": "With Description", "content": "(x) long $ with description\n"}
pub fn get_test_files() -> HashMap<String, HashMap<String, HashMap<String, String>>> {
    let data = include_str!("../../test/test_descriptions.json");
    let map: HashMap<String, HashMap<String, String>> = serde_json::from_str(&data).unwrap();

    let mut export_map: HashMap<String, HashMap<String, HashMap<String, String>>> = HashMap::new();

    for (file_name, tests) in map {
        export_map.insert(file_name.clone(), HashMap::new());

        for (test_name, test_description) in tests {
            let file_map = export_map.get_mut(&file_name).unwrap();
            let mut test_map = HashMap::new();

            // Add the description
            test_map.insert("description".to_string(), test_description);

            // Try to read the corresponding example file
            let example_path = format!("examples/{}.actions", test_name);
            match fs::read_to_string(&example_path) {
                Ok(content) => {
                    test_map.insert("content".to_string(), content);
                }
                Err(_) => {
                    // If file doesn't exist, add a placeholder or empty content
                    test_map.insert("content".to_string(), "".to_string());
                }
            }

            file_map.insert(test_name, test_map);
        }
    }

    export_map
}

// NOTE: uncomment these to include any queries that this grammar contains:

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");
//
pub const CUSTOM: &str = "hi mom!";

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading ClearHead Actions parser");
    }

    #[test]
    fn test_load_json_tests_structure() {
        let test_data = get_test_files();

        let actions = &test_data["actions"];
        let with_everything = &actions["with_everything"];

        assert_eq!(with_everything["description"], "With Everything");
        assert!(with_everything["content"].contains("(x) Mega Action"));
        assert!(with_everything["content"].contains("$ descriptions"));
    }
}
