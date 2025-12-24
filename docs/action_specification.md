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

