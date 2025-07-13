# Tree-sitter Parser for Action(s) files
This is intended to be a small, purpose-built parser in alignment with the specification describes in [the specification file](./docs/action_specification.md) 

Please read the specification for more in-depth coverage on what is available within the format and why it was designed the way it was

Taking a step back, these action files can be used in a few ways:
- as a more structured alternative to `todo.txt` complete with a parser that can be used as structured data while still allowing for a document-first workflow
- as a part of a larger whole in the ClearHead Framework, serving as the children for stories
- in an alternative framework that is less opinionated. Maybe a more GTD-centric framework that wants to use the actions as children for projects

## Roadmap
While I am trying to be relatively minimal with the parser, only supporting what is needed, there is still a need to support features that may be needed by others to increase longevity in the future:
- [x] Status
- [x] Name
- [x] Description
- [x] Priority
- [x] Context (Tags)
- [x] Story 
    - (or Priority if thats what you want to use this for, but the parent)
- [-] Do Date/Time with Recurrance
    - [x] Do Date
    - [x] Do Time
    - [-] Recurrance
        - [x] Daily
        - [x] Weekly
        - [-] Monthly
        - [-] Yearly
        - [-] Custom
- [-] Due date/time
- [x] Completed Date/time
- [x] ID (UUID v7) 
    - (simply checks if its a valid UUID, version validation left to clients)
- [x] up to 5 layers of children with all above properties

## Deployment Targets
So far, there are two usecases i know I will be using this for:
- [-] Within Neovim to give various features for text editing including:
    - [-] Highlighting
    - [-] indentation
    - [-] folding
    - [-] hiding rules
    - [-] text objects
- [-] as a library within the cli for:
    - [-] structured analysis of documents
    - [-] ease in type-serialization and deserialization

## Testing
All features of the parser should be covered by tests within the `tests` folder and can be run using the standard `tree-sitter test` if you have the cli installed locally

One deviation we have made from other implementations is that tests actually reside split between three files:
1. the `test/test_descriptions.json` file which contains 3 layers:
  1. The file name of the corpus test each test belongs to
  2. the name of the test
  3. the description
2. an actions file within the `examples` file of the same name of the test
3. a sexp file within `test/sexp` which shows the expected output tree in s-exp format

we use `scripts/generate_tests` to read these files and generate the corpus tests themselves
- this is why the test folder itself is not only empty, but ignored in git as this is required to keep things tidy
- this was ultimately intended to make these tests and files more reuasable in other contexts

## Contributing
Ive really tried to keep this as simple as possible, relying entirely on basic treesitter rules and careful grammer design instead of funky priority rules
- no C so far so the entire grammer is in the rules currently
- no precedence rules, we use special characters to make the work disambiguous
- low reliance on whitespace for through the same reason as above, ensuring there isnt too much worrying about indentation, while also supporting multi-line actions for free
see the everything test for a good example

we handle special characters by escaping them with `\` instead of making precedence rules. this makes is harder to write but easier to parse from a grammar perspective

But contributions are welcomed via pull requests! 
- if you make changes to the grammar itself, please just be sure to add tests to cover the new conditions you add, and make sure the existing tests still pass.
If possible, we always want to check-in commits where all tests (both new and existing) are passing to give users a sense of stability even on the main branch
- If you want to suggest new things we SHOULD cover, go ahead and review the [specification](./docs/action_specification.md) and put proposed changes there so we can be sure it aligns with the larger document before implementing the idea within code
