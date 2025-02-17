#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 110
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 65
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
  sym_priority_icon = 12,
  aux_sym_priority_number_token1 = 13,
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
  sym_priority_number = 43,
  sym_story = 44,
  sym_context_list = 45,
  sym_middle_context = 46,
  sym_tail_context = 47,
  sym_do_date_or_time = 48,
  sym_completed_date = 49,
  sym_date = 50,
  sym_month = 51,
  sym_day = 52,
  sym_time = 53,
  sym_hour = 54,
  sym_minute = 55,
  sym_duration = 56,
  sym_id = 57,
  sym_uuid = 58,
  sym_uuid_time_mid = 59,
  sym_uuid_version_random = 60,
  sym_uuid_variant_random = 61,
  aux_sym_action_list_repeat1 = 62,
  aux_sym_child_action_list_repeat1 = 63,
  aux_sym_context_list_repeat1 = 64,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(41);
      if (lookahead == '!') ADVANCE(55);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
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
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_priority_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
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
  [10] = {.lex_state = 40},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 40},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 40},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 40},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 1},
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
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 40},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 9},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 9},
  [84] = {.lex_state = 3},
  [85] = {.lex_state = 9},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 10},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 9},
  [92] = {.lex_state = 14},
  [93] = {.lex_state = 11},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 12},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 14},
  [100] = {.lex_state = 13},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 13},
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
    [sym_action_list] = STATE(108),
    [sym_root_action] = STATE(33),
    [sym_core_action] = STATE(30),
    [sym_state] = STATE(100),
    [aux_sym_action_list_repeat1] = STATE(33),
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
    STATE(16), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(37), 1,
      sym_completed_date,
    STATE(57), 1,
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
    STATE(15), 1,
      sym_context_list,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    STATE(53), 1,
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
    STATE(14), 1,
      sym_context_list,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(43), 1,
      sym_completed_date,
    STATE(61), 1,
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
    STATE(15), 1,
      sym_context_list,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [162] = 4,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(42), 1,
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
    STATE(14), 1,
      sym_context_list,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(43), 1,
      sym_completed_date,
    STATE(61), 1,
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
    STATE(15), 1,
      sym_context_list,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    STATE(53), 1,
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
    STATE(13), 1,
      sym_context_list,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(38), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [272] = 3,
    ACTIONS(37), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(35), 6,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [289] = 1,
    ACTIONS(40), 10,
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
  [302] = 3,
    ACTIONS(44), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(42), 6,
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
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(35), 1,
      sym_completed_date,
    STATE(63), 1,
      sym_id,
    ACTIONS(46), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [343] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(38), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [367] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(43), 1,
      sym_completed_date,
    STATE(61), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [391] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(27), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [415] = 1,
    ACTIONS(48), 9,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
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
  [451] = 1,
    ACTIONS(56), 8,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [462] = 3,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(47), 1,
      sym_duration,
    ACTIONS(58), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [476] = 1,
    ACTIONS(60), 7,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [486] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(35), 1,
      sym_completed_date,
    STATE(63), 1,
      sym_id,
    ACTIONS(46), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [504] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(38), 1,
      sym_completed_date,
    STATE(60), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [522] = 1,
    ACTIONS(62), 7,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [532] = 3,
    ACTIONS(66), 1,
      sym_time_designator,
    STATE(36), 1,
      sym_time,
    ACTIONS(64), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [546] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(43), 1,
      sym_completed_date,
    STATE(61), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [564] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(44), 1,
      sym_completed_date,
    STATE(55), 1,
      sym_id,
    ACTIONS(68), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [582] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(46), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [600] = 4,
    ACTIONS(72), 1,
      sym_child_icon,
    STATE(81), 1,
      sym_child_action_list,
    ACTIONS(70), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(40), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [615] = 4,
    ACTIONS(74), 1,
      sym_not_started,
    ACTIONS(78), 1,
      anon_sym_DASH,
    STATE(103), 1,
      sym_in_progress,
    ACTIONS(76), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [630] = 1,
    ACTIONS(80), 6,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_time_designator,
      sym_id_icon,
  [639] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
    STATE(30), 1,
      sym_core_action,
    STATE(100), 1,
      sym_state,
    STATE(34), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [656] = 5,
    ACTIONS(84), 1,
      ts_builtin_sym_end,
    ACTIONS(86), 1,
      anon_sym_LPAREN,
    STATE(30), 1,
      sym_core_action,
    STATE(100), 1,
      sym_state,
    STATE(34), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [673] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(55), 1,
      sym_id,
    ACTIONS(68), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [685] = 1,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [693] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(53), 1,
      sym_id,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [705] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(63), 1,
      sym_id,
    ACTIONS(46), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [717] = 3,
    ACTIONS(93), 1,
      sym_child_icon,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(39), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [729] = 3,
    ACTIONS(72), 1,
      sym_child_icon,
    ACTIONS(96), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(39), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [741] = 1,
    ACTIONS(98), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [749] = 1,
    ACTIONS(58), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [757] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(60), 1,
      sym_id,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [769] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(52), 1,
      sym_id,
    ACTIONS(100), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [781] = 1,
    ACTIONS(102), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [789] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(61), 1,
      sym_id,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [801] = 1,
    ACTIONS(104), 5,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [809] = 1,
    ACTIONS(106), 4,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
      sym_id_icon,
  [816] = 3,
    ACTIONS(66), 1,
      sym_time_designator,
    ACTIONS(108), 1,
      sym_year,
    STATE(41), 2,
      sym_date,
      sym_time,
  [827] = 2,
    ACTIONS(44), 1,
      aux_sym_middle_context_token1,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [836] = 1,
    ACTIONS(110), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [842] = 1,
    ACTIONS(112), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [848] = 1,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [854] = 1,
    ACTIONS(114), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [860] = 1,
    ACTIONS(100), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [866] = 3,
    ACTIONS(116), 1,
      anon_sym_DASH,
    ACTIONS(118), 1,
      sym__uuid_chunk,
    STATE(68), 1,
      sym_uuid_version_random,
  [876] = 1,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [882] = 1,
    ACTIONS(120), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [888] = 3,
    ACTIONS(122), 1,
      anon_sym_DASH,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    STATE(86), 1,
      sym_uuid_variant_random,
  [898] = 1,
    ACTIONS(46), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [904] = 1,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [910] = 1,
    ACTIONS(126), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [916] = 1,
    ACTIONS(68), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [922] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(70), 1,
      sym_core_action,
    STATE(100), 1,
      sym_state,
  [932] = 3,
    ACTIONS(118), 1,
      sym__uuid_chunk,
    ACTIONS(128), 1,
      anon_sym_DASH,
    STATE(66), 1,
      sym_uuid_version_random,
  [942] = 3,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    ACTIONS(130), 1,
      anon_sym_DASH,
    STATE(73), 1,
      sym_uuid_variant_random,
  [952] = 3,
    ACTIONS(132), 1,
      anon_sym_DASH,
    ACTIONS(134), 1,
      sym__uuid_chunk,
    STATE(56), 1,
      sym_uuid_time_mid,
  [962] = 3,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    ACTIONS(136), 1,
      anon_sym_DASH,
    STATE(80), 1,
      sym_uuid_variant_random,
  [972] = 1,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [978] = 1,
    ACTIONS(140), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [984] = 1,
    ACTIONS(142), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [990] = 1,
    ACTIONS(144), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [995] = 2,
    ACTIONS(146), 1,
      anon_sym_DASH,
    ACTIONS(148), 1,
      sym_uuid_random,
  [1002] = 2,
    ACTIONS(150), 1,
      aux_sym_month_token1,
    STATE(98), 1,
      sym_hour,
  [1009] = 2,
    ACTIONS(108), 1,
      sym_year,
    STATE(48), 1,
      sym_date,
  [1016] = 2,
    ACTIONS(118), 1,
      sym__uuid_chunk,
    STATE(59), 1,
      sym_uuid_version_random,
  [1023] = 1,
    ACTIONS(152), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1028] = 2,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    STATE(73), 1,
      sym_uuid_variant_random,
  [1035] = 1,
    ACTIONS(154), 2,
      anon_sym_DASH,
      sym_uuid_random,
  [1040] = 2,
    ACTIONS(156), 1,
      anon_sym_DASH,
    ACTIONS(158), 1,
      sym_uuid_random,
  [1047] = 1,
    ACTIONS(160), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [1052] = 2,
    ACTIONS(118), 1,
      sym__uuid_chunk,
    STATE(66), 1,
      sym_uuid_version_random,
  [1059] = 2,
    ACTIONS(162), 1,
      aux_sym_month_token1,
    STATE(6), 1,
      sym_minute,
  [1066] = 2,
    ACTIONS(164), 1,
      anon_sym_DASH,
    ACTIONS(166), 1,
      sym_uuid_random,
  [1073] = 2,
    ACTIONS(168), 1,
      aux_sym_month_token1,
    STATE(97), 1,
      sym_month,
  [1080] = 2,
    ACTIONS(170), 1,
      anon_sym_DASH,
    ACTIONS(172), 1,
      sym_uuid_random,
  [1087] = 2,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    STATE(84), 1,
      sym_uuid_variant_random,
  [1094] = 2,
    ACTIONS(134), 1,
      sym__uuid_chunk,
    STATE(65), 1,
      sym_uuid_time_mid,
  [1101] = 2,
    ACTIONS(174), 1,
      sym_uuid_time_high,
    STATE(62), 1,
      sym_uuid,
  [1108] = 2,
    ACTIONS(124), 1,
      sym__uuid_chunk,
    STATE(86), 1,
      sym_uuid_variant_random,
  [1115] = 2,
    ACTIONS(176), 1,
      aux_sym_month_token1,
    STATE(26), 1,
      sym_day,
  [1122] = 2,
    ACTIONS(178), 1,
      aux_sym_priority_number_token1,
    STATE(18), 1,
      sym_priority_number,
  [1129] = 1,
    ACTIONS(180), 1,
      aux_sym_description_token1,
  [1133] = 1,
    ACTIONS(148), 1,
      sym_uuid_random,
  [1137] = 1,
    ACTIONS(182), 1,
      aux_sym_story_token1,
  [1141] = 1,
    ACTIONS(184), 1,
      anon_sym_DASH,
  [1145] = 1,
    ACTIONS(186), 1,
      anon_sym_DASH,
  [1149] = 1,
    ACTIONS(188), 1,
      anon_sym_COLON,
  [1153] = 1,
    ACTIONS(190), 1,
      aux_sym_priority_number_token1,
  [1157] = 1,
    ACTIONS(192), 1,
      sym_name,
  [1161] = 1,
    ACTIONS(172), 1,
      sym_uuid_random,
  [1165] = 1,
    ACTIONS(194), 1,
      anon_sym_COLON,
  [1169] = 1,
    ACTIONS(196), 1,
      anon_sym_RPAREN,
  [1173] = 1,
    ACTIONS(198), 1,
      anon_sym_RPAREN,
  [1177] = 1,
    ACTIONS(166), 1,
      sym_uuid_random,
  [1181] = 1,
    ACTIONS(200), 1,
      anon_sym_DASH,
  [1185] = 1,
    ACTIONS(202), 1,
      sym_uuid_random,
  [1189] = 1,
    ACTIONS(204), 1,
      ts_builtin_sym_end,
  [1193] = 1,
    ACTIONS(206), 1,
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
  [SMALL_STATE(11)] = 289,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 319,
  [SMALL_STATE(14)] = 343,
  [SMALL_STATE(15)] = 367,
  [SMALL_STATE(16)] = 391,
  [SMALL_STATE(17)] = 415,
  [SMALL_STATE(18)] = 427,
  [SMALL_STATE(19)] = 438,
  [SMALL_STATE(20)] = 451,
  [SMALL_STATE(21)] = 462,
  [SMALL_STATE(22)] = 476,
  [SMALL_STATE(23)] = 486,
  [SMALL_STATE(24)] = 504,
  [SMALL_STATE(25)] = 522,
  [SMALL_STATE(26)] = 532,
  [SMALL_STATE(27)] = 546,
  [SMALL_STATE(28)] = 564,
  [SMALL_STATE(29)] = 582,
  [SMALL_STATE(30)] = 600,
  [SMALL_STATE(31)] = 615,
  [SMALL_STATE(32)] = 630,
  [SMALL_STATE(33)] = 639,
  [SMALL_STATE(34)] = 656,
  [SMALL_STATE(35)] = 673,
  [SMALL_STATE(36)] = 685,
  [SMALL_STATE(37)] = 693,
  [SMALL_STATE(38)] = 705,
  [SMALL_STATE(39)] = 717,
  [SMALL_STATE(40)] = 729,
  [SMALL_STATE(41)] = 741,
  [SMALL_STATE(42)] = 749,
  [SMALL_STATE(43)] = 757,
  [SMALL_STATE(44)] = 769,
  [SMALL_STATE(45)] = 781,
  [SMALL_STATE(46)] = 789,
  [SMALL_STATE(47)] = 801,
  [SMALL_STATE(48)] = 809,
  [SMALL_STATE(49)] = 816,
  [SMALL_STATE(50)] = 827,
  [SMALL_STATE(51)] = 836,
  [SMALL_STATE(52)] = 842,
  [SMALL_STATE(53)] = 848,
  [SMALL_STATE(54)] = 854,
  [SMALL_STATE(55)] = 860,
  [SMALL_STATE(56)] = 866,
  [SMALL_STATE(57)] = 876,
  [SMALL_STATE(58)] = 882,
  [SMALL_STATE(59)] = 888,
  [SMALL_STATE(60)] = 898,
  [SMALL_STATE(61)] = 904,
  [SMALL_STATE(62)] = 910,
  [SMALL_STATE(63)] = 916,
  [SMALL_STATE(64)] = 922,
  [SMALL_STATE(65)] = 932,
  [SMALL_STATE(66)] = 942,
  [SMALL_STATE(67)] = 952,
  [SMALL_STATE(68)] = 962,
  [SMALL_STATE(69)] = 972,
  [SMALL_STATE(70)] = 978,
  [SMALL_STATE(71)] = 984,
  [SMALL_STATE(72)] = 990,
  [SMALL_STATE(73)] = 995,
  [SMALL_STATE(74)] = 1002,
  [SMALL_STATE(75)] = 1009,
  [SMALL_STATE(76)] = 1016,
  [SMALL_STATE(77)] = 1023,
  [SMALL_STATE(78)] = 1028,
  [SMALL_STATE(79)] = 1035,
  [SMALL_STATE(80)] = 1040,
  [SMALL_STATE(81)] = 1047,
  [SMALL_STATE(82)] = 1052,
  [SMALL_STATE(83)] = 1059,
  [SMALL_STATE(84)] = 1066,
  [SMALL_STATE(85)] = 1073,
  [SMALL_STATE(86)] = 1080,
  [SMALL_STATE(87)] = 1087,
  [SMALL_STATE(88)] = 1094,
  [SMALL_STATE(89)] = 1101,
  [SMALL_STATE(90)] = 1108,
  [SMALL_STATE(91)] = 1115,
  [SMALL_STATE(92)] = 1122,
  [SMALL_STATE(93)] = 1129,
  [SMALL_STATE(94)] = 1133,
  [SMALL_STATE(95)] = 1137,
  [SMALL_STATE(96)] = 1141,
  [SMALL_STATE(97)] = 1145,
  [SMALL_STATE(98)] = 1149,
  [SMALL_STATE(99)] = 1153,
  [SMALL_STATE(100)] = 1157,
  [SMALL_STATE(101)] = 1161,
  [SMALL_STATE(102)] = 1165,
  [SMALL_STATE(103)] = 1169,
  [SMALL_STATE(104)] = 1173,
  [SMALL_STATE(105)] = 1177,
  [SMALL_STATE(106)] = 1181,
  [SMALL_STATE(107)] = 1185,
  [SMALL_STATE(108)] = 1189,
  [SMALL_STATE(109)] = 1193,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 4),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(19),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 6),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority_number, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 7),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(31),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2), SHIFT_REPEAT(64),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action_list, 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 8),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 7),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 9),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 6),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 5),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 8),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 9),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_time_mid, 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_version_random, 1),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_variant_random, 1),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 2),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [204] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
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
