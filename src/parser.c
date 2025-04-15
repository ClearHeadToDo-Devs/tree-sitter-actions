#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 138
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 100
#define ALIAS_COUNT 0
#define TOKEN_COUNT 47
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_child_icon = 1,
  sym_grandchild_icon = 2,
  sym_great_grandchild_icon = 3,
  sym_double_great_grandchild_icon = 4,
  sym_leaf_icon = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  sym_not_started = 8,
  sym_completed = 9,
  anon_sym_DASH = 10,
  sym_blocked = 11,
  sym_cancelled = 12,
  sym_name = 13,
  sym_desc_icon = 14,
  sym_description_text = 15,
  sym_priority_icon = 16,
  aux_sym_priority_number_token1 = 17,
  sym_story_icon = 18,
  sym_story_name = 19,
  sym_context_icon = 20,
  aux_sym_context_text_token1 = 21,
  sym_context_separator = 22,
  sym_do_date_icon = 23,
  anon_sym_PERCENT = 24,
  sym_recurrance_icon = 25,
  anon_sym_Da = 26,
  anon_sym_W = 27,
  anon_sym_Mon = 28,
  anon_sym_Tue = 29,
  anon_sym_Wen = 30,
  anon_sym_Thurs = 31,
  anon_sym_Fri = 32,
  anon_sym_Sat = 33,
  anon_sym_Sun = 34,
  sym_year = 35,
  aux_sym_month_token1 = 36,
  anon_sym_COLON = 37,
  anon_sym_am = 38,
  anon_sym_pm = 39,
  anon_sym_AM = 40,
  anon_sym_PM = 41,
  sym_duration_designator = 42,
  sym_id_icon = 43,
  sym_uuid_time_high = 44,
  sym_uuid_random = 45,
  sym__uuid_chunk = 46,
  sym_action_list = 47,
  sym_root_action = 48,
  sym_child_action_list = 49,
  sym_child_action = 50,
  sym_grandchild_action_list = 51,
  sym_grandchild_action = 52,
  sym_great_grandchild_action_list = 53,
  sym_great_grandchild_action = 54,
  sym_double_great_grandchild_action_list = 55,
  sym_double_great_grandchild_action = 56,
  sym_leaf_action_list = 57,
  sym_leaf_action = 58,
  sym_core_action = 59,
  sym_state = 60,
  sym_in_progress = 61,
  sym_description = 62,
  sym_priority = 63,
  sym_priority_number = 64,
  sym_story = 65,
  sym_context_list = 66,
  sym_middle_context = 67,
  sym_context_text = 68,
  sym_tail_context = 69,
  sym_do_date_or_time = 70,
  sym_completed_date = 71,
  sym_recurrance = 72,
  sym_recurrance_structure = 73,
  sym_daily_recurrance = 74,
  sym_weekly_recurrance = 75,
  sym_weekly_recurrance_days = 76,
  sym_extended_date_and_time = 77,
  sym_date_and_time = 78,
  sym_date = 79,
  sym_month = 80,
  sym_day = 81,
  sym_time = 82,
  sym_hour = 83,
  sym_minute = 84,
  sym_duration = 85,
  sym_duration_value = 86,
  sym_id = 87,
  sym_uuid = 88,
  sym_uuid_time_mid = 89,
  sym_uuid_version_random = 90,
  sym_uuid_variant_random = 91,
  aux_sym_action_list_repeat1 = 92,
  aux_sym_child_action_list_repeat1 = 93,
  aux_sym_grandchild_action_list_repeat1 = 94,
  aux_sym_great_grandchild_action_list_repeat1 = 95,
  aux_sym_double_great_grandchild_action_list_repeat1 = 96,
  aux_sym_leaf_action_list_repeat1 = 97,
  aux_sym_context_list_repeat1 = 98,
  aux_sym_weekly_recurrance_days_repeat1 = 99,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_child_icon] = "child_icon",
  [sym_grandchild_icon] = "grandchild_icon",
  [sym_great_grandchild_icon] = "great_grandchild_icon",
  [sym_double_great_grandchild_icon] = "double_great_grandchild_icon",
  [sym_leaf_icon] = "leaf_icon",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_not_started] = "not_started",
  [sym_completed] = "completed",
  [anon_sym_DASH] = "-",
  [sym_blocked] = "blocked",
  [sym_cancelled] = "cancelled",
  [sym_name] = "name",
  [sym_desc_icon] = "desc_icon",
  [sym_description_text] = "description_text",
  [sym_priority_icon] = "priority_icon",
  [aux_sym_priority_number_token1] = "priority_number_token1",
  [sym_story_icon] = "story_icon",
  [sym_story_name] = "story_name",
  [sym_context_icon] = "context_icon",
  [aux_sym_context_text_token1] = "context_text_token1",
  [sym_context_separator] = "context_separator",
  [sym_do_date_icon] = "do_date_icon",
  [anon_sym_PERCENT] = "%",
  [sym_recurrance_icon] = "recurrance_icon",
  [anon_sym_Da] = "Da",
  [anon_sym_W] = "W",
  [anon_sym_Mon] = "Mon",
  [anon_sym_Tue] = "Tue",
  [anon_sym_Wen] = "Wen",
  [anon_sym_Thurs] = "Thurs",
  [anon_sym_Fri] = "Fri",
  [anon_sym_Sat] = "Sat",
  [anon_sym_Sun] = "Sun",
  [sym_year] = "year",
  [aux_sym_month_token1] = "month_token1",
  [anon_sym_COLON] = ":",
  [anon_sym_am] = "am",
  [anon_sym_pm] = "pm",
  [anon_sym_AM] = "AM",
  [anon_sym_PM] = "PM",
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
  [sym_double_great_grandchild_action_list] = "double_great_grandchild_action_list",
  [sym_double_great_grandchild_action] = "double_great_grandchild_action",
  [sym_leaf_action_list] = "leaf_action_list",
  [sym_leaf_action] = "leaf_action",
  [sym_core_action] = "core_action",
  [sym_state] = "state",
  [sym_in_progress] = "in_progress",
  [sym_description] = "description",
  [sym_priority] = "priority",
  [sym_priority_number] = "priority_number",
  [sym_story] = "story",
  [sym_context_list] = "context_list",
  [sym_middle_context] = "middle_context",
  [sym_context_text] = "context_text",
  [sym_tail_context] = "tail_context",
  [sym_do_date_or_time] = "do_date_or_time",
  [sym_completed_date] = "completed_date",
  [sym_recurrance] = "recurrance",
  [sym_recurrance_structure] = "recurrance_structure",
  [sym_daily_recurrance] = "daily_recurrance",
  [sym_weekly_recurrance] = "weekly_recurrance",
  [sym_weekly_recurrance_days] = "weekly_recurrance_days",
  [sym_extended_date_and_time] = "extended_date_and_time",
  [sym_date_and_time] = "date_and_time",
  [sym_date] = "date",
  [sym_month] = "month",
  [sym_day] = "day",
  [sym_time] = "time",
  [sym_hour] = "hour",
  [sym_minute] = "minute",
  [sym_duration] = "duration",
  [sym_duration_value] = "duration_value",
  [sym_id] = "id",
  [sym_uuid] = "uuid",
  [sym_uuid_time_mid] = "uuid_time_mid",
  [sym_uuid_version_random] = "uuid_version_random",
  [sym_uuid_variant_random] = "uuid_variant_random",
  [aux_sym_action_list_repeat1] = "action_list_repeat1",
  [aux_sym_child_action_list_repeat1] = "child_action_list_repeat1",
  [aux_sym_grandchild_action_list_repeat1] = "grandchild_action_list_repeat1",
  [aux_sym_great_grandchild_action_list_repeat1] = "great_grandchild_action_list_repeat1",
  [aux_sym_double_great_grandchild_action_list_repeat1] = "double_great_grandchild_action_list_repeat1",
  [aux_sym_leaf_action_list_repeat1] = "leaf_action_list_repeat1",
  [aux_sym_context_list_repeat1] = "context_list_repeat1",
  [aux_sym_weekly_recurrance_days_repeat1] = "weekly_recurrance_days_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_child_icon] = sym_child_icon,
  [sym_grandchild_icon] = sym_grandchild_icon,
  [sym_great_grandchild_icon] = sym_great_grandchild_icon,
  [sym_double_great_grandchild_icon] = sym_double_great_grandchild_icon,
  [sym_leaf_icon] = sym_leaf_icon,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_not_started] = sym_not_started,
  [sym_completed] = sym_completed,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_blocked] = sym_blocked,
  [sym_cancelled] = sym_cancelled,
  [sym_name] = sym_name,
  [sym_desc_icon] = sym_desc_icon,
  [sym_description_text] = sym_description_text,
  [sym_priority_icon] = sym_priority_icon,
  [aux_sym_priority_number_token1] = aux_sym_priority_number_token1,
  [sym_story_icon] = sym_story_icon,
  [sym_story_name] = sym_story_name,
  [sym_context_icon] = sym_context_icon,
  [aux_sym_context_text_token1] = aux_sym_context_text_token1,
  [sym_context_separator] = sym_context_separator,
  [sym_do_date_icon] = sym_do_date_icon,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [sym_recurrance_icon] = sym_recurrance_icon,
  [anon_sym_Da] = anon_sym_Da,
  [anon_sym_W] = anon_sym_W,
  [anon_sym_Mon] = anon_sym_Mon,
  [anon_sym_Tue] = anon_sym_Tue,
  [anon_sym_Wen] = anon_sym_Wen,
  [anon_sym_Thurs] = anon_sym_Thurs,
  [anon_sym_Fri] = anon_sym_Fri,
  [anon_sym_Sat] = anon_sym_Sat,
  [anon_sym_Sun] = anon_sym_Sun,
  [sym_year] = sym_year,
  [aux_sym_month_token1] = aux_sym_month_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_am] = anon_sym_am,
  [anon_sym_pm] = anon_sym_pm,
  [anon_sym_AM] = anon_sym_AM,
  [anon_sym_PM] = anon_sym_PM,
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
  [sym_double_great_grandchild_action_list] = sym_double_great_grandchild_action_list,
  [sym_double_great_grandchild_action] = sym_double_great_grandchild_action,
  [sym_leaf_action_list] = sym_leaf_action_list,
  [sym_leaf_action] = sym_leaf_action,
  [sym_core_action] = sym_core_action,
  [sym_state] = sym_state,
  [sym_in_progress] = sym_in_progress,
  [sym_description] = sym_description,
  [sym_priority] = sym_priority,
  [sym_priority_number] = sym_priority_number,
  [sym_story] = sym_story,
  [sym_context_list] = sym_context_list,
  [sym_middle_context] = sym_middle_context,
  [sym_context_text] = sym_context_text,
  [sym_tail_context] = sym_tail_context,
  [sym_do_date_or_time] = sym_do_date_or_time,
  [sym_completed_date] = sym_completed_date,
  [sym_recurrance] = sym_recurrance,
  [sym_recurrance_structure] = sym_recurrance_structure,
  [sym_daily_recurrance] = sym_daily_recurrance,
  [sym_weekly_recurrance] = sym_weekly_recurrance,
  [sym_weekly_recurrance_days] = sym_weekly_recurrance_days,
  [sym_extended_date_and_time] = sym_extended_date_and_time,
  [sym_date_and_time] = sym_date_and_time,
  [sym_date] = sym_date,
  [sym_month] = sym_month,
  [sym_day] = sym_day,
  [sym_time] = sym_time,
  [sym_hour] = sym_hour,
  [sym_minute] = sym_minute,
  [sym_duration] = sym_duration,
  [sym_duration_value] = sym_duration_value,
  [sym_id] = sym_id,
  [sym_uuid] = sym_uuid,
  [sym_uuid_time_mid] = sym_uuid_time_mid,
  [sym_uuid_version_random] = sym_uuid_version_random,
  [sym_uuid_variant_random] = sym_uuid_variant_random,
  [aux_sym_action_list_repeat1] = aux_sym_action_list_repeat1,
  [aux_sym_child_action_list_repeat1] = aux_sym_child_action_list_repeat1,
  [aux_sym_grandchild_action_list_repeat1] = aux_sym_grandchild_action_list_repeat1,
  [aux_sym_great_grandchild_action_list_repeat1] = aux_sym_great_grandchild_action_list_repeat1,
  [aux_sym_double_great_grandchild_action_list_repeat1] = aux_sym_double_great_grandchild_action_list_repeat1,
  [aux_sym_leaf_action_list_repeat1] = aux_sym_leaf_action_list_repeat1,
  [aux_sym_context_list_repeat1] = aux_sym_context_list_repeat1,
  [aux_sym_weekly_recurrance_days_repeat1] = aux_sym_weekly_recurrance_days_repeat1,
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
  [sym_double_great_grandchild_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_leaf_icon] = {
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
  [sym_desc_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_description_text] = {
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
  [sym_story_icon] = {
    .visible = true,
    .named = true,
  },
  [sym_story_name] = {
    .visible = true,
    .named = true,
  },
  [sym_context_icon] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_context_text_token1] = {
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
  [sym_recurrance_icon] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Da] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_W] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Mon] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Tue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Wen] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Thurs] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Fri] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Sat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Sun] = {
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
  [sym_double_great_grandchild_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_double_great_grandchild_action] = {
    .visible = true,
    .named = true,
  },
  [sym_leaf_action_list] = {
    .visible = true,
    .named = true,
  },
  [sym_leaf_action] = {
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
  [sym_context_text] = {
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
  [sym_recurrance] = {
    .visible = true,
    .named = true,
  },
  [sym_recurrance_structure] = {
    .visible = true,
    .named = true,
  },
  [sym_daily_recurrance] = {
    .visible = true,
    .named = true,
  },
  [sym_weekly_recurrance] = {
    .visible = true,
    .named = true,
  },
  [sym_weekly_recurrance_days] = {
    .visible = true,
    .named = true,
  },
  [sym_extended_date_and_time] = {
    .visible = true,
    .named = true,
  },
  [sym_date_and_time] = {
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
  [sym_duration_value] = {
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
  [aux_sym_double_great_grandchild_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_leaf_action_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_context_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_weekly_recurrance_days_repeat1] = {
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
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(56);
      if (lookahead == '!') ADVANCE(74);
      if (lookahead == '#') ADVANCE(104);
      if (lookahead == '$') ADVANCE(71);
      if (lookahead == '%') ADVANCE(83);
      if (lookahead == '(') ADVANCE(62);
      if (lookahead == ')') ADVANCE(63);
      if (lookahead == '*') ADVANCE(76);
      if (lookahead == '+') ADVANCE(79);
      if (lookahead == ',') ADVANCE(81);
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == ':') ADVANCE(97);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '>') ADVANCE(57);
      if (lookahead == '@') ADVANCE(82);
      if (lookahead == 'A') ADVANCE(5);
      if (lookahead == 'D') ADVANCE(103);
      if (lookahead == 'F') ADVANCE(19);
      if (lookahead == 'M') ADVANCE(18);
      if (lookahead == 'P') ADVANCE(6);
      if (lookahead == 'R') ADVANCE(84);
      if (lookahead == 'S') ADVANCE(8);
      if (lookahead == 'T') ADVANCE(11);
      if (lookahead == 'W') ADVANCE(87);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'a') ADVANCE(13);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 'x') ADVANCE(65);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(64);
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'x') ADVANCE(65);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(66);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(66);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 4:
      if (lookahead == 'D') ADVANCE(7);
      if (lookahead == 'W') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 5:
      if (lookahead == 'M') ADVANCE(100);
      END_STATE();
    case 6:
      if (lookahead == 'M') ADVANCE(101);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(22);
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(23);
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == 'i') ADVANCE(92);
      END_STATE();
    case 13:
      if (lookahead == 'm') ADVANCE(98);
      END_STATE();
    case 14:
      if (lookahead == 'm') ADVANCE(99);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(88);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(94);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == 's') ADVANCE(91);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 24:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(24)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 25:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(25)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 26:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(73);
      END_STATE();
    case 27:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(70);
      END_STATE();
    case 28:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(78);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(107);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(106);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(105);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(44);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 54:
      if (eof) ADVANCE(56);
      if (lookahead == '#') ADVANCE(104);
      if (lookahead == '%') ADVANCE(83);
      if (lookahead == '(') ADVANCE(62);
      if (lookahead == '*') ADVANCE(76);
      if (lookahead == ',') ADVANCE(81);
      if (lookahead == '>') ADVANCE(57);
      if (lookahead == '@') ADVANCE(82);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(54)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 55:
      if (eof) ADVANCE(56);
      if (lookahead == '#') ADVANCE(104);
      if (lookahead == '%') ADVANCE(83);
      if (lookahead == '(') ADVANCE(62);
      if (lookahead == '*') ADVANCE(76);
      if (lookahead == '>') ADVANCE(57);
      if (lookahead == 'A') ADVANCE(5);
      if (lookahead == 'D') ADVANCE(102);
      if (lookahead == 'F') ADVANCE(19);
      if (lookahead == 'M') ADVANCE(18);
      if (lookahead == 'P') ADVANCE(6);
      if (lookahead == 'R') ADVANCE(84);
      if (lookahead == 'S') ADVANCE(8);
      if (lookahead == 'T') ADVANCE(11);
      if (lookahead == 'W') ADVANCE(10);
      if (lookahead == 'a') ADVANCE(13);
      if (lookahead == 'p') ADVANCE(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(55)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_child_icon);
      if (lookahead == '>') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_grandchild_icon);
      if (lookahead == '>') ADVANCE(59);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_great_grandchild_icon);
      if (lookahead == '>') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_double_great_grandchild_icon);
      if (lookahead == '>') ADVANCE(61);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_leaf_icon);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_not_started);
      if (lookahead == ' ') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_completed);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_blocked);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_cancelled);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_name);
      if (lookahead != 0 &&
          lookahead != '!' &&
          (lookahead < '#' || '%' < lookahead) &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_desc_icon);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_description_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(73);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_description_text);
      if (lookahead != 0 &&
          lookahead != '!' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '*' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_priority_icon);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_priority_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_story_icon);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_story_name);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(78);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_story_name);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '(' &&
          lookahead != '+' &&
          lookahead != '>' &&
          lookahead != '@') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_context_icon);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_context_text_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_context_separator);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_do_date_icon);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_recurrance_icon);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_Da);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_W);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_W);
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_Mon);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_Tue);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_Wen);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_Thurs);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_Fri);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_Sat);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_Sun);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_year);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_month_token1);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_am);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_pm);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_AM);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_PM);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_duration_designator);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_duration_designator);
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_id_icon);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_uuid_time_high);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_uuid_random);
      END_STATE();
    case 107:
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
  [3] = {.lex_state = 55},
  [4] = {.lex_state = 55},
  [5] = {.lex_state = 55},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 55},
  [9] = {.lex_state = 55},
  [10] = {.lex_state = 54},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 54},
  [13] = {.lex_state = 55},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 55},
  [18] = {.lex_state = 54},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 55},
  [21] = {.lex_state = 55},
  [22] = {.lex_state = 55},
  [23] = {.lex_state = 55},
  [24] = {.lex_state = 55},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 54},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 55},
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
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 1},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 54},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 24},
  [109] = {.lex_state = 55},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 55},
  [112] = {.lex_state = 55},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 25},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 3},
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 24},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 3},
  [123] = {.lex_state = 26},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 3},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 27},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 3},
  [132] = {.lex_state = 28},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 3},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 27},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_child_icon] = ACTIONS(1),
    [sym_grandchild_icon] = ACTIONS(1),
    [sym_great_grandchild_icon] = ACTIONS(1),
    [sym_double_great_grandchild_icon] = ACTIONS(1),
    [sym_leaf_icon] = ACTIONS(1),
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
    [sym_recurrance_icon] = ACTIONS(1),
    [anon_sym_Da] = ACTIONS(1),
    [anon_sym_W] = ACTIONS(1),
    [anon_sym_Mon] = ACTIONS(1),
    [anon_sym_Tue] = ACTIONS(1),
    [anon_sym_Wen] = ACTIONS(1),
    [anon_sym_Thurs] = ACTIONS(1),
    [anon_sym_Fri] = ACTIONS(1),
    [anon_sym_Sat] = ACTIONS(1),
    [anon_sym_Sun] = ACTIONS(1),
    [aux_sym_month_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_am] = ACTIONS(1),
    [anon_sym_pm] = ACTIONS(1),
    [anon_sym_AM] = ACTIONS(1),
    [anon_sym_PM] = ACTIONS(1),
    [sym_duration_designator] = ACTIONS(1),
    [sym_id_icon] = ACTIONS(1),
  },
  [1] = {
    [sym_action_list] = STATE(126),
    [sym_root_action] = STATE(72),
    [sym_core_action] = STATE(62),
    [sym_state] = STATE(137),
    [aux_sym_action_list_repeat1] = STATE(72),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(11), 1,
      sym_desc_icon,
    ACTIONS(13), 1,
      sym_priority_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(6), 1,
      sym_description,
    STATE(7), 1,
      sym_priority,
    STATE(14), 1,
      sym_context_list,
    STATE(32), 1,
      sym_do_date_or_time,
    STATE(41), 1,
      sym_completed_date,
    STATE(59), 1,
      sym_id,
    ACTIONS(7), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(9), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [49] = 5,
    STATE(4), 1,
      aux_sym_weekly_recurrance_days_repeat1,
    STATE(17), 1,
      sym_weekly_recurrance_days,
    ACTIONS(25), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(23), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
    ACTIONS(27), 7,
      anon_sym_Mon,
      anon_sym_Tue,
      anon_sym_Wen,
      anon_sym_Thurs,
      anon_sym_Fri,
      anon_sym_Sat,
      anon_sym_Sun,
  [79] = 4,
    STATE(5), 1,
      aux_sym_weekly_recurrance_days_repeat1,
    ACTIONS(31), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(29), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      aux_sym_month_token1,
      sym_id_icon,
    ACTIONS(33), 7,
      anon_sym_Mon,
      anon_sym_Tue,
      anon_sym_Wen,
      anon_sym_Thurs,
      anon_sym_Fri,
      anon_sym_Sat,
      anon_sym_Sun,
  [107] = 4,
    STATE(5), 1,
      aux_sym_weekly_recurrance_days_repeat1,
    ACTIONS(37), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(35), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      aux_sym_month_token1,
      sym_id_icon,
    ACTIONS(39), 7,
      anon_sym_Mon,
      anon_sym_Tue,
      anon_sym_Wen,
      anon_sym_Thurs,
      anon_sym_Fri,
      anon_sym_Sat,
      anon_sym_Sun,
  [135] = 12,
    ACTIONS(13), 1,
      sym_priority_icon,
    ACTIONS(15), 1,
      sym_context_icon,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(11), 1,
      sym_priority,
    STATE(16), 1,
      sym_context_list,
    STATE(26), 1,
      sym_do_date_or_time,
    STATE(40), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [178] = 10,
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
    STATE(26), 1,
      sym_do_date_or_time,
    STATE(40), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [215] = 2,
    ACTIONS(48), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(46), 12,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
      sym_duration_designator,
      sym_id_icon,
  [236] = 3,
    ACTIONS(52), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(54), 4,
      anon_sym_am,
      anon_sym_pm,
      anon_sym_AM,
      anon_sym_PM,
    ACTIONS(50), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_duration_designator,
      sym_id_icon,
  [259] = 5,
    ACTIONS(60), 1,
      aux_sym_context_text_token1,
    STATE(129), 1,
      sym_context_text,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(58), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(56), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [286] = 10,
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
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(63), 1,
      sym_id,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(65), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [323] = 5,
    ACTIONS(71), 1,
      aux_sym_context_text_token1,
    STATE(129), 1,
      sym_context_text,
    STATE(10), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
    ACTIONS(69), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(67), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [350] = 5,
    ACTIONS(77), 1,
      aux_sym_month_token1,
    STATE(24), 1,
      sym_time,
    STATE(124), 1,
      sym_hour,
    ACTIONS(75), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(73), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_duration_designator,
      sym_id_icon,
  [376] = 8,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(26), 1,
      sym_do_date_or_time,
    STATE(40), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [407] = 8,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(28), 1,
      sym_do_date_or_time,
    STATE(46), 1,
      sym_completed_date,
    STATE(56), 1,
      sym_id,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(81), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [438] = 8,
    ACTIONS(17), 1,
      sym_do_date_icon,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(30), 1,
      sym_do_date_or_time,
    STATE(42), 1,
      sym_completed_date,
    STATE(63), 1,
      sym_id,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(65), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [469] = 5,
    ACTIONS(77), 1,
      aux_sym_month_token1,
    STATE(38), 1,
      sym_time,
    STATE(124), 1,
      sym_hour,
    ACTIONS(85), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(83), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [493] = 3,
    ACTIONS(91), 1,
      sym_context_separator,
    ACTIONS(89), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(87), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      aux_sym_context_text_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [513] = 2,
    ACTIONS(95), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(93), 9,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_priority_icon,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [531] = 4,
    ACTIONS(101), 1,
      sym_duration_designator,
    STATE(36), 1,
      sym_duration,
    ACTIONS(99), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(97), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_id_icon,
  [553] = 2,
    ACTIONS(105), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(103), 9,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      aux_sym_month_token1,
      sym_duration_designator,
      sym_id_icon,
  [571] = 5,
    ACTIONS(77), 1,
      aux_sym_month_token1,
    STATE(43), 1,
      sym_time,
    STATE(124), 1,
      sym_hour,
    ACTIONS(109), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(107), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [595] = 2,
    ACTIONS(113), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(111), 9,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      aux_sym_month_token1,
      sym_duration_designator,
      sym_id_icon,
  [613] = 2,
    ACTIONS(117), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(115), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_duration_designator,
      sym_id_icon,
  [630] = 2,
    ACTIONS(121), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(119), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [647] = 6,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(42), 1,
      sym_completed_date,
    STATE(63), 1,
      sym_id,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(65), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [672] = 2,
    ACTIONS(125), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(123), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      aux_sym_context_text_token1,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [689] = 6,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(44), 1,
      sym_completed_date,
    STATE(58), 1,
      sym_id,
    ACTIONS(127), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(129), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [714] = 4,
    ACTIONS(135), 1,
      sym_recurrance_icon,
    STATE(45), 1,
      sym_recurrance,
    ACTIONS(133), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(131), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [735] = 6,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(46), 1,
      sym_completed_date,
    STATE(56), 1,
      sym_id,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(81), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [760] = 2,
    ACTIONS(139), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(137), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_duration_designator,
      sym_id_icon,
  [777] = 6,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(40), 1,
      sym_completed_date,
    STATE(54), 1,
      sym_id,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [802] = 2,
    ACTIONS(143), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(141), 8,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_context_icon,
      sym_do_date_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [819] = 2,
    ACTIONS(147), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(145), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_id_icon,
  [835] = 2,
    ACTIONS(151), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(149), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_id_icon,
  [851] = 2,
    ACTIONS(155), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(153), 7,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_recurrance_icon,
      sym_id_icon,
  [867] = 2,
    ACTIONS(159), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(157), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [882] = 2,
    ACTIONS(163), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(161), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [897] = 2,
    ACTIONS(167), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(165), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [912] = 4,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(63), 1,
      sym_id,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(65), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [931] = 4,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(54), 1,
      sym_id,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [950] = 4,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(56), 1,
      sym_id,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(81), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [969] = 2,
    ACTIONS(171), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(169), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [984] = 4,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(55), 1,
      sym_id,
    ACTIONS(173), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(175), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1003] = 2,
    ACTIONS(179), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(177), 6,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      anon_sym_PERCENT,
      sym_id_icon,
  [1018] = 4,
    ACTIONS(21), 1,
      sym_id_icon,
    STATE(58), 1,
      sym_id,
    ACTIONS(127), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(129), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1037] = 5,
    ACTIONS(185), 1,
      sym_leaf_icon,
    STATE(77), 1,
      sym_leaf_action_list,
    ACTIONS(181), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(49), 2,
      sym_leaf_action,
      aux_sym_leaf_action_list_repeat1,
    ACTIONS(183), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1058] = 4,
    ACTIONS(191), 1,
      sym_leaf_icon,
    ACTIONS(187), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(48), 2,
      sym_leaf_action,
      aux_sym_leaf_action_list_repeat1,
    ACTIONS(189), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1076] = 4,
    ACTIONS(185), 1,
      sym_leaf_icon,
    ACTIONS(194), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(48), 2,
      sym_leaf_action,
      aux_sym_leaf_action_list_repeat1,
    ACTIONS(196), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1094] = 2,
    ACTIONS(200), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
    ACTIONS(198), 5,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
      sym_id_icon,
  [1108] = 5,
    ACTIONS(206), 1,
      sym_double_great_grandchild_icon,
    STATE(79), 1,
      sym_double_great_grandchild_action_list,
    ACTIONS(202), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(67), 2,
      sym_double_great_grandchild_action,
      aux_sym_double_great_grandchild_action_list_repeat1,
    ACTIONS(204), 3,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
  [1128] = 5,
    ACTIONS(212), 1,
      sym_great_grandchild_icon,
    STATE(84), 1,
      sym_great_grandchild_action_list,
    ACTIONS(208), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(210), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(70), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [1147] = 2,
    ACTIONS(214), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(216), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1160] = 2,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(65), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1173] = 2,
    ACTIONS(218), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(220), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1186] = 2,
    ACTIONS(127), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(129), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1199] = 2,
    ACTIONS(222), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(224), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1212] = 2,
    ACTIONS(173), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(175), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1225] = 2,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(44), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1238] = 2,
    ACTIONS(226), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(228), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1251] = 2,
    ACTIONS(230), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(232), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1264] = 6,
    ACTIONS(236), 1,
      sym_child_icon,
    ACTIONS(238), 1,
      sym_story_icon,
    STATE(73), 1,
      sym_story,
    STATE(107), 1,
      sym_child_action_list,
    ACTIONS(234), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(80), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1285] = 2,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(81), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1298] = 2,
    ACTIONS(240), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(242), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1311] = 2,
    ACTIONS(244), 4,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
      sym_story_icon,
    ACTIONS(246), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1324] = 4,
    ACTIONS(252), 1,
      sym_double_great_grandchild_icon,
    ACTIONS(248), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(66), 2,
      sym_double_great_grandchild_action,
      aux_sym_double_great_grandchild_action_list_repeat1,
    ACTIONS(250), 3,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
  [1341] = 4,
    ACTIONS(206), 1,
      sym_double_great_grandchild_icon,
    ACTIONS(255), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(66), 2,
      sym_double_great_grandchild_action,
      aux_sym_double_great_grandchild_action_list_repeat1,
    ACTIONS(257), 3,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
  [1358] = 5,
    ACTIONS(261), 1,
      sym_child_icon,
    ACTIONS(263), 1,
      sym_grandchild_icon,
    STATE(97), 1,
      sym_grandchild_action_list,
    ACTIONS(259), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(76), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [1376] = 2,
    ACTIONS(265), 3,
      ts_builtin_sym_end,
      sym_leaf_icon,
      anon_sym_LPAREN,
    ACTIONS(267), 4,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
      sym_double_great_grandchild_icon,
  [1388] = 4,
    ACTIONS(212), 1,
      sym_great_grandchild_icon,
    ACTIONS(269), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(271), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(71), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [1404] = 4,
    ACTIONS(277), 1,
      sym_great_grandchild_icon,
    ACTIONS(273), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    ACTIONS(275), 2,
      sym_child_icon,
      sym_grandchild_icon,
    STATE(71), 2,
      sym_great_grandchild_action,
      aux_sym_great_grandchild_action_list_repeat1,
  [1420] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(280), 1,
      ts_builtin_sym_end,
    STATE(62), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
    STATE(74), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [1437] = 4,
    ACTIONS(236), 1,
      sym_child_icon,
    STATE(120), 1,
      sym_child_action_list,
    ACTIONS(282), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(80), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1452] = 5,
    ACTIONS(284), 1,
      ts_builtin_sym_end,
    ACTIONS(286), 1,
      anon_sym_LPAREN,
    STATE(62), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
    STATE(74), 2,
      sym_root_action,
      aux_sym_action_list_repeat1,
  [1469] = 4,
    ACTIONS(289), 1,
      sym_not_started,
    ACTIONS(293), 1,
      anon_sym_DASH,
    STATE(136), 1,
      sym_in_progress,
    ACTIONS(291), 3,
      sym_completed,
      sym_blocked,
      sym_cancelled,
  [1484] = 4,
    ACTIONS(263), 1,
      sym_grandchild_icon,
    ACTIONS(297), 1,
      sym_child_icon,
    ACTIONS(295), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(78), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [1499] = 2,
    ACTIONS(299), 3,
      ts_builtin_sym_end,
      sym_double_great_grandchild_icon,
      anon_sym_LPAREN,
    ACTIONS(301), 3,
      sym_child_icon,
      sym_grandchild_icon,
      sym_great_grandchild_icon,
  [1510] = 4,
    ACTIONS(305), 1,
      sym_child_icon,
    ACTIONS(307), 1,
      sym_grandchild_icon,
    ACTIONS(303), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(78), 2,
      sym_grandchild_action,
      aux_sym_grandchild_action_list_repeat1,
  [1525] = 2,
    ACTIONS(312), 2,
      sym_child_icon,
      sym_grandchild_icon,
    ACTIONS(310), 3,
      ts_builtin_sym_end,
      sym_great_grandchild_icon,
      anon_sym_LPAREN,
  [1535] = 3,
    ACTIONS(236), 1,
      sym_child_icon,
    ACTIONS(314), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(83), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1547] = 4,
    ACTIONS(316), 1,
      anon_sym_Da,
    ACTIONS(318), 1,
      anon_sym_W,
    STATE(39), 1,
      sym_recurrance_structure,
    STATE(37), 2,
      sym_daily_recurrance,
      sym_weekly_recurrance,
  [1561] = 3,
    ACTIONS(71), 1,
      aux_sym_context_text_token1,
    STATE(129), 1,
      sym_context_text,
    STATE(12), 3,
      sym_middle_context,
      sym_tail_context,
      aux_sym_context_list_repeat1,
  [1573] = 3,
    ACTIONS(322), 1,
      sym_child_icon,
    ACTIONS(320), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
    STATE(83), 2,
      sym_child_action,
      aux_sym_child_action_list_repeat1,
  [1585] = 2,
    ACTIONS(327), 1,
      sym_child_icon,
    ACTIONS(325), 3,
      ts_builtin_sym_end,
      sym_grandchild_icon,
      anon_sym_LPAREN,
  [1594] = 4,
    ACTIONS(329), 1,
      sym_year,
    STATE(13), 1,
      sym_date,
    STATE(20), 1,
      sym_date_and_time,
    STATE(29), 1,
      sym_extended_date_and_time,
  [1607] = 3,
    ACTIONS(331), 1,
      anon_sym_DASH,
    ACTIONS(333), 1,
      sym__uuid_chunk,
    STATE(88), 1,
      sym_uuid_version_random,
  [1617] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(47), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
  [1627] = 3,
    ACTIONS(335), 1,
      anon_sym_DASH,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    STATE(106), 1,
      sym_uuid_variant_random,
  [1637] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(51), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
  [1647] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(68), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
  [1657] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(69), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
  [1667] = 1,
    ACTIONS(339), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [1673] = 3,
    ACTIONS(333), 1,
      sym__uuid_chunk,
    ACTIONS(341), 1,
      anon_sym_DASH,
    STATE(98), 1,
      sym_uuid_version_random,
  [1683] = 3,
    ACTIONS(329), 1,
      sym_year,
    STATE(13), 1,
      sym_date,
    STATE(50), 1,
      sym_date_and_time,
  [1693] = 3,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    ACTIONS(343), 1,
      anon_sym_DASH,
    STATE(115), 1,
      sym_uuid_variant_random,
  [1703] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(52), 1,
      sym_core_action,
    STATE(137), 1,
      sym_state,
  [1713] = 1,
    ACTIONS(345), 3,
      ts_builtin_sym_end,
      sym_child_icon,
      anon_sym_LPAREN,
  [1719] = 3,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    ACTIONS(347), 1,
      anon_sym_DASH,
    STATE(117), 1,
      sym_uuid_variant_random,
  [1729] = 3,
    ACTIONS(349), 1,
      anon_sym_DASH,
    ACTIONS(351), 1,
      sym__uuid_chunk,
    STATE(86), 1,
      sym_uuid_time_mid,
  [1739] = 2,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    STATE(102), 1,
      sym_uuid_variant_random,
  [1746] = 1,
    ACTIONS(353), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1751] = 2,
    ACTIONS(355), 1,
      anon_sym_DASH,
    ACTIONS(357), 1,
      sym_uuid_random,
  [1758] = 2,
    ACTIONS(333), 1,
      sym__uuid_chunk,
    STATE(95), 1,
      sym_uuid_version_random,
  [1765] = 2,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    STATE(117), 1,
      sym_uuid_variant_random,
  [1772] = 1,
    ACTIONS(359), 2,
      anon_sym_DASH,
      sym_uuid_random,
  [1777] = 2,
    ACTIONS(361), 1,
      anon_sym_DASH,
    ACTIONS(363), 1,
      sym_uuid_random,
  [1784] = 1,
    ACTIONS(282), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [1789] = 2,
    ACTIONS(365), 1,
      aux_sym_priority_number_token1,
    STATE(35), 1,
      sym_duration_value,
  [1796] = 2,
    ACTIONS(367), 1,
      aux_sym_month_token1,
    STATE(133), 1,
      sym_month,
  [1803] = 2,
    ACTIONS(351), 1,
      sym__uuid_chunk,
    STATE(93), 1,
      sym_uuid_time_mid,
  [1810] = 2,
    ACTIONS(369), 1,
      aux_sym_month_token1,
    STATE(9), 1,
      sym_minute,
  [1817] = 2,
    ACTIONS(371), 1,
      aux_sym_month_token1,
    STATE(23), 1,
      sym_day,
  [1824] = 1,
    ACTIONS(373), 2,
      anon_sym_DASH,
      sym__uuid_chunk,
  [1829] = 2,
    ACTIONS(375), 1,
      sym_uuid_time_high,
    STATE(61), 1,
      sym_uuid,
  [1836] = 2,
    ACTIONS(377), 1,
      anon_sym_DASH,
    ACTIONS(379), 1,
      sym_uuid_random,
  [1843] = 2,
    ACTIONS(337), 1,
      sym__uuid_chunk,
    STATE(115), 1,
      sym_uuid_variant_random,
  [1850] = 2,
    ACTIONS(381), 1,
      anon_sym_DASH,
    ACTIONS(383), 1,
      sym_uuid_random,
  [1857] = 2,
    ACTIONS(333), 1,
      sym__uuid_chunk,
    STATE(98), 1,
      sym_uuid_version_random,
  [1864] = 2,
    ACTIONS(385), 1,
      aux_sym_priority_number_token1,
    STATE(33), 1,
      sym_priority_number,
  [1871] = 1,
    ACTIONS(387), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [1876] = 1,
    ACTIONS(389), 1,
      anon_sym_DASH,
  [1880] = 1,
    ACTIONS(383), 1,
      sym_uuid_random,
  [1884] = 1,
    ACTIONS(391), 1,
      sym_description_text,
  [1888] = 1,
    ACTIONS(393), 1,
      anon_sym_COLON,
  [1892] = 1,
    ACTIONS(379), 1,
      sym_uuid_random,
  [1896] = 1,
    ACTIONS(395), 1,
      ts_builtin_sym_end,
  [1900] = 1,
    ACTIONS(397), 1,
      anon_sym_DASH,
  [1904] = 1,
    ACTIONS(399), 1,
      sym_name,
  [1908] = 1,
    ACTIONS(401), 1,
      sym_context_separator,
  [1912] = 1,
    ACTIONS(403), 1,
      anon_sym_COLON,
  [1916] = 1,
    ACTIONS(357), 1,
      sym_uuid_random,
  [1920] = 1,
    ACTIONS(405), 1,
      sym_story_name,
  [1924] = 1,
    ACTIONS(407), 1,
      anon_sym_DASH,
  [1928] = 1,
    ACTIONS(409), 1,
      anon_sym_RPAREN,
  [1932] = 1,
    ACTIONS(411), 1,
      sym_uuid_random,
  [1936] = 1,
    ACTIONS(413), 1,
      anon_sym_RPAREN,
  [1940] = 1,
    ACTIONS(415), 1,
      sym_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 49,
  [SMALL_STATE(4)] = 79,
  [SMALL_STATE(5)] = 107,
  [SMALL_STATE(6)] = 135,
  [SMALL_STATE(7)] = 178,
  [SMALL_STATE(8)] = 215,
  [SMALL_STATE(9)] = 236,
  [SMALL_STATE(10)] = 259,
  [SMALL_STATE(11)] = 286,
  [SMALL_STATE(12)] = 323,
  [SMALL_STATE(13)] = 350,
  [SMALL_STATE(14)] = 376,
  [SMALL_STATE(15)] = 407,
  [SMALL_STATE(16)] = 438,
  [SMALL_STATE(17)] = 469,
  [SMALL_STATE(18)] = 493,
  [SMALL_STATE(19)] = 513,
  [SMALL_STATE(20)] = 531,
  [SMALL_STATE(21)] = 553,
  [SMALL_STATE(22)] = 571,
  [SMALL_STATE(23)] = 595,
  [SMALL_STATE(24)] = 613,
  [SMALL_STATE(25)] = 630,
  [SMALL_STATE(26)] = 647,
  [SMALL_STATE(27)] = 672,
  [SMALL_STATE(28)] = 689,
  [SMALL_STATE(29)] = 714,
  [SMALL_STATE(30)] = 735,
  [SMALL_STATE(31)] = 760,
  [SMALL_STATE(32)] = 777,
  [SMALL_STATE(33)] = 802,
  [SMALL_STATE(34)] = 819,
  [SMALL_STATE(35)] = 835,
  [SMALL_STATE(36)] = 851,
  [SMALL_STATE(37)] = 867,
  [SMALL_STATE(38)] = 882,
  [SMALL_STATE(39)] = 897,
  [SMALL_STATE(40)] = 912,
  [SMALL_STATE(41)] = 931,
  [SMALL_STATE(42)] = 950,
  [SMALL_STATE(43)] = 969,
  [SMALL_STATE(44)] = 984,
  [SMALL_STATE(45)] = 1003,
  [SMALL_STATE(46)] = 1018,
  [SMALL_STATE(47)] = 1037,
  [SMALL_STATE(48)] = 1058,
  [SMALL_STATE(49)] = 1076,
  [SMALL_STATE(50)] = 1094,
  [SMALL_STATE(51)] = 1108,
  [SMALL_STATE(52)] = 1128,
  [SMALL_STATE(53)] = 1147,
  [SMALL_STATE(54)] = 1160,
  [SMALL_STATE(55)] = 1173,
  [SMALL_STATE(56)] = 1186,
  [SMALL_STATE(57)] = 1199,
  [SMALL_STATE(58)] = 1212,
  [SMALL_STATE(59)] = 1225,
  [SMALL_STATE(60)] = 1238,
  [SMALL_STATE(61)] = 1251,
  [SMALL_STATE(62)] = 1264,
  [SMALL_STATE(63)] = 1285,
  [SMALL_STATE(64)] = 1298,
  [SMALL_STATE(65)] = 1311,
  [SMALL_STATE(66)] = 1324,
  [SMALL_STATE(67)] = 1341,
  [SMALL_STATE(68)] = 1358,
  [SMALL_STATE(69)] = 1376,
  [SMALL_STATE(70)] = 1388,
  [SMALL_STATE(71)] = 1404,
  [SMALL_STATE(72)] = 1420,
  [SMALL_STATE(73)] = 1437,
  [SMALL_STATE(74)] = 1452,
  [SMALL_STATE(75)] = 1469,
  [SMALL_STATE(76)] = 1484,
  [SMALL_STATE(77)] = 1499,
  [SMALL_STATE(78)] = 1510,
  [SMALL_STATE(79)] = 1525,
  [SMALL_STATE(80)] = 1535,
  [SMALL_STATE(81)] = 1547,
  [SMALL_STATE(82)] = 1561,
  [SMALL_STATE(83)] = 1573,
  [SMALL_STATE(84)] = 1585,
  [SMALL_STATE(85)] = 1594,
  [SMALL_STATE(86)] = 1607,
  [SMALL_STATE(87)] = 1617,
  [SMALL_STATE(88)] = 1627,
  [SMALL_STATE(89)] = 1637,
  [SMALL_STATE(90)] = 1647,
  [SMALL_STATE(91)] = 1657,
  [SMALL_STATE(92)] = 1667,
  [SMALL_STATE(93)] = 1673,
  [SMALL_STATE(94)] = 1683,
  [SMALL_STATE(95)] = 1693,
  [SMALL_STATE(96)] = 1703,
  [SMALL_STATE(97)] = 1713,
  [SMALL_STATE(98)] = 1719,
  [SMALL_STATE(99)] = 1729,
  [SMALL_STATE(100)] = 1739,
  [SMALL_STATE(101)] = 1746,
  [SMALL_STATE(102)] = 1751,
  [SMALL_STATE(103)] = 1758,
  [SMALL_STATE(104)] = 1765,
  [SMALL_STATE(105)] = 1772,
  [SMALL_STATE(106)] = 1777,
  [SMALL_STATE(107)] = 1784,
  [SMALL_STATE(108)] = 1789,
  [SMALL_STATE(109)] = 1796,
  [SMALL_STATE(110)] = 1803,
  [SMALL_STATE(111)] = 1810,
  [SMALL_STATE(112)] = 1817,
  [SMALL_STATE(113)] = 1824,
  [SMALL_STATE(114)] = 1829,
  [SMALL_STATE(115)] = 1836,
  [SMALL_STATE(116)] = 1843,
  [SMALL_STATE(117)] = 1850,
  [SMALL_STATE(118)] = 1857,
  [SMALL_STATE(119)] = 1864,
  [SMALL_STATE(120)] = 1871,
  [SMALL_STATE(121)] = 1876,
  [SMALL_STATE(122)] = 1880,
  [SMALL_STATE(123)] = 1884,
  [SMALL_STATE(124)] = 1888,
  [SMALL_STATE(125)] = 1892,
  [SMALL_STATE(126)] = 1896,
  [SMALL_STATE(127)] = 1900,
  [SMALL_STATE(128)] = 1904,
  [SMALL_STATE(129)] = 1908,
  [SMALL_STATE(130)] = 1912,
  [SMALL_STATE(131)] = 1916,
  [SMALL_STATE(132)] = 1920,
  [SMALL_STATE(133)] = 1924,
  [SMALL_STATE(134)] = 1928,
  [SMALL_STATE(135)] = 1932,
  [SMALL_STATE(136)] = 1936,
  [SMALL_STATE(137)] = 1940,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 2),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weekly_recurrance, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weekly_recurrance, 1),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weekly_recurrance_days, 1),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weekly_recurrance_days, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_weekly_recurrance_days_repeat1, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_weekly_recurrance_days_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_weekly_recurrance_days_repeat1, 2), SHIFT_REPEAT(5),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 3),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_minute, 1),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_minute, 1),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 3),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 3),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_context_list_repeat1, 2),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_list_repeat1, 2), SHIFT_REPEAT(18),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 4),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 4),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_list, 2),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context_list, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_and_time, 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_and_time, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 5),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 5),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weekly_recurrance, 2),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weekly_recurrance, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tail_context, 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tail_context, 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context_text, 1),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_description, 2),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_description, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extended_date_and_time, 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_extended_date_and_time, 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day, 1),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_daily_recurrance, 1),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_daily_recurrance, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date, 5),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date, 5),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_and_time, 2),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_and_time, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority_number, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority_number, 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_middle_context, 2),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_middle_context, 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 6),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 6),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 2),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_do_date_or_time, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 4),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 4),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_priority, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_value, 1),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration_value, 1),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 2),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration, 2),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extended_date_and_time, 2),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_extended_date_and_time, 2),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_recurrance_structure, 1),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_recurrance_structure, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weekly_recurrance, 3),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weekly_recurrance, 3),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_recurrance, 2),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_recurrance, 2),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_daily_recurrance, 2),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_daily_recurrance, 2),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 7),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 7),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_do_date_or_time, 3),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_do_date_or_time, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_great_grandchild_action, 2),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_great_grandchild_action, 2),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_leaf_action_list_repeat1, 2),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_leaf_action_list_repeat1, 2),
  [191] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_leaf_action_list_repeat1, 2), SHIFT_REPEAT(91),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_leaf_action_list, 1),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_leaf_action_list, 1),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_completed_date, 2),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_completed_date, 2),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_great_grandchild_action, 2),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_great_grandchild_action, 2),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action, 2),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 8),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 8),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_core_action, 8),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_core_action, 8),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 5),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 5),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 9),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 9),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id, 2),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id, 2),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 1),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 6),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 6),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid, 7),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_uuid, 7),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_double_great_grandchild_action_list_repeat1, 2),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_great_grandchild_action_list_repeat1, 2),
  [252] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_great_grandchild_action_list_repeat1, 2), SHIFT_REPEAT(87),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_great_grandchild_action_list, 1),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_great_grandchild_action_list, 1),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 2),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_child_action, 2),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_leaf_action, 2),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_leaf_action, 2),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_great_grandchild_action_list, 1),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_great_grandchild_action_list, 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2),
  [277] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_great_grandchild_action_list_repeat1, 2), SHIFT_REPEAT(89),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_list, 1),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 2),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_action_list_repeat1, 2), SHIFT_REPEAT(75),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action_list, 1),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action_list, 1),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_great_grandchild_action, 3),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_great_grandchild_action, 3),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_grandchild_action_list_repeat1, 2), SHIFT_REPEAT(96),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_great_grandchild_action, 3),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_great_grandchild_action, 3),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action_list, 1),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2),
  [322] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_child_action_list_repeat1, 2), SHIFT_REPEAT(90),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grandchild_action, 3),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grandchild_action, 3),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_story, 2),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_action, 3),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_version_random, 1),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_variant_random, 1),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uuid_time_mid, 1),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_action, 3),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [395] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_month, 1),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state, 3),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hour, 1),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_progress, 1),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
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
