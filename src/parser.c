#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 75
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 0
#define TOKEN_COUNT 31
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
  sym_uuid = 30,
  sym_action_list = 31,
  sym_action = 32,
  sym_state = 33,
  sym_in_progress = 34,
  sym_description = 35,
  sym_priority = 36,
  sym_story = 37,
  sym_context_list = 38,
  sym_middle_context = 39,
  sym_tail_context = 40,
  sym_do_date_or_time = 41,
  sym_completed_date = 42,
  sym_date = 43,
  sym_month = 44,
  sym_day = 45,
  sym_time = 46,
  sym_hour = 47,
  sym_minute = 48,
  sym_duration = 49,
  sym_id = 50,
  aux_sym_action_list_repeat1 = 51,
  aux_sym_context_list_repeat1 = 52,
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
  [sym_uuid] = "uuid",
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
  [sym_uuid] = sym_uuid,
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
  [sym_uuid] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(49);
      if (lookahead == '!') ADVANCE(63);
      if (lookahead == '#') ADVANCE(81);
      if (lookahead == '$') ADVANCE(61);
      if (lookahead == '%') ADVANCE(71);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == '*') ADVANCE(66);
      if (lookahead == '+') ADVANCE(67);
      if (lookahead == ',') ADVANCE(69);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead == ':') ADVANCE(74);
      if (lookahead == '=') ADVANCE(55);
      if (lookahead == '@') ADVANCE(70);
      if (lookahead == 'A') ADVANCE(2);
      if (lookahead == 'D') ADVANCE(80);
      if (lookahead == 'P') ADVANCE(3);
      if (lookahead == 'T') ADVANCE(79);
      if (lookahead == '_') ADVANCE(56);
      if (lookahead == 'a') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(53);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(52);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead == '=') ADVANCE(55);
      if (lookahead == '_') ADVANCE(56);
      if (lookahead == 'x') ADVANCE(53);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'M') ADVANCE(77);
      END_STATE();
    case 3:
      if (lookahead == 'M') ADVANCE(78);
      END_STATE();
    case 4:
      if (lookahead == 'T') ADVANCE(79);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == 'm') ADVANCE(75);
      END_STATE();
    case 6:
      if (lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 8:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(65);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 11:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 12:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(18);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
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
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(44);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 48:
      if (eof) ADVANCE(49);
      if (lookahead == '#') ADVANCE(81);
      if (lookahead == '%') ADVANCE(71);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ',') ADVANCE(69);
      if (lookahead == '@') ADVANCE(70);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(48)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '-' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_time_designator);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_duration_designator);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_id_icon);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_uuid);
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
  [10] = {.lex_state = 48},
  [11] = {.lex_state = 48},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 48},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 48},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 48},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 7},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 7},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 7},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 12},
  [62] = {.lex_state = 8},
  [63] = {.lex_state = 9},
  [64] = {.lex_state = 10},
  [65] = {.lex_state = 9},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 12},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 11},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
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
    [sym_action_list] = STATE(74),
    [sym_action] = STATE(32),
    [sym_state] = STATE(63),
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
    STATE(33), 1,
      sym_completed_date,
    STATE(47), 1,
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
    STATE(6), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(41), 1,
      sym_completed_date,
    STATE(48), 1,
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
    STATE(8), 1,
      sym_story,
    STATE(15), 1,
      sym_context_list,
    STATE(22), 1,
      sym_do_date_or_time,
    STATE(44), 1,
      sym_completed_date,
    STATE(50), 1,
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
    STATE(6), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(41), 1,
      sym_completed_date,
    STATE(48), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [158] = 9,
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
    STATE(22), 1,
      sym_do_date_or_time,
    STATE(44), 1,
      sym_completed_date,
    STATE(50), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [187] = 4,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(43), 1,
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
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(39), 1,
      sym_completed_date,
    STATE(57), 1,
      sym_id,
    ACTIONS(33), 2,
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
    STATE(17), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(41), 1,
      sym_completed_date,
    STATE(48), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [264] = 3,
    ACTIONS(37), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [280] = 3,
    ACTIONS(42), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(40), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [296] = 1,
    ACTIONS(44), 9,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
      sym_id_icon,
  [308] = 1,
    ACTIONS(46), 8,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
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
    STATE(20), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [342] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(21), 1,
      sym_do_date_or_time,
    STATE(39), 1,
      sym_completed_date,
    STATE(57), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [365] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(41), 1,
      sym_completed_date,
    STATE(48), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [388] = 7,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(22), 1,
      sym_do_date_or_time,
    STATE(44), 1,
      sym_completed_date,
    STATE(50), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
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
  [433] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(34), 1,
      sym_completed_date,
    STATE(51), 1,
      sym_id,
    ACTIONS(56), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [450] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(45), 1,
      sym_completed_date,
    STATE(52), 1,
      sym_id,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [467] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(39), 1,
      sym_completed_date,
    STATE(57), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [484] = 4,
    ACTIONS(58), 1,
      sym_not_started,
    ACTIONS(62), 1,
      anon_sym_DASH,
    STATE(73), 1,
      sym_in_progress,
    ACTIONS(60), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [499] = 3,
    ACTIONS(31), 1,
      sym_duration_designator,
    STATE(37), 1,
      sym_duration,
    ACTIONS(64), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [512] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(41), 1,
      sym_completed_date,
    STATE(48), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [529] = 1,
    ACTIONS(66), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [538] = 1,
    ACTIONS(68), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [547] = 3,
    ACTIONS(72), 1,
      sym_time_designator,
    STATE(40), 1,
      sym_time,
    ACTIONS(70), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [560] = 5,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(44), 1,
      sym_completed_date,
    STATE(50), 1,
      sym_id,
    ACTIONS(25), 2,
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
    STATE(63), 1,
      sym_state,
    STATE(31), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [599] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    STATE(63), 1,
      sym_state,
    STATE(31), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [613] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(48), 1,
      sym_id,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [624] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(49), 1,
      sym_id,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [635] = 2,
    ACTIONS(42), 1,
      aux_sym_middle_context_token1,
    STATE(11), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [644] = 1,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [651] = 1,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [658] = 1,
    ACTIONS(89), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [665] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(52), 1,
      sym_id,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [676] = 1,
    ACTIONS(91), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [683] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(50), 1,
      sym_id,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [694] = 3,
    ACTIONS(72), 1,
      sym_time_designator,
    ACTIONS(93), 1,
      sym_year,
    STATE(38), 2,
      sym_date,
      sym_time,
  [705] = 1,
    ACTIONS(64), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_id_icon,
  [712] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(57), 1,
      sym_id,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [723] = 3,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(51), 1,
      sym_id,
    ACTIONS(56), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [734] = 1,
    ACTIONS(95), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_id_icon,
  [740] = 1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [745] = 1,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [750] = 1,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [755] = 1,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [760] = 1,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [765] = 1,
    ACTIONS(56), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [770] = 2,
    ACTIONS(99), 1,
      aux_sym_month_token1,
    STATE(7), 1,
      sym_minute,
  [777] = 2,
    ACTIONS(93), 1,
      sym_year,
    STATE(46), 1,
      sym_date,
  [784] = 1,
    ACTIONS(101), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [789] = 2,
    ACTIONS(103), 1,
      aux_sym_month_token1,
    STATE(68), 1,
      sym_month,
  [796] = 1,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [801] = 2,
    ACTIONS(105), 1,
      aux_sym_month_token1,
    STATE(28), 1,
      sym_day,
  [808] = 2,
    ACTIONS(107), 1,
      aux_sym_month_token1,
    STATE(71), 1,
      sym_hour,
  [815] = 1,
    ACTIONS(109), 1,
      anon_sym_COLON,
  [819] = 1,
    ACTIONS(111), 1,
      aux_sym_priority_token1,
  [823] = 1,
    ACTIONS(113), 1,
      aux_sym_story_token1,
  [827] = 1,
    ACTIONS(115), 1,
      sym_name,
  [831] = 1,
    ACTIONS(117), 1,
      aux_sym_description_token1,
  [835] = 1,
    ACTIONS(119), 1,
      sym_name,
  [839] = 1,
    ACTIONS(121), 1,
      anon_sym_RPAREN,
  [843] = 1,
    ACTIONS(123), 1,
      aux_sym_priority_token1,
  [847] = 1,
    ACTIONS(125), 1,
      anon_sym_DASH,
  [851] = 1,
    ACTIONS(127), 1,
      anon_sym_DASH,
  [855] = 1,
    ACTIONS(129), 1,
      sym_uuid,
  [859] = 1,
    ACTIONS(131), 1,
      anon_sym_COLON,
  [863] = 1,
    ACTIONS(133), 1,
      anon_sym_DASH,
  [867] = 1,
    ACTIONS(135), 1,
      anon_sym_RPAREN,
  [871] = 1,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 88,
  [SMALL_STATE(5)] = 123,
  [SMALL_STATE(6)] = 158,
  [SMALL_STATE(7)] = 187,
  [SMALL_STATE(8)] = 206,
  [SMALL_STATE(9)] = 235,
  [SMALL_STATE(10)] = 264,
  [SMALL_STATE(11)] = 280,
  [SMALL_STATE(12)] = 296,
  [SMALL_STATE(13)] = 308,
  [SMALL_STATE(14)] = 319,
  [SMALL_STATE(15)] = 342,
  [SMALL_STATE(16)] = 365,
  [SMALL_STATE(17)] = 388,
  [SMALL_STATE(18)] = 411,
  [SMALL_STATE(19)] = 421,
  [SMALL_STATE(20)] = 433,
  [SMALL_STATE(21)] = 450,
  [SMALL_STATE(22)] = 467,
  [SMALL_STATE(23)] = 484,
  [SMALL_STATE(24)] = 499,
  [SMALL_STATE(25)] = 512,
  [SMALL_STATE(26)] = 529,
  [SMALL_STATE(27)] = 538,
  [SMALL_STATE(28)] = 547,
  [SMALL_STATE(29)] = 560,
  [SMALL_STATE(30)] = 577,
  [SMALL_STATE(31)] = 585,
  [SMALL_STATE(32)] = 599,
  [SMALL_STATE(33)] = 613,
  [SMALL_STATE(34)] = 624,
  [SMALL_STATE(35)] = 635,
  [SMALL_STATE(36)] = 644,
  [SMALL_STATE(37)] = 651,
  [SMALL_STATE(38)] = 658,
  [SMALL_STATE(39)] = 665,
  [SMALL_STATE(40)] = 676,
  [SMALL_STATE(41)] = 683,
  [SMALL_STATE(42)] = 694,
  [SMALL_STATE(43)] = 705,
  [SMALL_STATE(44)] = 712,
  [SMALL_STATE(45)] = 723,
  [SMALL_STATE(46)] = 734,
  [SMALL_STATE(47)] = 740,
  [SMALL_STATE(48)] = 745,
  [SMALL_STATE(49)] = 750,
  [SMALL_STATE(50)] = 755,
  [SMALL_STATE(51)] = 760,
  [SMALL_STATE(52)] = 765,
  [SMALL_STATE(53)] = 770,
  [SMALL_STATE(54)] = 777,
  [SMALL_STATE(55)] = 784,
  [SMALL_STATE(56)] = 789,
  [SMALL_STATE(57)] = 796,
  [SMALL_STATE(58)] = 801,
  [SMALL_STATE(59)] = 808,
  [SMALL_STATE(60)] = 815,
  [SMALL_STATE(61)] = 819,
  [SMALL_STATE(62)] = 823,
  [SMALL_STATE(63)] = 827,
  [SMALL_STATE(64)] = 831,
  [SMALL_STATE(65)] = 835,
  [SMALL_STATE(66)] = 839,
  [SMALL_STATE(67)] = 843,
  [SMALL_STATE(68)] = 847,
  [SMALL_STATE(69)] = 851,
  [SMALL_STATE(70)] = 855,
  [SMALL_STATE(71)] = 859,
  [SMALL_STATE(72)] = 863,
  [SMALL_STATE(73)] = 867,
  [SMALL_STATE(74)] = 871,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(19),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 7),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(23),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 8),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 9),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [137] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
