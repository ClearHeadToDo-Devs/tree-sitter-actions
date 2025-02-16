---
title: Actions file specification
description: File Specification for the actions filetype
author: primary_desktop
categories: Reference
created: 2025-01-19T03:16:49-0800
updated: 2025-01-20T00:04:29-0800
version: 1.1.1
---
This specification will lay out the formal specifications for the `actions` filetype, usually denoted by a `*.actions` file.


# High-Level Guidelines

This specification will attempt to maintain backwards compatibility. That is, we will only add backwards-compatible changes to prevent implement's from dealing with breaking changes in the specification.


## plaintext implications

Fundamentally, the `actions` filetype is a list of actions that can be formally parsed in a machine-readable way while still being readable and writable with any application the user chooses
As such, great care is taken to minimize the amount of characters that need to be typed by a human, while being considerate to readability of the core file

Special considerations should be made to the readable nature of the document, and how this can result in design decisions that would not normally be taken within a database.
For example, the name should be considered a secondary key for the action. While we will have an ID that will ensure universal uniqueness, the plaintext nature of this solution lends itself to using the name as a natural key
This could result in a situation where other filetypes are using the name of the action rather than the id to identify it
As such, one should be considerate about creating default names for actions as this could lead to name collision within the implementation, and should instead use some form of pattern to create new actions automatically without having name collision (maybe default to UUID of action?)

## Parser Guidance

With that said, it is also a use-case that these files are able to be read by a formal parser to allow for data extraction and the potential for placing these pieces of data into a schema

Finally, in terms of rules-processing, we take the approach of newer markdown formats like neorg which deemphasize the importance of whitespace to denote depth.
Instead, we use explicit characters or a sequence of characters to make the act of parsing this work cleaner

# Structure

As denoted, each file can be understood as a list of actions that the person intends to take.

ordering matters here so each part is intended to be done in sequence to again make the act of parsing easier and minimizing the amount of characters that need to be escaped within the main text chunks

## Depth (Required)

Every child action starts with atleast one `>` character. Children of a parent action can be denoted by `>>` and so-on down to the official limit of 5 levels of depth.
6 levels was chosen to conform with standard markdown conventions

all other symbols will be valid for child actions, and parsing should still be easy since they will all be preceded by the progression of `>` characters


### Adding Children

Children actions should be added to the end of an action to leave the context closer to the name of the action. 
Children should be the last thing in the chain before the completion-date/Id

As such, child actions are encapsulated within the parent to make for easy parsing
styling around indentation is left up to the implementors, it should NOT be important to parsing the document


## State (Required)

We want to accomodate a few more states than done and not done, so we put the state between the `(` and the `)` characters
The options for states are as follows:
- ` ` Not Started (default)
- `x` Completed
- `-` In-Progress (for work-in-progress limits)
- `=` Blocked/Awaiting
- `_` Cancelled (for historical systems)

This and the depth constitute the primary "marker" for the start of an action, making both parsing and reading easier since you can easily scan for the beginning of the next action visually on the screen


## Name (Required)

The final required field is the name of the action itself. 

Due to the nature of the format, special characters will need to be escaped with the  character
The list of special characters that need to be escaped are below:
- `$` - Reserved for Descriptions
- `!` - Reserved for Priority
- `*` - Reserved for Stories/Projects
- `+` - Reserved for contexts
- `@` - Reserved for Do-Date-Time
- `%` - Reserved for Completed Date
- `>` - Reserved for Children

Otherwise, this is one of the more encompassing fields where users are allowed to write as much as they like, even newlines

however, do note the point above about using names as secondary keys so if something is going to be really long, save it for the description section below

### Description (optional)

The name fields status as a secondary key means that it is sometimes necessary to denote a longer description for an action

this is where the description comes in and we can start one at any point within our name field within the `$` character

However, the rules around escaping still apply to ensure easy parsing


## Priority (Optional)

Priority can be designated at any time with the `!` character followed by a number.

While there is no limit, it is encourage to support around 4 levels of priority atleast to support the eisenhower method


## Story/Project (Optional)

An action may designate a parent project/story. in this case, the name of the story/project is used as the key for the sake of readability

designated by the `*` character, the same rules apply around escaping forbidden characters

otherwise actions are assumed to be unparented.


## Context (Optional)

We use the context in accordance with GTD to answer the where question often. 

started with the `+` character, one can use multiple contexts by separating each one with the `,` character to get multiple tags

contexts are simply keys and cannot be assigned values


## Do-Date/Time (Optional)

actions can have a full date/time designated using the standard "YYYY-MM-DD" format after an initial `@` character

this allows systems that require a future data to utilize this for parsing, while still being optional in designation


### Time (Optional)

Time can either be added after the date, or given directly

The format will be the standard "HH:MM" in military time or "HH:MMam/pm" to designate time of day

If given directly it can be added directly after the `@` character

However, if given as an addition to the date, then it must be preceded by a `T` character


#### Duration (Optional)

Finally, we can give an optional duration after the time by supply the `D` character followed by a number that will be converted to minutes


## Completed Date (Optional)

Intended to be added automatically by tooling when the state is changed to completed.

Started with the `%` character, this helps to determine the date/time the action was completed.

follows the same rules as the Do-Date covered above

# Examples

As we have laid out above, we have quite an array of options when it comes to how much or how little information to give.

To give the most minimal example possible, we can see below:
`<( )Test Action>0194811d-afd0-797d-86de-f51376a33dbb`

the ease of parsing should allow most editors to automatically hide the ID, giving the writer a more pleasant viewing experience, while still giving the metadata the systems will need to identify the action universally


## Robust Example

As we saw, many optional pieces of context can be added so here is an example of an action that has much more of these optional parameters:

```actions
- (x)Go to the store for chicken
$ Make sure you get the stuff from the butcher directly
!1 *Run Errands
+Driving,Store,Market
@2025-01-19T08:30D30
%2025-01-19T10:30
```

The succinct way to read this is that one had an action to go to the store on January 19th, 2025 as a part of their running errands project. 
The action was expected to take 30 minutes but was completed in about two hours as we can see by the completion time.
Finally, it was part of the Driving, Store, and Market contexts and contains extra instructions on where to get the chicken


## Adding Children

Finally, we will do a showcase of the format for those actions with child actions:
```actions
-( ) Parent Action --( ) Child Action
```
Notice how the UUIDs cluster at the end, this allows the document to remain more readable as the ids will often be clustered at the end of the document and naturally flow into one-another


