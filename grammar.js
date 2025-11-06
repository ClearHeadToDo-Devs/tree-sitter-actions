/** @file parser for the actions file as defined by the specification therein
 * @author Darrion Burgess <darrionburgess@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const generatedRulesStrings = require('./grammar-generated');

// Build the rules object by merging hand-written and generated rules
const buildRules = () => {
  // Start with hand-maintained rules
  const handMaintainedRules = {
    action_list: $ => repeat($.root_action),

    root_action: $ => seq(
      $.state,
      $.name,
      optional($.description),
      optional($.priority),
      optional($.project),
      optional($.context),
      optional($.do_date_or_time),
      optional($.completed_date),
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
      optional($.description),
      optional($.priority),
      optional($.context),
      optional($.do_date_or_time),
      optional($.completed_date),
      optional($.recurrence),
      optional($.recurrence_interval),
      optional($.recurrence_count),
      optional($.recurrence_until),
      optional($.id),
      optional(field("children", repeat1($.child_action)))
    ),

    // Override generated rules that need special handling
    // do_date_or_time includes optional duration per spec (line 260-263)
    do_date_or_time: $ => seq(
      field('icon', '@'),
      field('value', choice($.iso_date_time, $.iso_date, $.iso_time)),
      optional($.duration)
    ),

    // Duration is parsed as part of do_date_or_time, but still a named rule
    duration: $ => seq(field('icon', 'D'), field('minutes', /\d+/)),

    // Utility rules (hand-maintained)
    // safe_text: must consume all characters until a special symbol
    // Use repeat1 to ensure greedy matching across whitespace
    safe_text: $ => repeat1(/[^$!*+@%>#\(\)\n\s]+/),
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

  // Integrate generated rules (but don't overwrite hand-maintained ones)
  // Note: generatedRulesStrings is actually an object of functions,
  // not strings (despite the variable name - historical artifact)
  for (const [key, ruleFn] of Object.entries(generatedRulesStrings)) {
    if (!handMaintainedRules[key]) {
      handMaintainedRules[key] = ruleFn;
    }
  }

  return handMaintainedRules;
};

module.exports = grammar({
  name: "actions",

  extras: $ => [
    /\s/, // Whitespace is not significant
  ],

  conflicts: $ => [
    [$.child_action]
  ],

  rules: buildRules()
});
