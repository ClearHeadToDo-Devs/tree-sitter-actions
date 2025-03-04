# Tree-sitter Parser for Action(s) files
This is intended to be a small, purpose-built parser in alignment with the specification describes in [the specification file](./docs/action_specification.md) 

Please read the specification for more in-depth coverage on what is available within the format and why it was designed the way it was

Taking a step back, these action files can be used in a few ways:
- as a more structured alternative to `todo.txt` complete with a parser that can be used as structured data while still allowing for a document-first workflow
- as a part of a larger whole in the ClearHead Framework, serving as the children for stories
- in an alternative framework that is less opinionated. Maybe a more GTD-centric framework that wants to use the actions as children for projects

## Deployment Targets
So far, there are two usecases i know I will be using this for:
- within Neovim to give various features for text editing including:
    - Highlighting
    - indentation
    - hiding rules
    - text objects
- as a library within the cli for:
    - structured analysis of documents
    - easy testing against existing documents at a structural level
    - ease in type-serialization and deserialization

## Testing
All features of the parser should be covered by tests within the `tests` folder and can be run using the standard `tree-sitter test` if you have the cli installed locally


