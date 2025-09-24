/** @file parser for the actions file as defined by the specification therein
 * @author Darrion Burgess <darrionburgess@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "actions",

  rules: {
    action_list: $ => repeat($.root_action),
    root_action: $ => seq(
        field("root_action_props",$.core_action),
        optional(field("action_story", $.story)),
        optional(field("children",$.child_action_list))
    ),
    child_action_list: $ => repeat1($.child_action),

    child_action: $ => seq(
      $.child_icon,
      field("child_action_pros",$.core_action),
      optional(field("grandchildren",$.grandchild_action_list))
    ),
    child_icon: $ => '>',

    grandchild_action_list: $ => repeat1($.grandchild_action),

    grandchild_action: $ => seq(
      $.grandchild_icon,
      field("grandchild_props",$.core_action),
      optional(field("great_grandchildren",$.great_grandchild_action_list))
    ),
    grandchild_icon: $ => '>>',

    great_grandchild_action_list: $ => repeat1($.great_grandchild_action),

    great_grandchild_action: $ => seq(
      $.great_grandchild_icon,
      field("great_grandchild_props",$.core_action),
      optional(field("double_great_grandchildren",$.double_great_grandchild_action_list))
    ),
    great_grandchild_icon: $ => '>>>',

    double_great_grandchild_action_list: $ => repeat1($.double_great_grandchild_action),

    double_great_grandchild_action: $ => seq(
      $.double_great_grandchild_icon,
      field("double_great_grandchildren_props",$.core_action),
      optional($.leaf_action_list)
    ),
    double_great_grandchild_icon: $ => '>>>>',

    leaf_action_list: $ => repeat1($.leaf_action),

    leaf_action: $ => seq(
      $.leaf_icon,
      field("leaf_action_props",$.core_action)
    ),
    leaf_icon: $ => '>>>>>',

    core_action: $ => seq(
        field("action_state",$.state),
        field("action_name",$.name),
        optional(field("action_description",$.description)),
        optional(field("action_priority",$.priority)),
        optional(field("action_context",$.context_list)),
        optional(field("action_do_date_time",$.do_date_or_time)),
        optional(field("action_completed_date", $.completed_date)),
        optional(field("action_id",$.id)),
    ),


    state: $ => seq('(', choice($.not_started, $.completed, $.in_progress, $.blocked, $.cancelled),')'),
    not_started: $ => ' ',
    completed: $ => 'x',
    in_progress: $ => '-',
    blocked: $ => '=',
    cancelled: $ => '_',

    name: $ => /[^$!*+@%>#\(]+/,

    description: $ => seq($.desc_icon, $.description_text),
    desc_icon: $ => '$',
    //allow `$` char
    description_text: $ => /[^!*+@%>#\(]+/,

    priority: $ => seq($.priority_icon, $.priority_number),
    priority_icon: $ => '!',
    priority_number: $ => /[0-9]+/,

    story: $ => seq($.story_icon, $.story_name),
    story_icon: $ => '*',
    //allow `*` char
    story_name: $ => /[^+@%>#\(]+/,

    context_list: $ => seq($.context_icon, repeat1(seq($.context_text, optional($.context_separator)))),
    context_icon: $ => '+',
    middle_context: $ => seq($.context_text, $.context_separator),
    context_text: $ => /[a-zA-Z0-9\-_]+/,
    context_separator: $ => ',',

    do_date_or_time: $ => seq($.do_date_icon, $.extended_date_and_time, optional($.recurrance)),
    do_date_icon: $ => '@',
    completed_date: $ => seq('%', $.date_and_time),

    recurrance: $ => seq($.recurrance_icon, $.recurrance_structure),
    recurrance_icon: $ => 'R',
    recurrance_structure: $ => choice($.daily_recurrance, $.weekly_recurrance),
    daily_recurrance: $ => seq('Da', optional($.time)),
    weekly_recurrance: $ => seq('W', optional(seq($.weekly_recurrance_days, optional($.time)))),
    weekly_recurrance_days: $ => repeat1(choice('Mon', 'Tue', 'Wen', 'Thurs', 'Fri', 'Sat', 'Sun')),

    extended_date_and_time: $ => seq($.date_and_time, optional($.duration)),
    date_and_time: $ => seq($.date, optional($.time)),
    date: $ => seq($.year,'-',$.month,'-',$.day),
    year: $ => /[0-9]{4}/,
    month: $ => /[0-9]{2}/,
    day: $ => /[0-9]{2}/,

    time: $ => seq(seq($.hour,':',$.minute), optional(choice('am','pm','AM','PM'))),
    hour: $ => /[0-9]{2}/,
    minute: $ => /[0-9]{2}/,

    duration: $ => seq($.duration_designator, $.duration_value ),
    duration_designator: $ => 'D',
    duration_value: $ => /[0-9]+/,

    //expects uuid v7
    id: $ => seq($.id_icon, $.uuid),
    id_icon: $ => '#',
    uuid: $ => seq($.uuid_time_high, optional('-'), $.uuid_time_mid, optional('-'), $.uuid_version_random, optional('-'),$.uuid_variant_random, optional('-'),$.uuid_random),
    uuid_time_high : $ => /[0-9a-f]{8}/,
    uuid_time_mid: $ => $._uuid_chunk,
    uuid_version_random: $ => $._uuid_chunk,
    uuid_variant_random: $ => $._uuid_chunk,
    uuid_random: $ => /[0-9a-f]{12}/,

    _uuid_chunk: $ => /[0-9a-f]{4}/,
  },
});
