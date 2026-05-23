#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 99
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 83
#define ALIAS_COUNT 0
#define TOKEN_COUNT 38
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 15
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 25

enum ts_symbol_identifiers {
  sym_depth1_marker = 1,
  sym_depth2_marker = 2,
  sym_depth3_marker = 3,
  sym_depth4_marker = 4,
  sym_depth5_marker = 5,
  sym_state_open = 6,
  sym_state_close = 7,
  sym_state_not_started = 8,
  sym_state_completed = 9,
  sym_state_in_progress = 10,
  anon_sym_EQ = 11,
  sym_state_cancelled = 12,
  aux_sym_name_text_chunk_token1 = 13,
  sym_description_marker = 14,
  sym_description_text_chunk = 15,
  anon_sym_LBRACK_LBRACK = 16,
  anon_sym_PIPE = 17,
  anon_sym_RBRACK_RBRACK = 18,
  aux_sym_link_text_token1 = 19,
  anon_sym_BANG = 20,
  aux_sym_priority_level_token1 = 21,
  anon_sym_STAR = 22,
  anon_sym_PLUS = 23,
  anon_sym_COMMA = 24,
  sym_tag = 25,
  anon_sym_AT = 26,
  anon_sym_COLON = 27,
  sym_datetime = 28,
  anon_sym_D = 29,
  anon_sym_PERCENT = 30,
  anon_sym_CARET = 31,
  anon_sym_LT = 32,
  sym_uuid_value = 33,
  sym_short_uuid_value = 34,
  sym_alias_name = 35,
  anon_sym_TILDE = 36,
  sym_id_hash = 37,
  sym_source_file = 38,
  sym__action_body = 39,
  sym_root_action = 40,
  sym_depth1_action = 41,
  sym_depth2_action = 42,
  sym_depth3_action = 43,
  sym_depth4_action = 44,
  sym_depth5_action = 45,
  sym_state = 46,
  sym_state_blocked = 47,
  sym_name = 48,
  sym_name_text_chunk = 49,
  sym__metadata = 50,
  sym_description = 51,
  sym_description_content = 52,
  sym_link = 53,
  sym_link_text = 54,
  sym_link_url = 55,
  sym_priority = 56,
  sym_priority_level = 57,
  sym_story = 58,
  sym_story_name = 59,
  sym_context = 60,
  sym_do_date = 61,
  sym_due_date = 62,
  sym_duration = 63,
  sym_minutes = 64,
  sym_completed_date = 65,
  sym_created_date = 66,
  sym_predecessor = 67,
  sym_predecessor_reference = 68,
  sym_predecessor_name = 69,
  sym_alias = 70,
  sym_sequential = 71,
  sym_id = 72,
  aux_sym_source_file_repeat1 = 73,
  aux_sym__action_body_repeat1 = 74,
  aux_sym_root_action_repeat1 = 75,
  aux_sym_depth1_action_repeat1 = 76,
  aux_sym_depth2_action_repeat1 = 77,
  aux_sym_depth3_action_repeat1 = 78,
  aux_sym_depth4_action_repeat1 = 79,
  aux_sym_name_repeat1 = 80,
  aux_sym_description_content_repeat1 = 81,
  aux_sym_context_repeat1 = 82,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_depth1_marker] = "depth1_marker",
  [sym_depth2_marker] = "depth2_marker",
  [sym_depth3_marker] = "depth3_marker",
  [sym_depth4_marker] = "depth4_marker",
  [sym_depth5_marker] = "depth5_marker",
  [sym_state_open] = "state_open",
  [sym_state_close] = "state_close",
  [sym_state_not_started] = "state_not_started",
  [sym_state_completed] = "state_completed",
  [sym_state_in_progress] = "state_in_progress",
  [anon_sym_EQ] = "=",
  [sym_state_cancelled] = "state_cancelled",
  [aux_sym_name_text_chunk_token1] = "name_text_chunk_token1",
  [sym_description_marker] = "description_marker",
  [sym_description_text_chunk] = "description_text_chunk",
  [anon_sym_LBRACK_LBRACK] = "[[",
  [anon_sym_PIPE] = "|",
  [anon_sym_RBRACK_RBRACK] = "]]",
  [aux_sym_link_text_token1] = "link_text_token1",
  [anon_sym_BANG] = "!",
  [aux_sym_priority_level_token1] = "priority_level_token1",
  [anon_sym_STAR] = "*",
  [anon_sym_PLUS] = "+",
  [anon_sym_COMMA] = ",",
  [sym_tag] = "tag",
  [anon_sym_AT] = "@",
  [anon_sym_COLON] = ":",
  [sym_datetime] = "datetime",
  [anon_sym_D] = "D",
  [anon_sym_PERCENT] = "%",
  [anon_sym_CARET] = "^",
  [anon_sym_LT] = "<",
  [sym_uuid_value] = "uuid_value",
  [sym_short_uuid_value] = "short_uuid_value",
  [sym_alias_name] = "alias_name",
  [anon_sym_TILDE] = "~",
  [sym_id_hash] = "id_hash",
  [sym_source_file] = "source_file",
  [sym__action_body] = "_action_body",
  [sym_root_action] = "root_action",
  [sym_depth1_action] = "depth1_action",
  [sym_depth2_action] = "depth2_action",
  [sym_depth3_action] = "depth3_action",
  [sym_depth4_action] = "depth4_action",
  [sym_depth5_action] = "depth5_action",
  [sym_state] = "state",
  [sym_state_blocked] = "state_blocked",
  [sym_name] = "name",
  [sym_name_text_chunk] = "name_text_chunk",
  [sym__metadata] = "_metadata",
  [sym_description] = "description",
  [sym_description_content] = "description_content",
  [sym_link] = "link",
  [sym_link_text] = "link_text",
  [sym_link_url] = "link_url",
  [sym_priority] = "priority",
  [sym_priority_level] = "priority_level",
  [sym_story] = "story",
  [sym_story_name] = "story_name",
  [sym_context] = "context",
  [sym_do_date] = "do_date",
  [sym_due_date] = "due_date",
  [sym_duration] = "duration",
  [sym_minutes] = "minutes",
  [sym_completed_date] = "completed_date",
  [sym_created_date] = "created_date",
  [sym_predecessor] = "predecessor",
  [sym_predecessor_reference] = "predecessor_reference",
  [sym_predecessor_name] = "predecessor_name",
  [sym_alias] = "alias",
  [sym_sequential] = "sequential",
  [sym_id] = "id",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__action_body_repeat1] = "_action_body_repeat1",
  [aux_sym_root_action_repeat1] = "root_action_repeat1",
  [aux_sym_depth1_action_repeat1] = "depth1_action_repeat1",
  [aux_sym_depth2_action_repeat1] = "depth2_action_repeat1",
  [aux_sym_depth3_action_repeat1] = "depth3_action_repeat1",
  [aux_sym_depth4_action_repeat1] = "depth4_action_repeat1",
  [aux_sym_name_repeat1] = "name_repeat1",
  [aux_sym_description_content_repeat1] = "description_content_repeat1",
  [aux_sym_context_repeat1] = "context_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_depth1_marker] = sym_depth1_marker,
  [sym_depth2_marker] = sym_depth2_marker,
  [sym_depth3_marker] = sym_depth3_marker,
  [sym_depth4_marker] = sym_depth4_marker,
  [sym_depth5_marker] = sym_depth5_marker,
  [sym_state_open] = sym_state_open,
  [sym_state_close] = sym_state_close,
  [sym_state_not_started] = sym_state_not_started,
  [sym_state_completed] = sym_state_completed,
  [sym_state_in_progress] = sym_state_in_progress,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_state_cancelled] = sym_state_cancelled,
  [aux_sym_name_text_chunk_token1] = aux_sym_name_text_chunk_token1,
  [sym_description_marker] = sym_description_marker,
  [sym_description_text_chunk] = sym_description_text_chunk,
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_RBRACK_RBRACK] = anon_sym_RBRACK_RBRACK,
  [aux_sym_link_text_token1] = aux_sym_link_text_token1,
  [anon_sym_BANG] = anon_sym_BANG,
  [aux_sym_priority_level_token1] = aux_sym_priority_level_token1,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_tag] = sym_tag,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_datetime] = sym_datetime,
  [anon_sym_D] = anon_sym_D,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_LT] = anon_sym_LT,
  [sym_uuid_value] = sym_uuid_value,
  [sym_short_uuid_value] = sym_short_uuid_value,
  [sym_alias_name] = sym_alias_name,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [sym_id_hash] = sym_id_hash,
  [sym_source_file] = sym_source_file,
  [sym__action_body] = sym__action_body,
  [sym_root_action] = sym_root_action,
  [sym_depth1_action] = sym_depth1_action,
  [sym_depth2_action] = sym_depth2_action,
  [sym_depth3_action] = sym_depth3_action,
  [sym_depth4_action] = sym_depth4_action,
  [sym_depth5_action] = sym_depth5_action,
  [sym_state] = sym_state,
  [sym_state_blocked] = sym_state_blocked,
  [sym_name] = sym_name,
  [sym_name_text_chunk] = sym_name_text_chunk,
  [sym__metadata] = sym__metadata,
  [sym_description] = sym_description,
  [sym_description_content] = sym_description_content,
  [sym_link] = sym_link,
  [sym_link_text] = sym_link_text,
  [sym_link_url] = sym_link_url,
  [sym_priority] = sym_priority,
  [sym_priority_level] = sym_priority_level,
  [sym_story] = sym_story,
  [sym_story_name] = sym_story_name,
  [sym_context] = sym_context,
  [sym_do_date] = sym_do_date,
  [sym_due_date] = sym_due_date,
  [sym_duration] = sym_duration,
  [sym_minutes] = sym_minutes,
  [sym_completed_date] = sym_completed_date,
  [sym_created_date] = sym_created_date,
  [sym_predecessor] = sym_predecessor,
  [sym_predecessor_reference] = sym_predecessor_reference,
  [sym_predecessor_name] = sym_predecessor_name,
  [sym_alias] = sym_alias,
  [sym_sequential] = sym_sequential,
  [sym_id] = sym_id,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__action_body_repeat1] = aux_sym__action_body_repeat1,
  [aux_sym_root_action_repeat1] = aux_sym_root_action_repeat1,
  [aux_sym_depth1_action_repeat1] = aux_sym_depth1_action_repeat1,
  [aux_sym_depth2_action_repeat1] = aux_sym_depth2_action_repeat1,
  [aux_sym_depth3_action_repeat1] = aux_sym_depth3_action_repeat1,
  [aux_sym_depth4_action_repeat1] = aux_sym_depth4_action_repeat1,
  [aux_sym_name_repeat1] = aux_sym_name_repeat1,
  [aux_sym_description_content_repeat1] = aux_sym_description_content_repeat1,
  [aux_sym_context_repeat1] = aux_sym_context_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_depth1_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_depth2_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_depth3_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_depth4_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_depth5_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_state_open] = {
    .visible = true,
    .named = true,
  },
  [sym_state_close] = {
    .visible = true,
    .named = true,
  },
  [sym_state_not_started] = {
    .visible = true,
    .named = true,
  },
  [sym_state_completed] = {
    .visible = true,
    .named = true,
  },
  [sym_state_in_progress] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_state_cancelled] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_name_text_chunk_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_description_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_description_text_chunk] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_link_text_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_priority_level_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_datetime] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_D] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [sym_uuid_value] = {
    .visible = true,
    .named = true,
  },
  [sym_short_uuid_value] = {
    .visible = true,
    .named = true,
  },
  [sym_alias_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [sym_id_hash] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__action_body] = {
    .visible = false,
    .named = true,
  },
  [sym_root_action] = {
    .visible = true,
    .named = true,
  },
  [sym_depth1_action] = {
    .visible = true,
    .named = true,
  },
  [sym_depth2_action] = {
    .visible = true,
    .named = true,
  },
  [sym_depth3_action] = {
    .visible = true,
    .named = true,
  },
  [sym_depth4_action] = {
    .visible = true,
    .named = true,
  },
  [sym_depth5_action] = {
    .visible = true,
    .named = true,
  },
  [sym_state] = {
    .visible = true,
    .named = true,
  },
  [sym_state_blocked] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_name_text_chunk] = {
    .visible = true,
    .named = true,
  },
  [sym__metadata] = {
    .visible = false,
    .named = true,
  },
  [sym_description] = {
    .visible = true,
    .named = true,
  },
  [sym_description_content] = {
    .visible = true,
    .named = true,
  },
  [sym_link] = {
    .visible = true,
    .named = true,
  },
  [sym_link_text] = {
    .visible = true,
    .named = true,
  },
  [sym_link_url] = {
    .visible = true,
    .named = true,
  },
  [sym_priority] = {
    .visible = true,
    .named = true,
  },
  [sym_priority_level] = {
    .visible = true,
    .named = true,
  },
  [sym_story] = {
    .visible = true,
    .named = true,
  },
  [sym_story_name] = {
    .visible = true,
    .named = true,
  },
  [sym_context] = {
    .visible = true,
    .named = true,
  },
  [sym_do_date] = {
    .visible = true,
    .named = true,
  },
  [sym_due_date] = {
    .visible = true,
    .named = true,
  },
  [sym_duration] = {
    .visible = true,
    .named = true,
  },
  [sym_minutes] = {
    .visible = true,
    .named = true,
  },
  [sym_completed_date] = {
    .visible = true,
    .named = true,
  },
  [sym_created_date] = {
    .visible = true,
    .named = true,
  },
  [sym_predecessor] = {
    .visible = true,
    .named = true,
  },
  [sym_predecessor_reference] = {
    .visible = true,
    .named = true,
  },
  [sym_predecessor_name] = {
    .visible = true,
    .named = true,
  },
  [sym_alias] = {
    .visible = true,
    .named = true,
  },
  [sym_sequential] = {
    .visible = true,
    .named = true,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__action_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_root_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_depth1_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_depth2_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_depth3_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_depth4_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_name_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_description_content_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_context_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_child = 1,
  field_close = 2,
  field_datetime = 3,
  field_duration = 4,
  field_icon = 5,
  field_item = 6,
  field_marker = 7,
  field_metadata = 8,
  field_minutes = 9,
  field_name = 10,
  field_open = 11,
  field_state = 12,
  field_text = 13,
  field_url = 14,
  field_value = 15,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_child] = "child",
  [field_close] = "close",
  [field_datetime] = "datetime",
  [field_duration] = "duration",
  [field_icon] = "icon",
  [field_item] = "item",
  [field_marker] = "marker",
  [field_metadata] = "metadata",
  [field_minutes] = "minutes",
  [field_name] = "name",
  [field_open] = "open",
  [field_state] = "state",
  [field_text] = "text",
  [field_url] = "url",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
  [2] = {.index = 3, .length = 1},
  [3] = {.index = 4, .length = 4},
  [4] = {.index = 8, .length = 2},
  [5] = {.index = 10, .length = 3},
  [6] = {.index = 13, .length = 4},
  [7] = {.index = 17, .length = 2},
  [8] = {.index = 19, .length = 1},
  [9] = {.index = 20, .length = 1},
  [10] = {.index = 21, .length = 3},
  [11] = {.index = 24, .length = 5},
  [12] = {.index = 29, .length = 1},
  [13] = {.index = 30, .length = 2},
  [14] = {.index = 32, .length = 2},
  [15] = {.index = 34, .length = 2},
  [16] = {.index = 36, .length = 2},
  [17] = {.index = 38, .length = 2},
  [18] = {.index = 40, .length = 3},
  [19] = {.index = 43, .length = 3},
  [20] = {.index = 46, .length = 3},
  [21] = {.index = 49, .length = 2},
  [22] = {.index = 51, .length = 1},
  [23] = {.index = 52, .length = 2},
  [24] = {.index = 54, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_metadata, 0, .inherited = true},
    {field_name, 0, .inherited = true},
    {field_state, 0, .inherited = true},
  [3] =
    {field_child, 0},
  [4] =
    {field_child, 1, .inherited = true},
    {field_metadata, 0, .inherited = true},
    {field_name, 0, .inherited = true},
    {field_state, 0, .inherited = true},
  [8] =
    {field_name, 1},
    {field_state, 0},
  [10] =
    {field_close, 2},
    {field_open, 0},
    {field_value, 1},
  [13] =
    {field_marker, 0},
    {field_metadata, 1, .inherited = true},
    {field_name, 1, .inherited = true},
    {field_state, 1, .inherited = true},
  [17] =
    {field_child, 0, .inherited = true},
    {field_child, 1, .inherited = true},
  [19] =
    {field_icon, 0},
  [20] =
    {field_metadata, 0},
  [21] =
    {field_metadata, 2, .inherited = true},
    {field_name, 1},
    {field_state, 0},
  [24] =
    {field_child, 2, .inherited = true},
    {field_marker, 0},
    {field_metadata, 1, .inherited = true},
    {field_name, 1, .inherited = true},
    {field_state, 1, .inherited = true},
  [29] =
    {field_url, 1},
  [30] =
    {field_icon, 0},
    {field_value, 1},
  [32] =
    {field_close, 1},
    {field_icon, 0},
  [34] =
    {field_icon, 0},
    {field_item, 1},
  [36] =
    {field_datetime, 1},
    {field_icon, 0},
  [38] =
    {field_metadata, 0, .inherited = true},
    {field_metadata, 1, .inherited = true},
  [40] =
    {field_close, 2},
    {field_icon, 0},
    {field_text, 1},
  [43] =
    {field_icon, 0},
    {field_item, 1},
    {field_item, 2, .inherited = true},
  [46] =
    {field_datetime, 1},
    {field_duration, 2},
    {field_icon, 0},
  [49] =
    {field_text, 1},
    {field_url, 3},
  [51] =
    {field_item, 1},
  [52] =
    {field_item, 0, .inherited = true},
    {field_item, 1, .inherited = true},
  [54] =
    {field_minutes, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 70,
  [72] = 72,
  [73] = 73,
  [74] = 9,
  [75] = 15,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 78,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 84,
  [95] = 83,
  [96] = 96,
  [97] = 97,
  [98] = 97,
};

