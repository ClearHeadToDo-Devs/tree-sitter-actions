//! Static types for tree-sitter-actions nodes
//! 
//! This module provides strongly-typed wrappers around tree-sitter nodes
//! to make working with the parse tree more ergonomic and type-safe.

use tree_sitter::{Node, TreeCursor};

/// Trait for converting tree-sitter nodes into typed structs
pub trait FromNode<'tree>: Sized {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError>;
}

/// Error type for parsing failures
#[derive(Debug, Clone, PartialEq)]
pub enum ParseError {
    UnexpectedNodeType { expected: &'static str, actual: String },
    MissingRequiredChild(&'static str),
    InvalidFieldName(String),
}

impl std::fmt::Display for ParseError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ParseError::UnexpectedNodeType { expected, actual } => {
                write!(f, "Expected node type '{}', found '{}'", expected, actual)
            }
            ParseError::MissingRequiredChild(field) => {
                write!(f, "Missing required child field '{}'", field)
            }
            ParseError::InvalidFieldName(name) => {
                write!(f, "Invalid field name '{}'", name)
            }
        }
    }
}

impl std::error::Error for ParseError {}

/// Helper function to get child by field name
fn get_child_by_field_name<'tree>(node: Node<'tree>, field_name: &str) -> Option<Node<'tree>> {
    let mut cursor = node.walk();
    for child in node.children(&mut cursor) {
        if let Some(name) = child.field_name() {
            if name == field_name {
                return Some(child);
            }
        }
    }
    None
}

/// Helper function to get all children of a specific type
fn get_children_by_type<'tree>(node: Node<'tree>, node_type: &str) -> Vec<Node<'tree>> {
    let mut cursor = node.walk();
    node.children(&mut cursor)
        .filter(|child| child.kind() == node_type)
        .collect()
}

/// Root node representing a list of actions
#[derive(Debug, Clone)]
pub struct ActionList<'tree> {
    pub actions: Vec<RootAction<'tree>>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for ActionList<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "action_list" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "action_list",
                actual: node.kind().to_string(),
            });
        }

        let actions = get_children_by_type(node, "root_action")
            .into_iter()
            .map(RootAction::from_node)
            .collect::<Result<Vec<_>, _>>()?;

        Ok(ActionList { actions, node })
    }
}

/// A root-level action with optional story and children
#[derive(Debug, Clone)]
pub struct RootAction<'tree> {
    pub root_action_props: CoreAction<'tree>,
    pub action_story: Option<Story<'tree>>,
    pub children: Option<ChildActionList<'tree>>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for RootAction<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "root_action" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "root_action",
                actual: node.kind().to_string(),
            });
        }

        let root_action_props = get_child_by_field_name(node, "root_action_props")
            .ok_or(ParseError::MissingRequiredChild("root_action_props"))
            .and_then(CoreAction::from_node)?;

        let action_story = get_child_by_field_name(node, "action_story")
            .map(Story::from_node)
            .transpose()?;

        let children = get_child_by_field_name(node, "children")
            .map(ChildActionList::from_node)
            .transpose()?;

        Ok(RootAction {
            root_action_props,
            action_story,
            children,
            node,
        })
    }
}

/// Core action properties shared by all action types
#[derive(Debug, Clone)]
pub struct CoreAction<'tree> {
    pub state: State<'tree>,
    pub name: Name<'tree>,
    pub description: Option<Description<'tree>>,
    pub priority: Option<Priority<'tree>>,
    pub context_list: Option<ContextList<'tree>>,
    pub do_date_or_time: Option<DoDateOrTime<'tree>>,
    pub completed_date: Option<CompletedDate<'tree>>,
    pub id: Option<Id<'tree>>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for CoreAction<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "core_action" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "core_action",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let state = children
            .iter()
            .find(|child| child.kind() == "state")
            .ok_or(ParseError::MissingRequiredChild("state"))
            .and_then(|&n| State::from_node(n))?;

        let name = children
            .iter()
            .find(|child| child.kind() == "name")
            .ok_or(ParseError::MissingRequiredChild("name"))
            .and_then(|&n| Name::from_node(n))?;

        let description = children
            .iter()
            .find(|child| child.kind() == "description")
            .map(|&n| Description::from_node(n))
            .transpose()?;

        let priority = children
            .iter()
            .find(|child| child.kind() == "priority")
            .map(|&n| Priority::from_node(n))
            .transpose()?;

        let context_list = children
            .iter()
            .find(|child| child.kind() == "context_list")
            .map(|&n| ContextList::from_node(n))
            .transpose()?;

        let do_date_or_time = children
            .iter()
            .find(|child| child.kind() == "do_date_or_time")
            .map(|&n| DoDateOrTime::from_node(n))
            .transpose()?;

        let completed_date = children
            .iter()
            .find(|child| child.kind() == "completed_date")
            .map(|&n| CompletedDate::from_node(n))
            .transpose()?;

        let id = children
            .iter()
            .find(|child| child.kind() == "id")
            .map(|&n| Id::from_node(n))
            .transpose()?;

        Ok(CoreAction {
            state,
            name,
            description,
            priority,
            context_list,
            do_date_or_time,
            completed_date,
            id,
            node,
        })
    }
}

