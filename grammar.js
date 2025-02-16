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
        optional($.do_date_or_time)
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
    description: $ => seq('$', /[^!*+@%>]+/),
    priority: $ => seq('!',/[0-9]+/),
    story: $ => seq('*', /[^+@%>]+/),

    context_list: $ => seq('+', repeat1(choice($.middle_context, $.tail_context))),
    middle_context: $ => seq(/[a-zA-Z0-9\-_]+/, ','),
    tail_context: $ => /[a-zA-Z0-9\-_]+/,

    do_date_or_time: $ => seq('@', choice($.date, $.time)),

    date: $ => seq(seq($.year,'-',$.month,'-',$.day), optional($.time)),
    year: $ => /[0-9]{4}/,
    month: $ => /[0-9]{2}/,
    day: $ => /[0-9]{2}/,

    time: $ => seq('T', seq($.hour,':',$.minute), optional(choice('am','pm','AM','PM')), optional($.duration)),
    hour: $ => /[0-9]{2}/,
    minute: $ => /[0-9]{2}/,

    duration: $ => seq('D', /[0-9]+/),
  }
});
