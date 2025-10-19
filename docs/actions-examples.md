# Actions Vocabulary Examples

This document provides practical examples of using the Actions Vocabulary in different RDF serializations and with various SPARQL queries.

## RDF Serialization Examples

### Turtle Example

```turtle
@prefix actions: <https://vocab.example.org/actions/> .
@prefix schema: <http://schema.org/> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

# Root action with project and priority
:task1 a actions:RootAction, actions:ProjectAction ;
    schema:name "Redesign company website" ;
    schema:description "Complete overhaul of the corporate website with modern design" ;
    actions:state actions:InProgress ;
    actions:depth 1 ;
    actions:project "Website Redesign" ;
    actions:priority 2 ;
    actions:context "computer", "design" ;
    actions:doDateTime "2025-02-01T09:00:00"^^xsd:dateTime ;
    actions:durationMinutes 480 ;
    schema:identifier "01924567-89ab-7def-8123-456789abcdef" ;
    actions:childAction :task2, :task3, :task4 .

# Child action - wireframes
:task2 a actions:ChildAction ;
    schema:name "Create wireframes for all pages" ;
    actions:state actions:Completed ;
    actions:depth 2 ;
    actions:context "design", "computer" ;
    actions:doDate "2025-01-20"^^xsd:date ;
    actions:durationMinutes 120 ;
    actions:completedDateTime "2025-01-20T15:30:00"^^xsd:dateTime ;
    actions:parentAction :task1 ;
    actions:childAction :task5 .

# Grandchild action
:task5 a actions:ChildAction ;
    schema:name "Design mobile wireframes" ;
    actions:state actions:Completed ;
    actions:depth 3 ;
    actions:context "design", "mobile" ;
    actions:completedDateTime "2025-01-20T14:00:00"^^xsd:dateTime ;
    actions:parentAction :task2 .

# Child action - development
:task3 a actions:ChildAction ;
    schema:name "Implement responsive layout" ;
    actions:state actions:NotStarted ;
    actions:depth 2 ;
    actions:context "coding", "computer" ;
    actions:doDate "2025-02-15"^^xsd:date ;
    actions:durationMinutes 360 ;
    actions:parentAction :task1 .

# Child action - testing  
:task4 a actions:ChildAction ;
    schema:name "Cross-browser testing" ;
    actions:state actions:NotStarted ;
    actions:depth 2 ;
    actions:context "testing", "computer" ;
    actions:doDate "2025-03-01"^^xsd:date ;
    actions:durationMinutes 180 ;
    actions:parentAction :task1 .

# Recurring action example
:task6 a actions:RootAction, actions:RecurringAction ;
    schema:name "Weekly team standup" ;
    actions:state actions:NotStarted ;
    actions:depth 1 ;
    actions:project "Team Management" ;
    actions:context "meeting", "video-call" ;
    actions:doDateTime "2025-01-20T09:00:00"^^xsd:dateTime ;
    actions:durationMinutes 30 ;
    actions:recurrenceFrequency "WEEKLY" ;
    actions:recurrenceInterval 1 ;
    actions:byDay "Mon", "Wed", "Fri" ;
    actions:recurrenceUntil "2025-12-31"^^xsd:date .

# GTD context action
:task7 a actions:RootAction ;
    schema:name "Call insurance company about claim" ;
    actions:state actions:Blocked ;
    actions:depth 1 ;
    actions:context "phone", "waiting-for" ;
    actions:priority 3 .
```

### JSON-LD Example