/// Action state (not started, completed, in progress, blocked, cancelled)
#[derive(Debug, Clone)]
pub struct State<'tree> {
    pub state_type: StateType<'tree>,
    pub node: Node<'tree>,
}

#[derive(Debug, Clone)]
pub enum StateType<'tree> {
    NotStarted(NotStarted<'tree>),
    Completed(Completed<'tree>),
    InProgress(InProgress<'tree>),
    Blocked(Blocked<'tree>),
    Cancelled(Cancelled<'tree>),
}

impl<'tree> FromNode<'tree> for State<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "state" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "state",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let child = node.children(&mut cursor).next()
            .ok_or(ParseError::MissingRequiredChild("state_type"))?;

        let state_type = match child.kind() {
            "not_started" => StateType::NotStarted(NotStarted::from_node(child)?),
            "completed" => StateType::Completed(Completed::from_node(child)?),
            "in_progress" => StateType::InProgress(InProgress::from_node(child)?),
            "blocked" => StateType::Blocked(Blocked::from_node(child)?),
            "cancelled" => StateType::Cancelled(Cancelled::from_node(child)?),
            _ => return Err(ParseError::UnexpectedNodeType {
                expected: "state type",
                actual: child.kind().to_string(),
            }),
        };

        Ok(State { state_type, node })
    }
}

// Simple wrapper types for leaf nodes
macro_rules! simple_node_type {
    ($name:ident, $kind:literal) => {
        #[derive(Debug, Clone)]
        pub struct $name<'tree> {
            pub node: Node<'tree>,
        }

        impl<'tree> FromNode<'tree> for $name<'tree> {
            fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
                if node.kind() != $kind {
                    return Err(ParseError::UnexpectedNodeType {
                        expected: $kind,
                        actual: node.kind().to_string(),
                    });
                }
                Ok($name { node })
            }
        }

        impl<'tree> $name<'tree> {
            pub fn text(&self) -> &str {
                self.node.utf8_text(&[]).unwrap_or("")
            }
        }
    };
}

// Define simple node types
simple_node_type!(NotStarted, "not_started");
simple_node_type!(Completed, "completed");
simple_node_type!(InProgress, "in_progress");
simple_node_type!(Blocked, "blocked");
simple_node_type!(Cancelled, "cancelled");
simple_node_type!(Name, "name");
simple_node_type!(DescriptionText, "description_text");
simple_node_type!(PriorityNumber, "priority_number");
simple_node_type!(StoryName, "story_name");
simple_node_type!(ContextText, "context_text");
simple_node_type!(Year, "year");
simple_node_type!(Month, "month");
simple_node_type!(Day, "day");
simple_node_type!(Hour, "hour");
simple_node_type!(Minute, "minute");
simple_node_type!(DurationValue, "duration_value");
simple_node_type!(UuidTimeHigh, "uuid_time_high");
simple_node_type!(UuidTimeMid, "uuid_time_mid");
simple_node_type!(UuidVersionRandom, "uuid_version_random");
simple_node_type!(UuidVariantRandom, "uuid_variant_random");
simple_node_type!(UuidRandom, "uuid_random");
simple_node_type!(WeeklyRecurranceDays, "weekly_recurrance_days");

