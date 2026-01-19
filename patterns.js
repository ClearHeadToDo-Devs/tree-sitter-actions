/**
 * Regex patterns used throughout the grammar
 *
 * Exports actual RegExp objects to avoid double-escaping hell.
 * Use these directly in grammar.js rules (no `new RegExp()` needed).
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

  // Text content patterns (RegExp objects - use directly, no new RegExp())
  name: notChars(METADATA_CHARS),
  description_text: notChars('!*+@%^#><~='),  // allows $ within descriptions
  story_name: notChars(METADATA_CHARS),
  tag: notChars(METADATA_CHARS + ','),
  predecessor_name: notChars(METADATA_CHARS),

  // Alias pattern: alphanumeric, underscores, hyphens only
  alias_name: /[a-zA-Z0-9_-]+/,

  // Simple patterns
  priority_level: /[0-9]+/,

  // UUID patterns
  uuid: /[0-9a-fA-F-]+/,
  // Short UUID: exactly 8 hex characters (first segment of full UUID)
  short_uuid: /[0-9a-fA-F]{8}/,
};
