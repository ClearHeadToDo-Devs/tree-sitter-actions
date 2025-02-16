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
        optional($.priority)
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
    
  }
});
