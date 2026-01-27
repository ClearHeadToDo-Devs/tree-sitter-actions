/**
 * Regex patterns used throughout the grammar
 *
 * Exports actual RegExp objects to avoid double-escaping hell.
 * Use these directly in grammar.js rules (no `new RegExp()` needed).
 *
 * Structural Archetypes:
 * - icon_value: icon + text (priority, story, alias, predecessor, id)
 * - icon_datetime: icon + datetime (completed_date, created_date)
 * - icon_composite: icon + parts (do_date: datetime, duration, recurrence)
 * - icon_list: icon + items (context)
 * - icon_rich_text: icon + text/links (description)
 * - marker_only: just icon (sequential)
 */

// Characters that introduce metadata fields
// Updated to include = (alias) and ~ (sequential)
const METADATA_CHARS = '$!*+@%^#><~=';

// Build a character class that excludes specific chars plus newline and brackets
const notChars = (chars) => new RegExp(`[^\\n${escapeForCharClass(chars)}\\[\\]]+`);

// Escape chars that have special meaning inside a character class
function escapeForCharClass(str) {
  return str.replace(/[\^\-\]\\]/g, '\\$&');
}

module.exports = {
  // Reference for documentation/other tools
  metadata_chars: METADATA_CHARS,

  // Structural primitives (consolidated patterns)
  safe_text: notChars(METADATA_CHARS),      // General text excluding metadata markers
  identifier: /[a-zA-Z0-9_-]+/,             // Alphanumeric identifiers with underscores/hyphens
  number: /[0-9]+/,                         // Numeric values
  tag_text: notChars(METADATA_CHARS + ','), // Tag text (excludes comma for list separation)
  description_text: /[^$]+/,                 // Description text (delimited by $, can span lines)

  // UUID patterns
  uuid: /[0-9a-fA-F-]+/,
  short_uuid: /[0-9a-fA-F]{8}/,

  // Export helper for custom patterns
  notChars,
};
