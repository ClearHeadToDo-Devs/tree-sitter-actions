/**
 * Regex patterns used throughout the grammar
 *
 * These patterns are the single source of truth for both:
 * - Tree-sitter grammar parsing (grammar.js)
 * - JSON Schema validation (schema/actions.schema.json)
 *
 * This ensures parsing and validation use identical rules.
 */

module.exports = {
  // Character classes for metadata markers
  metadata_chars: '$!*+@%#>',

  // Core field patterns
  name: '[^\\n$!*+@%#>]+',
  description_text: '[^\\n!*+@%#>]+',  // Exclude all metadata markers except $
  priority_level: '[0-9]+',
  story_name: '[^\\n!$+@%#>]+',
  tag: '[^,\\n!$*@%#>]+',
  datetime_do: '[^\\n!$*+%#>]+',
  datetime_completed: '[^\\n!$*+@#>]+',
  uuid: '[0-9a-fA-F-]+',
};