// Icon types
simple_node_type!(ChildIcon, "child_icon");
simple_node_type!(GrandchildIcon, "grandchild_icon");
simple_node_type!(GreatGrandchildIcon, "great_grandchild_icon");
simple_node_type!(DoubleGreatGrandchildIcon, "double_great_grandchild_icon");
simple_node_type!(LeafIcon, "leaf_icon");
simple_node_type!(DescIcon, "desc_icon");
simple_node_type!(PriorityIcon, "priority_icon");
simple_node_type!(StoryIcon, "story_icon");
simple_node_type!(ContextIcon, "context_icon");
simple_node_type!(ContextSeparator, "context_separator");
simple_node_type!(DoDateIcon, "do_date_icon");
simple_node_type!(IdIcon, "id_icon");
simple_node_type!(DurationDesignator, "duration_designator");
simple_node_type!(RecurranceIcon, "recurrance_icon");

/// Action description with icon and text
#[derive(Debug, Clone)]
pub struct Description<'tree> {
    pub desc_icon: DescIcon<'tree>,
    pub description_text: DescriptionText<'tree>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for Description<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "description" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "description",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let desc_icon = children
            .iter()
            .find(|child| child.kind() == "desc_icon")
            .ok_or(ParseError::MissingRequiredChild("desc_icon"))
            .and_then(|&n| DescIcon::from_node(n))?;

        let description_text = children
            .iter()
            .find(|child| child.kind() == "description_text")
            .ok_or(ParseError::MissingRequiredChild("description_text"))
            .and_then(|&n| DescriptionText::from_node(n))?;

        Ok(Description {
            desc_icon,
            description_text,
            node,
        })
    }
}

/// Action priority with icon and number
#[derive(Debug, Clone)]
pub struct Priority<'tree> {
    pub priority_icon: PriorityIcon<'tree>,
    pub priority_number: PriorityNumber<'tree>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for Priority<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "priority" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "priority",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let priority_icon = children
            .iter()
            .find(|child| child.kind() == "priority_icon")
            .ok_or(ParseError::MissingRequiredChild("priority_icon"))
            .and_then(|&n| PriorityIcon::from_node(n))?;

        let priority_number = children
            .iter()
            .find(|child| child.kind() == "priority_number")
            .ok_or(ParseError::MissingRequiredChild("priority_number"))
            .and_then(|&n| PriorityNumber::from_node(n))?;

        Ok(Priority {
            priority_icon,
            priority_number,
            node,
        })
    }
}

/// Story with icon and name
#[derive(Debug, Clone)]
pub struct Story<'tree> {
    pub story_icon: StoryIcon<'tree>,
    pub story_name: StoryName<'tree>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for Story<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "story" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "story",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let story_icon = children
            .iter()
            .find(|child| child.kind() == "story_icon")
            .ok_or(ParseError::MissingRequiredChild("story_icon"))
            .and_then(|&n| StoryIcon::from_node(n))?;

        let story_name = children
            .iter()
            .find(|child| child.kind() == "story_name")
            .ok_or(ParseError::MissingRequiredChild("story_name"))
            .and_then(|&n| StoryName::from_node(n))?;

        Ok(Story {
            story_icon,
            story_name,
            node,
        })
    }
}

/// Context list with icon and context items
#[derive(Debug, Clone)]
pub struct ContextList<'tree> {
    pub context_icon: ContextIcon<'tree>,
    pub contexts: Vec<ContextItem<'tree>>,
    pub node: Node<'tree>,
}

#[derive(Debug, Clone)]
pub enum ContextItem<'tree> {
    Middle(MiddleContext<'tree>),
    Text(ContextText<'tree>),
}

impl<'tree> FromNode<'tree> for ContextList<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "context_list" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "context_list",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let context_icon = children
            .iter()
            .find(|child| child.kind() == "context_icon")
            .ok_or(ParseError::MissingRequiredChild("context_icon"))
            .and_then(|&n| ContextIcon::from_node(n))?;

        let contexts = children
            .iter()
            .filter(|child| child.kind() == "middle_context" || child.kind() == "context_text")
            .map(|&child| match child.kind() {
                "middle_context" => MiddleContext::from_node(child).map(ContextItem::Middle),
                "context_text" => ContextText::from_node(child).map(ContextItem::Text),
                _ => unreachable!(),
            })
            .collect::<Result<Vec<_>, _>>()?;

        Ok(ContextList {
            context_icon,
            contexts,
            node,
        })
    }
}

