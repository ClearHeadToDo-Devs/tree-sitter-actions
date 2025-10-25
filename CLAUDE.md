# overview
you are serving as a parser builder that is building a treesitter parser for a new `actions` filetype

we are using standard treesitter grammer rules 

## Docs
Key folders and files include:
- `test` includes test samples
- `docs` includes the action specification for a verbal overview
- `grammar.js` which is the rules themselves

## References
This is an example of ontology-driven development where we have a formal OWL ontology and SHACL shapes, as well as a `syntax_mapping` file to enable our work around the semantic layer while still building out the parser in the way we would expect

# Tooling
This is a treesitter project therefore, always default to the `tree-sitter` cli so that you are able to use and validate with proper commands

check `tree-sitter help` for the list of commands

## NPM
At a larger level, this is a node project so we have a few commands that you can see from within the project itself
