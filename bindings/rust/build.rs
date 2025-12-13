use std::collections::HashMap;
use std::env;
use std::fs::{self, *};
fn main() {
    let src_dir = std::path::Path::new("src");

    let mut c_config = cc::Build::new();
    c_config.std("c11").include(src_dir);

    #[cfg(target_env = "msvc")]
    c_config.flag("-utf-8");

    let parser_path = src_dir.join("parser.c");
    c_config.file(&parser_path);
    println!("cargo:rerun-if-changed={}", parser_path.to_str().unwrap());

    let scanner_path = src_dir.join("scanner.c");
    if scanner_path.exists() {
        c_config.file(&scanner_path);
        println!("cargo:rerun-if-changed={}", scanner_path.to_str().unwrap());
    }

    c_config.compile("tree-sitter-actions");
    generate_test_data_file();
}

/// Generate a Rust file containing the test data at compile time
fn generate_test_data_file() {
    let test_data = get_test_files();

    let out_dir = env::var("OUT_DIR").unwrap();
    let dest_path = std::path::Path::new(&out_dir).join("generated_tests.rs");

    let mut file_content = String::new();

    // Generate the examples module with organized constants
    file_content.push_str("/// Example `.actions` files organized by category.\n");
    file_content.push_str("///\n");
    file_content.push_str("/// These examples are useful for testing parsers and downstream tools\n");
    file_content.push_str("/// that work with the `.actions` file format.\n");
    file_content.push_str("///\n");
    file_content.push_str("/// # Example\n");
    file_content.push_str("/// ```\n");
    file_content.push_str("/// use tree_sitter_actions::examples;\n");
    file_content.push_str("///\n");
    file_content.push_str("/// let content = examples::properties::WITH_PRIORITY;\n");
    file_content.push_str("/// // Use content in your tests...\n");
    file_content.push_str("/// ```\n");
    file_content.push_str("pub mod examples {\n");

    for (category, tests) in &test_data {
        // Convert category name to valid Rust module name (e.g., "actions" -> "actions")
        file_content.push_str(&format!("    /// Examples for {}\n", category));
        file_content.push_str(&format!("    pub mod {} {{\n", category));

        for (test_name, _) in tests {
            // Convert test name to SCREAMING_SNAKE_CASE for constant
            let const_name = test_name.to_uppercase();

            file_content.push_str(&format!(
                "        /// Example: {}\n",
                test_name.replace('_', " ")
            ));
            file_content.push_str(&format!(
                "        pub const {}: &str = include_str!(concat!(env!(\"CARGO_MANIFEST_DIR\"), \"/examples/{}.actions\"));\n",
                const_name, test_name
            ));
        }

        file_content.push_str("    }\n\n");
    }

    file_content.push_str("}\n\n");

    // Keep the old get_test_data() function for backwards compatibility
    file_content.push_str("/// Get test files data generated at compile time\n");
    file_content.push_str("///\n");
    file_content.push_str("/// **Note:** Consider using the `examples` module for easier access to example files.\n");
    file_content.push_str(
        "pub fn get_test_data() -> std::collections::HashMap<String, std::collections::HashMap<String, std::collections::HashMap<String, String>>> {\n",
    );
    file_content.push_str("    let mut map = std::collections::HashMap::new();\n\n");

    for (category, tests) in &test_data {
        file_content.push_str(&format!(
            "    map.insert(\"{}\".to_string(), {{\n",
            category
        ));
        file_content.push_str("        let mut category_map = std::collections::HashMap::new();\n");

        for (test_name, test_info) in tests {
            file_content.push_str(&format!(
                "        category_map.insert(\"{}\".to_string(), {{\n",
                test_name
            ));
            file_content
                .push_str("            let mut test_map = std::collections::HashMap::new();\n");

            for (key, value) in test_info {
                let escaped_value = value
                    .replace('\\', "\\\\")
                    .replace('"', "\\\"")
                    .replace('\n', "\\n")
                    .replace('\r', "\\r");
                file_content.push_str(&format!(
                    "            test_map.insert(\"{}\".to_string(), \"{}\".to_string());\n",
                    key, escaped_value
                ));
            }

            file_content.push_str("            test_map\n");
            file_content.push_str("        });\n");
        }

        file_content.push_str("        category_map\n");
        file_content.push_str("    });\n\n");
    }

    file_content.push_str("    map\n");
    file_content.push_str("}\n");

    write(&dest_path, file_content).unwrap();
}

/// Load test descriptions and example file contents into a nested HashMap structure.
///
/// Returns a HashMap with the structure:
/// category -> test_name -> {"description": "...", "content": "..."}
///
/// For example:
/// - "actions" -> "with_everything" -> {"description": "With Everything", "content": "(x) Mega Action\n..."}
/// - "properties" -> "with_description" -> {"description": "With Description", "content": "(x) long $ with description\n"}
fn get_test_files() -> HashMap<String, HashMap<String, HashMap<String, String>>> {
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let descriptions_path = std::path::Path::new(&manifest_dir)
        .join("test")
        .join("test_descriptions.json");
    let data = fs::read_to_string(descriptions_path).unwrap();
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
            let example_path = std::path::Path::new(&manifest_dir)
                .join("examples")
                .join(format!("{}.actions", test_name));
            match read_to_string(&example_path) {
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
