#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 43
#define ALIAS_COUNT 0
#define TOKEN_COUNT 23
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
  anon_sym_D = 22,
  sym_action_list = 23,
  sym_action = 24,
  sym_state = 25,
  sym_in_progress = 26,
  sym_description = 27,
  sym_priority = 28,
  sym_story = 29,
  sym_context_list = 30,
  sym_middle_context = 31,
  sym_tail_context = 32,
  sym_do_date_or_time = 33,
  sym_date = 34,
  sym_month = 35,
  sym_day = 36,
  sym_time = 37,
  sym_hour = 38,
  sym_minute = 39,
  sym_duration = 40,
  aux_sym_action_list_repeat1 = 41,
  aux_sym_context_list_repeat1 = 42,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '$') ADVANCE(23);
      if (lookahead == '(') ADVANCE(14);
      if (lookahead == ')') ADVANCE(15);
      if (lookahead == '*') ADVANCE(28);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == ',') ADVANCE(33);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == 'D') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(37);
      if (lookahead == '_') ADVANCE(20);
      if (lookahead == 'x') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(16);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '_') ADVANCE(20);
      if (lookahead == 'x') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'T') ADVANCE(37);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 3:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 4:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(25);
      END_STATE();
    case 5:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 6:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(30);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      if (lookahead == '(') ADVANCE(14);
      if (lookahead == ',') ADVANCE(33);
      if (lookahead == '@') ADVANCE(34);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(32);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(25);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_T);
      END_STATE();
    case 38:
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
  [6] = {.lex_state = 12},
  [7] = {.lex_state = 12},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 12},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 12},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 3},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 3},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 7},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 5},
  [52] = {.lex_state = 7},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
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
    [anon_sym_D] = ACTIONS(1),
  },
  [1] = {
    [sym_action_list] = STATE(43),
    [sym_action] = STATE(13),
    [sym_state] = STATE(51),
    [aux_sym_action_list_repeat1] = STATE(13),
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
    STATE(4), 1,
      sym_priority,
    STATE(12), 1,
      sym_story,
    STATE(19), 1,
      sym_context_list,
    STATE(34), 1,
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
    STATE(5), 1,
      sym_priority,
    STATE(11), 1,
      sym_story,
    STATE(25), 1,
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
    STATE(25), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [87] = 7,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(10), 1,
      sym_story,
    STATE(22), 1,
      sym_context_list,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [110] = 3,
    ACTIONS(25), 1,
      aux_sym_middle_context_token1,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_AT,
    STATE(7), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [124] = 3,
    ACTIONS(29), 1,
      aux_sym_middle_context_token1,
    ACTIONS(27), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_AT,
    STATE(7), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [138] = 4,
    ACTIONS(32), 1,
      sym_not_started,
    ACTIONS(36), 1,
      anon_sym_DASH,
    STATE(50), 1,
      sym_in_progress,
    ACTIONS(34), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [153] = 1,
    ACTIONS(38), 6,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
  [162] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(24), 1,
      sym_context_list,
    STATE(39), 1,
      sym_do_date_or_time,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [179] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(22), 1,
      sym_context_list,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [196] = 5,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(25), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [213] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(51), 1,
      sym_state,
    STATE(15), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [227] = 2,
    ACTIONS(46), 1,
      anon_sym_COMMA,
    ACTIONS(44), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      anon_sym_AT,
  [237] = 4,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 1,
      anon_sym_LPAREN,
    STATE(51), 1,
      sym_state,
    STATE(15), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [251] = 1,
    ACTIONS(53), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_AT,
  [259] = 2,
    ACTIONS(25), 1,
      aux_sym_middle_context_token1,
    STATE(6), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [268] = 3,
    ACTIONS(57), 1,
      anon_sym_T,
    STATE(33), 1,
      sym_time,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [279] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(32), 1,
      sym_do_date_or_time,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [290] = 1,
    ACTIONS(59), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
      anon_sym_AT,
  [297] = 3,
    ACTIONS(57), 1,
      anon_sym_T,
    ACTIONS(61), 1,
      sym_year,
    STATE(30), 2,
      sym_date,
      sym_time,
  [308] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(39), 1,
      sym_do_date_or_time,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [319] = 1,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PLUS,
      anon_sym_AT,
  [326] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(37), 1,
      sym_do_date_or_time,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [337] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(40), 1,
      sym_do_date_or_time,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [348] = 3,
    ACTIONS(69), 1,
      anon_sym_D,
    STATE(36), 1,
      sym_duration,
    ACTIONS(67), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [359] = 1,
    ACTIONS(71), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_D,
  [365] = 1,
    ACTIONS(73), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_T,
  [371] = 2,
    ACTIONS(75), 1,
      aux_sym_month_token1,
    STATE(53), 1,
      sym_hour,
  [378] = 1,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [383] = 1,
    ACTIONS(79), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [388] = 1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [393] = 1,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [398] = 1,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [403] = 2,
    ACTIONS(83), 1,
      aux_sym_month_token1,
    STATE(42), 1,
      sym_month,
  [410] = 1,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [415] = 1,
    ACTIONS(87), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [420] = 2,
    ACTIONS(89), 1,
      aux_sym_month_token1,
    STATE(18), 1,
      sym_day,
  [427] = 1,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [432] = 1,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [437] = 2,
    ACTIONS(91), 1,
      aux_sym_month_token1,
    STATE(26), 1,
      sym_minute,
  [444] = 1,
    ACTIONS(93), 1,
      anon_sym_DASH,
  [448] = 1,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
  [452] = 1,
    ACTIONS(97), 1,
      aux_sym_description_token1,
  [456] = 1,
    ACTIONS(99), 1,
      anon_sym_DASH,
  [460] = 1,
    ACTIONS(101), 1,
      aux_sym_priority_token1,
  [464] = 1,
    ACTIONS(103), 1,
      sym_name,
  [468] = 1,
    ACTIONS(105), 1,
      anon_sym_RPAREN,
  [472] = 1,
    ACTIONS(107), 1,
      aux_sym_story_token1,
  [476] = 1,
    ACTIONS(109), 1,
      anon_sym_RPAREN,
  [480] = 1,
    ACTIONS(111), 1,
      sym_name,
  [484] = 1,
    ACTIONS(113), 1,
      aux_sym_priority_token1,
  [488] = 1,
    ACTIONS(115), 1,
      anon_sym_DASH,
  [492] = 1,
    ACTIONS(117), 1,
      anon_sym_DASH,
  [496] = 1,
    ACTIONS(119), 1,
      anon_sym_DASH,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 110,
  [SMALL_STATE(7)] = 124,
  [SMALL_STATE(8)] = 138,
  [SMALL_STATE(9)] = 153,
  [SMALL_STATE(10)] = 162,
  [SMALL_STATE(11)] = 179,
  [SMALL_STATE(12)] = 196,
  [SMALL_STATE(13)] = 213,
  [SMALL_STATE(14)] = 227,
  [SMALL_STATE(15)] = 237,
  [SMALL_STATE(16)] = 251,
  [SMALL_STATE(17)] = 259,
  [SMALL_STATE(18)] = 268,
  [SMALL_STATE(19)] = 279,
  [SMALL_STATE(20)] = 290,
  [SMALL_STATE(21)] = 297,
  [SMALL_STATE(22)] = 308,
  [SMALL_STATE(23)] = 319,
  [SMALL_STATE(24)] = 326,
  [SMALL_STATE(25)] = 337,
  [SMALL_STATE(26)] = 348,
  [SMALL_STATE(27)] = 359,
  [SMALL_STATE(28)] = 365,
  [SMALL_STATE(29)] = 371,
  [SMALL_STATE(30)] = 378,
  [SMALL_STATE(31)] = 383,
  [SMALL_STATE(32)] = 388,
  [SMALL_STATE(33)] = 393,
  [SMALL_STATE(34)] = 398,
  [SMALL_STATE(35)] = 403,
  [SMALL_STATE(36)] = 410,
  [SMALL_STATE(37)] = 415,
  [SMALL_STATE(38)] = 420,
  [SMALL_STATE(39)] = 427,
  [SMALL_STATE(40)] = 432,
  [SMALL_STATE(41)] = 437,
  [SMALL_STATE(42)] = 444,
  [SMALL_STATE(43)] = 448,
  [SMALL_STATE(44)] = 452,
  [SMALL_STATE(45)] = 456,
  [SMALL_STATE(46)] = 460,
  [SMALL_STATE(47)] = 464,
  [SMALL_STATE(48)] = 468,
  [SMALL_STATE(49)] = 472,
  [SMALL_STATE(50)] = 476,
  [SMALL_STATE(51)] = 480,
  [SMALL_STATE(52)] = 484,
  [SMALL_STATE(53)] = 488,
  [SMALL_STATE(54)] = 492,
  [SMALL_STATE(55)] = 496,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(14),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(8),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 6),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 5),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 7),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [95] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
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
