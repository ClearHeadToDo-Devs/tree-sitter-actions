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

this means that there are currently no plans to add a top-level 'version' structure as we want to make sure that an action list made today will still be parsable 10 years from now, even if there are new features that have been added in that time.

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

## Align to strong foundations
to the degree possible, we try to adhere to the [action schema](https://schema.org/Action) defined at schema.org so that we are able to align with the larger semantic data community and leave the door open for interoperability in the future

and do note from the W3C consortium we define an Action as a subset of a [Thing](http://webschemas.appspot.com/Thing) from a schema perspective

## Dates, times, and repititions
we make repeated use of date formats in this file type.

we primarily follow the [icalendar standard](https://en.wikipedia.org/wiki/ICalendar) as these can be seen as specialized calendar events and a core usecase is the integration with calendar apps
dates, times, and durations will be written using the [ISO 8601 Date Standard](https://en.wikipedia.org/wiki/ISO_8601) 

this makes reading dates consistent and easily parsable by nearly any language while also aligning to the notation most expected by the international community 

while only some will take advantage of the extended functionality, they will all share the same base of the ISO 8601 standard
### Date Structure
As denoted, each file can be understood as a list of actions that the person intends to take.

ordering matters here so each part is intended to be done in sequence to again make the act of parsing easier and minimizing the amount of characters that need to be escaped within the main text chunks

both formats should be supported:
- YYYY-MM-DD
- YYYYMMDD

weekly formats should also be supported in cases where the ability for ambiguity is required (like do date)
- YYYY-www
- YYYYwww

ordinal dates are on a per-parser bases. for the time being, there is no need to support this unless there are requests for more generic date representations in specific parsing scenarios
#### Time
Time is denoted with the `T` character after the date and supports both extended and simplified formats:
- full
    - hh:mm:ss.sss
    - hhmmss.sss
- seconds
    - hh:mm:ss
    - hhmmss
- minutes
    - hh:mm
    - hhmm
- hour
    - hh
    - hh

if in an unambiguous context (like a child of an action due on a specific day) then simply listing the time should be sufficient, without the requirement of even a date

However, do note this will be implementation specific and will require more opinionated configuration than would otherwise be feasible for this work

remember, `00:00:00` denotes the INSTANT a day begins from a calculation perspective and can serve as a good default when needed for a time structure in more strictly typed languages

##### Timezones
Timezones are optional. if omited, local time is assumed as the standard suggests.

However, we should also note that the UTC offsets are accepted for the possibility of international parsing
- <time>Z (zero UTC offset)
- <time>+/-hh:mm
- <time>+/-hhmm
- <time>+/-hh

#### Durations
While a single day-time is the representation of a single time, we also want the ability to easily respresent the DURATION of this time

ISO 8601 covers this with the `P` designator

and has the following format:
- `P[n]Y[n]M[n]DT[n]H[n]M[n]S`
    - like the date format, each designator is preceded by the number of that period
    - durations that dont need a specific signifier, can simply omit it 
        - Full example: `P1Y2M3DT4H5M6S` is: 1 year, 2 Months, 3 Days, 4 Hours, 5 Minutes and 6 Seconds
        - pragmatic date example: `P1M` is: 1 Month
        - pragmatic hour example: `PT5M` is: 5 Minutes
            - note the `T` designator to disambiguate between the `M` for Month and Minutes respectively
- `P<date>T<time>`
    - This format is similar to the first, but instead simply uses a similar format as above to denote the duration
        - do note, standard logic applies, one cannot do an end time that would end up being 25 hours etc
            - full example: `P0001-02-03T04-05-06` is 1 year, 2 Months, 3 Days, 4 Hours, 5 Minutes and 6 Seconds just like above
##### Time Intervals
Therefore, we have a few formats for when we have to designate a duration AND a date
- `<start>/<end>`
- `<start>/<duration>`
- `<duration>/<end>`

While you CAN simply list a duration on its own, again, given the context enables it. 

However, great care must be taken to handle the inherent ambiguity around durations alone (if we say 2 months, that could be 28,29,30, or 31 days)

By contrast, if we put the duration after a proper date, then there is no ambiguity as we can calculate two months from that specific starting date rather than an arbitrary starting date

same goes for time and seconds due to leap seconds

### Repitition
Finally, we can denote that all the mechanics above can be used to REPEAT this period.

we primarily use the field [RFC 5545 section 3.8.5.3](https://datatracker.ietf.org/doc/html/rfc5545#section-3.8.5.3)  

using [RFC 5546 section 3.3.10](https://datatracker.ietf.org/doc/html/rfc5545#section-3.3.10) to define the format, only we use the fields more thoughtfully

We can add a repitition AFTER the date itself which serves as the "DSTART" value in the reccurance rule

We denote a repition with the `R` character

it should be noted what this DOES is try to calculate the event set if these events are to be exported into a calendar format which is a common usecase for this type of data

in the end this will be used to define the recurrance set which is the set of events that we plan to use with this work

#### Frequency
We can have the following frequencies:
- MI = Minutely
- H = Hourly
- D = Daily
- W = Weekly
- MO = Monthly
- Y = Yearly

This is the first field and the only MANDATORY one besides the start date itself. All other fields can go in whatever order is needed
##### Bounding the Repition
we immediately have values to bound these options:
- `U` = Until Date
    - End date of the repition
- `C` = Count
    - The MAXIMUM count of repitions allowd
- `I` = Interval
    - the interval of repition, defaulting to 1
        - so `D` with `I2` is a repition of every other day

###### Semantic Bounding
We also can bound them based on more calendar-specific formats:

The best way to think of this is that each frequency can use all bounds of LESS GRANULARITY.

So the by minute frequency can only use the "By Minute" property alonge with the ones above, by contrast, the "yearly" frequency can use every value possible to represent what it needs for a frequency
- `BMI` = By Minute
    - A list of integers between 0 and 60 representing which minute(s) in the hour to repeat
- `BH` = By Hour
    -   list of numbers between 0 and 23 representing what hour to repeat this within
- `BD` = By Day
    - an integer representing the numbered day in the week 
- `BMOD` = By Month Day
    - A list of days of the month
    - can accept negative and positive values
- `BMO` = By Month
    - List of ints representing months
## Depth (Required)
Every child action starts with atleast one `>` character. Children of a parent action can be denoted by `>>` and so-on down to the official limit of 5 levels of depth.
6 levels was chosen to conform with standard markdown conventions

all other symbols will be valid for child actions, and parsing should still be easy sivce they will all be preceded by the progression of `>` characters

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

we use the eisenhower matrix method as described in [the attached pdf](./Eisenhower-Matrix-Fillable.pdf)


## Story/Project (Optional)
An action may designate a parent project/story. in this case, the name of the story/project is used as the key for the sake of readability

designated by the `*` character, the same rules apply around escaping forbidden characters

otherwise actions are assumed to be unparented.

### Root Actions only
It should also be noted that only root actions can have a parent project/story.

It is assumed that any child action(s) are part of the parent action and do not need to be designated as part of a project

This radically reduces the complexity of the parser and allows for a more readable format, it also makes querying radically easier since it enables us to simply query for the root node of the tree and get all of the children without needing to do any special parsing


## Context (Optional)
We use the context in accordance with GTD to answer the where question often. 

started with the `+` character, one can use multiple contexts by separating each one with the `,` character to get multiple tags

contexts are simply keys and cannot be assigned values

## Do-Date/Time (Optional)
Actions can have a do-date, do-time, or both. This is designated by the `@` character. The format conforms to a simplified subset of ISO 8601.

- **Date**: A date is specified in `YYYY-MM-DD` format (e.g., `@2025-10-20`).
- **Time**: A time is specified in 24-hour `HH:MM` format (e.g., `@14:30`).
- **Date and Time**: A date and time are combined with a `T` separator: `YYYY-MM-DDTHH:MM` (e.g., `@2025-10-20T14:30`).

#### Duration (Optional)
We can give an optional duration after the time by supply the `D` character followed by a number that will be converted to minutes

this can look like a simple `D30` to mean a duration of 30 minutes

for application designers, durations are assumed to default to 15 minutes

##### Recurrance
We can use that do-date as simply a start date for a recurring task by adding the `R` Character followed by one of the following options for recurrance:
- `D` Daily
  - We can also put a list of time(s) to allow for the use-case of something that needs to be done multiple times a day (think medications)
- `W` Weekly
  - Can give a list of the day(s) of the week where you want this to recur {Mon, Tue, Wed, Thurs, Fri, Sat, Sun}
- `M` Monthly
  - Can list the week(s) to be recurred {1, 2, 3, 4, 5}
- `Y` Yearly
  - Can list the Month(s) this should be done {Jan, Feb, March, April, June, July, August, September, October, November, December}
- `C` Custom Data Recurrance
  - Can list which week(s) this should be done {1, 2, 3, 4, 5}
  - Can also list the day to be recurred {Mon, Tue, Wed, Thurs, Fri, Sat, Sun}
  - and time it needs to be done

  for any of these, its assumed that the recurrance adopts the date/time originally used for the do-date

  for example, if you do a weekly recurring action on tuesday and dont designate date, then the action assumed to be done every tuesday at the time you put

###### End Date
Recurrance is assumed to go on forever unless an end date is otherwise designated (i mean, you do need to take the trash out for the rest of your life?)

however, you can put an end date in the date with the `E` Character, followed by a standardized date/time format that we have covered in the other dates that we listed here

## Completed Date (Optional)

Intended to be added automatically by tooling when the state is changed to completed.

Started with the `%` character, this helps to determine the date/time the action was completed.

It follows the same format as the Do-Date/Time: `YYYY-MM-DD`, `HH:MM`, or `YYYY-MM-DDTHH:MM`.

## Id (Optional)
for this we are going to be using the v7 of the UUID standard.

the icon for this is `#` but is optional as we want to support the ability to create actions WITHOUT forcing the user to add a uuid manually before it is interpretted

### Implications
here, we are trying to leave the door open for applications to go in later and update this whole thing with automated tools such as the cli that will be able to review and update these ids after the user has created the initial version of the structure

# Examples
As we have laid out above, we have quite an array of options when it comes to how much or how little information to give.

To give the most minimal example possible, we can see below:
`[ ] Test Action`

This hopefully serves to show that these should be able to be short, with the ability to read for a human without structured editing able to go through

## Robust Example
As we saw, many optional pieces of context can be added so here is an example of an action that has much more of these optional parameters:

```actions
[x] Go to the store for chicken
    $ Make sure you get the stuff from the butcher directly
    !1 
    *Run Errands
+Driving,Store,Market
@2025-01-19T08:30D30
%2025-01-19T10:30
#214342414342413424
```

The succinct way to read this is that one had an action to go to the store on January 19th, 2025 as a part of their running errands project. 
The action was expected to take 30 minutes but was completed in about two hours as we can see by the completion time.
Finally, it was part of the Driving, Store, and Market contexts and contains extra instructions on where to get the chicken


## Adding Children
Finally, we will do a showcase of the format for those actions with child actions:
```actions
[ ] Parent Action >[ ] Child Action
```

# JSON Serialization Format
This section defines the canonical JSON serialization format for `.actions` files. Implementations that parse `.actions` files and convert them to structured data should follow this specification to ensure interoperability.

## Purpose
While the `.actions` format is designed to be human-readable plaintext, many applications need to:
- Convert parsed actions into structured data (JSON, databases, etc.)
- Validate serialized data programmatically
- Exchange action data between different tools
- Store actions in systems that require structured formats

This specification ensures all implementations serialize to the same JSON structure.

## Schema Location
The canonical JSON Schema is maintained in this repository at `schema/actions.schema.json` and is generated from the same source patterns used by the tree-sitter grammar to ensure consistency.

## Structure

### Root Document
The root JSON document is an object containing a flat array of all actions:

```json
{
  "actions": [
    // flat array of all action objects (hierarchy via parent_id)
  ]
}
```

### Action Object
Each action object has the following structure:

```json
{
  "state": "not_started",
  "name": "Action name",
  "description": "Optional description",
  "priority": 1,
  "story": "Project name",
  "contexts": ["context1", "context2"],
  "doDate": {
    "datetime": "2025-01-19T08:30",
    "duration": 30,
    "recurrence": {
      "frequency": "weekly",
      "interval": 1,
      "byDay": ["Mon", "Wed"]
    }
  },
  "completedDate": "2025-01-19T10:30",
  "id": "214342414342413424",
  "parent_id": null,
  "depth": 0
}
```

**Hierarchical Structure**: Actions are stored in a flat array. Hierarchy is represented via `parent_id` references and `depth` levels. This design:
- Simplifies queries (no recursive traversal needed for filtering)
- Maps directly to SQL storage (relational foreign keys)
- Enables efficient mutations (moving actions = changing parent_id)
- Maintains all information needed to reconstruct the tree for display

## Field Specifications

### Required Fields

#### `state` (string, required)
The current state of the action. Must be one of:
- `"not_started"` - Corresponds to `[ ]` in plaintext
- `"completed"` - Corresponds to `[x]` in plaintext
- `"in_progress"` - Corresponds to `[-]` in plaintext
- `"blocked"` - Corresponds to `[=]` in plaintext
- `"cancelled"` - Corresponds to `[_]` in plaintext

**Type**: String enum
**Pattern**: `^(not_started|completed|in_progress|blocked|cancelled)$`

#### `name` (string, required)
The name/title of the action. This serves as a secondary key (after ID) for human readability.

**Type**: String
**Min Length**: 1
**Pattern**: Must not contain unescaped metadata marker characters (`$!*+@%#>`)

### Optional Fields

#### `description` (string, optional)
Long-form description of the action. Corresponds to `$` metadata in plaintext.

**Type**: String
**Omit if**: Not present in source

#### `priority` (integer, optional)
Numeric priority level. Corresponds to `!` metadata in plaintext.

**Type**: Integer
**Minimum**: 0
**Omit if**: Not present in source

#### `story` (string, optional)
Parent project/story name. Corresponds to `*` metadata in plaintext.
Only valid for root-level actions.

**Type**: String
**Pattern**: Must not contain unescaped metadata marker characters
**Omit if**: Not present in source

#### `contexts` (array, optional)
Array of context tags. Corresponds to `+` metadata in plaintext.
The plaintext comma-separated list is split into array elements.

**Type**: Array of strings
**Pattern (each element)**: Must not contain unescaped metadata marker characters or commas
**Omit if**: Not present in source

#### `doDate` (object, optional)
Scheduled date/time for the action. Corresponds to `@` metadata in plaintext.

**Type**: Object with the following fields:
- `datetime` (string, required): ISO 8601 formatted date/time
- `duration` (integer, optional): Duration in minutes
- `recurrence` (object, optional): Recurrence rule (see Recurrence Object below)

**Omit if**: Not present in source

##### Recurrence Object
When present within `doDate`, defines how the action repeats:

```json
{
  "frequency": "daily",
  "interval": 1,
  "count": 10,
  "until": "2025-12-31",
  "byMinute": [0, 15, 30, 45],
  "byHour": [9, 17],
  "byDay": ["Mon", "Wed", "Fri"],
  "byMonthDay": [1, 15],
  "byMonth": [1, 6, 12]
}
```

**Fields**:
- `frequency` (string, required): One of `"minutely"`, `"hourly"`, `"daily"`, `"weekly"`, `"monthly"`, `"yearly"`
- `interval` (integer, optional): Interval between recurrences (default: 1)
- `count` (integer, optional): Maximum number of occurrences
- `until` (string, optional): End date in ISO 8601 format
- `byMinute` (array of integers, optional): Minutes within the hour [0-60]
- `byHour` (array of integers, optional): Hours within the day [0-23]
- `byDay` (array of strings, optional): Days of the week ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
- `byMonthDay` (array of integers, optional): Days of the month (negative values count from end)
- `byMonth` (array of integers, optional): Months [1-12]

#### `completedDate` (string, optional)
ISO 8601 formatted date/time when the action was completed. Corresponds to `%` metadata in plaintext.
Typically added automatically by tooling when state changes to `completed`.

**Type**: String (ISO 8601)
**Omit if**: Not present in source

#### `id` (string, optional)
UUIDv7 identifier for the action. Corresponds to `#` metadata in plaintext.

**Type**: String
**Pattern**: `^[0-9a-fA-F-]+$` (UUID format)
**Omit if**: Not present in source

#### `parent_id` (string or null, optional)
UUID of the parent action. Null (or omitted) for root-level actions. Corresponds to the hierarchy level indicated by `>` prefixes in plaintext.

**Type**: String (UUID format) or null
**Pattern**: `^[0-9a-fA-F-]+$` (when not null)
**Default**: null (root action)
**Omit if**: Root action (depth = 0)

#### `depth` (integer, optional)
Nesting level of the action. Root actions have depth 0, their children have depth 1, etc. Matches the number of `>` prefixes in plaintext format.

**Type**: Integer
**Range**: 0-5 (matching plaintext depth limit)
**Default**: 0
**Omit if**: Root action (depth = 0)

**Note**: The `depth` field can be computed from `parent_id` by walking up the parent chain, but including it explicitly enables efficient queries without joins.

## Type Mappings

| Plaintext | JSON Type | Notes |
|-----------|-----------|-------|
| State marker `[x]` | String enum | Mapped to readable names |
| Priority `!1` | Integer | Numeric value only |
| Contexts `+a,b,c` | Array of strings | Split on comma |
| Do-date `@2025-01-19` | String (ISO 8601) | Within `doDate.datetime` |
| Duration `D30` | Integer | Minutes, within `doDate.duration` |
| Completed `%2025-01-19` | String (ISO 8601) | Direct mapping |
| UUID `#abc-123` | String | Direct mapping |
| Children `>` | String (UUID) | Parent's UUID in `parent_id` field |
| Depth level `>>`| Integer | Count of `>` markers in `depth` field |

## Optional Field Handling

Implementations should **omit** optional fields from JSON when they are not present in the source `.actions` file, rather than including them with `null` values. This keeps the JSON clean and minimal.

**Example**:
```json
// Good - minimal action
{
  "state": "not_started",
  "name": "Simple task"
}

// Avoid - unnecessary nulls
{
  "state": "not_started",
  "name": "Simple task",
  "description": null,
  "priority": null,
  "contexts": null
}
```

## Complete Example

Given this plaintext `.actions` file:
```actions
[x] Go to the store for chicken
    $ Make sure you get the stuff from the butcher directly
    !1
    *Run Errands
+Driving,Store,Market
@2025-01-19T08:30D30
%2025-01-19T10:30
#214342414342413424
>[ ] Get chicken from butcher
>>[-] Ask for organic options
```

The canonical JSON serialization is:
```json
{
  "actions": [
    {
      "state": "completed",
      "name": "Go to the store for chicken",
      "description": "Make sure you get the stuff from the butcher directly",
      "priority": 1,
      "story": "Run Errands",
      "contexts": ["Driving", "Store", "Market"],
      "doDate": {
        "datetime": "2025-01-19T08:30",
        "duration": 30
      },
      "completedDate": "2025-01-19T10:30",
      "id": "214342414342413424",
      "parent_id": null,
      "depth": 0
    },
    {
      "state": "not_started",
      "name": "Get chicken from butcher",
      "id": "018e3c2a-1234-7890-abcd-ef1234567890",
      "parent_id": "214342414342413424",
      "depth": 1
    },
    {
      "state": "in_progress",
      "name": "Ask for organic options",
      "id": "018e3c2b-5678-7890-abcd-ef1234567890",
      "parent_id": "018e3c2a-1234-7890-abcd-ef1234567890",
      "depth": 2
    }
  ]
}
```

**Note**: Actions are stored in a flat array. The parent-child relationships are expressed through `parent_id` references. To reconstruct the tree for display:
1. Filter actions where `parent_id` is null to get root actions
2. For each action, find children where `parent_id` matches the action's `id`
3. Use `depth` field for efficient indentation without recursive counting

## Validation

All JSON output should validate against the JSON Schema provided at `schema/actions.schema.json` in this repository. The schema is generated from the same regex patterns used by the tree-sitter grammar to ensure parsing and validation are consistent.

---

# SQL Storage Schema

## Purpose

While the `.actions` format is designed as human-readable plaintext and JSON enables data interchange, many applications require persistent relational storage for:

- **Complex queries with indexes** - Efficiently find actions by priority, context, due date, etc.
- **Multi-user concurrent access** - Multiple clients querying and updating the same dataset
- **Transactional updates** - Ensure data consistency when modifying related actions
- **Integration with existing systems** - Work alongside other database-backed applications
- **Performance at scale** - Handle thousands of actions with indexed queries

This section defines the canonical SQL schema for storing `.actions` data in relational databases.

## Schema Location

The canonical SQL schema is maintained at `schema/actions.sql` in the repository. It is designed for SQLite for maximum portability, but can be adapted for PostgreSQL, MySQL, or other relational databases.

## Design Philosophy

The schema prioritizes:

1. **Normalization** - Separate tables for multi-valued fields (contexts, recurrence) to enable efficient querying
2. **Performance** - Indexes on commonly-queried fields (state, priority, due date, story)
3. **Data integrity** - Foreign keys, constraints, CHECK clauses enforce format rules
4. **Simplicity** - Standard SQL features, minimal database-specific functionality
5. **Interoperability** - Tools using this schema can share databases and exchange data

## Schema Definition

### Core Tables

#### `actions` Table

Stores the main action data with one row per action. Hierarchical structure is represented via self-referencing `parent_id`.

```sql
CREATE TABLE actions (
    id TEXT PRIMARY KEY,
    parent_id TEXT REFERENCES actions(id) ON DELETE CASCADE,
    state TEXT NOT NULL CHECK(state IN ('not_started', 'completed', 'in_progress', 'blocked', 'cancelled')),
    name TEXT NOT NULL,
    description TEXT,
    priority INTEGER CHECK(priority >= 0),
    story TEXT,
    do_datetime TEXT,          -- ISO 8601 format
    do_duration INTEGER,        -- Duration in minutes
    completed_datetime TEXT,    -- ISO 8601 format
    depth INTEGER NOT NULL DEFAULT 0 CHECK(depth >= 0 AND depth <= 5)
);

-- Indexes for common queries
CREATE INDEX idx_actions_state ON actions(state);
CREATE INDEX idx_actions_priority ON actions(priority);
CREATE INDEX idx_actions_story ON actions(story);
CREATE INDEX idx_actions_do_datetime ON actions(do_datetime);
CREATE INDEX idx_actions_parent ON actions(parent_id);
CREATE INDEX idx_actions_depth ON actions(depth);
```

**Fields:**
- `id` - UUIDv7 identifier (optional in plaintext, generated if not provided)
- `parent_id` - Self-reference for hierarchical actions. NULL for root actions
- `state` - Current state, constrained to valid values
- `name` - Action name/title (required)
- `description` - Optional long-form description
- `priority` - Numeric priority (NULL if not specified)
- `story` - Parent project/story name (only for root actions where depth=0)
- `do_datetime` - Scheduled date/time in ISO 8601 format
- `do_duration` - Duration in minutes (NULL if not specified)
- `completed_datetime` - Completion timestamp in ISO 8601 format
- `depth` - Nesting level (0=root, 1-5=child depths)

#### `action_contexts` Table

Normalized storage for the multi-valued contexts field. Allows efficient querying by context.

```sql
CREATE TABLE action_contexts (
    action_id TEXT NOT NULL REFERENCES actions(id) ON DELETE CASCADE,
    context TEXT NOT NULL,
    PRIMARY KEY (action_id, context)
);

CREATE INDEX idx_action_contexts_context ON action_contexts(context);
```

**Why normalized?**
Enables efficient queries like "all actions in the 'work' context" without string parsing:
```sql
SELECT a.* FROM actions a
JOIN action_contexts c ON a.id = c.action_id
WHERE c.context = 'work';
```

#### `action_recurrence` Table

Stores recurrence rules for recurring actions. One row per action with recurrence.

```sql
CREATE TABLE action_recurrence (
    action_id TEXT PRIMARY KEY REFERENCES actions(id) ON DELETE CASCADE,
    frequency TEXT NOT NULL CHECK(frequency IN ('minutely', 'hourly', 'daily', 'weekly', 'monthly', 'yearly')),
    interval INTEGER DEFAULT 1 CHECK(interval >= 1),
    count INTEGER CHECK(count >= 1),
    until_date TEXT,            -- ISO 8601 format
    by_minute TEXT,             -- JSON array: [0, 15, 30]
    by_hour TEXT,               -- JSON array: [9, 17]
    by_day TEXT,                -- JSON array: ["Mon", "Wed"]
    by_month_day TEXT,          -- JSON array: [1, 15, -1]
    by_month TEXT               -- JSON array: [1, 6, 12]
);
```

**Note on JSON fields:**
The `by_*` fields store JSON arrays for simplicity in SQLite. Databases with native array support (PostgreSQL) can use array types instead.

### Helper Views

#### `actions_with_contexts` View

Denormalized view joining actions with their contexts for convenient querying.

```sql
CREATE VIEW actions_with_contexts AS
SELECT
    a.*,
    GROUP_CONCAT(c.context, ',') as contexts
FROM actions a
LEFT JOIN action_contexts c ON a.id = c.action_id
GROUP BY a.id;
```

## Type Mappings

Translation between plaintext, JSON, and SQL representations:

| Plaintext | JSON Type | SQL Type | SQL Table | Notes |
|-----------|-----------|----------|-----------|-------|
| State `[x]` | String enum | `TEXT CHECK(...)` | `actions.state` | Enforced with CHECK constraint |
| Name | String | `TEXT NOT NULL` | `actions.name` | Required field |
| Description `$` | String | `TEXT` | `actions.description` | NULL if not present |
| Priority `!1` | Integer | `INTEGER CHECK(>= 0)` | `actions.priority` | NULL if not present |
| Story `*` | String | `TEXT` | `actions.story` | NULL if not present, only for root actions |
| Contexts `+a,b` | Array of strings | Separate table | `action_contexts` | Normalized for querying |
| Do-date `@` | String (ISO 8601) | `TEXT` | `actions.do_datetime` | Stored as ISO 8601 string |
| Duration `D30` | Integer (minutes) | `INTEGER` | `actions.do_duration` | NULL if not present |
| Recurrence `R` | Object | Separate table | `action_recurrence` | NULL if not recurring |
| Completed `%` | String (ISO 8601) | `TEXT` | `actions.completed_datetime` | NULL if not completed |
| UUID `#` | String | `TEXT PRIMARY KEY` | `actions.id` | Generated if not provided |
| Children `>` | Nested array | `parent_id` self-reference | `actions.parent_id` | Hierarchical via foreign key |

## Design Decisions

### Why normalize contexts into a separate table?

**Benefit:** Enables efficient filtering and aggregation
```sql
-- Find all actions in 'work' context
SELECT a.* FROM actions a
JOIN action_contexts c ON a.id = c.action_id
WHERE c.context = 'work';

-- Count actions by context
SELECT context, COUNT(*) FROM action_contexts GROUP BY context;
```

**Alternative:** Store as JSON array or comma-separated TEXT
**Trade-off:** Simpler schema, but requires string parsing or JSON functions for queries

### Why store dates as TEXT instead of DATE/TIMESTAMP?

**Benefit:** Preserves full ISO 8601 format including timezone information
**Benefit:** Portable across databases (SQLite has limited date types)
**Benefit:** Matches JSON format exactly

**Note:** SQL date functions can still operate on ISO 8601 TEXT:
```sql
-- SQLite
SELECT * FROM actions WHERE date(do_datetime) = date('now');

-- PostgreSQL
SELECT * FROM actions WHERE do_datetime::timestamp >= NOW();
```

### Why use parent_id instead of a closure table?

**Rationale:** The format limits nesting to 5 levels, making a simple parent_id sufficient

**Benefit:** Simple schema, easy to understand
**Trade-off:** Queries for "all descendants" require recursive CTEs

**For deep tree queries:**
```sql
-- Get all descendants of an action (SQLite/PostgreSQL)
WITH RECURSIVE descendants AS (
  SELECT * FROM actions WHERE id = ?
  UNION ALL
  SELECT a.* FROM actions a
  JOIN descendants d ON a.parent_id = d.id
)
SELECT * FROM descendants;
```

**Alternative:** Add a closure table for applications needing frequent tree traversal

### Why separate table for recurrence?

**Rationale:** Most actions don't recur - normalization saves space
**Benefit:** Clean separation of concerns
**Benefit:** Easy to query "all recurring actions"

## Example Queries

### Basic Filters

**All P1 actions:**
```sql
SELECT * FROM actions WHERE priority = 1;
```

**All completed actions:**
```sql
SELECT * FROM actions WHERE state = 'completed';
```

**Actions in 'work' context:**
```sql
SELECT a.* FROM actions a
JOIN action_contexts c ON a.id = c.action_id
WHERE c.context = 'work';
```

**Actions in 'work' OR 'urgent' context:**
```sql
SELECT DISTINCT a.* FROM actions a
JOIN action_contexts c ON a.id = c.action_id
WHERE c.context IN ('work', 'urgent');
```

### Date Queries

**Actions due today:**
```sql
SELECT * FROM actions
WHERE date(do_datetime) = date('now');
```

**Actions due this week:**
```sql
SELECT * FROM actions
WHERE do_datetime >= date('now', 'weekday 0', '-7 days')
  AND do_datetime < date('now', 'weekday 0');
```

**Overdue not-started actions:**
```sql
SELECT * FROM actions
WHERE state = 'not_started'
  AND do_datetime < datetime('now');
```

### Aggregate Queries

**Completion rate by project:**
```sql
SELECT
  story,
  COUNT(*) as total,
  SUM(CASE WHEN state = 'completed' THEN 1 ELSE 0 END) as completed,
  ROUND(100.0 * SUM(CASE WHEN state = 'completed' THEN 1 ELSE 0 END) / COUNT(*), 2) as completion_rate
FROM actions
WHERE story IS NOT NULL AND depth = 0
GROUP BY story;
```

**Action count by state:**
```sql
SELECT state, COUNT(*) as count
FROM actions
GROUP BY state
ORDER BY count DESC;
```

**Priority distribution:**
```sql
SELECT
  COALESCE(priority, 999) as priority,
  COUNT(*) as count
FROM actions
GROUP BY priority
ORDER BY priority;
```

### Hierarchical Queries

**Root actions only:**
```sql
SELECT * FROM actions WHERE parent_id IS NULL;
-- Or equivalently:
SELECT * FROM actions WHERE depth = 0;
```

**Actions with children:**
```sql
SELECT DISTINCT p.* FROM actions p
JOIN actions c ON c.parent_id = p.id;
```

**Immediate children of an action:**
```sql
SELECT * FROM actions WHERE parent_id = ?;
```

**All descendants (recursive):**
```sql
WITH RECURSIVE descendants AS (
  SELECT * FROM actions WHERE id = ?
  UNION ALL
  SELECT a.* FROM actions a
  JOIN descendants d ON a.parent_id = d.id
)
SELECT * FROM descendants WHERE id != ?;  -- Exclude the parent itself
```

### Complex Queries

**P1 actions in 'work' context due this week:**
```sql
SELECT a.* FROM actions a
JOIN action_contexts c ON a.id = c.action_id
WHERE a.priority = 1
  AND c.context = 'work'
  AND a.do_datetime >= date('now', 'weekday 0', '-7 days')
  AND a.do_datetime < date('now', 'weekday 0');
```

**Blocked actions with no children:**
```sql
SELECT a.* FROM actions a
LEFT JOIN actions c ON c.parent_id = a.id
WHERE a.state = 'blocked'
  AND c.id IS NULL;
```

**Actions with multiple contexts:**
```sql
SELECT action_id, COUNT(*) as context_count
FROM action_contexts
GROUP BY action_id
HAVING COUNT(*) > 1;
```

## Importing from JSON

Example of loading JSON data into the SQL schema:

```sql
-- Using SQLite JSON functions
-- Assuming you have a 'json_data' column with the full JSON

-- Insert root actions
INSERT INTO actions (id, state, name, description, priority, story, do_datetime, do_duration, completed_datetime, depth)
SELECT
  json_extract(value, '$.id'),
  json_extract(value, '$.state'),
  json_extract(value, '$.name'),
  json_extract(value, '$.description'),
  json_extract(value, '$.priority'),
  json_extract(value, '$.story'),
  json_extract(value, '$.doDate.datetime'),
  json_extract(value, '$.doDate.duration'),
  json_extract(value, '$.completedDate'),
  0  -- Root actions have depth 0
FROM json_each((SELECT json_data FROM import_table), '$.actions');

-- Insert contexts
INSERT INTO action_contexts (action_id, context)
SELECT
  json_extract(action.value, '$.id'),
  context.value
FROM json_each((SELECT json_data FROM import_table), '$.actions') as action,
     json_each(json_extract(action.value, '$.contexts')) as context;
```

For more examples, see `examples/queries/sql/` in the repository.

## Database-Specific Adaptations

### PostgreSQL

**Type changes:**
```sql
-- Use VARCHAR with lengths
name VARCHAR(500) NOT NULL

-- Native array types for contexts
CREATE TABLE actions (
  ...
  contexts TEXT[]  -- Instead of separate table
);

-- Or use JSONB for recurrence fields
by_day JSONB  -- Instead of TEXT
```

**Advantages:**
- Native array operations
- JSONB query capabilities
- Better full-text search (tsvector)

### MySQL

**Type changes:**
```sql
-- Add VARCHAR lengths
name VARCHAR(500) NOT NULL

-- Use DATETIME instead of TEXT for dates
do_datetime DATETIME

-- Use ENUM for state (optional)
state ENUM('not_started', 'completed', 'in_progress', 'blocked', 'cancelled')
```

### General Adaptations

**Add timestamps:**
```sql
ALTER TABLE actions ADD COLUMN created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP;
ALTER TABLE actions ADD COLUMN updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;
```

**Add soft deletes:**
```sql
ALTER TABLE actions ADD COLUMN deleted_at TIMESTAMP NULL;
CREATE INDEX idx_actions_deleted ON actions(deleted_at);
```

**Add user ownership:**
```sql
ALTER TABLE actions ADD COLUMN user_id INTEGER REFERENCES users(id);
CREATE INDEX idx_actions_user ON actions(user_id);
```

## Validation

Tools implementing this schema should:

1. Validate that imported JSON conforms to `schema/actions.schema.json`
2. Enforce foreign key constraints (ensure parent_id references valid actions)
3. Maintain depth consistency (parent depth + 1 = child depth)
4. Ensure story is only set for root actions (depth = 0)
5. Validate ISO 8601 format for date fields before insertion

## Further Reading

- See `schema/actions.sql` for the complete reference implementation
- See `examples/queries/sql/` for more query examples
- See `examples/queries/jq/` for JSON manipulation before SQL import
