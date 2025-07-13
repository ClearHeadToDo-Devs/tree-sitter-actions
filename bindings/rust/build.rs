use serde_json::*;
use std::collections::HashMap;
use std::fs::*;
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
    
    let out_dir = std::env::var("OUT_DIR").unwrap();
    let dest_path = std::path::Path::new(&out_dir).join("test_data.rs");
    
    let mut file_content = String::new();
    file_content.push_str("use std::collections::HashMap;\n\n");
    file_content.push_str("/// Get test files data generated at compile time\n");
    file_content.push_str("pub fn get_test_files() -> HashMap<String, HashMap<String, HashMap<String, String>>> {\n");
    file_content.push_str("    let mut map = HashMap::new();\n\n");
    
    for (category, tests) in &test_data {
        file_content.push_str(&format!("    map.insert(\"{}\".to_string(), {{\n", category));
        file_content.push_str("        let mut category_map = HashMap::new();\n");
        
        for (test_name, test_info) in tests {
            file_content.push_str(&format!("        category_map.insert(\"{}\".to_string(), {{\n", test_name));
            file_content.push_str("            let mut test_map = HashMap::new();\n");
            
            for (key, value) in test_info {
                let escaped_value = value.replace('\\', "\\\\").replace('"', "\\\"").replace('\n', "\\n").replace('\r', "\\r");
                file_content.push_str(&format!("            test_map.insert(\"{}\".to_string(), \"{}\".to_string());\n", key, escaped_value));
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