static TSCharacterRange aux_sym_name_text_chunk_token1_character_set_1[] = {
  {0, '\t'}, {0x0b, ' '}, {'"', '"'}, {'&', ')'}, {',', '9'}, {';', ';'}, {'?', '?'}, {'A', 'Z'},
  {'\\', '\\'}, {'_', '}'}, {0x7f, 0x10ffff},
};

static TSCharacterRange sym_tag_character_set_1[] = {
  {0, '\t'}, {0x0b, ' '}, {'"', '"'}, {'&', ')'}, {'-', '9'}, {';', ';'}, {'?', '?'}, {'A', 'Z'},
  {'\\', '\\'}, {'_', '}'}, {0x7f, 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(34);
      ADVANCE_MAP(
        '!', 67,
        '#', 92,
        '$', 59,
        '%', 86,
        '*', 73,
        '+', 74,
        ',', 75,
        '-', 46,
        ':', 79,
        '<', 88,
        '=', 47,
        '>', 35,
        '@', 78,
        'D', 85,
        '[', 41,
        ']', 43,
        '^', 87,
        '_', 48,
        'x', 45,
        '|', 63,
        '~', 91,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(44);
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'x') ADVANCE(45);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '$') ADVANCE(59);
      if (lookahead == '[') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0) ADVANCE(61);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == ':') ADVANCE(24);
      END_STATE();
    case 6:
      if (lookahead == ':') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 7:
      if (lookahead == '[') ADVANCE(62);
      END_STATE();
    case 8:
      if (lookahead == ']') ADVANCE(64);
      END_STATE();
    case 9:
      if (lookahead == ']') ADVANCE(42);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(66);
      END_STATE();
    case 11:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 12:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(89);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(4);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(5);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(3);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 31:
      if (eof) ADVANCE(34);
      if (lookahead == '\n') SKIP(31);
      if (lookahead == '!') ADVANCE(67);
      if (lookahead == '#') ADVANCE(92);
      if (lookahead == '$') ADVANCE(59);
      if (lookahead == '%') ADVANCE(86);
      if (lookahead == '*') ADVANCE(73);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == '-') ADVANCE(57);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == '<') ADVANCE(88);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '@') ADVANCE(78);
      if (lookahead == '[') ADVANCE(41);
      if (lookahead == '^') ADVANCE(87);
      if (lookahead == '~') ADVANCE(91);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '^') ADVANCE(58);
      END_STATE();
    case 32:
      if (eof) ADVANCE(34);
      if (lookahead == '\n') SKIP(32);
      if (lookahead == '!') ADVANCE(67);
      if (lookahead == '#') ADVANCE(92);
      if (lookahead == '$') ADVANCE(59);
      if (lookahead == '%') ADVANCE(86);
      if (lookahead == '*') ADVANCE(73);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == '<') ADVANCE(88);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '@') ADVANCE(78);
      if (lookahead == '[') ADVANCE(40);
      if (lookahead == '^') ADVANCE(87);
      if (lookahead == '~') ADVANCE(91);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(76);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '^') ADVANCE(77);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      ADVANCE_MAP(
        '!', 67,
        '#', 92,
        '$', 59,
        '%', 86,
        '*', 73,
        '+', 74,
        ':', 79,
        '<', 88,
        '=', 47,
        '>', 35,
        '@', 78,
        '[', 40,
        ']', 8,
        '^', 87,
        '|', 63,
        '~', 91,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_depth1_marker);
      if (lookahead == '>') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_depth2_marker);
      if (lookahead == '>') ADVANCE(37);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_depth3_marker);
      if (lookahead == '>') ADVANCE(38);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_depth4_marker);
      if (lookahead == '>') ADVANCE(39);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_depth5_marker);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_state_open);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_state_open);
      if (lookahead == '[') ADVANCE(62);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_state_close);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_state_close);
      if (lookahead == ']') ADVANCE(64);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_state_not_started);
      if (lookahead == ' ') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_state_completed);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_state_in_progress);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_state_cancelled);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_name_text_chunk_token1);
      if ((!eof && set_contains(aux_sym_name_text_chunk_token1_character_set_1, 11, lookahead))) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_description_marker);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_description_text_chunk);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '[') ADVANCE(61);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_description_text_chunk);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '[') ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_link_text_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(66);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_link_text_token1);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_priority_level_token1);
      if (lookahead == '-') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_priority_level_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_priority_level_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_priority_level_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_priority_level_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_tag);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(76);
      if ((!eof && set_contains(sym_tag_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_tag);
      if ((!eof && set_contains(sym_tag_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_datetime);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_datetime);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == 'Z') ADVANCE(80);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(26);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_datetime);
      if (lookahead == ':') ADVANCE(25);
      if (lookahead == 'Z') ADVANCE(80);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(26);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_datetime);
      if (lookahead == 'T') ADVANCE(23);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_datetime);
      if (lookahead == 'Z') ADVANCE(80);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_D);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_uuid_value);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_alias_name);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_id_hash);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 31},
  [6] = {.lex_state = 31},
  [7] = {.lex_state = 32},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 31},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 31},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 31},
  [16] = {.lex_state = 33},
  [17] = {.lex_state = 32},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 31},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 31},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 10},
  [71] = {.lex_state = 10},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 33},
  [77] = {.lex_state = 31},
  [78] = {.lex_state = 10},
  [79] = {.lex_state = 10},
  [80] = {.lex_state = 31},
  [81] = {.lex_state = 9},
  [82] = {.lex_state = 9},
  [83] = {.lex_state = 33},
  [84] = {.lex_state = 33},
  [85] = {.lex_state = 11},
  [86] = {.lex_state = 9},
  [87] = {.lex_state = 9},
  [88] = {.lex_state = 33},
  [89] = {.lex_state = 11},
  [90] = {.lex_state = 11},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 11},
  [93] = {.lex_state = 12},
  [94] = {.lex_state = 33},
  [95] = {.lex_state = 33},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_depth1_marker] = ACTIONS(1),
    [sym_depth2_marker] = ACTIONS(1),
    [sym_depth3_marker] = ACTIONS(1),
    [sym_depth4_marker] = ACTIONS(1),
    [sym_depth5_marker] = ACTIONS(1),
    [sym_state_open] = ACTIONS(1),
    [sym_state_close] = ACTIONS(1),
    [sym_state_completed] = ACTIONS(1),
    [sym_state_in_progress] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_state_cancelled] = ACTIONS(1),
    [sym_description_marker] = ACTIONS(1),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_RBRACK_RBRACK] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [aux_sym_priority_level_token1] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_datetime] = ACTIONS(1),
    [anon_sym_D] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [sym_id_hash] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(91),
    [sym__action_body] = STATE(63),
    [sym_root_action] = STATE(54),
    [sym_state] = STATE(53),
    [aux_sym_source_file_repeat1] = STATE(54),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_state_open] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(11), 1,
      anon_sym_EQ,
    ACTIONS(13), 1,
      sym_description_marker,
    ACTIONS(15), 1,
      anon_sym_BANG,
    ACTIONS(17), 1,
      anon_sym_STAR,
    ACTIONS(19), 1,
      anon_sym_PLUS,
    ACTIONS(21), 1,
      anon_sym_AT,
    ACTIONS(23), 1,
      anon_sym_COLON,
    ACTIONS(25), 1,
      anon_sym_PERCENT,
    ACTIONS(27), 1,
      anon_sym_CARET,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(31), 1,
      anon_sym_TILDE,
    ACTIONS(33), 1,
      sym_id_hash,
    STATE(3), 1,
      aux_sym__action_body_repeat1,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
    ACTIONS(9), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    STATE(35), 13,
      sym__metadata,
      sym_description,
      sym_priority,
      sym_story,
      sym_context,
      sym_do_date,
      sym_due_date,
      sym_completed_date,
      sym_created_date,
      sym_predecessor,
      sym_alias,
      sym_sequential,
      sym_id,
  [66] = 16,
    ACTIONS(39), 1,
      anon_sym_EQ,
    ACTIONS(42), 1,
      sym_description_marker,
    ACTIONS(45), 1,
      anon_sym_BANG,
    ACTIONS(48), 1,
      anon_sym_STAR,
    ACTIONS(51), 1,
      anon_sym_PLUS,
    ACTIONS(54), 1,
      anon_sym_AT,
    ACTIONS(57), 1,
      anon_sym_COLON,
    ACTIONS(60), 1,
      anon_sym_PERCENT,
    ACTIONS(63), 1,
      anon_sym_CARET,
    ACTIONS(66), 1,
      anon_sym_LT,
    ACTIONS(69), 1,
      anon_sym_TILDE,
    ACTIONS(72), 1,
      sym_id_hash,
    STATE(3), 1,
      aux_sym__action_body_repeat1,
    ACTIONS(35), 3,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
    ACTIONS(37), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    STATE(35), 13,
      sym__metadata,
      sym_description,
      sym_priority,
      sym_story,
      sym_context,
      sym_do_date,
      sym_due_date,
      sym_completed_date,
      sym_created_date,
      sym_predecessor,
      sym_alias,
      sym_sequential,
      sym_id,
  [132] = 16,
    ACTIONS(11), 1,
      anon_sym_EQ,
    ACTIONS(13), 1,
      sym_description_marker,
    ACTIONS(15), 1,
      anon_sym_BANG,
    ACTIONS(17), 1,
      anon_sym_STAR,
    ACTIONS(19), 1,
      anon_sym_PLUS,
    ACTIONS(21), 1,
      anon_sym_AT,
    ACTIONS(23), 1,
      anon_sym_COLON,
    ACTIONS(25), 1,
      anon_sym_PERCENT,
    ACTIONS(27), 1,
      anon_sym_CARET,
    ACTIONS(29), 1,
      anon_sym_LT,
    ACTIONS(31), 1,
      anon_sym_TILDE,
    ACTIONS(33), 1,
      sym_id_hash,
    STATE(2), 1,
      aux_sym__action_body_repeat1,
    ACTIONS(75), 3,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
    ACTIONS(77), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    STATE(35), 13,
      sym__metadata,
      sym_description,
      sym_priority,
      sym_story,
      sym_context,
      sym_do_date,
      sym_due_date,
      sym_completed_date,
      sym_created_date,
      sym_predecessor,
      sym_alias,
      sym_sequential,
      sym_id,
  [198] = 5,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      aux_sym_name_text_chunk_token1,
    ACTIONS(85), 1,
      anon_sym_LBRACK_LBRACK,
    STATE(6), 3,
      sym_name_text_chunk,
      sym_link,
      aux_sym_name_repeat1,
    ACTIONS(81), 18,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [233] = 5,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
    ACTIONS(91), 1,
      aux_sym_name_text_chunk_token1,
    ACTIONS(94), 1,
      anon_sym_LBRACK_LBRACK,
    STATE(6), 3,
      sym_name_text_chunk,
      sym_link,
      aux_sym_name_repeat1,
    ACTIONS(89), 18,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [268] = 3,
    ACTIONS(97), 1,
      ts_builtin_sym_end,
    ACTIONS(101), 1,
      sym_tag,
    ACTIONS(99), 19,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [296] = 4,
    ACTIONS(107), 1,
      anon_sym_COMMA,
    STATE(13), 1,
      aux_sym_context_repeat1,
    ACTIONS(105), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(103), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [326] = 2,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      aux_sym_name_text_chunk_token1,
    ACTIONS(111), 19,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_LBRACK_LBRACK,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [352] = 4,
    ACTIONS(117), 1,
      anon_sym_D,
    STATE(23), 1,
      sym_duration,
    ACTIONS(115), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(113), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [382] = 4,
    ACTIONS(117), 1,
      anon_sym_D,
    STATE(22), 1,
      sym_duration,
    ACTIONS(121), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(119), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [412] = 2,
    ACTIONS(123), 2,
      ts_builtin_sym_end,
      aux_sym_name_text_chunk_token1,
    ACTIONS(125), 19,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_LBRACK_LBRACK,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [438] = 4,
    ACTIONS(107), 1,
      anon_sym_COMMA,
    STATE(14), 1,
      aux_sym_context_repeat1,
    ACTIONS(129), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(127), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [468] = 4,
    ACTIONS(135), 1,
      anon_sym_COMMA,
    STATE(14), 1,
      aux_sym_context_repeat1,
    ACTIONS(133), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(131), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [498] = 2,
    ACTIONS(138), 2,
      ts_builtin_sym_end,
      aux_sym_name_text_chunk_token1,
    ACTIONS(140), 19,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_LBRACK_LBRACK,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [524] = 3,
    ACTIONS(146), 1,
      sym_alias_name,
    ACTIONS(144), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(142), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [551] = 3,
    ACTIONS(148), 1,
      ts_builtin_sym_end,
    ACTIONS(152), 1,
      sym_tag,
    ACTIONS(150), 18,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [578] = 2,
    ACTIONS(156), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(154), 16,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [603] = 2,
    ACTIONS(160), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(158), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [627] = 2,
    ACTIONS(164), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(162), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [651] = 2,
    ACTIONS(168), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(166), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [675] = 2,
    ACTIONS(172), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(170), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [699] = 2,
    ACTIONS(176), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(174), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [723] = 2,
    ACTIONS(180), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(178), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [747] = 2,
    ACTIONS(184), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(182), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [771] = 2,
    ACTIONS(188), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(186), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [795] = 2,
    ACTIONS(192), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(190), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [819] = 2,
    ACTIONS(196), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(194), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [843] = 2,
    ACTIONS(200), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(198), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [867] = 2,
    ACTIONS(204), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(202), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [891] = 2,
    ACTIONS(208), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(206), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [915] = 2,
    ACTIONS(212), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(210), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [939] = 2,
    ACTIONS(216), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(214), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [963] = 2,
    ACTIONS(220), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(218), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [987] = 2,
    ACTIONS(224), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(222), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [1011] = 2,
    ACTIONS(228), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(226), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [1035] = 2,
    ACTIONS(232), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
    ACTIONS(230), 15,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
      anon_sym_EQ,
      sym_description_marker,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
      anon_sym_COLON,
      anon_sym_PERCENT,
      anon_sym_CARET,
      anon_sym_LT,
      anon_sym_TILDE,
      sym_id_hash,
  [1059] = 5,
    ACTIONS(238), 1,
      sym_depth5_marker,
    STATE(38), 1,
      aux_sym_depth4_action_repeat1,
    STATE(44), 1,
      sym_depth5_action,
    ACTIONS(234), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(236), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
  [1079] = 5,
    ACTIONS(245), 1,
      sym_depth5_marker,
    STATE(40), 1,
      aux_sym_depth4_action_repeat1,
    STATE(44), 1,
      sym_depth5_action,
    ACTIONS(241), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(243), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
  [1099] = 5,
    ACTIONS(245), 1,
      sym_depth5_marker,
    STATE(38), 1,
      aux_sym_depth4_action_repeat1,
    STATE(44), 1,
      sym_depth5_action,
    ACTIONS(247), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(249), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
  [1119] = 5,
    ACTIONS(255), 1,
      sym_depth4_marker,
    STATE(41), 1,
      aux_sym_depth3_action_repeat1,
    STATE(57), 1,
      sym_depth4_action,
    ACTIONS(251), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(253), 3,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
  [1138] = 5,
    ACTIONS(262), 1,
      sym_depth4_marker,
    STATE(41), 1,
      aux_sym_depth3_action_repeat1,
    STATE(57), 1,
      sym_depth4_action,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(260), 3,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
  [1157] = 5,
    ACTIONS(262), 1,
      sym_depth4_marker,
    STATE(42), 1,
      aux_sym_depth3_action_repeat1,
    STATE(57), 1,
      sym_depth4_action,
    ACTIONS(264), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(266), 3,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
  [1176] = 2,
    ACTIONS(268), 3,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
    ACTIONS(270), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
  [1188] = 5,
    ACTIONS(276), 1,
      sym_depth3_marker,
    STATE(48), 1,
      aux_sym_depth2_action_repeat1,
    STATE(61), 1,
      sym_depth3_action,
    ACTIONS(272), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(274), 2,
      sym_depth1_marker,
      sym_depth2_marker,
  [1206] = 5,
    ACTIONS(282), 1,
      sym_depth3_marker,
    STATE(46), 1,
      aux_sym_depth2_action_repeat1,
    STATE(61), 1,
      sym_depth3_action,
    ACTIONS(278), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(280), 2,
      sym_depth1_marker,
      sym_depth2_marker,
  [1224] = 2,
    ACTIONS(285), 3,
      ts_builtin_sym_end,
      sym_depth5_marker,
      sym_state_open,
    ACTIONS(287), 4,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
      sym_depth4_marker,
  [1236] = 5,
    ACTIONS(276), 1,
      sym_depth3_marker,
    STATE(46), 1,
      aux_sym_depth2_action_repeat1,
    STATE(61), 1,
      sym_depth3_action,
    ACTIONS(289), 2,
      ts_builtin_sym_end,
      sym_state_open,
    ACTIONS(291), 2,
      sym_depth1_marker,
      sym_depth2_marker,
  [1254] = 5,
    ACTIONS(293), 1,
      sym_description_marker,
    ACTIONS(295), 1,
      sym_description_text_chunk,
    ACTIONS(297), 1,
      anon_sym_LBRACK_LBRACK,
    STATE(96), 1,
      sym_description_content,
    STATE(59), 2,
      sym_link,
      aux_sym_description_content_repeat1,
  [1271] = 4,
    ACTIONS(299), 1,
      sym_state_not_started,
    ACTIONS(303), 1,
      anon_sym_EQ,
    STATE(87), 1,
      sym_state_blocked,
    ACTIONS(301), 3,
      sym_state_completed,
      sym_state_in_progress,
      sym_state_cancelled,
  [1286] = 5,
    ACTIONS(307), 1,
      sym_depth1_marker,
    ACTIONS(309), 1,
      sym_depth2_marker,
    STATE(55), 1,
      aux_sym_depth1_action_repeat1,
    STATE(65), 1,
      sym_depth2_action,
    ACTIONS(305), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1303] = 5,
    ACTIONS(309), 1,
      sym_depth2_marker,
    ACTIONS(313), 1,
      sym_depth1_marker,
    STATE(51), 1,
      aux_sym_depth1_action_repeat1,
    STATE(65), 1,
      sym_depth2_action,
    ACTIONS(311), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1320] = 4,
    ACTIONS(83), 1,
      aux_sym_name_text_chunk_token1,
    ACTIONS(85), 1,
      anon_sym_LBRACK_LBRACK,
    STATE(4), 1,
      sym_name,
    STATE(5), 3,
      sym_name_text_chunk,
      sym_link,
      aux_sym_name_repeat1,
  [1335] = 5,
    ACTIONS(5), 1,
      sym_state_open,
    ACTIONS(315), 1,
      ts_builtin_sym_end,
    STATE(53), 1,
      sym_state,
    STATE(63), 1,
      sym__action_body,
    STATE(56), 2,
      sym_root_action,
      aux_sym_source_file_repeat1,
  [1352] = 5,
    ACTIONS(319), 1,
      sym_depth1_marker,
    ACTIONS(321), 1,
      sym_depth2_marker,
    STATE(55), 1,
      aux_sym_depth1_action_repeat1,
    STATE(65), 1,
      sym_depth2_action,
    ACTIONS(317), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1369] = 5,
    ACTIONS(324), 1,
      ts_builtin_sym_end,
    ACTIONS(326), 1,
      sym_state_open,
    STATE(53), 1,
      sym_state,
    STATE(63), 1,
      sym__action_body,
    STATE(56), 2,
      sym_root_action,
      aux_sym_source_file_repeat1,
  [1386] = 2,
    ACTIONS(329), 3,
      ts_builtin_sym_end,
      sym_depth4_marker,
      sym_state_open,
    ACTIONS(331), 3,
      sym_depth1_marker,
      sym_depth2_marker,
      sym_depth3_marker,
  [1397] = 4,
    ACTIONS(335), 1,
      sym_depth1_marker,
    STATE(60), 1,
      aux_sym_root_action_repeat1,
    STATE(68), 1,
      sym_depth1_action,
    ACTIONS(333), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1411] = 4,
    ACTIONS(297), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(337), 1,
      sym_description_marker,
    ACTIONS(339), 1,
      sym_description_text_chunk,
    STATE(64), 2,
      sym_link,
      aux_sym_description_content_repeat1,
  [1425] = 4,
    ACTIONS(343), 1,
      sym_depth1_marker,
    STATE(60), 1,
      aux_sym_root_action_repeat1,
    STATE(68), 1,
      sym_depth1_action,
    ACTIONS(341), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1439] = 2,
    ACTIONS(348), 2,
      sym_depth1_marker,
      sym_depth2_marker,
    ACTIONS(346), 3,
      ts_builtin_sym_end,
      sym_depth3_marker,
      sym_state_open,
  [1449] = 4,
    ACTIONS(350), 1,
      aux_sym_name_text_chunk_token1,
    STATE(31), 1,
      sym_predecessor_reference,
    STATE(32), 1,
      sym_predecessor_name,
    ACTIONS(352), 2,
      sym_uuid_value,
      sym_short_uuid_value,
  [1463] = 4,
    ACTIONS(335), 1,
      sym_depth1_marker,
    STATE(58), 1,
      aux_sym_root_action_repeat1,
    STATE(68), 1,
      sym_depth1_action,
    ACTIONS(354), 2,
      ts_builtin_sym_end,
      sym_state_open,
  [1477] = 4,
    ACTIONS(356), 1,
      sym_description_marker,
    ACTIONS(358), 1,
      sym_description_text_chunk,
    ACTIONS(361), 1,
      anon_sym_LBRACK_LBRACK,
    STATE(64), 2,
      sym_link,
      aux_sym_description_content_repeat1,
  [1491] = 2,
    ACTIONS(366), 1,
      sym_depth1_marker,
    ACTIONS(364), 3,
      ts_builtin_sym_end,
      sym_depth2_marker,
      sym_state_open,
  [1500] = 3,
    ACTIONS(5), 1,
      sym_state_open,
    STATE(45), 1,
      sym__action_body,
    STATE(53), 1,
      sym_state,
  [1510] = 3,
    ACTIONS(5), 1,
      sym_state_open,
    STATE(39), 1,
      sym__action_body,
    STATE(53), 1,
      sym_state,
  [1520] = 1,
    ACTIONS(368), 3,
      ts_builtin_sym_end,
      sym_depth1_marker,
      sym_state_open,
  [1526] = 3,
    ACTIONS(5), 1,
      sym_state_open,
    STATE(52), 1,
      sym__action_body,
    STATE(53), 1,
      sym_state,
  [1536] = 3,
    ACTIONS(370), 1,
      aux_sym_link_text_token1,
    STATE(84), 1,
      sym_link_url,
    STATE(97), 1,
      sym_link_text,
  [1546] = 3,
    ACTIONS(370), 1,
      aux_sym_link_text_token1,
    STATE(94), 1,
      sym_link_url,
    STATE(98), 1,
      sym_link_text,
  [1556] = 3,
    ACTIONS(5), 1,
      sym_state_open,
    STATE(43), 1,
      sym__action_body,
    STATE(53), 1,
      sym_state,
  [1566] = 3,
    ACTIONS(5), 1,
      sym_state_open,
    STATE(47), 1,
      sym__action_body,
    STATE(53), 1,
      sym_state,
  [1576] = 2,
    ACTIONS(109), 1,
      sym_description_text_chunk,
    ACTIONS(111), 2,
      sym_description_marker,
      anon_sym_LBRACK_LBRACK,
  [1584] = 2,
    ACTIONS(138), 1,
      sym_description_text_chunk,
    ACTIONS(140), 2,
      sym_description_marker,
      anon_sym_LBRACK_LBRACK,
  [1592] = 2,
    ACTIONS(372), 1,
      anon_sym_PIPE,
    ACTIONS(374), 1,
      anon_sym_RBRACK_RBRACK,
  [1599] = 2,
    ACTIONS(376), 1,
      aux_sym_name_text_chunk_token1,
    STATE(25), 1,
      sym_story_name,
  [1606] = 2,
    ACTIONS(378), 1,
      aux_sym_link_text_token1,
    STATE(95), 1,
      sym_link_url,
  [1613] = 2,
    ACTIONS(378), 1,
      aux_sym_link_text_token1,
    STATE(83), 1,
      sym_link_url,
  [1620] = 2,
    ACTIONS(380), 1,
      aux_sym_name_text_chunk_token1,
    ACTIONS(382), 1,
      anon_sym_LBRACK_LBRACK,
  [1627] = 2,
    ACTIONS(384), 1,
      aux_sym_priority_level_token1,
    STATE(20), 1,
      sym_minutes,
  [1634] = 2,
    ACTIONS(386), 1,
      aux_sym_priority_level_token1,
    STATE(21), 1,
      sym_priority_level,
  [1641] = 1,
    ACTIONS(388), 1,
      anon_sym_RBRACK_RBRACK,
  [1645] = 1,
    ACTIONS(390), 1,
      anon_sym_RBRACK_RBRACK,
  [1649] = 1,
    ACTIONS(392), 1,
      sym_datetime,
  [1653] = 1,
    ACTIONS(394), 1,
      sym_state_close,
  [1657] = 1,
    ACTIONS(396), 1,
      sym_state_close,
  [1661] = 1,
    ACTIONS(374), 1,
      anon_sym_RBRACK_RBRACK,
  [1665] = 1,
    ACTIONS(398), 1,
      sym_datetime,
  [1669] = 1,
    ACTIONS(400), 1,
      sym_datetime,
  [1673] = 1,
    ACTIONS(402), 1,
      ts_builtin_sym_end,
  [1677] = 1,
    ACTIONS(404), 1,
      sym_datetime,
  [1681] = 1,
    ACTIONS(406), 1,
      sym_uuid_value,
  [1685] = 1,
    ACTIONS(408), 1,
      anon_sym_RBRACK_RBRACK,
  [1689] = 1,
    ACTIONS(410), 1,
      anon_sym_RBRACK_RBRACK,
  [1693] = 1,
    ACTIONS(412), 1,
      sym_description_marker,
  [1697] = 1,
    ACTIONS(414), 1,
      anon_sym_PIPE,
  [1701] = 1,
    ACTIONS(416), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 66,
  [SMALL_STATE(4)] = 132,
  [SMALL_STATE(5)] = 198,
  [SMALL_STATE(6)] = 233,
  [SMALL_STATE(7)] = 268,
  [SMALL_STATE(8)] = 296,
  [SMALL_STATE(9)] = 326,
  [SMALL_STATE(10)] = 352,
  [SMALL_STATE(11)] = 382,
  [SMALL_STATE(12)] = 412,
  [SMALL_STATE(13)] = 438,
  [SMALL_STATE(14)] = 468,
  [SMALL_STATE(15)] = 498,
  [SMALL_STATE(16)] = 524,
  [SMALL_STATE(17)] = 551,
  [SMALL_STATE(18)] = 578,
  [SMALL_STATE(19)] = 603,
  [SMALL_STATE(20)] = 627,
  [SMALL_STATE(21)] = 651,
  [SMALL_STATE(22)] = 675,
  [SMALL_STATE(23)] = 699,
  [SMALL_STATE(24)] = 723,
  [SMALL_STATE(25)] = 747,
  [SMALL_STATE(26)] = 771,
  [SMALL_STATE(27)] = 795,
  [SMALL_STATE(28)] = 819,
  [SMALL_STATE(29)] = 843,
  [SMALL_STATE(30)] = 867,
  [SMALL_STATE(31)] = 891,
  [SMALL_STATE(32)] = 915,
  [SMALL_STATE(33)] = 939,
  [SMALL_STATE(34)] = 963,
  [SMALL_STATE(35)] = 987,
  [SMALL_STATE(36)] = 1011,
  [SMALL_STATE(37)] = 1035,
  [SMALL_STATE(38)] = 1059,
  [SMALL_STATE(39)] = 1079,
  [SMALL_STATE(40)] = 1099,
  [SMALL_STATE(41)] = 1119,
  [SMALL_STATE(42)] = 1138,
  [SMALL_STATE(43)] = 1157,
  [SMALL_STATE(44)] = 1176,
  [SMALL_STATE(45)] = 1188,
  [SMALL_STATE(46)] = 1206,
  [SMALL_STATE(47)] = 1224,
  [SMALL_STATE(48)] = 1236,
  [SMALL_STATE(49)] = 1254,
  [SMALL_STATE(50)] = 1271,
  [SMALL_STATE(51)] = 1286,
  [SMALL_STATE(52)] = 1303,
  [SMALL_STATE(53)] = 1320,
  [SMALL_STATE(54)] = 1335,
  [SMALL_STATE(55)] = 1352,
  [SMALL_STATE(56)] = 1369,
  [SMALL_STATE(57)] = 1386,
  [SMALL_STATE(58)] = 1397,
  [SMALL_STATE(59)] = 1411,
  [SMALL_STATE(60)] = 1425,
  [SMALL_STATE(61)] = 1439,
  [SMALL_STATE(62)] = 1449,
  [SMALL_STATE(63)] = 1463,
  [SMALL_STATE(64)] = 1477,
  [SMALL_STATE(65)] = 1491,
  [SMALL_STATE(66)] = 1500,
  [SMALL_STATE(67)] = 1510,
  [SMALL_STATE(68)] = 1520,
  [SMALL_STATE(69)] = 1526,
  [SMALL_STATE(70)] = 1536,
  [SMALL_STATE(71)] = 1546,
  [SMALL_STATE(72)] = 1556,
  [SMALL_STATE(73)] = 1566,
  [SMALL_STATE(74)] = 1576,
  [SMALL_STATE(75)] = 1584,
  [SMALL_STATE(76)] = 1592,
  [SMALL_STATE(77)] = 1599,
  [SMALL_STATE(78)] = 1606,
  [SMALL_STATE(79)] = 1613,
  [SMALL_STATE(80)] = 1620,
  [SMALL_STATE(81)] = 1627,
  [SMALL_STATE(82)] = 1634,
  [SMALL_STATE(83)] = 1641,
  [SMALL_STATE(84)] = 1645,
  [SMALL_STATE(85)] = 1649,
  [SMALL_STATE(86)] = 1653,
  [SMALL_STATE(87)] = 1657,
  [SMALL_STATE(88)] = 1661,
  [SMALL_STATE(89)] = 1665,
  [SMALL_STATE(90)] = 1669,
  [SMALL_STATE(91)] = 1673,
  [SMALL_STATE(92)] = 1677,
  [SMALL_STATE(93)] = 1681,
  [SMALL_STATE(94)] = 1685,
  [SMALL_STATE(95)] = 1689,
  [SMALL_STATE(96)] = 1693,
  [SMALL_STATE(97)] = 1697,
  [SMALL_STATE(98)] = 1701,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__action_body, 3, 0, 10),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__action_body, 3, 0, 10),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(16),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(49),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(82),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(77),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(17),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(85),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(89),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(90),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(92),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(62),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(26),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 2, 0, 17), SHIFT_REPEAT(93),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__action_body, 2, 0, 4),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__action_body, 2, 0, 4),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 1, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_name_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_name_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_name_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_name_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 1, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 2, 0, 15),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 2, 0, 15),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 3, 0, 12),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 3, 0, 12),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date, 2, 0, 16),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_do_date, 2, 0, 16),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_due_date, 2, 0, 16),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_due_date, 2, 0, 16),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name_text_chunk, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name_text_chunk, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 3, 0, 19),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 3, 0, 19),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 23),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 23),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 23), SHIFT_REPEAT(7),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 5, 0, 21),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 5, 0, 21),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 1, 0, 8),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 1, 0, 8),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 1, 0, 8),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 1, 0, 8),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 22),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 22),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_created_date, 2, 0, 16),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_created_date, 2, 0, 16),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2, 0, 24),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration, 2, 0, 24),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2, 0, 13),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority, 2, 0, 13),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_due_date, 3, 0, 20),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_due_date, 3, 0, 20),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date, 3, 0, 20),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_do_date, 3, 0, 20),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority_level, 1, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority_level, 1, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2, 0, 13),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_story, 2, 0, 13),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sequential, 1, 0, 8),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sequential, 1, 0, 8),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2, 0, 14),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_description, 2, 0, 14),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 2, 0, 13),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 2, 0, 13),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minutes, 1, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_minutes, 1, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2, 0, 13),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id, 2, 0, 13),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_predecessor, 2, 0, 13),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_predecessor, 2, 0, 13),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_predecessor_reference, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_predecessor_reference, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 3, 0, 18),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_description, 3, 0, 18),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_predecessor_name, 1, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_predecessor_name, 1, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__action_body_repeat1, 1, 0, 9),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__action_body_repeat1, 1, 0, 9),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story_name, 1, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_story_name, 1, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2, 0, 16),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_completed_date, 2, 0, 16),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth4_action_repeat1, 2, 0, 7),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth4_action_repeat1, 2, 0, 7),
  [238] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_depth4_action_repeat1, 2, 0, 7), SHIFT_REPEAT(73),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth4_action, 2, 0, 6),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth4_action, 2, 0, 6),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth4_action, 3, 0, 11),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth4_action, 3, 0, 11),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth3_action_repeat1, 2, 0, 7),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth3_action_repeat1, 2, 0, 7),
  [255] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_depth3_action_repeat1, 2, 0, 7), SHIFT_REPEAT(67),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth3_action, 3, 0, 11),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth3_action, 3, 0, 11),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth3_action, 2, 0, 6),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth3_action, 2, 0, 6),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth4_action_repeat1, 1, 0, 2),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth4_action_repeat1, 1, 0, 2),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth2_action, 2, 0, 6),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth2_action, 2, 0, 6),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth2_action_repeat1, 2, 0, 7),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth2_action_repeat1, 2, 0, 7),
  [282] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_depth2_action_repeat1, 2, 0, 7), SHIFT_REPEAT(72),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth5_action, 2, 0, 6),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth5_action, 2, 0, 6),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth2_action, 3, 0, 11),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth2_action, 3, 0, 11),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [297] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [301] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth1_action, 3, 0, 11),
  [307] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth1_action, 3, 0, 11),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_depth1_action, 2, 0, 6),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_depth1_action, 2, 0, 6),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth1_action_repeat1, 2, 0, 7),
  [319] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth1_action_repeat1, 2, 0, 7),
  [321] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_depth1_action_repeat1, 2, 0, 7), SHIFT_REPEAT(66),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [326] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth3_action_repeat1, 1, 0, 2),
  [331] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth3_action_repeat1, 1, 0, 2),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 2, 0, 3),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_description_content, 1, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_action_repeat1, 2, 0, 7),
  [343] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_action_repeat1, 2, 0, 7), SHIFT_REPEAT(69),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth2_action_repeat1, 1, 0, 2),
  [348] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth2_action_repeat1, 1, 0, 2),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 1, 0, 1),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_description_content_repeat1, 2, 0, 0),
  [358] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_description_content_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [361] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_description_content_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_depth1_action_repeat1, 1, 0, 2),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_depth1_action_repeat1, 1, 0, 2),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_action_repeat1, 1, 0, 2),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link_text, 1, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link_url, 1, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3, 0, 5),
  [382] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_state, 3, 0, 5),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_blocked, 1, 0, 0),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [402] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_actions(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
