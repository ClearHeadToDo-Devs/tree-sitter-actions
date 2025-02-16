#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 17
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
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
  sym_action_list = 13,
  sym_action = 14,
  sym_state = 15,
  sym_description = 16,
  sym_priority = 17,
  aux_sym_action_list_repeat1 = 18,
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
  [sym_action_list] = "action_list",
  [sym_action] = "action",
  [sym_state] = "state",
  [sym_description] = "description",
  [sym_priority] = "priority",
  [aux_sym_action_list_repeat1] = "action_list_repeat1",
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
  [sym_action_list] = sym_action_list,
  [sym_action] = sym_action,
  [sym_state] = sym_state,
  [sym_description] = sym_description,
  [sym_priority] = sym_priority,
  [aux_sym_action_list_repeat1] = aux_sym_action_list_repeat1,
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
  [aux_sym_action_list_repeat1] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '!') ADVANCE(17);
      if (lookahead == '$') ADVANCE(14);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '=') ADVANCE(10);
      if (lookahead == '_') ADVANCE(11);
      if (lookahead == 'x') ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(7);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '=') ADVANCE(10);
      if (lookahead == '_') ADVANCE(11);
      if (lookahead == 'x') ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(13);
      END_STATE();
    case 3:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(16);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_in_progress);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '$' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_description_token1);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '%' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_priority_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 0},
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
  },
  [1] = {
    [sym_action_list] = STATE(11),
    [sym_action] = STATE(4),
    [sym_state] = STATE(12),
    [aux_sym_action_list_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(9), 1,
      anon_sym_DOLLAR,
    ACTIONS(11), 1,
      anon_sym_BANG,
    STATE(6), 1,
      sym_description,
    STATE(8), 1,
      sym_priority,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [17] = 2,
    ACTIONS(13), 1,
      sym_not_started,
    ACTIONS(15), 4,
      sym_completed,
      sym_in_progress,
      sym_blocked,
      sym_cancelled,
  [27] = 4,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      sym_state,
    STATE(5), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [41] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    STATE(12), 1,
      sym_state,
    STATE(5), 2,
      sym_action,
      aux_sym_action_list_repeat1,
  [55] = 3,
    ACTIONS(11), 1,
      anon_sym_BANG,
    STATE(10), 1,
      sym_priority,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [66] = 1,
    ACTIONS(26), 3,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_BANG,
  [72] = 1,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [77] = 1,
    ACTIONS(28), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [82] = 1,
    ACTIONS(30), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [87] = 1,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
  [91] = 1,
    ACTIONS(34), 1,
      sym_name,
  [95] = 1,
    ACTIONS(36), 1,
      anon_sym_RPAREN,
  [99] = 1,
    ACTIONS(38), 1,
      sym_name,
  [103] = 1,
    ACTIONS(40), 1,
      aux_sym_description_token1,
  [107] = 1,
    ACTIONS(42), 1,
      aux_sym_priority_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 17,
  [SMALL_STATE(4)] = 27,
  [SMALL_STATE(5)] = 41,
  [SMALL_STATE(6)] = 55,
  [SMALL_STATE(7)] = 66,
  [SMALL_STATE(8)] = 72,
  [SMALL_STATE(9)] = 77,
  [SMALL_STATE(10)] = 82,
  [SMALL_STATE(11)] = 87,
  [SMALL_STATE(12)] = 91,
  [SMALL_STATE(13)] = 95,
  [SMALL_STATE(14)] = 99,
  [SMALL_STATE(15)] = 103,
  [SMALL_STATE(16)] = 107,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(3),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 3),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 4),
  [32] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
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
