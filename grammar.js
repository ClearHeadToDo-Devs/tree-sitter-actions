/**
 * @file parser for the actions file as defined by the specification therein
 * @author Darrion Burgess <darrionburgess@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "actions",

  rules: {
    action_list: $ => repeat($.action),

    action: $ => seq(
        $.state,
        $.name,
        optional($.description),
        optional($.priority),
        optional($.story),
        optional($.context_list),
        optional($.do_date_or_time),
        optional($.completed_date)
    ),


    state: $ => seq('(', choice($.not_started, $.completed, $.in_progress, $.blocked, $.cancelled),')'),
    not_started: $ => ' ',
    completed: $ => 'x',
    in_progress: $ => '-',
    blocked: $ => '=',
    cancelled: $ => '_',

    //name is anything but reserved chars
    name: $ => /[^$!*+@%>]+/,
    // description is same as name except description char is okay
    description: $ => seq($.desc_icon, /[^!*+@%>]+/),
    desc_icon: $ => '$',
    priority: $ => seq($.priority_icon,/[0-9]+/),
    priority_icon: $ => '!',
    story: $ => seq($.story_icon, /[^+@%>]+/),
    story_icon: $ => '*',

    context_list: $ => seq($.context_icon, repeat1(choice($.middle_context, $.tail_context))),
    context_icon: $ => '+',
    middle_context: $ => seq(/[a-zA-Z0-9\-_]+/, $.context_separator),
    context_separator: $ => ',',
    tail_context: $ => /[a-zA-Z0-9\-_]+/,

    do_date_or_time: $ => seq($.do_date_icon, choice($.date, $.time)),
    do_date_icon: $ => '@',
    completed_date: $ => seq('%', $.date),

    date: $ => seq(seq($.year,'-',$.month,'-',$.day), optional($.time)),
    year: $ => /[0-9]{4}/,
    month: $ => /[0-9]{2}/,
    day: $ => /[0-9]{2}/,

    time: $ => seq($.time_designator, seq($.hour,':',$.minute), optional(choice('am','pm','AM','PM')), optional($.duration)),
    time_designator: $ => ('T'),
    hour: $ => /[0-9]{2}/,
    minute: $ => /[0-9]{2}/,

    duration: $ => seq($.duration_designator, /[0-9]+/),
    duration_designator: $ => 'D'
  }
});