/// Middle context with text and separator
#[derive(Debug, Clone)]
pub struct MiddleContext<'tree> {
    pub context_text: ContextText<'tree>,
    pub context_separator: ContextSeparator<'tree>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for MiddleContext<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "middle_context" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "middle_context",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let context_text = children
            .iter()
            .find(|child| child.kind() == "context_text")
            .ok_or(ParseError::MissingRequiredChild("context_text"))
            .and_then(|&n| ContextText::from_node(n))?;

        let context_separator = children
            .iter()
            .find(|child| child.kind() == "context_separator")
            .ok_or(ParseError::MissingRequiredChild("context_separator"))
            .and_then(|&n| ContextSeparator::from_node(n))?;

        Ok(MiddleContext {
            context_text,
            context_separator,
            node,
        })
    }
}

// Additional complex types would continue here...
// For brevity, I'll include a few more key ones:

/// Child action list
#[derive(Debug, Clone)]
pub struct ChildActionList<'tree> {
    pub actions: Vec<ChildAction<'tree>>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for ChildActionList<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "child_action_list" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "child_action_list",
                actual: node.kind().to_string(),
            });
        }

        let actions = get_children_by_type(node, "child_action")
            .into_iter()
            .map(ChildAction::from_node)
            .collect::<Result<Vec<_>, _>>()?;

        Ok(ChildActionList { actions, node })
    }
}

/// Child action with icon and core action
#[derive(Debug, Clone)]
pub struct ChildAction<'tree> {
    pub child_icon: ChildIcon<'tree>,
    pub core_action: CoreAction<'tree>,
    pub grandchild_action_list: Option<GrandchildActionList<'tree>>,
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for ChildAction<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "child_action" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "child_action",
                actual: node.kind().to_string(),
            });
        }

        let mut cursor = node.walk();
        let children: Vec<_> = node.children(&mut cursor).collect();

        let child_icon = children
            .iter()
            .find(|child| child.kind() == "child_icon")
            .ok_or(ParseError::MissingRequiredChild("child_icon"))
            .and_then(|&n| ChildIcon::from_node(n))?;

        let core_action = children
            .iter()
            .find(|child| child.kind() == "core_action")
            .ok_or(ParseError::MissingRequiredChild("core_action"))
            .and_then(|&n| CoreAction::from_node(n))?;

        let grandchild_action_list = children
            .iter()
            .find(|child| child.kind() == "grandchild_action_list")
            .map(|&n| GrandchildActionList::from_node(n))
            .transpose()?;

        Ok(ChildAction {
            child_icon,
            core_action,
            grandchild_action_list,
            node,
        })
    }
}

// Placeholder for remaining types - you would continue implementing
// GrandchildActionList, DoDateOrTime, CompletedDate, Id, etc.
// following the same patterns shown above.

#[derive(Debug, Clone)]
pub struct GrandchildActionList<'tree> {
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for GrandchildActionList<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "grandchild_action_list" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "grandchild_action_list",
                actual: node.kind().to_string(),
            });
        }
        Ok(GrandchildActionList { node })
    }
}

#[derive(Debug, Clone)]
pub struct DoDateOrTime<'tree> {
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for DoDateOrTime<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "do_date_or_time" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "do_date_or_time",
                actual: node.kind().to_string(),
            });
        }
        Ok(DoDateOrTime { node })
    }
}

#[derive(Debug, Clone)]
pub struct CompletedDate<'tree> {
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for CompletedDate<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "completed_date" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "completed_date",
                actual: node.kind().to_string(),
            });
        }
        Ok(CompletedDate { node })
    }
}

#[derive(Debug, Clone)]
pub struct Id<'tree> {
    pub node: Node<'tree>,
}

impl<'tree> FromNode<'tree> for Id<'tree> {
    fn from_node(node: Node<'tree>) -> Result<Self, ParseError> {
        if node.kind() != "id" {
            return Err(ParseError::UnexpectedNodeType {
                expected: "id",
                actual: node.kind().to_string(),
            });
        }
        Ok(Id { node })
    }
}
