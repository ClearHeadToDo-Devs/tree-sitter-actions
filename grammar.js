// Import patterns from shared source
const PATTERNS = require('./patterns.js');

module.exports = grammar({
  name: 'actions',

  extras: $ => [
    /\s/, // Allow whitespace anywhere
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
      field('marker', $.depth1_marker),
      $._action_body,
      repeat(field('child', $.depth2_action))
    ),

    // Depth 2 actions (two > prefixes)
    depth2_action: $ => seq(
      field('marker', $.depth2_marker),
      $._action_body,
      repeat(field('child', $.depth3_action))
    ),

    // Depth 3 actions (three > prefixes)
    depth3_action: $ => seq(
      field('marker', $.depth3_marker),
      $._action_body,
      repeat(field('child', $.depth4_action))
    ),

    // Depth 4 actions (four > prefixes)
    depth4_action: $ => seq(
      field('marker', $.depth4_marker),
      $._action_body,
      repeat(field('child', $.depth5_action))
    ),

    // Depth 5 actions (five > prefixes) - leaf level
    depth5_action: $ => seq(
      field('marker', $.depth5_marker),
      $._action_body
    ),

    // Depth markers as named nodes for syntax highlighting
    depth1_marker: $ => '>',
    depth2_marker: $ => '>>',
    depth3_marker: $ => '>>>',
    depth4_marker: $ => '>>>>',
    depth5_marker: $ => '>>>>>',

    // State markers - explicit state names per specification
    state: $ => seq(
      field('open', $.state_open),
      field('value', choice(
        $.state_not_started,
        $.state_completed,
        $.state_in_progress,
        $.state_blocked,
        $.state_cancelled
      )),
      field('close', $.state_close)
    ),

    state_open: $ => '[',
    state_close: $ => ']',

    state_not_started: $ => ' ',
    state_completed: $ => 'x',
    state_in_progress: $ => '-',
    state_blocked: $ => '=',
    state_cancelled: $ => '_',

    // Action name - can contain text and links
    name: $ => repeat1(choice(
      $.link,
      $.name_text_chunk
    )),

    // Text chunk within name (excludes metadata markers and [)
    name_text_chunk: $ => PATTERNS.name,

    // Metadata fields (hidden node, children are the actual metadata)
    _metadata: $ => choice(
      $.description,
      $.priority,
      $.story,
      $.context,
      $.do_date,
      $.completed_date,
      $.created_date,
      $.predecessor,
      $.alias,
      $.sequential,
      $.id
    ),

    // Description: $ followed by text and/or links
    description: $ => seq(
      field('icon', '$'),
      field('text', repeat1(choice(
        $.link,
        $.description_text_chunk
      )))
    ),

    // Text chunk within description (excludes metadata markers except $ and excludes [)
    description_text_chunk: $ => PATTERNS.description_text,

    // Link: [[text|url]] or [[url]]
    link: $ => seq(
      '[[',
      choice(
        // Full form: [[text|url]]
        seq(
          field('text', $.link_text),
          '|',
          field('url', $.link_url)
        ),
        // Shorthand: [[url]]
        field('url', $.link_url)
      ),
      ']]'
    ),

    // Link text (everything except | and ])
    link_text: $ => /[^\|\]]+/,

    // Link URL (everything except | and ])
    link_url: $ => /[^\|\]]+/,

    // Priority: ! followed by number
    priority: $ => seq(
      field('icon', '!'),
      field('level', $.priority_level)
    ),

    // Priority level (1-5)
    priority_level: $ => PATTERNS.priority_level,

    // Story/Project: * followed by name (root actions only)
    story: $ => seq(
      field('icon', '*'),
      field('name', $.story_name)
    ),

    // Story name
    story_name: $ => PATTERNS.story_name,

    // Context: + followed by comma-separated tags
    context: $ => seq(
      field('icon', '+'),
      optional(seq(
        field('tag', $.tag),
        repeat(seq(',', optional(field('tag', $.tag))))
      ))
    ),

    // Individual context tag
    tag: $ => PATTERNS.tag,

    // Do-date/time: @ followed by ISO 8601 date/time, optional duration, optional recurrence
    do_date: $ => seq(
      field('icon', '@'),
      field('datetime', $.datetime),
      optional(field('duration', $.duration)),
      optional(field('recurrence', $.recurrence))
    ),

    // ISO 8601 datetime: YYYY-MM-DD or YYYY-MM-DDTHH:MM or YYYY-MM-DDTHH:MM:SS with optional timezone
    datetime: $ => /[0-9]{4}-[0-9]{2}-[0-9]{2}(T[0-9]{2}:[0-9]{2}(:[0-9]{2}(\.[0-9]+)?)?(Z|[+-][0-9]{2}:?[0-9]{2})?)?/,

    // Duration: D followed by number of minutes
    duration: $ => seq(
      'D',
      field('minutes', $.minutes)
    ),

    minutes: $ => /[0-9]+/,

    // Recurrence: R: followed by RRULE syntax
    recurrence: $ => seq(
      'R:',
      field('rrule', $.rrule_content)
    ),

    rrule_content: $ => /FREQ=(SECONDLY|MINUTELY|HOURLY|DAILY|WEEKLY|MONTHLY|YEARLY)(;[A-Z]+(=[A-Z0-9,+-]+)?)*/,

    // Completed date: % followed by ISO 8601 date/time
    completed_date: $ => seq(
      field('icon', '%'),
      field('datetime', $.datetime)
    ),

    // Created date: ^ followed by ISO 8601 date/time
    created_date: $ => seq(
      field('icon', '^'),
      field('datetime', $.datetime)
    ),

    // Predecessor: < followed by action name or UUID
    predecessor: $ => seq(
      field('icon', '<'),
      field('reference', $.predecessor_reference)
    ),

    // Predecessor reference can be a UUID, short UUID, or an action name
    predecessor_reference: $ => choice(
      $.uuid_value,
      $.short_uuid_value,
      $.predecessor_name
    ),

    // Predecessor name - action name reference (not UUID)
    // Excludes characters that would indicate UUID format and metadata markers
    predecessor_name: $ => PATTERNS.predecessor_name,

    // UUID value as named node (full UUID with hyphens)
    uuid_value: $ => PATTERNS.uuid,

    // Short UUID value - first 8 hex characters only
    short_uuid_value: $ => PATTERNS.short_uuid,

    // Alias: = followed by alias name
    alias: $ => seq(
      field('icon', '='),
      optional(field('name', $.alias_name))
    ),

    // Alias name - alphanumeric, underscores, hyphens
    alias_name: $ => PATTERNS.alias_name,

    // Sequential marker: ~ indicates children are sequential
    sequential: $ => field('icon', '~'),

    // ID: # followed by UUID
    id: $ => seq(
      field('icon', $.id_hash),
      field('uuid', $.uuid_value)
    ),

    id_hash: $ => '#',
  }
});
