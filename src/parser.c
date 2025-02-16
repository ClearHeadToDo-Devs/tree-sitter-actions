#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 58
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 0
#define TOKEN_COUNT 28
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
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
  anon_sym_DOLLAR = 9,
  aux_sym_description_token1 = 10,
  anon_sym_BANG = 11,
  aux_sym_priority_token1 = 12,
  anon_sym_STAR = 13,
  aux_sym_story_token1 = 14,
  anon_sym_PLUS = 15,
  aux_sym_middle_context_token1 = 16,
  anon_sym_COMMA = 17,
  anon_sym_AT = 18,
  sym_year = 19,
  aux_sym_month_token1 = 20,
  anon_sym_T = 21,
  anon_sym_COLON = 22,
  anon_sym_am = 23,
  anon_sym_pm = 24,
  anon_sym_AM = 25,
  anon_sym_PM = 26,
  anon_sym_D = 27,
  sym_action_list = 28,
  sym_action = 29,
  sym_state = 30,
  sym_in_progress = 31,
  sym_description = 32,
  sym_priority = 33,
  sym_story = 34,
  sym_context_list = 35,
  sym_middle_context = 36,
  sym_tail_context = 37,
  sym_do_date_or_time = 38,
  sym_date = 39,
  sym_month = 40,
  sym_day = 41,
  sym_time = 42,
  sym_hour = 43,
  sym_minute = 44,
  sym_duration = 45,
  aux_sym_action_list_repeat1 = 46,
  aux_sym_context_list_repeat1 = 47,
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
  [anon_sym_DOLLAR] = "$",
  [aux_sym_description_token1] = "description_token1",
  [anon_sym_BANG] = "!",
  [aux_sym_priority_token1] = "priority_token1",
  [anon_sym_STAR] = "*",
  [aux_sym_story_token1] = "story_token1",
  [anon_sym_PLUS] = "+",
  [aux_sym_middle_context_token1] = "middle_context_token1",
  [anon_sym_COMMA] = ",",
  [anon_sym_AT] = "@",
  [sym_year] = "year",
  [aux_sym_month_token1] = "month_token1",
  [anon_sym_T] = "T",
  [anon_sym_COLON] = ":",
  [anon_sym_am] = "am",
  [anon_sym_pm] = "pm",
  [anon_sym_AM] = "AM",
  [anon_sym_PM] = "PM",
  [anon_sym_D] = "D",
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
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym_description_token1] = aux_sym_description_token1,
  [anon_sym_BANG] = anon_sym_BANG,
  [aux_sym_priority_token1] = aux_sym_priority_token1,
  [anon_sym_STAR] = anon_sym_STAR,
  [aux_sym_story_token1] = aux_sym_story_token1,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [aux_sym_middle_context_token1] = aux_sym_middle_context_token1,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_AT] = anon_sym_AT,
  [sym_year] = sym_year,
  [aux_sym_month_token1] = aux_sym_month_token1,
  [anon_sym_T] = anon_sym_T,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_am] = anon_sym_am,
  [anon_sym_pm] = anon_sym_pm,
  [anon_sym_AM] = anon_sym_AM,
  [anon_sym_PM] = anon_sym_PM,
  [anon_sym_D] = anon_sym_D,
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
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_description_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_priority_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_story_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_middle_context_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
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
  [anon_sym_T] = {
    .visible = true,
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
  [anon_sym_D] = {
    .visible = true,
    .named = false,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '!') ADVANCE(30);
      if (lookahead == '$') ADVANCE(27);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(32);
      if (lookahead == '+') ADVANCE(35);
      if (lookahead == ',') ADVANCE(37);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == '=') ADVANCE(23);
      if (lookahead == '@') ADVANCE(38);
      if (lookahead == 'A') ADVANCE(2);
      if (lookahead == 'D') ADVANCE(47);
      if (lookahead == 'P') ADVANCE(3);
      if (lookahead == 'T') ADVANCE(41);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == 'a') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
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
      if (lookahead == 'T') ADVANCE(41);
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
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(29);
      END_STATE();
    case 9:
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
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(34);
      END_STATE();
    case 11:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
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
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(34);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_PLUS);
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
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_T);
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
      ACCEPT_TOKEN(anon_sym_D);
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
  [8] = {.lex_state = 16},
  [9] = {.lex_state = 16},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 16},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 16},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 16},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 7},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 7},
  [44] = {.lex_state = 11},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 8},
  [48] = {.lex_state = 9},
  [49] = {.lex_state = 10},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 9},
  [53] = {.lex_state = 11},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
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
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [aux_sym_priority_token1] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [sym_year] = ACTIONS(1),
    [aux_sym_month_token1] = ACTIONS(1),
    [anon_sym_T] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_am] = ACTIONS(1),
    [anon_sym_pm] = ACTIONS(1),
    [anon_sym_AM] = ACTIONS(1),
    [anon_sym_PM] = ACTIONS(1),
    [anon_sym_D] = ACTIONS(1),
  },
  [1] = {
    [sym_action_list] = STATE(57),
    [sym_action] = STATE(18),
    [sym_state] = STATE(52),
    [aux_sym_action_list_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(9), 1,
      anon_sym_DOLLAR,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(3), 1,
      sym_description,
    STATE(5), 1,
      sym_priority,
    STATE(13), 1,
      sym_story,
    STATE(23), 1,
      sym_context_list,
    STATE(38), 1,
      sym_do_date_or_time,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [35] = 9,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(4), 1,
      sym_priority,
    STATE(14), 1,
      sym_story,
    STATE(24), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [64] = 7,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(11), 1,
      sym_story,
    STATE(20), 1,
      sym_context_list,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [87] = 7,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(14), 1,
      sym_story,
    STATE(24), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [110] = 4,
    ACTIONS(27), 1,
      anon_sym_D,
    STATE(37), 1,
      sym_duration,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(25), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
  [127] = 1,
    ACTIONS(29), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      anon_sym_D,
  [137] = 3,
    ACTIONS(33), 1,
      aux_sym_middle_context_token1,
    ACTIONS(31), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_AT,
    STATE(9), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [151] = 3,
    ACTIONS(37), 1,
      aux_sym_middle_context_token1,
    ACTIONS(35), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_AT,
    STATE(9), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [165] = 1,
    ACTIONS(40), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
  [174] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(19), 1,
      sym_context_list,
    STATE(42), 1,
      sym_do_date_or_time,
    ACTIONS(42), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [191] = 4,
    ACTIONS(44), 1,
      sym_not_started,
    ACTIONS(48), 1,
      anon_sym_DASH,
    STATE(51), 1,
      sym_in_progress,
    ACTIONS(46), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [206] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(24), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [223] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(20), 1,
      sym_context_list,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [240] = 4,
    ACTIONS(50), 1,
      ts_builtin_sym_end,
    ACTIONS(52), 1,
      anon_sym_LPAREN,
    STATE(52), 1,
      sym_state,
    STATE(15), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [254] = 1,
    ACTIONS(55), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
  [262] = 2,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    ACTIONS(57), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      anon_sym_AT,
  [272] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
    STATE(52), 1,
      sym_state,
    STATE(15), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [286] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(31), 1,
      sym_do_date_or_time,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [297] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(42), 1,
      sym_do_date_or_time,
    ACTIONS(42), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [308] = 2,
    ACTIONS(33), 1,
      aux_sym_middle_context_token1,
    STATE(8), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [317] = 3,
    ACTIONS(65), 1,
      sym_year,
    ACTIONS(67), 1,
      anon_sym_T,
    STATE(39), 2,
      sym_date,
      sym_time,
  [328] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [339] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [350] = 1,
    ACTIONS(69), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PLUS,
      anon_sym_AT,
  [357] = 1,
    ACTIONS(71), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      anon_sym_AT,
  [364] = 3,
    ACTIONS(67), 1,
      anon_sym_T,
    STATE(36), 1,
      sym_time,
    ACTIONS(73), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [375] = 3,
    ACTIONS(27), 1,
      anon_sym_D,
    STATE(34), 1,
      sym_duration,
    ACTIONS(75), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [386] = 1,
    ACTIONS(77), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_T,
  [392] = 2,
    ACTIONS(79), 1,
      aux_sym_month_token1,
    STATE(54), 1,
      sym_hour,
  [399] = 1,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [404] = 1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [409] = 1,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [414] = 1,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [419] = 2,
    ACTIONS(87), 1,
      aux_sym_month_token1,
    STATE(45), 1,
      sym_month,
  [426] = 1,
    ACTIONS(89), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [431] = 1,
    ACTIONS(75), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [436] = 1,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [441] = 1,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [446] = 1,
    ACTIONS(42), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [451] = 2,
    ACTIONS(93), 1,
      aux_sym_month_token1,
    STATE(27), 1,
      sym_day,
  [458] = 1,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [463] = 2,
    ACTIONS(95), 1,
      aux_sym_month_token1,
    STATE(6), 1,
      sym_minute,
  [470] = 1,
    ACTIONS(97), 1,
      aux_sym_priority_token1,
  [474] = 1,
    ACTIONS(99), 1,
      anon_sym_DASH,
  [478] = 1,
    ACTIONS(101), 1,
      anon_sym_DASH,
  [482] = 1,
    ACTIONS(103), 1,
      aux_sym_description_token1,
  [486] = 1,
    ACTIONS(105), 1,
      sym_name,
  [490] = 1,
    ACTIONS(107), 1,
      aux_sym_story_token1,
  [494] = 1,
    ACTIONS(109), 1,
      anon_sym_RPAREN,
  [498] = 1,
    ACTIONS(111), 1,
      anon_sym_RPAREN,
  [502] = 1,
    ACTIONS(113), 1,
      sym_name,
  [506] = 1,
    ACTIONS(115), 1,
      aux_sym_priority_token1,
  [510] = 1,
    ACTIONS(117), 1,
      anon_sym_COLON,
  [514] = 1,
    ACTIONS(119), 1,
      anon_sym_COLON,
  [518] = 1,
    ACTIONS(121), 1,
      anon_sym_DASH,
  [522] = 1,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 110,
  [SMALL_STATE(7)] = 127,
  [SMALL_STATE(8)] = 137,
  [SMALL_STATE(9)] = 151,
  [SMALL_STATE(10)] = 165,
  [SMALL_STATE(11)] = 174,
  [SMALL_STATE(12)] = 191,
  [SMALL_STATE(13)] = 206,
  [SMALL_STATE(14)] = 223,
  [SMALL_STATE(15)] = 240,
  [SMALL_STATE(16)] = 254,
  [SMALL_STATE(17)] = 262,
  [SMALL_STATE(18)] = 272,
  [SMALL_STATE(19)] = 286,
  [SMALL_STATE(20)] = 297,
  [SMALL_STATE(21)] = 308,
  [SMALL_STATE(22)] = 317,
  [SMALL_STATE(23)] = 328,
  [SMALL_STATE(24)] = 339,
  [SMALL_STATE(25)] = 350,
  [SMALL_STATE(26)] = 357,
  [SMALL_STATE(27)] = 364,
  [SMALL_STATE(28)] = 375,
  [SMALL_STATE(29)] = 386,
  [SMALL_STATE(30)] = 392,
  [SMALL_STATE(31)] = 399,
  [SMALL_STATE(32)] = 404,
  [SMALL_STATE(33)] = 409,
  [SMALL_STATE(34)] = 414,
  [SMALL_STATE(35)] = 419,
  [SMALL_STATE(36)] = 426,
  [SMALL_STATE(37)] = 431,
  [SMALL_STATE(38)] = 436,
  [SMALL_STATE(39)] = 441,
  [SMALL_STATE(40)] = 446,
  [SMALL_STATE(41)] = 451,
  [SMALL_STATE(42)] = 458,
  [SMALL_STATE(43)] = 463,
  [SMALL_STATE(44)] = 470,
  [SMALL_STATE(45)] = 474,
  [SMALL_STATE(46)] = 478,
  [SMALL_STATE(47)] = 482,
  [SMALL_STATE(48)] = 486,
  [SMALL_STATE(49)] = 490,
  [SMALL_STATE(50)] = 494,
  [SMALL_STATE(51)] = 498,
  [SMALL_STATE(52)] = 502,
  [SMALL_STATE(53)] = 506,
  [SMALL_STATE(54)] = 510,
  [SMALL_STATE(55)] = 514,
  [SMALL_STATE(56)] = 518,
  [SMALL_STATE(57)] = 522,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(17),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(12),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 7),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 6),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [123] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
