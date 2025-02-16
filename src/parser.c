#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 66
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 0
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
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
  sym_action_list = 29,
  sym_action = 30,
  sym_state = 31,
  sym_in_progress = 32,
  sym_description = 33,
  sym_priority = 34,
  sym_story = 35,
  sym_context_list = 36,
  sym_middle_context = 37,
  sym_tail_context = 38,
  sym_do_date_or_time = 39,
  sym_completed_date = 40,
  sym_date = 41,
  sym_month = 42,
  sym_day = 43,
  sym_time = 44,
  sym_hour = 45,
  sym_minute = 46,
  sym_duration = 47,
  aux_sym_action_list_repeat1 = 48,
  aux_sym_context_list_repeat1 = 49,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '$') ADVANCE(29);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(34);
      if (lookahead == '+') ADVANCE(35);
      if (lookahead == ',') ADVANCE(37);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == '=') ADVANCE(23);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == 'A') ADVANCE(2);
      if (lookahead == 'D') ADVANCE(48);
      if (lookahead == 'P') ADVANCE(3);
      if (lookahead == 'T') ADVANCE(47);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == 'a') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(20);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '=') ADVANCE(23);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == 'x') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'M') ADVANCE(45);
      END_STATE();
    case 3:
      if (lookahead == 'M') ADVANCE(46);
      END_STATE();
    case 4:
      if (lookahead == 'T') ADVANCE(47);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == 'm') ADVANCE(43);
      END_STATE();
    case 6:
      if (lookahead == 'm') ADVANCE(44);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 8:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(26);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(33);
      END_STATE();
    case 11:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ',') ADVANCE(37);
      if (lookahead == '@') ADVANCE(38);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(26);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(33);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_time_designator);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_duration_designator);
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
  [7] = {.lex_state = 16},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 16},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 16},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 16},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 16},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 7},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 7},
  [49] = {.lex_state = 7},
  [50] = {.lex_state = 7},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 8},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 9},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 8},
  [60] = {.lex_state = 11},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 11},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 10},
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
  },
  [1] = {
    [sym_action_list] = STATE(64),
    [sym_action] = STATE(23),
    [sym_state] = STATE(59),
    [aux_sym_action_list_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
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
    STATE(3), 1,
      sym_description,
    STATE(5), 1,
      sym_priority,
    STATE(11), 1,
      sym_story,
    STATE(18), 1,
      sym_context_list,
    STATE(29), 1,
      sym_do_date_or_time,
    STATE(43), 1,
      sym_completed_date,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [41] = 11,
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
    STATE(4), 1,
      sym_priority,
    STATE(12), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [76] = 9,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(9), 1,
      sym_story,
    STATE(15), 1,
      sym_context_list,
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [105] = 9,
    ACTIONS(13), 1,
      sym_story_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(12), 1,
      sym_story,
    STATE(17), 1,
      sym_context_list,
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [134] = 4,
    ACTIONS(29), 1,
      sym_duration_designator,
    STATE(39), 1,
      sym_duration,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
    ACTIONS(27), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
  [152] = 3,
    ACTIONS(33), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(31), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [167] = 1,
    ACTIONS(35), 8,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
  [178] = 7,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(14), 1,
      sym_context_list,
    STATE(34), 1,
      sym_do_date_or_time,
    STATE(51), 1,
      sym_completed_date,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [201] = 3,
    ACTIONS(41), 1,
      aux_sym_middle_context_token1,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(39), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [216] = 7,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(17), 1,
      sym_context_list,
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [239] = 7,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(15), 1,
      sym_context_list,
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [262] = 1,
    ACTIONS(44), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [272] = 5,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(32), 1,
      sym_do_date_or_time,
    STATE(47), 1,
      sym_completed_date,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [289] = 5,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(34), 1,
      sym_do_date_or_time,
    STATE(51), 1,
      sym_completed_date,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [306] = 4,
    ACTIONS(48), 1,
      sym_not_started,
    ACTIONS(52), 1,
      anon_sym_DASH,
    STATE(58), 1,
      sym_in_progress,
    ACTIONS(50), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [321] = 5,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(45), 1,
      sym_completed_date,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [338] = 5,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [355] = 1,
    ACTIONS(54), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [364] = 2,
    ACTIONS(58), 1,
      sym_context_separator,
    ACTIONS(56), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [375] = 4,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(62), 1,
      anon_sym_LPAREN,
    STATE(59), 1,
      sym_state,
    STATE(21), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [389] = 1,
    ACTIONS(65), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [397] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    STATE(59), 1,
      sym_state,
    STATE(21), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [411] = 3,
    ACTIONS(71), 1,
      sym_time_designator,
    STATE(38), 1,
      sym_time,
    ACTIONS(69), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [423] = 3,
    ACTIONS(29), 1,
      sym_duration_designator,
    STATE(37), 1,
      sym_duration,
    ACTIONS(73), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [435] = 1,
    ACTIONS(75), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
  [443] = 3,
    ACTIONS(71), 1,
      sym_time_designator,
    ACTIONS(77), 1,
      sym_year,
    STATE(36), 2,
      sym_date,
      sym_time,
  [454] = 3,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(51), 1,
      sym_completed_date,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [465] = 3,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(46), 1,
      sym_completed_date,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [476] = 3,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(45), 1,
      sym_completed_date,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [487] = 1,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
      sym_time_designator,
  [494] = 3,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(44), 1,
      sym_completed_date,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [505] = 2,
    ACTIONS(33), 1,
      aux_sym_middle_context_token1,
    STATE(7), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [514] = 3,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(47), 1,
      sym_completed_date,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [525] = 1,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [531] = 1,
    ACTIONS(85), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [537] = 1,
    ACTIONS(87), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [543] = 1,
    ACTIONS(89), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [549] = 1,
    ACTIONS(73), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [555] = 2,
    ACTIONS(77), 1,
      sym_year,
    STATE(42), 1,
      sym_date,
  [562] = 2,
    ACTIONS(91), 1,
      aux_sym_month_token1,
    STATE(24), 1,
      sym_day,
  [569] = 1,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [574] = 1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [579] = 1,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [584] = 1,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [589] = 1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [594] = 1,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [599] = 2,
    ACTIONS(97), 1,
      aux_sym_month_token1,
    STATE(6), 1,
      sym_minute,
  [606] = 2,
    ACTIONS(99), 1,
      aux_sym_month_token1,
    STATE(61), 1,
      sym_month,
  [613] = 2,
    ACTIONS(101), 1,
      aux_sym_month_token1,
    STATE(55), 1,
      sym_hour,
  [620] = 1,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [625] = 1,
    ACTIONS(103), 1,
      sym_name,
  [629] = 1,
    ACTIONS(105), 1,
      anon_sym_COLON,
  [633] = 1,
    ACTIONS(107), 1,
      anon_sym_RPAREN,
  [637] = 1,
    ACTIONS(109), 1,
      anon_sym_COLON,
  [641] = 1,
    ACTIONS(111), 1,
      aux_sym_description_token1,
  [645] = 1,
    ACTIONS(113), 1,
      anon_sym_DASH,
  [649] = 1,
    ACTIONS(115), 1,
      anon_sym_RPAREN,
  [653] = 1,
    ACTIONS(117), 1,
      sym_name,
  [657] = 1,
    ACTIONS(119), 1,
      aux_sym_priority_token1,
  [661] = 1,
    ACTIONS(121), 1,
      anon_sym_DASH,
  [665] = 1,
    ACTIONS(123), 1,
      anon_sym_DASH,
  [669] = 1,
    ACTIONS(125), 1,
      aux_sym_priority_token1,
  [673] = 1,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
  [677] = 1,
    ACTIONS(129), 1,
      aux_sym_story_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 41,
  [SMALL_STATE(4)] = 76,
  [SMALL_STATE(5)] = 105,
  [SMALL_STATE(6)] = 134,
  [SMALL_STATE(7)] = 152,
  [SMALL_STATE(8)] = 167,
  [SMALL_STATE(9)] = 178,
  [SMALL_STATE(10)] = 201,
  [SMALL_STATE(11)] = 216,
  [SMALL_STATE(12)] = 239,
  [SMALL_STATE(13)] = 262,
  [SMALL_STATE(14)] = 272,
  [SMALL_STATE(15)] = 289,
  [SMALL_STATE(16)] = 306,
  [SMALL_STATE(17)] = 321,
  [SMALL_STATE(18)] = 338,
  [SMALL_STATE(19)] = 355,
  [SMALL_STATE(20)] = 364,
  [SMALL_STATE(21)] = 375,
  [SMALL_STATE(22)] = 389,
  [SMALL_STATE(23)] = 397,
  [SMALL_STATE(24)] = 411,
  [SMALL_STATE(25)] = 423,
  [SMALL_STATE(26)] = 435,
  [SMALL_STATE(27)] = 443,
  [SMALL_STATE(28)] = 454,
  [SMALL_STATE(29)] = 465,
  [SMALL_STATE(30)] = 476,
  [SMALL_STATE(31)] = 487,
  [SMALL_STATE(32)] = 494,
  [SMALL_STATE(33)] = 505,
  [SMALL_STATE(34)] = 514,
  [SMALL_STATE(35)] = 525,
  [SMALL_STATE(36)] = 531,
  [SMALL_STATE(37)] = 537,
  [SMALL_STATE(38)] = 543,
  [SMALL_STATE(39)] = 549,
  [SMALL_STATE(40)] = 555,
  [SMALL_STATE(41)] = 562,
  [SMALL_STATE(42)] = 569,
  [SMALL_STATE(43)] = 574,
  [SMALL_STATE(44)] = 579,
  [SMALL_STATE(45)] = 584,
  [SMALL_STATE(46)] = 589,
  [SMALL_STATE(47)] = 594,
  [SMALL_STATE(48)] = 599,
  [SMALL_STATE(49)] = 606,
  [SMALL_STATE(50)] = 613,
  [SMALL_STATE(51)] = 620,
  [SMALL_STATE(52)] = 625,
  [SMALL_STATE(53)] = 629,
  [SMALL_STATE(54)] = 633,
  [SMALL_STATE(55)] = 637,
  [SMALL_STATE(56)] = 641,
  [SMALL_STATE(57)] = 645,
  [SMALL_STATE(58)] = 649,
  [SMALL_STATE(59)] = 653,
  [SMALL_STATE(60)] = 657,
  [SMALL_STATE(61)] = 661,
  [SMALL_STATE(62)] = 665,
  [SMALL_STATE(63)] = 669,
  [SMALL_STATE(64)] = 673,
  [SMALL_STATE(65)] = 677,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(20),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(16),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 7),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 8),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [127] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
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
