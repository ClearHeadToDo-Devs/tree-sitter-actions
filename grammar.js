/** @file parser for the actions file as defined by the specification therein
 * @author Darrion Burgess <darrionburgess@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const generatedRulesStrings = require('./grammar-generated'); // Renamed for clarity

module.exports = grammar({
  name: "actions",

  rules: ($) => { // rules property is now a function that returns an object
    const allRules = {
      action_list: $ => repeat($.root_action),

      root_action: $ => seq(
        $.state,
        $.name,
        optional($.priority),
        optional($.context),
        optional($.description),
        optional($.project),
        optional($.do_date_or_time),
        optional($.completed_date),
        optional($.duration),
        optional($.recurrence),
        optional($.recurrence_interval),
        optional($.recurrence_count),
        optional($.recurrence_until),
        optional($.id),
        optional(field("children", repeat1($.child_action)))
      ),

      child_action: $ => seq(
        $.depth,
        $.state,
        $.name,
        optional($.priority),
        optional($.context),
        optional($.description),
        optional($.do_date_or_time),
        optional($.completed_date),
        optional($.duration),
        optional($.recurrence),
        optional($.recurrence_interval),
        optional($.recurrence_count),
        optional($.recurrence_until),
        optional($.id),
        optional(field("children", repeat1($.child_action)))
      ),

      // Utility rules (hand-maintained)
      safe_text: $ => /[^$!*+@%>#\(]+/,
      iso_date: $ => /\d{4}-\d{2}-\d{2}/,
      iso_time: $ => /\d{2}:\d{2}/,
      iso_date_time: $ => /\d{4}-\d{2}-\d{2}T\d{2}:\d{2}/,

      // Depth markers
      depth: $ => choice(
        '>',
        '>>',
        '>>>',
        '>>>>',
        '>>>>>'
      ),
    };

    // Integrate generated rules
    for (const [key, valueString] of Object.entries(generatedRulesStrings)) {
      // Each valueString is already a function body string like "($) => seq(...)"
      // So, create a new function from this string
      allRules[key] = eval(valueString);
    }

    return allRules;
  }),
});