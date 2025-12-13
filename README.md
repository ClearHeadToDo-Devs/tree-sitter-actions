# Tree Sitter Actions File Format Parser
===============================
A simple Tree Sitter parser for the custom `.actions` file format.

## Usage
1. Generate the parser:
    ```bash
    tree-sitter generate
    ```
2. Test the parser on an example file:
    ```bash
    tree-sitter parse examples/with_priority.actions
    ```
3. Use the parser in your project as needed, directly with the CLI is fine
  - we can also build the parser into other apps by using this as a library in a client applications
  - or maybe you have an editor that supports tree-sitter grammars, you can use this grammar to get syntax highlighting and other features for `.actions` files!

For detailed usage examples (Rust library, editors, other languages), see [docs/usage.md](docs/usage.md).
# Tree Sitter Action File Format Parser
This is a simple parser for the custom `.actions` [File Format](docs/action_specification.md) to be used in whatever form may be needed.

Actions can be thought of as planned, intended actions to be taken on by an agent.
- Could be fun plans you have for a trip
- Could outline the needs for an LLM to follow
- This could be traditional Tasks

This could be seen as a set of Intended Actions from a CIO ontology standpoint, but the usecases can vary these are just what we have in mind upon writing.

## Purpose
My purpose in creating this parser is to create the intention management file format that the world deserved. Slightly more complex than todo.txt, but not by much, while still being a plaintext format that can be used in whatever format may work for you.

In particular, the values are (you can also read this in the file specification linked above):
- Human Readable and Writable
  - Minimal syntax to remember and change
  - treesitter is tolerant of errors, trying to parse as best as possible
- Unambigous parsing parameters to make it easy to parse for machines
  - For example, we do NOT use whitespace to indicate structure, instead, we use specific characters like `>` with a recurrence for how many levels deep you are
  - Great lengths have been taken to make reading the tree easy for implementors, using only normal rules and ensuring we are careful about the use of `labels` vs syntax tree formats

## Usecases
This is to serve as a simple file format that can be used in several contexts:
- As a parsing library within any editor that supports tree-sitter grammars.
  - at its simplest, using this parser is as simple as installing the tree-sitter library and editing your own `.actions` files! things like syntax highlighting, indentation, and folding should "just work" (knock on wood)
- As a core parsing library for downstream projects like the rust CLI im working on
  - Allows the bulk of the parsing to be done by this grammar, with things like the CLI and guis just using the tree to generate data and do their own functionality
    - In particular, being able to parse this data, put it into a proper data structure or even database, and then re-encode the data back into the `.actions` format is a key usecase
- As a reading tool for things like LLM agents who actually prefer viewing data as AST trees rather than plaintext when it comes to reading data

# Inspirations
- [Neovim](https://neovim.io/) was one of the first editors to use tree-sitter for syntax highlighting and code understanding and gave me a glimpse into the power and speed of tree-sitter
- [Todoist](https://www.todoist.com/) has been my main GTD tool, and while i want to create a FOSS alternative here, much of my design language has come from using todoist for years
  - in particular, the "quick add" syntax of todoist has been a big inspiration for the syntax of this file format
  - As well as deep calendar integration to allow tasks to be scheduled
  - I tinkered with creating a todoist client, but i feel uneasy about building projects around a closed source, proprietary API that may change at any time
- [Taskwarrior](https://taskwarrior.org/) showed the power we can get if we work with data rather than text alone.
  - They made the design decision to use entirely structured data, having people do commands that ultimately get saved in SQLite. A good, solid system but I love working in my editor, so having a plaintext format as the base ground upone which we can build feels more right for my sensibilities
  - [Azure Devops](https://azure.microsoft.com/en-us/products/devops) is what we use at my employer and while it has all the bad parts of microsoft, it also does a good job of placing the graph database as a core part of the application and has always stuck with me as a good example of how to think about tasks as more than just text
    - in particular, the ability to make hierarchical tasks, link tasks together, and have rich metadata has always been something ive wanted to see in a plaintext format
- [Neorg](https://github.com/nvim-neorg/neorg) is a tree-sitter based note taking system that uses treesitter as its core engine for parsing notes, and inspired me to think about how to use tree-sitter for my own plaintext formats
  - in addition, i feel neorg made many good syntactic decisions as well like the discipline of NOT using whitespace as parsing data.
    - The reason this file format exists rather than using Neorg directly is that Neorg is a big project that tries to do much more than actions, and it didnt feel right using it for this small purpose.
- [Org Mode](https://orgmode.org/) is the granddaddy of plaintext task and while, like neorg, it tries to do too much for my purpose, one cannot deny the power that org mode users enjoy and i believe that comes directly from a strong plaintext format specification that has built upon over decades from brilliant users.
- [todo.txt](todotxt.org) to show the power of simplicity in plaintext task management and being something that ive seen inspire many great engineers when using the most simple tools
  - Still, for this purpose, we needed more things than what we got

# Development and Testing

Tests are organized into `examples/`, `test/trees/`, and `test/corpus/` directories that work together to enable reuse by downstream projects.

Run tests:
```bash
npm run test:grammar
```

Regenerate tests after modifying the grammar or examples:
```bash
npm run regen:verify
```

For details on the test architecture, build system, and contributing workflow, see [docs/contributing.md](docs/contributing.md).
