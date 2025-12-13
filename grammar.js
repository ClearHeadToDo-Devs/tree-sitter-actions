module.exports = grammar({
  name: 'actions',

  extras: $ => [
    /\s/,  // Allow whitespace anywhere
  ],

  rules: {
    source_file: $ => repeat($.root_action),

    // Root level actions (depth 0)
    root_action: $ => seq(
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata)),
      repeat(field('child', $.depth1_action))
    ),

    // Depth 1 actions (one > prefix)
    depth1_action: $ => seq(
      '>',
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata)),
      repeat(field('child', $.depth2_action))
    ),

    // Depth 2 actions (two > prefixes)
    depth2_action: $ => seq(
      '>>',
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata)),
      repeat(field('child', $.depth3_action))
    ),

    // Depth 3 actions (three > prefixes)
    depth3_action: $ => seq(
      '>>>',
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata)),
      repeat(field('child', $.depth4_action))
    ),

    // Depth 4 actions (four > prefixes)
    depth4_action: $ => seq(
      '>>>>',
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata)),
      repeat(field('child', $.depth5_action))
    ),

    // Depth 5 actions (five > prefixes) - leaf level
    depth5_action: $ => seq(
      '>>>>>',
      field('state', $.state),
      field('name', $.name),
      repeat(field('metadata', $._metadata))
    ),

    // State markers
    state: $ => choice(
      seq('[', ' ', ']'),   // not started
      seq('[', 'x', ']'),   // completed
      seq('[', '-', ']'),   // in progress
      seq('[', '=', ']'),   // blocked/awaiting
      seq('[', '_', ']')    // cancelled
    ),

    // Action name - everything up to a newline or reserved character
    name: $ => /[^\n$!*+@%#>]+/,

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
      field('text', /[^\n]+/)
    ),

    // Priority: ! followed by number
    priority: $ => seq(
      '!',
      field('level', /[0-9]+/)
    ),

    // Story/Project: * followed by name (root actions only)
    story: $ => seq(
      '*',
      field('name', /[^\n!$+@%#>]+/)
    ),

    // Context: + followed by comma-separated tags
    context: $ => seq(
      '+',
      field('tags', /[^\n!$*@%#>]+/)
    ),

    // Do-date/time: @ followed by ISO 8601 date/time
    do_date: $ => seq(
      '@',
      field('datetime', /[^\n!$*+%#>]+/)
    ),

    // Completed date: % followed by ISO 8601 date/time
    completed_date: $ => seq(
      '%',
      field('datetime', /[^\n!$*+@#>]+/)
    ),

    // ID: # followed by UUID
    id: $ => seq(
      '#',
      field('uuid', /[0-9a-fA-F-]+/)
    ),
  }
});
