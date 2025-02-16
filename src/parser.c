#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 31
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  sym_not_started = 3,
  sym_completed = 4,
  sym_in_progress = 5,
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
  sym_action_list = 18,
  sym_action = 19,
  sym_state = 20,
  sym_description = 21,
  sym_priority = 22,
  sym_story = 23,
  sym_context_list = 24,
  sym_middle_context = 25,
  sym_tail_context = 26,
  aux_sym_action_list_repeat1 = 27,
  aux_sym_context_list_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_not_started] = "not_started",
  [sym_completed] = "completed",
  [sym_in_progress] = "in_progress",
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
  [sym_action_list] = "action_list",
  [sym_action] = "action",
  [sym_state] = "state",
  [sym_description] = "description",
  [sym_priority] = "priority",
  [sym_story] = "story",
  [sym_context_list] = "context_list",
  [sym_middle_context] = "middle_context",
  [sym_tail_context] = "tail_context",
  [aux_sym_action_list_repeat1] = "action_list_repeat1",
  [aux_sym_context_list_repeat1] = "context_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_not_started] = sym_not_started,
  [sym_completed] = sym_completed,
  [sym_in_progress] = sym_in_progress,
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
  [sym_action_list] = sym_action_list,
  [sym_action] = sym_action,
  [sym_state] = sym_state,
  [sym_description] = sym_description,
  [sym_priority] = sym_priority,
  [sym_story] = sym_story,
  [sym_context_list] = sym_context_list,
  [sym_middle_context] = sym_middle_context,
  [sym_tail_context] = sym_tail_context,
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
  [sym_in_progress] = {
    .visible = true,
    .named = true,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '!') ADVANCE(23);
      if (lookahead == '$') ADVANCE(20);
      if (lookahead == '(') ADVANCE(8);
      if (lookahead == ')') ADVANCE(9);
      if (lookahead == '*') ADVANCE(26);
      if (lookahead == '+') ADVANCE(29);
      if (lookahead == ',') ADVANCE(31);
      if (lookahead == '-') ADVANCE(14);
      if (lookahead == '=') ADVANCE(15);
      if (lookahead == '_') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(10);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '=') ADVANCE(15);
      if (lookahead == '_') ADVANCE(16);
      if (lookahead == 'x') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      END_STATE();
    case 3:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 4:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(19);
      END_STATE();
    case 5:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 6:
      if (eof) ADVANCE(7);
      if (lookahead == '(') ADVANCE(8);
      if (lookahead == ',') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_completed);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_in_progress);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_in_progress);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_cancelled);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_story_token1);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_middle_context_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_COMMA);
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
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 6},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 5},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_completed] = ACTIONS(1),
    [sym_in_progress] = ACTIONS(1),
    [sym_blocked] = ACTIONS(1),
    [sym_cancelled] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [aux_sym_priority_token1] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [aux_sym_middle_context_token1] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
  },
  [1] = {
    [sym_action_list] = STATE(26),
    [sym_action] = STATE(9),
    [sym_state] = STATE(27),
    [aux_sym_action_list_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(9), 1,
      anon_sym_DOLLAR,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(3), 1,
      sym_description,
    STATE(7), 1,
      sym_priority,
    STATE(12), 1,
      sym_story,
    STATE(20), 1,
      sym_context_list,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [29] = 7,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(5), 1,
      sym_priority,
    STATE(16), 1,
      sym_story,
    STATE(21), 1,
      sym_context_list,
    ACTIONS(17), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [52] = 3,
    ACTIONS(21), 1,
      aux_sym_middle_context_token1,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(4), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [65] = 5,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(17), 1,
      sym_story,
    STATE(22), 1,
      sym_context_list,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [82] = 3,
    ACTIONS(28), 1,
      aux_sym_middle_context_token1,
    ACTIONS(26), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(4), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [95] = 5,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(16), 1,
      sym_story,
    STATE(21), 1,
      sym_context_list,
    ACTIONS(17), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [112] = 2,
    ACTIONS(30), 1,
      sym_not_started,
    ACTIONS(32), 4,
      sym_completed,
      sym_in_progress,
      sym_blocked,
      sym_cancelled,
  [122] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    STATE(27), 1,
      sym_state,
    STATE(10), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [136] = 4,
    ACTIONS(36), 1,
      ts_builtin_sym_end,
    ACTIONS(38), 1,
      anon_sym_LPAREN,
    STATE(27), 1,
      sym_state,
    STATE(10), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [150] = 1,
    ACTIONS(41), 5,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_STAR,
      anon_sym_PLUS,
  [158] = 3,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(21), 1,
      sym_context_list,
    ACTIONS(17), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [169] = 2,
    ACTIONS(28), 1,
      aux_sym_middle_context_token1,
    STATE(6), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [178] = 1,
    ACTIONS(43), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_PLUS,
  [185] = 2,
    ACTIONS(47), 1,
      anon_sym_COMMA,
    ACTIONS(45), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
  [194] = 3,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(22), 1,
      sym_context_list,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [205] = 3,
    ACTIONS(15), 1,
      anon_sym_PLUS,
    STATE(23), 1,
      sym_context_list,
    ACTIONS(49), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [216] = 1,
    ACTIONS(51), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_PLUS,
  [222] = 1,
    ACTIONS(53), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      aux_sym_middle_context_token1,
  [228] = 1,
    ACTIONS(17), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [233] = 1,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [238] = 1,
    ACTIONS(49), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [243] = 1,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [248] = 1,
    ACTIONS(57), 1,
      aux_sym_priority_token1,
  [252] = 1,
    ACTIONS(59), 1,
      aux_sym_story_token1,
  [256] = 1,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
  [260] = 1,
    ACTIONS(63), 1,
      sym_name,
  [264] = 1,
    ACTIONS(65), 1,
      aux_sym_description_token1,
  [268] = 1,
    ACTIONS(67), 1,
      sym_name,
  [272] = 1,
    ACTIONS(69), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 65,
  [SMALL_STATE(6)] = 82,
  [SMALL_STATE(7)] = 95,
  [SMALL_STATE(8)] = 112,
  [SMALL_STATE(9)] = 122,
  [SMALL_STATE(10)] = 136,
  [SMALL_STATE(11)] = 150,
  [SMALL_STATE(12)] = 158,
  [SMALL_STATE(13)] = 169,
  [SMALL_STATE(14)] = 178,
  [SMALL_STATE(15)] = 185,
  [SMALL_STATE(16)] = 194,
  [SMALL_STATE(17)] = 205,
  [SMALL_STATE(18)] = 216,
  [SMALL_STATE(19)] = 222,
  [SMALL_STATE(20)] = 228,
  [SMALL_STATE(21)] = 233,
  [SMALL_STATE(22)] = 238,
  [SMALL_STATE(23)] = 243,
  [SMALL_STATE(24)] = 248,
  [SMALL_STATE(25)] = 252,
  [SMALL_STATE(26)] = 256,
  [SMALL_STATE(27)] = 260,
  [SMALL_STATE(28)] = 264,
  [SMALL_STATE(29)] = 268,
  [SMALL_STATE(30)] = 272,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(15),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [32] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(8),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 5),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 6),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [61] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
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
