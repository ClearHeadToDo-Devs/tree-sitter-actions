#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 120
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 73
#define ALIAS_COUNT 0
#define TOKEN_COUNT 36
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_child_icon = 1,
  sym_grandchild_icon = 2,
  sym_great_grandchild_icon = 3,
  anon_sym_LPAREN = 4,
  anon_sym_RPAREN = 5,
  sym_not_started = 6,
  sym_completed = 7,
  anon_sym_DASH = 8,
  sym_blocked = 9,
  sym_cancelled = 10,
  sym_name = 11,
  aux_sym_description_token1 = 12,
  sym_desc_icon = 13,
  sym_priority_icon = 14,
  aux_sym_priority_number_token1 = 15,
  aux_sym_story_token1 = 16,
  sym_story_icon = 17,
  sym_context_icon = 18,
  aux_sym_middle_context_token1 = 19,
  sym_context_separator = 20,
  sym_do_date_icon = 21,
  anon_sym_PERCENT = 22,
  sym_year = 23,
  aux_sym_month_token1 = 24,
  anon_sym_COLON = 25,
  anon_sym_am = 26,
  anon_sym_pm = 27,
  anon_sym_AM = 28,
  anon_sym_PM = 29,
  sym_time_designator = 30,
  sym_duration_designator = 31,
  sym_id_icon = 32,
  sym_uuid_time_high = 33,
  sym_uuid_random = 34,
  sym__uuid_chunk = 35,
  sym_action_list = 36,
  sym_root_action = 37,
  sym_child_action_list = 38,
  sym_child_action = 39,
  sym_grandchild_action_list = 40,
  sym_grandchild_action = 41,
  sym_great_grandchild_action_list = 42,
  sym_great_grandchild_action = 43,
  sym_core_action = 44,
  sym_state = 45,
  sym_in_progress = 46,
  sym_description = 47,
  sym_priority = 48,
  sym_priority_number = 49,
  sym_story = 50,
  sym_context_list = 51,
  sym_middle_context = 52,
  sym_tail_context = 53,
  sym_do_date_or_time = 54,
  sym_completed_date = 55,
  sym_date = 56,
  sym_month = 57,
  sym_day = 58,
  sym_time = 59,
  sym_hour = 60,
  sym_minute = 61,
  sym_duration = 62,
  sym_id = 63,
  sym_uuid = 64,
  sym_uuid_time_mid = 65,
  sym_uuid_version_random = 66,
  sym_uuid_variant_random = 67,
  aux_sym_action_list_repeat1 = 68,
  aux_sym_child_action_list_repeat1 = 69,
  aux_sym_grandchild_action_list_repeat1 = 70,
  aux_sym_great_grandchild_action_list_repeat1 = 71,
  aux_sym_context_list_repeat1 = 72,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_child_icon] = "child_icon",
  [sym_grandchild_icon] = "grandchild_icon",
  [sym_great_grandchild_icon] = "great_grandchild_icon",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_not_started] = "not_started",
  [sym_completed] = "completed",
  [anon_sym_DASH] = "-",
  [sym_blocked] = "blocked",
  [sym_cancelled] = "cancelled",
  [sym_name] = "name",
  [aux_sym_description_token1] = "description_token1",
  [sym_desc_icon] = "desc_icon",
  [sym_priority_icon] = "priority_icon",
  [aux_sym_priority_number_token1] = "priority_number_token1",
  [aux_sym_story_token1] = "story_token1",
  [sym_story_icon] = "story_icon",
  [sym_context_icon] = "context_icon",
  [aux_sym_middle_context_token1] = "middle_context_token1",
  [sym_context_separator] = "context_separator",
  [sym_do_date_icon] = "do_date_icon",
  [anon_sym_PERCENT] = "%",
  [sym_year] = "year",
  [aux_sym_month_token1] = "month_token1",
  [anon_sym_COLON] = ":",
  [anon_sym_am] = "am",
  [anon_sym_pm] = "pm",
  [anon_sym_AM] = "AM",
  [anon_sym_PM] = "PM",
  [sym_time_designator] = "time_designator",
  [sym_duration_designator] = "duration_designator",
  [sym_id_icon] = "id_icon",
  [sym_uuid_time_high] = "uuid_time_high",
  [sym_uuid_random] = "uuid_random",
  [sym__uuid_chunk] = "_uuid_chunk",
  [sym_action_list] = "action_list",
  [sym_root_action] = "root_action",
  [sym_child_action_list] = "child_action_list",
  [sym_child_action] = "child_action",
  [sym_grandchild_action_list] = "grandchild_action_list",
  [sym_grandchild_action] = "grandchild_action",
  [sym_great_grandchild_action_list] = "great_grandchild_action_list",
  [sym_great_grandchild_action] = "great_grandchild_action",
  [sym_core_action] = "core_action",
  [sym_state] = "state",
  [sym_in_progress] = "in_progress",
  [sym_description] = "description",
  [sym_priority] = "priority",
  [sym_priority_number] = "priority_number",
  [sym_story] = "story",
  [sym_context_list] = "context_list",
  [sym_middle_context] = "middle_context",
  [sym_tail_context] = "tail_context",
  [sym_do_date_or_time] = "do_date_or_time",
  [sym_completed_date] = "completed_date",
  [sym_date] = "date",
  [sym_month] = "month",
  [sym_day] = "day",
  [sym_time] = "time",
  [sym_hour] = "hour",
  [sym_minute] = "minute",
  [sym_duration] = "duration",
  [sym_id] = "id",
  [sym_uuid] = "uuid",
  [sym_uuid_time_mid] = "uuid_time_mid",
  [sym_uuid_version_random] = "uuid_version_random",
  [sym_uuid_variant_random] = "uuid_variant_random",
  [aux_sym_action_list_repeat1] = "action_list_repeat1",
  [aux_sym_child_action_list_repeat1] = "child_action_list_repeat1",
  [aux_sym_grandchild_action_list_repeat1] = "grandchild_action_list_repeat1",
  [aux_sym_great_grandchild_action_list_repeat1] = "great_grandchild_action_list_repeat1",
  [aux_sym_context_list_repeat1] = "context_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_child_icon] = sym_child_icon,
  [sym_grandchild_icon] = sym_grandchild_icon,
  [sym_great_grandchild_icon] = sym_great_grandchild_icon,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_not_started] = sym_not_started,
  [sym_completed] = sym_completed,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_blocked] = sym_blocked,
  [sym_cancelled] = sym_cancelled,
  [sym_name] = sym_name,
  [aux_sym_description_token1] = aux_sym_description_token1,
  [sym_desc_icon] = sym_desc_icon,
  [sym_priority_icon] = sym_priority_icon,
  [aux_sym_priority_number_token1] = aux_sym_priority_number_token1,
  [aux_sym_story_token1] = aux_sym_story_token1,
  [sym_story_icon] = sym_story_icon,
  [sym_context_icon] = sym_context_icon,
  [aux_sym_middle_context_token1] = aux_sym_middle_context_token1,
  [sym_context_separator] = sym_context_separator,
  [sym_do_date_icon] = sym_do_date_icon,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [sym_year] = sym_year,
  [aux_sym_month_token1] = aux_sym_month_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_am] = anon_sym_am,
  [anon_sym_pm] = anon_sym_pm,
  [anon_sym_AM] = anon_sym_AM,
  [anon_sym_PM] = anon_sym_PM,
  [sym_time_designator] = sym_time_designator,
  [sym_duration_designator] = sym_duration_designator,
  [sym_id_icon] = sym_id_icon,
  [sym_uuid_time_high] = sym_uuid_time_high,
  [sym_uuid_random] = sym_uuid_random,
  [sym__uuid_chunk] = sym__uuid_chunk,
  [sym_action_list] = sym_action_list,
  [sym_root_action] = sym_root_action,
  [sym_child_action_list] = sym_child_action_list,
  [sym_child_action] = sym_child_action,
  [sym_grandchild_action_list] = sym_grandchild_action_list,
  [sym_grandchild_action] = sym_grandchild_action,
  [sym_great_grandchild_action_list] = sym_great_grandchild_action_list,
  [sym_great_grandchild_action] = sym_great_grandchild_action,
  [sym_core_action] = sym_core_action,
  [sym_state] = sym_state,
  [sym_in_progress] = sym_in_progress,
  [sym_description] = sym_description,
  [sym_priority] = sym_priority,
  [sym_priority_number] = sym_priority_number,
  [sym_story] = sym_story,
  [sym_context_list] = sym_context_list,
  [sym_middle_context] = sym_middle_context,
  [sym_tail_context] = sym_tail_context,
  [sym_do_date_or_time] = sym_do_date_or_time,
  [sym_completed_date] = sym_completed_date,
  [sym_date] = sym_date,
  [sym_month] = sym_month,
  [sym_day] = sym_day,
  [sym_time] = sym_time,
  [sym_hour] = sym_hour,
  [sym_minute] = sym_minute,
  [sym_duration] = sym_duration,
  [sym_id] = sym_id,
  [sym_uuid] = sym_uuid,
  [sym_uuid_time_mid] = sym_uuid_time_mid,
  [sym_uuid_version_random] = sym_uuid_version_random,
  [sym_uuid_variant_random] = sym_uuid_variant_random,
  [aux_sym_action_list_repeat1] = aux_sym_action_list_repeat1,
  [aux_sym_child_action_list_repeat1] = aux_sym_child_action_list_repeat1,
  [aux_sym_grandchild_action_list_repeat1] = aux_sym_grandchild_action_list_repeat1,
  [aux_sym_great_grandchild_action_list_repeat1] = aux_sym_great_grandchild_action_list_repeat1,
  [aux_sym_context_list_repeat1] = aux_sym_context_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_child_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_grandchild_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_great_grandchild_icon] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_not_started] = {
    .visible = true,
    .named = true,
  },
  [sym_completed] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_blocked] = {
    .visible = true,
    .named = true,
  },
  [sym_cancelled] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_description_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_desc_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_priority_icon] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_priority_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_story_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_story_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_context_icon] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_middle_context_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_context_separator] = {
    .visible = true,
    .named = true,
  },
  [sym_do_date_icon] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [sym_year] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_month_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_am] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pm] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PM] = {
    .visible = true,
    .named = false,
  },
  [sym_time_designator] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_designator] = {
    .visible = true,
    .named = true,
  },
  [sym_id_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid_time_high] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid_random] = {
    .visible = true,
    .named = true,
  },
  [sym__uuid_chunk] = {
    .visible = false,
    .named = true,
  },
  [sym_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_root_action] = {
    .visible = true,
    .named = true,
  },
  [sym_child_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_child_action] = {
    .visible = true,
    .named = true,
  },
  [sym_grandchild_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_grandchild_action] = {
    .visible = true,
    .named = true,
  },
  [sym_great_grandchild_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_great_grandchild_action] = {
    .visible = true,
    .named = true,
  },
  [sym_core_action] = {
    .visible = true,
    .named = true,
  },
  [sym_state] = {
    .visible = true,
    .named = true,
  },
  [sym_in_progress] = {
    .visible = true,
    .named = true,
  },
  [sym_description] = {
    .visible = true,
    .named = true,
  },
  [sym_priority] = {
    .visible = true,
    .named = true,
  },
  [sym_priority_number] = {
    .visible = true,
    .named = true,
  },
  [sym_story] = {
    .visible = true,
    .named = true,
  },
  [sym_context_list] = {
    .visible = true,
    .named = true,
  },
  [sym_middle_context] = {
    .visible = true,
    .named = true,
  },
  [sym_tail_context] = {
    .visible = true,
    .named = true,
  },
  [sym_do_date_or_time] = {
    .visible = true,
    .named = true,
  },
  [sym_completed_date] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [sym_month] = {
    .visible = true,
    .named = true,
  },
  [sym_day] = {
    .visible = true,
    .named = true,
  },
  [sym_time] = {
    .visible = true,
    .named = true,
  },
  [sym_hour] = {
    .visible = true,
    .named = true,
  },
  [sym_minute] = {
    .visible = true,
    .named = true,
  },
  [sym_duration] = {
    .visible = true,
    .named = true,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid_time_mid] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid_version_random] = {
    .visible = true,
    .named = true,
  },
  [sym_uuid_variant_random] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_child_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_grandchild_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_great_grandchild_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_context_list_repeat1] = {
    .visible = false,
    .named = false,
  },
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
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
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
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(41);
      if (lookahead == '!') ADVANCE(57);
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '$') ADVANCE(56);
      if (lookahead == '%') ADVANCE(66);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == ')') ADVANCE(46);
      if (lookahead == '*') ADVANCE(61);
      if (lookahead == '+') ADVANCE(62);
      if (lookahead == ',') ADVANCE(64);
      if (lookahead == '-') ADVANCE(49);
      if (lookahead == ':') ADVANCE(69);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == '>') ADVANCE(42);
      if (lookahead == '@') ADVANCE(65);
      if (lookahead == 'A') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(75);
      if (lookahead == 'P') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(74);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == 'a') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(47);
      if (lookahead == '-') ADVANCE(49);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == 'x') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == 'M') ADVANCE(72);
      END_STATE();
    case 5:
      if (lookahead == 'M') ADVANCE(73);
      END_STATE();
    case 6:
      if (lookahead == 'T') ADVANCE(74);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(70);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(71);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 11:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 12:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(55);
      END_STATE();
    case 13:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 14:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 40:
      if (eof) ADVANCE(41);
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '%') ADVANCE(66);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == ',') ADVANCE(64);
      if (lookahead == '>') ADVANCE(42);
      if (lookahead == '@') ADVANCE(65);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(40)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_child_icon);
      if (lookahead == '>') ADVANCE(43);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_grandchild_icon);
      if (lookahead == '>') ADVANCE(44);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_great_grandchild_icon);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(55);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_priority_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_time_designator);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_duration_designator);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_id_icon);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_uuid_time_high);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_uuid_random);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__uuid_chunk);
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
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 40},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 40},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 40},
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
  [29] = {.lex_state = 40},
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
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 40},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 3},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 3},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 9},
  [93] = {.lex_state = 3},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 14},
  [97] = {.lex_state = 6},
  [98] = {.lex_state = 9},
  [99] = {.lex_state = 9},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 9},
  [102] = {.lex_state = 10},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 14},
  [106] = {.lex_state = 11},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 12},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 13},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 3},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 13},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_child_icon] = ACTIONS(1),
    [sym_grandchild_icon] = ACTIONS(1),
    [sym_great_grandchild_icon] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_completed] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_blocked] = ACTIONS(1),
    [sym_cancelled] = ACTIONS(1),
    [sym_desc_icon] = ACTIONS(1),
    [sym_priority_icon] = ACTIONS(1),
    [aux_sym_priority_number_token1] = ACTIONS(1),
    [sym_story_icon] = ACTIONS(1),
    [sym_context_icon] = ACTIONS(1),
    [sym_context_separator] = ACTIONS(1),
    [sym_do_date_icon] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [sym_year] = ACTIONS(1),
    [aux_sym_month_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_am] = ACTIONS(1),
    [anon_sym_pm] = ACTIONS(1),
    [anon_sym_AM] = ACTIONS(1),
    [anon_sym_PM] = ACTIONS(1),
    [sym_time_designator] = ACTIONS(1),
    [sym_duration_designator] = ACTIONS(1),
    [sym_id_icon] = ACTIONS(1),
  },
  [1] = {
    [sym_action_list] = STATE(110),
    [sym_root_action] = STATE(48),
    [sym_core_action] = STATE(49),
    [sym_state] = STATE(119),
    [aux_sym_action_list_repeat1] = STATE(48),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(11), 1,
      sym_desc_icon,
    ACTIONS(13), 1,
      sym_priority_icon,
    ACTIONS(15), 1,
      sym_story_icon,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(3), 1,
      sym_description,
    STATE(5), 1,
      sym_priority,
    STATE(9), 1,
      sym_story,
    STATE(16), 1,
      sym_context_list,
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(35), 1,
      sym_completed_date,
    STATE(62), 1,
      sym_id,
    ACTIONS(9), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [52] = 14,
    ACTIONS(13), 1,
      sym_priority_icon,
    ACTIONS(15), 1,
      sym_story_icon,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(4), 1,
      sym_priority,
    STATE(7), 1,
      sym_story,
    STATE(13), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [98] = 12,
    ACTIONS(15), 1,
      sym_story_icon,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(6), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(66), 1,
      sym_id,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [138] = 12,
    ACTIONS(15), 1,
      sym_story_icon,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(7), 1,
      sym_story,
    STATE(13), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [178] = 10,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(15), 1,
      sym_context_list,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(39), 1,
      sym_completed_date,
    STATE(61), 1,
      sym_id,
    ACTIONS(35), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [212] = 10,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(17), 1,
      sym_context_list,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(66), 1,
      sym_id,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [246] = 5,
    ACTIONS(43), 1,
      sym_duration_designator,
    STATE(41), 1,
      sym_duration,
    ACTIONS(39), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(41), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
    ACTIONS(37), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [270] = 10,
    ACTIONS(17), 1,
      sym_context_icon,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(13), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [304] = 4,
    ACTIONS(49), 1,
      aux_sym_middle_context_token1,
    ACTIONS(47), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(45), 6,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [325] = 2,
    ACTIONS(54), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(52), 10,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
      sym_id_icon,
  [342] = 4,
    ACTIONS(60), 1,
      aux_sym_middle_context_token1,
    ACTIONS(58), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(56), 6,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [363] = 8,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(66), 1,
      sym_id,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [391] = 2,
    ACTIONS(64), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(62), 9,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [407] = 8,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(32), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(68), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [435] = 8,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [463] = 8,
    ACTIONS(19), 1,
      sym_do_date_icon,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(39), 1,
      sym_completed_date,
    STATE(61), 1,
      sym_id,
    ACTIONS(35), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [491] = 3,
    ACTIONS(74), 1,
      sym_context_separator,
    ACTIONS(72), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(70), 7,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [508] = 2,
    ACTIONS(78), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(76), 8,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [523] = 2,
    ACTIONS(82), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(80), 8,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [538] = 6,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(38), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(86), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(84), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [560] = 4,
    ACTIONS(92), 1,
      sym_time_designator,
    STATE(44), 1,
      sym_time,
    ACTIONS(90), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(88), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [578] = 6,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(42), 1,
      sym_completed_date,
    STATE(66), 1,
      sym_id,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [600] = 6,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(32), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(68), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [622] = 6,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(39), 1,
      sym_completed_date,
    STATE(61), 1,
      sym_id,
    ACTIONS(35), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [644] = 4,
    ACTIONS(43), 1,
      sym_duration_designator,
    STATE(33), 1,
      sym_duration,
    ACTIONS(96), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(94), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [662] = 2,
    ACTIONS(100), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(98), 7,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [676] = 6,
    ACTIONS(21), 1,
      anon_sym_PERCENT,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(45), 1,
      sym_completed_date,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [698] = 2,
    ACTIONS(104), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(102), 7,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [712] = 5,
    ACTIONS(110), 1,
      sym_great_grandchild_icon,
    STATE(69), 1,
      sym_great_grandchild_action_list,
    ACTIONS(106), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(108), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(36), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [731] = 2,
    ACTIONS(114), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(112), 6,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_time_designator,
      sym_id_icon,
  [744] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(54), 1,
      sym_id,
    ACTIONS(86), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(84), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [760] = 2,
    ACTIONS(118), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(116), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [772] = 2,
    ACTIONS(122), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(120), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [784] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(68), 1,
      sym_id,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [800] = 4,
    ACTIONS(110), 1,
      sym_great_grandchild_icon,
    ACTIONS(124), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(126), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(43), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [816] = 2,
    ACTIONS(130), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(128), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [828] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(59), 1,
      sym_id,
    ACTIONS(134), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(132), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [844] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(53), 1,
      sym_id,
    ACTIONS(68), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [860] = 5,
    ACTIONS(138), 1,
      sym_child_icon,
    ACTIONS(140), 1,
      sym_grandchild_icon,
    STATE(79), 1,
      sym_grandchild_action_list,
    ACTIONS(136), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(52), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [878] = 2,
    ACTIONS(96), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(94), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [890] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(61), 1,
      sym_id,
    ACTIONS(35), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [906] = 4,
    ACTIONS(146), 1,
      sym_great_grandchild_icon,
    ACTIONS(142), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(144), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(43), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [922] = 2,
    ACTIONS(151), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(149), 5,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [934] = 4,
    ACTIONS(23), 1,
      sym_id_icon,
    STATE(66), 1,
      sym_id,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [950] = 4,
    ACTIONS(153), 1,
      sym_not_started,
    ACTIONS(157), 1,
      anon_sym_DASH,
    STATE(118), 1,
      sym_in_progress,
    ACTIONS(155), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [965] = 2,
    ACTIONS(161), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(159), 4,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
      sym_id_icon,
  [976] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(163), 1,
      ts_builtin_sym_end,
    STATE(49), 1,
      sym_core_action,
    STATE(119), 1,
      sym_state,
    STATE(51), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [993] = 4,
    ACTIONS(167), 1,
      sym_child_icon,
    STATE(91), 1,
      sym_child_action_list,
    ACTIONS(165), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(65), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1008] = 4,
    ACTIONS(171), 1,
      sym_child_icon,
    ACTIONS(173), 1,
      sym_grandchild_icon,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(50), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [1023] = 5,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
    ACTIONS(178), 1,
      anon_sym_LPAREN,
    STATE(49), 1,
      sym_core_action,
    STATE(119), 1,
      sym_state,
    STATE(51), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [1040] = 4,
    ACTIONS(140), 1,
      sym_grandchild_icon,
    ACTIONS(183), 1,
      sym_child_icon,
    ACTIONS(181), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(50), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [1055] = 2,
    ACTIONS(86), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(84), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1065] = 2,
    ACTIONS(134), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(132), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1075] = 2,
    ACTIONS(187), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(185), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1085] = 2,
    ACTIONS(191), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(189), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1095] = 2,
    ACTIONS(195), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(193), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1105] = 2,
    ACTIONS(199), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(197), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1115] = 2,
    ACTIONS(203), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(201), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1125] = 2,
    ACTIONS(207), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(205), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1135] = 2,
    ACTIONS(68), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1145] = 2,
    ACTIONS(27), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1155] = 2,
    ACTIONS(211), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(209), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1165] = 2,
    ACTIONS(215), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(213), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1175] = 3,
    ACTIONS(167), 1,
      sym_child_icon,
    ACTIONS(217), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(67), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1187] = 2,
    ACTIONS(35), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1197] = 3,
    ACTIONS(221), 1,
      sym_child_icon,
    ACTIONS(219), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(67), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1209] = 2,
    ACTIONS(31), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1219] = 2,
    ACTIONS(226), 1,
      sym_child_icon,
    ACTIONS(224), 3,
      ts_builtin_sym_end,
      sym_grandchild_icon,
      anon_sym_LPAREN,
  [1228] = 2,
    ACTIONS(60), 1,
      aux_sym_middle_context_token1,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [1237] = 3,
    ACTIONS(92), 1,
      sym_time_designator,
    ACTIONS(228), 1,
      sym_year,
    STATE(34), 2,
      sym_date,
      sym_time,
  [1248] = 3,
    ACTIONS(230), 1,
      anon_sym_DASH,
    ACTIONS(232), 1,
      sym__uuid_chunk,
    STATE(80), 1,
      sym_uuid_version_random,
  [1258] = 3,
    ACTIONS(234), 1,
      anon_sym_DASH,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    STATE(90), 1,
      sym_uuid_variant_random,
  [1268] = 3,
    ACTIONS(238), 1,
      anon_sym_DASH,
    ACTIONS(240), 1,
      sym__uuid_chunk,
    STATE(76), 1,
      sym_uuid_time_mid,
  [1278] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(60), 1,
      sym_core_action,
    STATE(119), 1,
      sym_state,
  [1288] = 3,
    ACTIONS(232), 1,
      sym__uuid_chunk,
    ACTIONS(242), 1,
      anon_sym_DASH,
    STATE(73), 1,
      sym_uuid_version_random,
  [1298] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(40), 1,
      sym_core_action,
    STATE(119), 1,
      sym_state,
  [1308] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(30), 1,
      sym_core_action,
    STATE(119), 1,
      sym_state,
  [1318] = 1,
    ACTIONS(244), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [1324] = 3,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    ACTIONS(246), 1,
      anon_sym_DASH,
    STATE(83), 1,
      sym_uuid_variant_random,
  [1334] = 3,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    ACTIONS(248), 1,
      anon_sym_DASH,
    STATE(93), 1,
      sym_uuid_variant_random,
  [1344] = 2,
    ACTIONS(240), 1,
      sym__uuid_chunk,
    STATE(72), 1,
      sym_uuid_time_mid,
  [1351] = 2,
    ACTIONS(250), 1,
      anon_sym_DASH,
    ACTIONS(252), 1,
      sym_uuid_random,
  [1358] = 2,
    ACTIONS(254), 1,
      anon_sym_DASH,
    ACTIONS(256), 1,
      sym_uuid_random,
  [1365] = 2,
    ACTIONS(232), 1,
      sym__uuid_chunk,
    STATE(80), 1,
      sym_uuid_version_random,
  [1372] = 2,
    ACTIONS(232), 1,
      sym__uuid_chunk,
    STATE(81), 1,
      sym_uuid_version_random,
  [1379] = 1,
    ACTIONS(258), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1384] = 2,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    STATE(83), 1,
      sym_uuid_variant_random,
  [1391] = 1,
    ACTIONS(260), 2,
      anon_sym_DASH,
      sym_uuid_random,
  [1396] = 2,
    ACTIONS(262), 1,
      anon_sym_DASH,
    ACTIONS(264), 1,
      sym_uuid_random,
  [1403] = 1,
    ACTIONS(266), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [1408] = 2,
    ACTIONS(268), 1,
      aux_sym_month_token1,
    STATE(8), 1,
      sym_minute,
  [1415] = 2,
    ACTIONS(270), 1,
      anon_sym_DASH,
    ACTIONS(272), 1,
      sym_uuid_random,
  [1422] = 1,
    ACTIONS(274), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1427] = 2,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    STATE(84), 1,
      sym_uuid_variant_random,
  [1434] = 2,
    ACTIONS(276), 1,
      aux_sym_priority_number_token1,
    STATE(20), 1,
      sym_priority_number,
  [1441] = 2,
    ACTIONS(228), 1,
      sym_year,
    STATE(47), 1,
      sym_date,
  [1448] = 2,
    ACTIONS(278), 1,
      aux_sym_month_token1,
    STATE(113), 1,
      sym_month,
  [1455] = 2,
    ACTIONS(280), 1,
      aux_sym_month_token1,
    STATE(109), 1,
      sym_hour,
  [1462] = 2,
    ACTIONS(236), 1,
      sym__uuid_chunk,
    STATE(93), 1,
      sym_uuid_variant_random,
  [1469] = 2,
    ACTIONS(282), 1,
      aux_sym_month_token1,
    STATE(22), 1,
      sym_day,
  [1476] = 2,
    ACTIONS(284), 1,
      sym_uuid_time_high,
    STATE(55), 1,
      sym_uuid,
  [1483] = 1,
    ACTIONS(286), 1,
      anon_sym_DASH,
  [1487] = 1,
    ACTIONS(252), 1,
      sym_uuid_random,
  [1491] = 1,
    ACTIONS(288), 1,
      aux_sym_priority_number_token1,
  [1495] = 1,
    ACTIONS(290), 1,
      aux_sym_story_token1,
  [1499] = 1,
    ACTIONS(292), 1,
      anon_sym_COLON,
  [1503] = 1,
    ACTIONS(294), 1,
      aux_sym_description_token1,
  [1507] = 1,
    ACTIONS(296), 1,
      anon_sym_COLON,
  [1511] = 1,
    ACTIONS(298), 1,
      ts_builtin_sym_end,
  [1515] = 1,
    ACTIONS(272), 1,
      sym_uuid_random,
  [1519] = 1,
    ACTIONS(300), 1,
      sym_name,
  [1523] = 1,
    ACTIONS(302), 1,
      anon_sym_DASH,
  [1527] = 1,
    ACTIONS(304), 1,
      anon_sym_DASH,
  [1531] = 1,
    ACTIONS(256), 1,
      sym_uuid_random,
  [1535] = 1,
    ACTIONS(306), 1,
      anon_sym_RPAREN,
  [1539] = 1,
    ACTIONS(308), 1,
      sym_uuid_random,
  [1543] = 1,
    ACTIONS(310), 1,
      anon_sym_RPAREN,
  [1547] = 1,
    ACTIONS(312), 1,
      sym_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 52,
  [SMALL_STATE(4)] = 98,
  [SMALL_STATE(5)] = 138,
  [SMALL_STATE(6)] = 178,
  [SMALL_STATE(7)] = 212,
  [SMALL_STATE(8)] = 246,
  [SMALL_STATE(9)] = 270,
  [SMALL_STATE(10)] = 304,
  [SMALL_STATE(11)] = 325,
  [SMALL_STATE(12)] = 342,
  [SMALL_STATE(13)] = 363,
  [SMALL_STATE(14)] = 391,
  [SMALL_STATE(15)] = 407,
  [SMALL_STATE(16)] = 435,
  [SMALL_STATE(17)] = 463,
  [SMALL_STATE(18)] = 491,
  [SMALL_STATE(19)] = 508,
  [SMALL_STATE(20)] = 523,
  [SMALL_STATE(21)] = 538,
  [SMALL_STATE(22)] = 560,
  [SMALL_STATE(23)] = 578,
  [SMALL_STATE(24)] = 600,
  [SMALL_STATE(25)] = 622,
  [SMALL_STATE(26)] = 644,
  [SMALL_STATE(27)] = 662,
  [SMALL_STATE(28)] = 676,
  [SMALL_STATE(29)] = 698,
  [SMALL_STATE(30)] = 712,
  [SMALL_STATE(31)] = 731,
  [SMALL_STATE(32)] = 744,
  [SMALL_STATE(33)] = 760,
  [SMALL_STATE(34)] = 772,
  [SMALL_STATE(35)] = 784,
  [SMALL_STATE(36)] = 800,
  [SMALL_STATE(37)] = 816,
  [SMALL_STATE(38)] = 828,
  [SMALL_STATE(39)] = 844,
  [SMALL_STATE(40)] = 860,
  [SMALL_STATE(41)] = 878,
  [SMALL_STATE(42)] = 890,
  [SMALL_STATE(43)] = 906,
  [SMALL_STATE(44)] = 922,
  [SMALL_STATE(45)] = 934,
  [SMALL_STATE(46)] = 950,
  [SMALL_STATE(47)] = 965,
  [SMALL_STATE(48)] = 976,
  [SMALL_STATE(49)] = 993,
  [SMALL_STATE(50)] = 1008,
  [SMALL_STATE(51)] = 1023,
  [SMALL_STATE(52)] = 1040,
  [SMALL_STATE(53)] = 1055,
  [SMALL_STATE(54)] = 1065,
  [SMALL_STATE(55)] = 1075,
  [SMALL_STATE(56)] = 1085,
  [SMALL_STATE(57)] = 1095,
  [SMALL_STATE(58)] = 1105,
  [SMALL_STATE(59)] = 1115,
  [SMALL_STATE(60)] = 1125,
  [SMALL_STATE(61)] = 1135,
  [SMALL_STATE(62)] = 1145,
  [SMALL_STATE(63)] = 1155,
  [SMALL_STATE(64)] = 1165,
  [SMALL_STATE(65)] = 1175,
  [SMALL_STATE(66)] = 1187,
  [SMALL_STATE(67)] = 1197,
  [SMALL_STATE(68)] = 1209,
  [SMALL_STATE(69)] = 1219,
  [SMALL_STATE(70)] = 1228,
  [SMALL_STATE(71)] = 1237,
  [SMALL_STATE(72)] = 1248,
  [SMALL_STATE(73)] = 1258,
  [SMALL_STATE(74)] = 1268,
  [SMALL_STATE(75)] = 1278,
  [SMALL_STATE(76)] = 1288,
  [SMALL_STATE(77)] = 1298,
  [SMALL_STATE(78)] = 1308,
  [SMALL_STATE(79)] = 1318,
  [SMALL_STATE(80)] = 1324,
  [SMALL_STATE(81)] = 1334,
  [SMALL_STATE(82)] = 1344,
  [SMALL_STATE(83)] = 1351,
  [SMALL_STATE(84)] = 1358,
  [SMALL_STATE(85)] = 1365,
  [SMALL_STATE(86)] = 1372,
  [SMALL_STATE(87)] = 1379,
  [SMALL_STATE(88)] = 1384,
  [SMALL_STATE(89)] = 1391,
  [SMALL_STATE(90)] = 1396,
  [SMALL_STATE(91)] = 1403,
  [SMALL_STATE(92)] = 1408,
  [SMALL_STATE(93)] = 1415,
  [SMALL_STATE(94)] = 1422,
  [SMALL_STATE(95)] = 1427,
  [SMALL_STATE(96)] = 1434,
  [SMALL_STATE(97)] = 1441,
  [SMALL_STATE(98)] = 1448,
  [SMALL_STATE(99)] = 1455,
  [SMALL_STATE(100)] = 1462,
  [SMALL_STATE(101)] = 1469,
  [SMALL_STATE(102)] = 1476,
  [SMALL_STATE(103)] = 1483,
  [SMALL_STATE(104)] = 1487,
  [SMALL_STATE(105)] = 1491,
  [SMALL_STATE(106)] = 1495,
  [SMALL_STATE(107)] = 1499,
  [SMALL_STATE(108)] = 1503,
  [SMALL_STATE(109)] = 1507,
  [SMALL_STATE(110)] = 1511,
  [SMALL_STATE(111)] = 1515,
  [SMALL_STATE(112)] = 1519,
  [SMALL_STATE(113)] = 1523,
  [SMALL_STATE(114)] = 1527,
  [SMALL_STATE(115)] = 1531,
  [SMALL_STATE(116)] = 1535,
  [SMALL_STATE(117)] = 1539,
  [SMALL_STATE(118)] = 1543,
  [SMALL_STATE(119)] = 1547,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 2),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 3),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 4),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 4),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 5),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 5),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 4),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(18),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_minute, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context_list, 2),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_description, 2),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 6),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 6),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tail_context, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority_number, 1),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority_number, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority, 2),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 7),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 7),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date, 5),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 5),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_story, 2),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_middle_context, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action, 2),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action, 2),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day, 1),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 6),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_do_date_or_time, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_great_grandchild_action_list, 1),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_great_grandchild_action_list, 1),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration, 2),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 8),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 8),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 2),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_child_action, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2), SHIFT_REPEAT(75),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date, 6),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_completed_date, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 1),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2),
  [173] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2), SHIFT_REPEAT(78),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [178] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(46),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action_list, 1),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action_list, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id, 2),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 8),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 8),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 9),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 9),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 7),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 7),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 9),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 9),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_great_grandchild_action, 2),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_great_grandchild_action, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 5),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 5),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 6),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 6),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action_list, 1),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2),
  [221] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2), SHIFT_REPEAT(77),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action, 3),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action, 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 3),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_version_random, 1),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_variant_random, 1),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 2),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_time_mid, 1),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [298] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_actions(void) {
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
