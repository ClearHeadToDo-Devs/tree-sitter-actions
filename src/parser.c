#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 103
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 0
#define TOKEN_COUNT 33
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  sym_not_started = 3,
  sym_completed = 4,
  anon_sym_DASH = 5,
  sym_blocked = 6,
  sym_cancelled = 7,
  sym_name = 8,
  aux_sym_description_token1 = 9,
  sym_desc_icon = 10,
  aux_sym_priority_token1 = 11,
  sym_priority_icon = 12,
  aux_sym_story_token1 = 13,
  sym_story_icon = 14,
  sym_context_icon = 15,
  aux_sym_middle_context_token1 = 16,
  sym_context_separator = 17,
  sym_do_date_icon = 18,
  anon_sym_PERCENT = 19,
  sym_year = 20,
  aux_sym_month_token1 = 21,
  anon_sym_COLON = 22,
  anon_sym_am = 23,
  anon_sym_pm = 24,
  anon_sym_AM = 25,
  anon_sym_PM = 26,
  sym_time_designator = 27,
  sym_duration_designator = 28,
  sym_id_icon = 29,
  sym_uuid_time_high = 30,
  sym_uuid_random = 31,
  sym_uuid_chunk = 32,
  sym_action_list = 33,
  sym_action = 34,
  sym_state = 35,
  sym_in_progress = 36,
  sym_description = 37,
  sym_priority = 38,
  sym_story = 39,
  sym_context_list = 40,
  sym_middle_context = 41,
  sym_tail_context = 42,
  sym_do_date_or_time = 43,
  sym_completed_date = 44,
  sym_date = 45,
  sym_month = 46,
  sym_day = 47,
  sym_time = 48,
  sym_hour = 49,
  sym_minute = 50,
  sym_duration = 51,
  sym_id = 52,
  sym_uuid = 53,
  sym_uuid_time_mid = 54,
  sym_uuid_version_random = 55,
  sym_uuid_variant_random = 56,
  aux_sym_action_list_repeat1 = 57,
  aux_sym_context_list_repeat1 = 58,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym_uuid_chunk] = "uuid_chunk",
  [sym_action_list] = "action_list",
  [sym_action] = "action",
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
  [aux_sym_context_list_repeat1] = "context_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym_uuid_chunk] = sym_uuid_chunk,
  [sym_action_list] = sym_action_list,
  [sym_action] = sym_action,
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
  [aux_sym_context_list_repeat1] = aux_sym_context_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [sym_uuid_chunk] = {
    .visible = true,
    .named = true,
  },
  [sym_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_action] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(41);
      if (lookahead == '!') ADVANCE(55);
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '$') ADVANCE(53);
      if (lookahead == '%') ADVANCE(63);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == ')') ADVANCE(43);
      if (lookahead == '*') ADVANCE(58);
      if (lookahead == '+') ADVANCE(59);
      if (lookahead == ',') ADVANCE(61);
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == ':') ADVANCE(66);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '@') ADVANCE(62);
      if (lookahead == 'A') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(72);
      if (lookahead == 'P') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(71);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'a') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(45);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(44);
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'x') ADVANCE(45);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == 'M') ADVANCE(69);
      END_STATE();
    case 5:
      if (lookahead == 'M') ADVANCE(70);
      END_STATE();
    case 6:
      if (lookahead == 'T') ADVANCE(71);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(67);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(68);
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
          lookahead == ' ') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    case 12:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(50);
      END_STATE();
    case 13:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(57);
      END_STATE();
    case 14:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(74);
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
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '%') ADVANCE(63);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == ',') ADVANCE(61);
      if (lookahead == '@') ADVANCE(62);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(40)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(50);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(57);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_time_designator);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_duration_designator);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_id_icon);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_uuid_time_high);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_uuid_random);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_uuid_chunk);
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
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 40},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 40},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 9},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 3},
  [63] = {.lex_state = 9},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 9},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 10},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 9},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 14},
  [86] = {.lex_state = 11},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 14},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 12},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 12},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 13},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [sym_action_list] = STATE(92),
    [sym_action] = STATE(32),
    [sym_state] = STATE(93),
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
    STATE(9), 1,
      sym_story,
    STATE(16), 1,
      sym_context_list,
    STATE(25), 1,
      sym_do_date_or_time,
    STATE(39), 1,
      sym_completed_date,
    STATE(65), 1,
      sym_id,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [47] = 13,
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
    STATE(8), 1,
      sym_story,
    STATE(15), 1,
      sym_context_list,
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [88] = 11,
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
    STATE(14), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(55), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [123] = 11,
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
    STATE(8), 1,
      sym_story,
    STATE(15), 1,
      sym_context_list,
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [158] = 4,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(33), 1,
      sym_duration,
    ACTIONS(27), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
    ACTIONS(29), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
  [177] = 9,
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
    STATE(37), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [206] = 9,
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
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(55), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [235] = 9,
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
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [264] = 1,
    ACTIONS(35), 9,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
      sym_id_icon,
  [276] = 3,
    ACTIONS(39), 1,
      aux_sym_middle_context_token1,
    STATE(11), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(37), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [292] = 3,
    ACTIONS(44), 1,
      aux_sym_middle_context_token1,
    STATE(11), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(42), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [308] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(24), 1,
      sym_do_date_or_time,
    STATE(38), 1,
      sym_completed_date,
    STATE(75), 1,
      sym_id,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [331] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(23), 1,
      sym_do_date_or_time,
    STATE(37), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [354] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(55), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [377] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [400] = 1,
    ACTIONS(48), 8,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [411] = 1,
    ACTIONS(50), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [421] = 2,
    ACTIONS(54), 1,
      sym_context_separator,
    ACTIONS(52), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [433] = 3,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(43), 1,
      sym_duration,
    ACTIONS(56), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [446] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(45), 1,
      sym_completed_date,
    STATE(55), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [463] = 3,
    ACTIONS(60), 1,
      sym_time_designator,
    STATE(40), 1,
      sym_time,
    ACTIONS(58), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [476] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(38), 1,
      sym_completed_date,
    STATE(75), 1,
      sym_id,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [493] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(36), 1,
      sym_completed_date,
    STATE(84), 1,
      sym_id,
    ACTIONS(62), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [510] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(42), 1,
      sym_completed_date,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [527] = 4,
    ACTIONS(64), 1,
      sym_not_started,
    ACTIONS(68), 1,
      anon_sym_DASH,
    STATE(101), 1,
      sym_in_progress,
    ACTIONS(66), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [542] = 1,
    ACTIONS(70), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [551] = 1,
    ACTIONS(72), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [560] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(37), 1,
      sym_completed_date,
    STATE(53), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [577] = 1,
    ACTIONS(74), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_time_designator,
      sym_id_icon,
  [585] = 4,
    ACTIONS(76), 1,
      ts_builtin_sym_end,
    ACTIONS(78), 1,
      anon_sym_LPAREN,
    STATE(93), 1,
      sym_state,
    STATE(31), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [599] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    STATE(93), 1,
      sym_state,
    STATE(31), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [613] = 1,
    ACTIONS(56), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [620] = 1,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [627] = 2,
    ACTIONS(44), 1,
      aux_sym_middle_context_token1,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [636] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(57), 1,
      sym_id,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [647] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(75), 1,
      sym_id,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [658] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(84), 1,
      sym_id,
    ACTIONS(62), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [669] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(64), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [680] = 1,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [687] = 1,
    ACTIONS(89), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [694] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(55), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [705] = 1,
    ACTIONS(91), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [712] = 3,
    ACTIONS(60), 1,
      sym_time_designator,
    ACTIONS(93), 1,
      sym_year,
    STATE(41), 2,
      sym_date,
      sym_time,
  [723] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(53), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [734] = 3,
    ACTIONS(95), 1,
      anon_sym_DASH,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    STATE(73), 1,
      sym_uuid_variant_random,
  [744] = 3,
    ACTIONS(99), 1,
      anon_sym_DASH,
    ACTIONS(101), 1,
      sym_uuid_chunk,
    STATE(52), 1,
      sym_uuid_version_random,
  [754] = 3,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    ACTIONS(103), 1,
      anon_sym_DASH,
    STATE(62), 1,
      sym_uuid_variant_random,
  [764] = 1,
    ACTIONS(105), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_id_icon,
  [770] = 3,
    ACTIONS(107), 1,
      anon_sym_DASH,
    ACTIONS(109), 1,
      sym_uuid_chunk,
    STATE(51), 1,
      sym_uuid_time_mid,
  [780] = 3,
    ACTIONS(101), 1,
      sym_uuid_chunk,
    ACTIONS(111), 1,
      anon_sym_DASH,
    STATE(46), 1,
      sym_uuid_version_random,
  [790] = 3,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    ACTIONS(113), 1,
      anon_sym_DASH,
    STATE(82), 1,
      sym_uuid_variant_random,
  [800] = 1,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [805] = 2,
    ACTIONS(93), 1,
      sym_year,
    STATE(49), 1,
      sym_date,
  [812] = 1,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [817] = 2,
    ACTIONS(115), 1,
      anon_sym_DASH,
    ACTIONS(117), 1,
      sym_uuid_random,
  [824] = 1,
    ACTIONS(119), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [829] = 2,
    ACTIONS(121), 1,
      aux_sym_month_token1,
    STATE(6), 1,
      sym_minute,
  [836] = 2,
    ACTIONS(101), 1,
      sym_uuid_chunk,
    STATE(52), 1,
      sym_uuid_version_random,
  [843] = 1,
    ACTIONS(123), 2,
      anon_sym_DASH,
      sym_uuid_chunk,
  [848] = 1,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [853] = 2,
    ACTIONS(127), 1,
      anon_sym_DASH,
    ACTIONS(129), 1,
      sym_uuid_random,
  [860] = 2,
    ACTIONS(131), 1,
      aux_sym_month_token1,
    STATE(97), 1,
      sym_month,
  [867] = 1,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [872] = 1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [877] = 2,
    ACTIONS(133), 1,
      aux_sym_month_token1,
    STATE(22), 1,
      sym_day,
  [884] = 2,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    STATE(56), 1,
      sym_uuid_variant_random,
  [891] = 1,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [896] = 2,
    ACTIONS(101), 1,
      sym_uuid_chunk,
    STATE(48), 1,
      sym_uuid_version_random,
  [903] = 1,
    ACTIONS(137), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [908] = 2,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    STATE(82), 1,
      sym_uuid_variant_random,
  [915] = 1,
    ACTIONS(139), 2,
      anon_sym_DASH,
      sym_uuid_random,
  [920] = 2,
    ACTIONS(141), 1,
      anon_sym_DASH,
    ACTIONS(143), 1,
      sym_uuid_random,
  [927] = 2,
    ACTIONS(145), 1,
      sym_uuid_time_high,
    STATE(76), 1,
      sym_uuid,
  [934] = 1,
    ACTIONS(62), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [939] = 1,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [944] = 1,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [949] = 1,
    ACTIONS(151), 2,
      anon_sym_DASH,
      sym_uuid_chunk,
  [954] = 2,
    ACTIONS(153), 1,
      aux_sym_month_token1,
    STATE(90), 1,
      sym_hour,
  [961] = 2,
    ACTIONS(109), 1,
      sym_uuid_chunk,
    STATE(47), 1,
      sym_uuid_time_mid,
  [968] = 2,
    ACTIONS(97), 1,
      sym_uuid_chunk,
    STATE(62), 1,
      sym_uuid_variant_random,
  [975] = 2,
    ACTIONS(155), 1,
      anon_sym_DASH,
    ACTIONS(157), 1,
      sym_uuid_random,
  [982] = 1,
    ACTIONS(159), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [987] = 1,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [992] = 1,
    ACTIONS(161), 1,
      aux_sym_priority_token1,
  [996] = 1,
    ACTIONS(163), 1,
      aux_sym_description_token1,
  [1000] = 1,
    ACTIONS(165), 1,
      anon_sym_DASH,
  [1004] = 1,
    ACTIONS(167), 1,
      aux_sym_priority_token1,
  [1008] = 1,
    ACTIONS(157), 1,
      sym_uuid_random,
  [1012] = 1,
    ACTIONS(169), 1,
      anon_sym_COLON,
  [1016] = 1,
    ACTIONS(171), 1,
      sym_name,
  [1020] = 1,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
  [1024] = 1,
    ACTIONS(175), 1,
      sym_name,
  [1028] = 1,
    ACTIONS(129), 1,
      sym_uuid_random,
  [1032] = 1,
    ACTIONS(177), 1,
      aux_sym_story_token1,
  [1036] = 1,
    ACTIONS(179), 1,
      anon_sym_COLON,
  [1040] = 1,
    ACTIONS(181), 1,
      anon_sym_DASH,
  [1044] = 1,
    ACTIONS(117), 1,
      sym_uuid_random,
  [1048] = 1,
    ACTIONS(183), 1,
      anon_sym_DASH,
  [1052] = 1,
    ACTIONS(185), 1,
      sym_uuid_random,
  [1056] = 1,
    ACTIONS(187), 1,
      anon_sym_RPAREN,
  [1060] = 1,
    ACTIONS(189), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 88,
  [SMALL_STATE(5)] = 123,
  [SMALL_STATE(6)] = 158,
  [SMALL_STATE(7)] = 177,
  [SMALL_STATE(8)] = 206,
  [SMALL_STATE(9)] = 235,
  [SMALL_STATE(10)] = 264,
  [SMALL_STATE(11)] = 276,
  [SMALL_STATE(12)] = 292,
  [SMALL_STATE(13)] = 308,
  [SMALL_STATE(14)] = 331,
  [SMALL_STATE(15)] = 354,
  [SMALL_STATE(16)] = 377,
  [SMALL_STATE(17)] = 400,
  [SMALL_STATE(18)] = 411,
  [SMALL_STATE(19)] = 421,
  [SMALL_STATE(20)] = 433,
  [SMALL_STATE(21)] = 446,
  [SMALL_STATE(22)] = 463,
  [SMALL_STATE(23)] = 476,
  [SMALL_STATE(24)] = 493,
  [SMALL_STATE(25)] = 510,
  [SMALL_STATE(26)] = 527,
  [SMALL_STATE(27)] = 542,
  [SMALL_STATE(28)] = 551,
  [SMALL_STATE(29)] = 560,
  [SMALL_STATE(30)] = 577,
  [SMALL_STATE(31)] = 585,
  [SMALL_STATE(32)] = 599,
  [SMALL_STATE(33)] = 613,
  [SMALL_STATE(34)] = 620,
  [SMALL_STATE(35)] = 627,
  [SMALL_STATE(36)] = 636,
  [SMALL_STATE(37)] = 647,
  [SMALL_STATE(38)] = 658,
  [SMALL_STATE(39)] = 669,
  [SMALL_STATE(40)] = 680,
  [SMALL_STATE(41)] = 687,
  [SMALL_STATE(42)] = 694,
  [SMALL_STATE(43)] = 705,
  [SMALL_STATE(44)] = 712,
  [SMALL_STATE(45)] = 723,
  [SMALL_STATE(46)] = 734,
  [SMALL_STATE(47)] = 744,
  [SMALL_STATE(48)] = 754,
  [SMALL_STATE(49)] = 764,
  [SMALL_STATE(50)] = 770,
  [SMALL_STATE(51)] = 780,
  [SMALL_STATE(52)] = 790,
  [SMALL_STATE(53)] = 800,
  [SMALL_STATE(54)] = 805,
  [SMALL_STATE(55)] = 812,
  [SMALL_STATE(56)] = 817,
  [SMALL_STATE(57)] = 824,
  [SMALL_STATE(58)] = 829,
  [SMALL_STATE(59)] = 836,
  [SMALL_STATE(60)] = 843,
  [SMALL_STATE(61)] = 848,
  [SMALL_STATE(62)] = 853,
  [SMALL_STATE(63)] = 860,
  [SMALL_STATE(64)] = 867,
  [SMALL_STATE(65)] = 872,
  [SMALL_STATE(66)] = 877,
  [SMALL_STATE(67)] = 884,
  [SMALL_STATE(68)] = 891,
  [SMALL_STATE(69)] = 896,
  [SMALL_STATE(70)] = 903,
  [SMALL_STATE(71)] = 908,
  [SMALL_STATE(72)] = 915,
  [SMALL_STATE(73)] = 920,
  [SMALL_STATE(74)] = 927,
  [SMALL_STATE(75)] = 934,
  [SMALL_STATE(76)] = 939,
  [SMALL_STATE(77)] = 944,
  [SMALL_STATE(78)] = 949,
  [SMALL_STATE(79)] = 954,
  [SMALL_STATE(80)] = 961,
  [SMALL_STATE(81)] = 968,
  [SMALL_STATE(82)] = 975,
  [SMALL_STATE(83)] = 982,
  [SMALL_STATE(84)] = 987,
  [SMALL_STATE(85)] = 992,
  [SMALL_STATE(86)] = 996,
  [SMALL_STATE(87)] = 1000,
  [SMALL_STATE(88)] = 1004,
  [SMALL_STATE(89)] = 1008,
  [SMALL_STATE(90)] = 1012,
  [SMALL_STATE(91)] = 1016,
  [SMALL_STATE(92)] = 1020,
  [SMALL_STATE(93)] = 1024,
  [SMALL_STATE(94)] = 1028,
  [SMALL_STATE(95)] = 1032,
  [SMALL_STATE(96)] = 1036,
  [SMALL_STATE(97)] = 1040,
  [SMALL_STATE(98)] = 1044,
  [SMALL_STATE(99)] = 1048,
  [SMALL_STATE(100)] = 1052,
  [SMALL_STATE(101)] = 1056,
  [SMALL_STATE(102)] = 1060,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(19),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 7),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(26),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 8),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 9),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_version_random, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 6),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 7),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 9),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_variant_random, 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 8),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_time_mid, 1),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 5),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [173] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
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
