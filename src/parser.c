#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 109
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 64
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_child_icon = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  sym_not_started = 4,
  sym_completed = 5,
  anon_sym_DASH = 6,
  sym_blocked = 7,
  sym_cancelled = 8,
  sym_name = 9,
  aux_sym_description_token1 = 10,
  sym_desc_icon = 11,
  aux_sym_priority_token1 = 12,
  sym_priority_icon = 13,
  aux_sym_story_token1 = 14,
  sym_story_icon = 15,
  sym_context_icon = 16,
  aux_sym_middle_context_token1 = 17,
  sym_context_separator = 18,
  sym_do_date_icon = 19,
  anon_sym_PERCENT = 20,
  sym_year = 21,
  aux_sym_month_token1 = 22,
  anon_sym_COLON = 23,
  anon_sym_am = 24,
  anon_sym_pm = 25,
  anon_sym_AM = 26,
  anon_sym_PM = 27,
  sym_time_designator = 28,
  sym_duration_designator = 29,
  sym_id_icon = 30,
  sym_uuid_time_high = 31,
  sym_uuid_random = 32,
  sym__uuid_chunk = 33,
  sym_action_list = 34,
  sym_root_action = 35,
  sym_child_action_list = 36,
  sym_child_action = 37,
  sym_core_action = 38,
  sym_state = 39,
  sym_in_progress = 40,
  sym_description = 41,
  sym_priority = 42,
  sym_story = 43,
  sym_context_list = 44,
  sym_middle_context = 45,
  sym_tail_context = 46,
  sym_do_date_or_time = 47,
  sym_completed_date = 48,
  sym_date = 49,
  sym_month = 50,
  sym_day = 51,
  sym_time = 52,
  sym_hour = 53,
  sym_minute = 54,
  sym_duration = 55,
  sym_id = 56,
  sym_uuid = 57,
  sym_uuid_time_mid = 58,
  sym_uuid_version_random = 59,
  sym_uuid_variant_random = 60,
  aux_sym_action_list_repeat1 = 61,
  aux_sym_child_action_list_repeat1 = 62,
  aux_sym_context_list_repeat1 = 63,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_child_icon] = "child_icon",
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
  [aux_sym_priority_token1] = "priority_token1",
  [sym_priority_icon] = "priority_icon",
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
  [sym_core_action] = "core_action",
  [sym_state] = "state",
  [sym_in_progress] = "in_progress",
  [sym_description] = "description",
  [sym_priority] = "priority",
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
  [aux_sym_context_list_repeat1] = "context_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_child_icon] = sym_child_icon,
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
  [aux_sym_priority_token1] = aux_sym_priority_token1,
  [sym_priority_icon] = sym_priority_icon,
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
  [sym_core_action] = sym_core_action,
  [sym_state] = sym_state,
  [sym_in_progress] = sym_in_progress,
  [sym_description] = sym_description,
  [sym_priority] = sym_priority,
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
  [aux_sym_priority_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_priority_icon] = {
    .visible = true,
    .named = true,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(41);
      if (lookahead == '!') ADVANCE(56);
      if (lookahead == '#') ADVANCE(74);
      if (lookahead == '$') ADVANCE(54);
      if (lookahead == '%') ADVANCE(64);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '*') ADVANCE(59);
      if (lookahead == '+') ADVANCE(60);
      if (lookahead == ',') ADVANCE(62);
      if (lookahead == '-') ADVANCE(47);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == '=') ADVANCE(48);
      if (lookahead == '>') ADVANCE(42);
      if (lookahead == '@') ADVANCE(63);
      if (lookahead == 'A') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(73);
      if (lookahead == 'P') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(72);
      if (lookahead == '_') ADVANCE(49);
      if (lookahead == 'a') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(55);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead == '-') ADVANCE(47);
      if (lookahead == '=') ADVANCE(48);
      if (lookahead == '_') ADVANCE(49);
      if (lookahead == 'x') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(47);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(47);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == 'M') ADVANCE(70);
      END_STATE();
    case 5:
      if (lookahead == 'M') ADVANCE(71);
      END_STATE();
    case 6:
      if (lookahead == 'T') ADVANCE(72);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(68);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(69);
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
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 12:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 13:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(51);
      END_STATE();
    case 14:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(55);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
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
      if (lookahead == '#') ADVANCE(74);
      if (lookahead == '%') ADVANCE(64);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ',') ADVANCE(62);
      if (lookahead == '>') ADVANCE(42);
      if (lookahead == '@') ADVANCE(63);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(40)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_child_icon);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_time_designator);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_duration_designator);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_id_icon);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_uuid_time_high);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_uuid_random);
      END_STATE();
    case 77:
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
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 40},
  [12] = {.lex_state = 40},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 40},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 40},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
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
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 40},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 9},
  [74] = {.lex_state = 6},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 9},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 9},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 10},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 9},
  [91] = {.lex_state = 3},
  [92] = {.lex_state = 11},
  [93] = {.lex_state = 14},
  [94] = {.lex_state = 12},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 14},
  [99] = {.lex_state = 13},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 13},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_child_icon] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_completed] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_blocked] = ACTIONS(1),
    [sym_cancelled] = ACTIONS(1),
    [sym_desc_icon] = ACTIONS(1),
    [aux_sym_priority_token1] = ACTIONS(1),
    [sym_priority_icon] = ACTIONS(1),
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
    [sym_action_list] = STATE(107),
    [sym_root_action] = STATE(32),
    [sym_core_action] = STATE(29),
    [sym_state] = STATE(99),
    [aux_sym_action_list_repeat1] = STATE(32),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(9), 1,
      sym_desc_icon,
    ACTIONS(11), 1,
      sym_priority_icon,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(3), 1,
      sym_description,
    STATE(5), 1,
      sym_priority,
    STATE(8), 1,
      sym_story,
    STATE(15), 1,
      sym_context_list,
    STATE(26), 1,
      sym_do_date_or_time,
    STATE(36), 1,
      sym_completed_date,
    STATE(56), 1,
      sym_id,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [48] = 13,
    ACTIONS(11), 1,
      sym_priority_icon,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(4), 1,
      sym_priority,
    STATE(7), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [90] = 11,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(9), 1,
      sym_story,
    STATE(13), 1,
      sym_context_list,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [126] = 11,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(7), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [162] = 4,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(41), 1,
      sym_duration,
    ACTIONS(29), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
    ACTIONS(27), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [182] = 9,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(13), 1,
      sym_context_list,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [212] = 9,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(17), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [242] = 9,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(16), 1,
      sym_context_list,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(37), 1,
      sym_completed_date,
    STATE(59), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [272] = 1,
    ACTIONS(35), 10,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
      sym_id_icon,
  [285] = 3,
    ACTIONS(39), 1,
      aux_sym_middle_context_token1,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(37), 6,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [302] = 3,
    ACTIONS(43), 1,
      aux_sym_middle_context_token1,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(41), 6,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [319] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(37), 1,
      sym_completed_date,
    STATE(59), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [343] = 1,
    ACTIONS(46), 9,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [355] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [379] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(34), 1,
      sym_completed_date,
    STATE(62), 1,
      sym_id,
    ACTIONS(48), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [403] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [427] = 1,
    ACTIONS(50), 8,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [438] = 2,
    ACTIONS(54), 1,
      sym_context_separator,
    ACTIONS(52), 7,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [451] = 3,
    ACTIONS(58), 1,
      sym_time_designator,
    STATE(35), 1,
      sym_time,
    ACTIONS(56), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [465] = 1,
    ACTIONS(60), 7,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [475] = 3,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(46), 1,
      sym_duration,
    ACTIONS(62), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [489] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(42), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [507] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(43), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(64), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [525] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(37), 1,
      sym_completed_date,
    STATE(59), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [543] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [561] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(34), 1,
      sym_completed_date,
    STATE(62), 1,
      sym_id,
    ACTIONS(48), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [579] = 1,
    ACTIONS(66), 7,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [589] = 4,
    ACTIONS(70), 1,
      sym_child_icon,
    STATE(80), 1,
      sym_child_action_list,
    ACTIONS(68), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(39), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [604] = 4,
    ACTIONS(72), 1,
      sym_not_started,
    ACTIONS(76), 1,
      anon_sym_DASH,
    STATE(102), 1,
      sym_in_progress,
    ACTIONS(74), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [619] = 1,
    ACTIONS(78), 6,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_time_designator,
      sym_id_icon,
  [628] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      ts_builtin_sym_end,
    STATE(29), 1,
      sym_core_action,
    STATE(99), 1,
      sym_state,
    STATE(33), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [645] = 5,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
    ACTIONS(84), 1,
      anon_sym_LPAREN,
    STATE(29), 1,
      sym_core_action,
    STATE(99), 1,
      sym_state,
    STATE(33), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [662] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(54), 1,
      sym_id,
    ACTIONS(64), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [674] = 1,
    ACTIONS(87), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [682] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(52), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [694] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(62), 1,
      sym_id,
    ACTIONS(48), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [706] = 3,
    ACTIONS(91), 1,
      sym_child_icon,
    ACTIONS(89), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(38), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [718] = 3,
    ACTIONS(70), 1,
      sym_child_icon,
    ACTIONS(94), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(38), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [730] = 1,
    ACTIONS(96), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [738] = 1,
    ACTIONS(62), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [746] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(59), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [758] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(51), 1,
      sym_id,
    ACTIONS(98), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [770] = 1,
    ACTIONS(100), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [778] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(60), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [790] = 1,
    ACTIONS(102), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [798] = 1,
    ACTIONS(104), 4,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_id_icon,
  [805] = 3,
    ACTIONS(58), 1,
      sym_time_designator,
    ACTIONS(106), 1,
      sym_year,
    STATE(40), 2,
      sym_date,
      sym_time,
  [816] = 2,
    ACTIONS(39), 1,
      aux_sym_middle_context_token1,
    STATE(11), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [825] = 1,
    ACTIONS(108), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [831] = 1,
    ACTIONS(110), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [837] = 1,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [843] = 1,
    ACTIONS(112), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [849] = 1,
    ACTIONS(98), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [855] = 3,
    ACTIONS(114), 1,
      anon_sym_DASH,
    ACTIONS(116), 1,
      sym__uuid_chunk,
    STATE(67), 1,
      sym_uuid_version_random,
  [865] = 1,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [871] = 1,
    ACTIONS(118), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [877] = 3,
    ACTIONS(120), 1,
      anon_sym_DASH,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    STATE(85), 1,
      sym_uuid_variant_random,
  [887] = 1,
    ACTIONS(48), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [893] = 1,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [899] = 1,
    ACTIONS(124), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [905] = 1,
    ACTIONS(64), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [911] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(69), 1,
      sym_core_action,
    STATE(99), 1,
      sym_state,
  [921] = 3,
    ACTIONS(116), 1,
      sym__uuid_chunk,
    ACTIONS(126), 1,
      anon_sym_DASH,
    STATE(65), 1,
      sym_uuid_version_random,
  [931] = 3,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    ACTIONS(128), 1,
      anon_sym_DASH,
    STATE(72), 1,
      sym_uuid_variant_random,
  [941] = 3,
    ACTIONS(130), 1,
      anon_sym_DASH,
    ACTIONS(132), 1,
      sym__uuid_chunk,
    STATE(55), 1,
      sym_uuid_time_mid,
  [951] = 3,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    ACTIONS(134), 1,
      anon_sym_DASH,
    STATE(79), 1,
      sym_uuid_variant_random,
  [961] = 1,
    ACTIONS(136), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [967] = 1,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [973] = 1,
    ACTIONS(140), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [979] = 1,
    ACTIONS(142), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [984] = 2,
    ACTIONS(144), 1,
      anon_sym_DASH,
    ACTIONS(146), 1,
      sym_uuid_random,
  [991] = 2,
    ACTIONS(148), 1,
      aux_sym_month_token1,
    STATE(97), 1,
      sym_hour,
  [998] = 2,
    ACTIONS(106), 1,
      sym_year,
    STATE(47), 1,
      sym_date,
  [1005] = 2,
    ACTIONS(116), 1,
      sym__uuid_chunk,
    STATE(58), 1,
      sym_uuid_version_random,
  [1012] = 1,
    ACTIONS(150), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1017] = 2,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    STATE(72), 1,
      sym_uuid_variant_random,
  [1024] = 1,
    ACTIONS(152), 2,
      anon_sym_DASH,
      sym_uuid_random,
  [1029] = 2,
    ACTIONS(154), 1,
      anon_sym_DASH,
    ACTIONS(156), 1,
      sym_uuid_random,
  [1036] = 1,
    ACTIONS(158), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [1041] = 2,
    ACTIONS(116), 1,
      sym__uuid_chunk,
    STATE(65), 1,
      sym_uuid_version_random,
  [1048] = 2,
    ACTIONS(160), 1,
      aux_sym_month_token1,
    STATE(6), 1,
      sym_minute,
  [1055] = 2,
    ACTIONS(162), 1,
      anon_sym_DASH,
    ACTIONS(164), 1,
      sym_uuid_random,
  [1062] = 2,
    ACTIONS(166), 1,
      aux_sym_month_token1,
    STATE(96), 1,
      sym_month,
  [1069] = 2,
    ACTIONS(168), 1,
      anon_sym_DASH,
    ACTIONS(170), 1,
      sym_uuid_random,
  [1076] = 2,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    STATE(83), 1,
      sym_uuid_variant_random,
  [1083] = 2,
    ACTIONS(132), 1,
      sym__uuid_chunk,
    STATE(64), 1,
      sym_uuid_time_mid,
  [1090] = 2,
    ACTIONS(172), 1,
      sym_uuid_time_high,
    STATE(61), 1,
      sym_uuid,
  [1097] = 2,
    ACTIONS(122), 1,
      sym__uuid_chunk,
    STATE(85), 1,
      sym_uuid_variant_random,
  [1104] = 2,
    ACTIONS(174), 1,
      aux_sym_month_token1,
    STATE(20), 1,
      sym_day,
  [1111] = 1,
    ACTIONS(146), 1,
      sym_uuid_random,
  [1115] = 1,
    ACTIONS(176), 1,
      aux_sym_description_token1,
  [1119] = 1,
    ACTIONS(178), 1,
      aux_sym_priority_token1,
  [1123] = 1,
    ACTIONS(180), 1,
      aux_sym_story_token1,
  [1127] = 1,
    ACTIONS(182), 1,
      anon_sym_DASH,
  [1131] = 1,
    ACTIONS(184), 1,
      anon_sym_DASH,
  [1135] = 1,
    ACTIONS(186), 1,
      anon_sym_COLON,
  [1139] = 1,
    ACTIONS(188), 1,
      aux_sym_priority_token1,
  [1143] = 1,
    ACTIONS(190), 1,
      sym_name,
  [1147] = 1,
    ACTIONS(170), 1,
      sym_uuid_random,
  [1151] = 1,
    ACTIONS(192), 1,
      anon_sym_COLON,
  [1155] = 1,
    ACTIONS(194), 1,
      anon_sym_RPAREN,
  [1159] = 1,
    ACTIONS(196), 1,
      anon_sym_RPAREN,
  [1163] = 1,
    ACTIONS(164), 1,
      sym_uuid_random,
  [1167] = 1,
    ACTIONS(198), 1,
      anon_sym_DASH,
  [1171] = 1,
    ACTIONS(200), 1,
      sym_uuid_random,
  [1175] = 1,
    ACTIONS(202), 1,
      ts_builtin_sym_end,
  [1179] = 1,
    ACTIONS(204), 1,
      sym_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 48,
  [SMALL_STATE(4)] = 90,
  [SMALL_STATE(5)] = 126,
  [SMALL_STATE(6)] = 162,
  [SMALL_STATE(7)] = 182,
  [SMALL_STATE(8)] = 212,
  [SMALL_STATE(9)] = 242,
  [SMALL_STATE(10)] = 272,
  [SMALL_STATE(11)] = 285,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 319,
  [SMALL_STATE(14)] = 343,
  [SMALL_STATE(15)] = 355,
  [SMALL_STATE(16)] = 379,
  [SMALL_STATE(17)] = 403,
  [SMALL_STATE(18)] = 427,
  [SMALL_STATE(19)] = 438,
  [SMALL_STATE(20)] = 451,
  [SMALL_STATE(21)] = 465,
  [SMALL_STATE(22)] = 475,
  [SMALL_STATE(23)] = 489,
  [SMALL_STATE(24)] = 507,
  [SMALL_STATE(25)] = 525,
  [SMALL_STATE(26)] = 543,
  [SMALL_STATE(27)] = 561,
  [SMALL_STATE(28)] = 579,
  [SMALL_STATE(29)] = 589,
  [SMALL_STATE(30)] = 604,
  [SMALL_STATE(31)] = 619,
  [SMALL_STATE(32)] = 628,
  [SMALL_STATE(33)] = 645,
  [SMALL_STATE(34)] = 662,
  [SMALL_STATE(35)] = 674,
  [SMALL_STATE(36)] = 682,
  [SMALL_STATE(37)] = 694,
  [SMALL_STATE(38)] = 706,
  [SMALL_STATE(39)] = 718,
  [SMALL_STATE(40)] = 730,
  [SMALL_STATE(41)] = 738,
  [SMALL_STATE(42)] = 746,
  [SMALL_STATE(43)] = 758,
  [SMALL_STATE(44)] = 770,
  [SMALL_STATE(45)] = 778,
  [SMALL_STATE(46)] = 790,
  [SMALL_STATE(47)] = 798,
  [SMALL_STATE(48)] = 805,
  [SMALL_STATE(49)] = 816,
  [SMALL_STATE(50)] = 825,
  [SMALL_STATE(51)] = 831,
  [SMALL_STATE(52)] = 837,
  [SMALL_STATE(53)] = 843,
  [SMALL_STATE(54)] = 849,
  [SMALL_STATE(55)] = 855,
  [SMALL_STATE(56)] = 865,
  [SMALL_STATE(57)] = 871,
  [SMALL_STATE(58)] = 877,
  [SMALL_STATE(59)] = 887,
  [SMALL_STATE(60)] = 893,
  [SMALL_STATE(61)] = 899,
  [SMALL_STATE(62)] = 905,
  [SMALL_STATE(63)] = 911,
  [SMALL_STATE(64)] = 921,
  [SMALL_STATE(65)] = 931,
  [SMALL_STATE(66)] = 941,
  [SMALL_STATE(67)] = 951,
  [SMALL_STATE(68)] = 961,
  [SMALL_STATE(69)] = 967,
  [SMALL_STATE(70)] = 973,
  [SMALL_STATE(71)] = 979,
  [SMALL_STATE(72)] = 984,
  [SMALL_STATE(73)] = 991,
  [SMALL_STATE(74)] = 998,
  [SMALL_STATE(75)] = 1005,
  [SMALL_STATE(76)] = 1012,
  [SMALL_STATE(77)] = 1017,
  [SMALL_STATE(78)] = 1024,
  [SMALL_STATE(79)] = 1029,
  [SMALL_STATE(80)] = 1036,
  [SMALL_STATE(81)] = 1041,
  [SMALL_STATE(82)] = 1048,
  [SMALL_STATE(83)] = 1055,
  [SMALL_STATE(84)] = 1062,
  [SMALL_STATE(85)] = 1069,
  [SMALL_STATE(86)] = 1076,
  [SMALL_STATE(87)] = 1083,
  [SMALL_STATE(88)] = 1090,
  [SMALL_STATE(89)] = 1097,
  [SMALL_STATE(90)] = 1104,
  [SMALL_STATE(91)] = 1111,
  [SMALL_STATE(92)] = 1115,
  [SMALL_STATE(93)] = 1119,
  [SMALL_STATE(94)] = 1123,
  [SMALL_STATE(95)] = 1127,
  [SMALL_STATE(96)] = 1131,
  [SMALL_STATE(97)] = 1135,
  [SMALL_STATE(98)] = 1139,
  [SMALL_STATE(99)] = 1143,
  [SMALL_STATE(100)] = 1147,
  [SMALL_STATE(101)] = 1151,
  [SMALL_STATE(102)] = 1155,
  [SMALL_STATE(103)] = 1159,
  [SMALL_STATE(104)] = 1163,
  [SMALL_STATE(105)] = 1167,
  [SMALL_STATE(106)] = 1171,
  [SMALL_STATE(107)] = 1175,
  [SMALL_STATE(108)] = 1179,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 4),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(19),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 6),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 7),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(30),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2), SHIFT_REPEAT(63),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action_list, 1),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 8),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 7),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 9),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 6),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 5),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 8),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 9),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_time_mid, 1),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_version_random, 1),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_variant_random, 1),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 2),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [202] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
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
