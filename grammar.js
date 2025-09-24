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
        field("properties",$.core_properties),
        optional(field("story", seq(field('icon', '*'), field('text',$.safe_text)))),
        optional(field("children",repeat1($.child_action)))
    ),

    child_action: $ => seq(
      field("depth", '>'),
      field("properties",$.core_properties),
      optional(field("children",repeat1($.grandchild_action)))
    ),

    grandchild_action: $ => seq(
      field("depth", '>>'),
      field("properties",$.core_properties),
      optional(field("children",repeat1($.great_grandchild_action)))
    ),

    great_grandchild_action: $ => seq(
      field('depth', '>>>'),
      field("properties",$.core_properties),
      optional(field("children",repeat1($.double_great_grandchild_action)))
    ),

    double_great_grandchild_action: $ => seq(
      field('depth', '>>>>'),
      field("properties",$.core_properties),
      optional(field("children",repeat1($.leaf_action)))
    ),

    leaf_action: $ => seq(
      field('depth', '>>>>>'),
      field("properties",$.core_properties)
    ),

    core_properties: $ => seq(
        field("state",seq(field('opening','['), field('icon', choice(' ', 'x', '-', '=', '_')),field("closing",']'))),
        field("name",$.safe_text),
        optional(repeat1(choice(
        (field("description",seq(field('icon', '$'), field('text',$.safe_text)))),
        (field("priority",seq(field('icon','!'), field('number', choice('1', '2', '3', '4'))))),
        (field("context",seq(field('icon', '+'), field('list', repeat1(seq(field('text', $.safe_text, optional(field('separator',','))))))))),
        (field("do_date_time",$.do_date_or_time)),
        (field("completed_date_time", $.completed_date)),
        (field("id",$.id)))))
    ),


    safe_text: $ => /[^$!*+@%>#\(]+/,
    do_date_or_time: $ => seq(field('icon','@'), $.extended_date_and_time, optional($.recurrance)),
    completed_date: $ => seq(field('icon','%'), $.date_and_time),

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
