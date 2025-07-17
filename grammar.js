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
      field("root_props",$.core_action),
      optional(field("story", $.story)),
      optional(field("children",$.child_action_list))
    ),
    child_action_list: $ => repeat1($.child_action),

    child_action: $ => seq(
      field('child_icon','>'),
      field("child_props",$.core_action),
      optional(field("grandchildren",$.grandchild_action_list))
    ),

    grandchild_action_list: $ => repeat1($.grandchild_action),

    grandchild_action: $ => seq(
      field('grandchild_icon','>>'),
      field("grandchild_props",$.core_action),
      optional(field("great_grandchildren",$.great_grandchild_action_list))
    ),

    great_grandchild_action_list: $ => repeat1($.great_grandchild_action),

    great_grandchild_action: $ => seq(
      field('great_grandchild_icon','>>>'),
      field("great_grandchild_props",$.core_action),
      optional(field("double_great_grandchildren",$.double_great_grandchild_action_list))
    ),

    double_great_grandchild_action_list: $ => repeat1($.double_great_grandchild_action),

    double_great_grandchild_action: $ => seq(
      field('double_great_grandchild_icon','>>>>'),
      field("double_great_grandchild_props",$.core_action),
      optional(field("leaves",$.leaf_action_list))
    ),

    leaf_action_list: $ => repeat1($.leaf_action),

    leaf_action: $ => seq(
      field('leaf_action_icon','>>>>>'),
      field("leaf_props",$.core_action)
    ),

    core_action: $ => seq(
      field('state',$.state),
      field('name',$.name),
      optional(field('description',$.description)),
      optional(field('priority',$.priority)),
      optional(field('context_list',$.context_list)),
      optional(field('do_date_time',$.do_date_or_time)),
      optional(field('completed_date_time',$.completed_date)),
      optional(field("id",$.id)),
    ),


    state: $ => seq(field('state_begin'),'(', choice($.not_started, $.completed, $.in_progress, $.blocked, $.cancelled),field('state_end',')')),
    not_started: $ => ' ',
    completed: $ => 'x',
    in_progress: $ => '-',
    blocked: $ => '=',
    cancelled: $ => '_',

    name: $ => /[^$!*+@%>#\(]+/,

    description: $ => seq(field('description_icon','$'), $.description_text),
    description_text: $ => /[^!*+@%>#\(]+/,

    priority: $ => seq(field('priority_icon','!'), $.priority_number),
    priority_number: $ => /[0-9]+/,

    story: $ => seq(field('story_icon','*'), $.story_name),
    //allow `*` char
    story_name: $ => /[^+@%>#\(]+/,

    context_list: $ => seq(field('context_list_icon','+'), repeat1(choice($.middle_context, $.context_text))),
    middle_context: $ => seq($.context_text, field('context_separator',',')),
    context_text: $ => /[a-zA-Z0-9\-_]+/,

    do_date_or_time: $ => seq('@', $.extended_date_and_time, optional($.recurrance)),
    completed_date: $ => seq('%', $.date_and_time),

    recurrance: $ => seq('R', $.recurrance_structure),
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

    duration: $ => seq('D', $.duration_value ),
    duration_value: $ => /[0-9]+/,

    //expects uuid v7
    id: $ => seq('#', $.uuid),
    uuid: $ => seq($.uuid_time_high, optional('-'), $.uuid_time_mid, optional('-'), $.uuid_version_random, optional('-'),$.uuid_variant_random, optional('-'),$.uuid_random),
    uuid_time_high : $ => /[0-9a-f]{8}/,
    uuid_time_mid: $ => $._uuid_chunk,
    uuid_version_random: $ => $._uuid_chunk,
    uuid_variant_random: $ => $._uuid_chunk,
    uuid_random: $ => /[0-9a-f]{12}/,

    _uuid_chunk: $ => /[0-9a-f]{4}/,
  },
});