```json
{
  "@context": {
    "actions": "https://vocab.example.org/actions/",
    "schema": "http://schema.org/",
    "xsd": "http://www.w3.org/2001/XMLSchema#"
  },
  "@graph": [
    {
      "@id": "_:task1",
      "@type": ["actions:RootAction", "actions:ProjectAction", "schema:Action"],
      "schema:name": "Redesign company website",
      "schema:description": "Complete overhaul of the corporate website with modern design",
      "actions:state": {"@id": "actions:InProgress"},
      "actions:depth": 1,
      "actions:project": "Website Redesign",
      "actions:priority": 2,
      "actions:context": ["computer", "design"],
      "actions:doDateTime": {
        "@type": "xsd:dateTime",
        "@value": "2025-02-01T09:00:00"
      },
      "actions:durationMinutes": 480,
      "schema:identifier": "01924567-89ab-7def-8123-456789abcdef",
      "actions:childAction": [
        {"@id": "_:task2"},
        {"@id": "_:task3"},
        {"@id": "_:task4"}
      ]
    },
    {
      "@id": "_:task2",
      "@type": ["actions:ChildAction", "schema:Action"],
      "schema:name": "Create wireframes for all pages",
      "actions:state": {"@id": "actions:Completed"},
      "actions:depth": 2,
      "actions:context": ["design", "computer"],
      "actions:doDate": {
        "@type": "xsd:date",
        "@value": "2025-01-20"
      },
      "actions:durationMinutes": 120,
      "actions:completedDateTime": {
        "@type": "xsd:dateTime", 
        "@value": "2025-01-20T15:30:00"
      },
      "actions:parentAction": {"@id": "_:task1"},
      "actions:childAction": [{"@id": "_:task5"}]
    },
    {
      "@id": "_:task6",
      "@type": ["actions:RootAction", "actions:RecurringAction", "schema:Action"],
      "schema:name": "Weekly team standup",
      "actions:state": {"@id": "actions:NotStarted"},
      "actions:project": "Team Management",
      "actions:context": ["meeting", "video-call"],
      "actions:doDateTime": {
        "@type": "xsd:dateTime",
        "@value": "2025-01-20T09:00:00"
      },
      "actions:durationMinutes": 30,
      "actions:recurrenceFrequency": "WEEKLY",
      "actions:recurrenceInterval": 1,
      "actions:byDay": ["Mon", "Wed", "Fri"],
      "actions:recurrenceUntil": {
        "@type": "xsd:date",
        "@value": "2025-12-31"
      }
    }
  ]
}
```

## SPARQL Query Examples

### 1. Find All Actions in a Project

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?action ?name ?state ?depth
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:state ?state ;
          actions:depth ?depth .
  
  # Either the action itself has the project, or its root parent does
  {
    ?action actions:project "Website Redesign" .
  } UNION {
    ?action actions:parentAction+ ?root .
    ?root actions:project "Website Redesign" .
  }
}
ORDER BY ?depth ?name
```

### 2. Get Next Actions by Context (GTD Style)

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?action ?name ?project ?priority
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:state actions:NotStarted ;
          actions:context ?context .
  
  FILTER(CONTAINS(?context, "computer"))
  
  # Only show actions that don't have incomplete children
  FILTER NOT EXISTS {
    ?action actions:childAction ?child .
    ?child actions:state ?childState .
    FILTER(?childState != actions:Completed)
  }
  
  OPTIONAL { ?action actions:project ?project }
  OPTIONAL { ?action actions:priority ?priority }
}
ORDER BY ?priority ?name
```

### 3. Project Progress Report

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?project 
       (COUNT(?total) as ?totalActions)
       (COUNT(?completed) as ?completedActions)
       (ROUND(100 * COUNT(?completed) / COUNT(?total)) as ?percentComplete)
WHERE {
  # Find all root actions with projects
  ?rootAction a actions:RootAction ;
              actions:project ?project .
  
  # Get all actions in the project (including children)
  {
    ?total actions:project ?project .
  } UNION {
    ?total actions:parentAction+ ?rootAction .
  }
  
  # Count completed actions
  OPTIONAL {
    {
      ?completed actions:project ?project ;
                 actions:state actions:Completed .
    } UNION {
      ?completed actions:parentAction+ ?rootAction ;
                 actions:state actions:Completed .
    }
  }
}
GROUP BY ?project
ORDER BY DESC(?percentComplete)
```

### 4. Find Overdue Actions

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>
PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>

SELECT ?action ?name ?dueDate ?project ?context
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:state ?state .
  
  # Not completed or cancelled
  FILTER(?state != actions:Completed && ?state != actions:Cancelled)
  
  # Has a due date in the past
  {
    ?action actions:doDate ?dueDate .
    FILTER(?dueDate < NOW())
  } UNION {
    ?action actions:doDateTime ?dueDatetime .
    BIND(xsd:date(?dueDatetime) as ?dueDate)
    FILTER(?dueDatetime < NOW())
  }
  
  OPTIONAL { ?action actions:project ?project }
  OPTIONAL { ?action actions:context ?context }
}
ORDER BY ?dueDate
```

### 5. Time Tracking Summary

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?project 
       (SUM(?estimatedMinutes) as ?totalEstimated)
       (SUM(?actualMinutes) as ?totalActual)
       (COUNT(?completedActions) as ?completedCount)
