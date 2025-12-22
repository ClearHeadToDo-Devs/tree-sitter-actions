// Import patterns from shared source
const PATTERNS = require('./patterns.js');

module.exports = grammar({
  name: 'actions',

  extras: $ => [
    /\s/,  // Allow whitespace anywhere
  ],

  rules: {
    source_file: $ => repeat($.root_action),

    // Common action body (state + name + metadata)
    _action_body: $ => seq(
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata))
    ),

    // Root level actions (depth 0)
    root_action: $ => seq(
      $._action_body,
      repeat(field('child', $.depth1_action))
    ),

    // Depth 1 actions (one > prefix)
    depth1_action: $ => seq(
      '>',
      $._action_body,
      repeat(field('child', $.depth2_action))
    ),

    // Depth 2 actions (two > prefixes)
    depth2_action: $ => seq(
      '>>',
      $._action_body,
      repeat(field('child', $.depth3_action))
    ),

    // Depth 3 actions (three > prefixes)
    depth3_action: $ => seq(
      '>>>',
      $._action_body,
      repeat(field('child', $.depth4_action))
    ),

    // Depth 4 actions (four > prefixes)
    depth4_action: $ => seq(
      '>>>>',
      $._action_body,
      repeat(field('child', $.depth5_action))
    ),

    // Depth 5 actions (five > prefixes) - leaf level
    depth5_action: $ => seq(
      '>>>>>',
      $._action_body
    ),

    // State markers - explicit state names per specification
    state: $ => seq('[', field('value', choice(
      $.state_not_started,
      $.state_completed,
      $.state_in_progress,
      $.state_blocked,
      $.state_cancelled
    )), ']'),

    state_not_started: $ => ' ',
    state_completed: $ => 'x',
    state_in_progress: $ => '-',
    state_blocked: $ => '=',
    state_cancelled: $ => '_',

    // Action name - everything up to a newline or reserved character
    name: $ => new RegExp(PATTERNS.name),

    // Metadata fields (hidden node, children are the actual metadata)
    _metadata: $ => choice(
      $.description,
      $.priority,
      $.story,
      $.context,
      $.do_date,
      $.completed_date,
      $.id
    ),

    // Description: $ followed by text
    description: $ => seq(
      '$',
      field('text', new RegExp(PATTERNS.description_text))
    ),

    // Priority: ! followed by number
    priority: $ => seq(
      '!',
      field('level', new RegExp(PATTERNS.priority_level))
    ),

    // Story/Project: * followed by name (root actions only)
    story: $ => seq(
      '*',
      field('name', new RegExp(PATTERNS.story_name))
    ),

    // Context: + followed by comma-separated tags
    context: $ => seq(
      '+',
      field('tag', $.tag),
      repeat(seq(',', field('tag', $.tag)))
    ),

    // Individual context tag
    tag: $ => new RegExp(PATTERNS.tag),

    // Do-date/time: @ followed by ISO 8601 date/time
    do_date: $ => seq(
      '@',
      field('datetime', new RegExp(PATTERNS.datetime_do))
    ),

    // Completed date: % followed by ISO 8601 date/time
    completed_date: $ => seq(
      '%',
      field('datetime', new RegExp(PATTERNS.datetime_completed))
    ),

    // ID: # followed by UUID
    id: $ => seq(
      '#',
      field('uuid', new RegExp(PATTERNS.uuid))
    ),
  }
});