WHERE {
  ?action a actions:Action ;
          actions:project ?project ;
          actions:state actions:Completed .
  
  OPTIONAL { ?action actions:durationMinutes ?estimatedMinutes }
  
  # Calculate actual time if we have start and end dates
  OPTIONAL {
    ?action actions:doDateTime ?startTime ;
            actions:completedDateTime ?endTime .
    BIND(MINUTES(?endTime - ?startTime) as ?actualMinutes)
  }
  
  BIND(?action as ?completedActions)
}
GROUP BY ?project
HAVING(?totalEstimated > 0 || ?totalActual > 0)
ORDER BY DESC(?totalActual)
```

### 6. Find Actions Available Now (Context + Time)

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?action ?name ?context ?duration ?priority
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:state actions:NotStarted ;
          actions:context ?context .
  
  # Available contexts (parameterizable)
  VALUES ?availableContext { "computer" "phone" "office" }
  FILTER(CONTAINS(?context, ?availableContext))
  
  # No blocking dependencies
  FILTER NOT EXISTS {
    ?action actions:parentAction ?parent .
    ?parent actions:state ?parentState .
    FILTER(?parentState != actions:Completed)
  }
  
  # Optional time constraints
  OPTIONAL { ?action actions:durationMinutes ?duration }
  OPTIONAL { ?action actions:priority ?priority }
  
  # Not scheduled for future (available now)
  FILTER NOT EXISTS {
    ?action actions:doDateTime ?futureTime .
    FILTER(?futureTime > NOW())
  }
}
ORDER BY ?priority DESC(?duration)
LIMIT 10
```

### 7. Recurring Actions Due Today

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?action ?name ?time ?project
WHERE {
  ?action a actions:RecurringAction ;
          schema:name ?name ;
          actions:recurrenceFrequency "DAILY" ;
          actions:doDateTime ?scheduledTime .
  
  # Check if scheduled for today
  FILTER(xsd:date(?scheduledTime) = xsd:date(NOW()))
  
  BIND(xsd:time(?scheduledTime) as ?time)
  
  OPTIONAL { ?action actions:project ?project }
}
ORDER BY ?time
```

## Schema.org Compatibility Examples

### Mapping to Schema.org JSON-LD

```json
{
  "@context": {
    "schema": "http://schema.org/"
  },
  "@type": "Action",
  "schema:name": "Review quarterly reports",
  "schema:description": "Analyze Q4 performance metrics",
  "schema:actionStatus": "http://schema.org/PotentialActionStatus",
  "schema:startTime": "2025-02-01T14:00:00",
  "schema:location": "office",
  "schema:identifier": "01924567-89ab-7def-8123-456789abcdef"
}
```

### SPARQL Query for Schema.org Compatibility

```sparql
# Convert Actions vocabulary to Schema.org properties
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

CONSTRUCT {
  ?action a schema:Action ;
          schema:name ?name ;
          schema:actionStatus ?schemaStatus ;
          schema:startTime ?startTime ;
          schema:endTime ?endTime ;
          schema:location ?location ;
          schema:identifier ?id .
}
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:state ?actionState .
  
  # Map custom states to Schema.org equivalents
  OPTIONAL {
    VALUES (?actionState ?schemaStatus) {
      (actions:NotStarted schema:PotentialActionStatus)
      (actions:InProgress schema:ActiveActionStatus)  
      (actions:Completed schema:CompletedActionStatus)
    }
  }
  
  OPTIONAL { ?action actions:doDateTime ?startTime }
  OPTIONAL { ?action actions:completedDateTime ?endTime }
  OPTIONAL { ?action actions:context ?location }
  OPTIONAL { ?action schema:identifier ?id }
}
```

## Integration Examples

### iCalendar Export SPARQL

```sparql
PREFIX actions: <https://vocab.example.org/actions/>
PREFIX schema: <http://schema.org/>

SELECT ?name ?startDateTime ?duration ?location ?project ?status
WHERE {
  ?action a actions:Action ;
          schema:name ?name ;
          actions:doDateTime ?startDateTime .
  
  OPTIONAL { ?action actions:durationMinutes ?duration }
  OPTIONAL { ?action actions:context ?location }
  OPTIONAL { ?action actions:project ?project }
  
  # Map action state to calendar status
  ?action actions:state ?actionState .
  BIND(
    IF(?actionState = actions:Completed, "COMPLETED",
    IF(?actionState = actions:InProgress, "IN-PROCESS", 
    "TENTATIVE")) as ?status
  )
}
ORDER BY ?startDateTime
```

These examples demonstrate the flexibility and power of the Actions Vocabulary for various task management and semantic web use cases.
