;; ==============================================================================
;; Topiary formatting query for .actions files
;;
;; This query file implements the formatting rules defined in:
;; https://github.com/clearheadtodo-devs/specifications/formatting_specification.md
;;
;; Supports two formatting modes:
;;   - Compact (single-line): metadata separated by spaces on same line
;;   - List (multi-line): metadata on separate lines with indentation
;;
;; Mode selection is controlled by Topiary's multi-line vs single-line context.
;; ==============================================================================

;; ------------------------------------------------------------------------------
;; Root Actions (depth 0)
;; ------------------------------------------------------------------------------

;; State bracket and name stay together, always one space between
(root_action
  (state) @append_space
)

;; After the name, start indenting for metadata (in list mode)
;; In compact mode, this does nothing; in list mode, metadata gets indented
(root_action
  (name) @append_indent_start
)

;; Each metadata item gets a "spaced softline" before it:
;;   - In compact mode (single-line): expands to a single space
;;   - In list mode (multi-line): expands to newline + indent
(root_action
  (description) @prepend_spaced_softline
)

(root_action
  (priority) @prepend_spaced_softline
)

(root_action
  (story) @prepend_spaced_softline
)

(root_action
  (context) @prepend_spaced_softline
)

(root_action
  (do_date) @prepend_spaced_softline
)

(root_action
  (completed_date) @prepend_spaced_softline
)

(root_action
  (id) @prepend_spaced_softline
)

;; End the indent scope and force a newline after the action
(root_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Child Actions - Depth 1
;; ------------------------------------------------------------------------------

(depth1_action
  (depth1_marker) @append_space  ; ">" followed by space
)

(depth1_action
  (state) @append_space
)

(depth1_action
  (name) @append_indent_start
)

(depth1_action
  (description) @prepend_spaced_softline
)

(depth1_action
  (priority) @prepend_spaced_softline
)

(depth1_action
  (story) @prepend_spaced_softline
)

(depth1_action
  (context) @prepend_spaced_softline
)

(depth1_action
  (do_date) @prepend_spaced_softline
)

(depth1_action
  (completed_date) @prepend_spaced_softline
)

(depth1_action
  (id) @prepend_spaced_softline
)

(depth1_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Child Actions - Depth 2
;; ------------------------------------------------------------------------------

(depth2_action
  (depth2_marker) @append_space  ; ">>" followed by space
)

(depth2_action
  (state) @append_space
)

(depth2_action
  (name) @append_indent_start
)

(depth2_action
  (description) @prepend_spaced_softline
)

(depth2_action
  (priority) @prepend_spaced_softline
)

(depth2_action
  (story) @prepend_spaced_softline
)

(depth2_action
  (context) @prepend_spaced_softline
)

(depth2_action
  (do_date) @prepend_spaced_softline
)

(depth2_action
  (completed_date) @prepend_spaced_softline
)

(depth2_action
  (id) @prepend_spaced_softline
)

(depth2_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Child Actions - Depth 3
;; ------------------------------------------------------------------------------

(depth3_action
  (depth3_marker) @append_space  ; ">>>" followed by space
)

(depth3_action
  (state) @append_space
)

(depth3_action
  (name) @append_indent_start
)

(depth3_action
  (description) @prepend_spaced_softline
)

(depth3_action
  (priority) @prepend_spaced_softline
)

(depth3_action
  (story) @prepend_spaced_softline
)

(depth3_action
  (context) @prepend_spaced_softline
)

(depth3_action
  (do_date) @prepend_spaced_softline
)

(depth3_action
  (completed_date) @prepend_spaced_softline
)

(depth3_action
  (id) @prepend_spaced_softline
)

(depth3_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Child Actions - Depth 4
;; ------------------------------------------------------------------------------

(depth4_action
  (depth4_marker) @append_space  ; ">>>>" followed by space
)

(depth4_action
  (state) @append_space
)

(depth4_action
  (name) @append_indent_start
)

(depth4_action
  (description) @prepend_spaced_softline
)

(depth4_action
  (priority) @prepend_spaced_softline
)

(depth4_action
  (story) @prepend_spaced_softline
)

(depth4_action
  (context) @prepend_spaced_softline
)

(depth4_action
  (do_date) @prepend_spaced_softline
)

(depth4_action
  (completed_date) @prepend_spaced_softline
)

(depth4_action
  (id) @prepend_spaced_softline
)

(depth4_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Child Actions - Depth 5 (leaf level)
;; ------------------------------------------------------------------------------

(depth5_action
  (depth5_marker) @append_space  ; ">>>>>" followed by space
)

(depth5_action
  (state) @append_space
)

(depth5_action
  (name) @append_indent_start
)

(depth5_action
  (description) @prepend_spaced_softline
)

(depth5_action
  (priority) @prepend_spaced_softline
)

;; Note: depth5 cannot have story (only root actions can)

(depth5_action
  (context) @prepend_spaced_softline
)

(depth5_action
  (do_date) @prepend_spaced_softline
)

(depth5_action
  (completed_date) @prepend_spaced_softline
)

(depth5_action
  (id) @prepend_spaced_softline
)

(depth5_action) @prepend_indent_end @append_hardline

;; ------------------------------------------------------------------------------
;; Metadata Icon Spacing
;; Per formatting_specification.md: only $ gets a space after the icon
;; ------------------------------------------------------------------------------

;; Description: space after $ icon
(description
  "$$" @append_space
)

;; All other metadata icons have no space (value follows directly):
;; Priority: !1 (no space)
;; Story: *Project (no space)
;; Context: +Work (no space)
;; Do-date: @2025-01-20 (no space)
;; Duration is part of do_date node, handled by grammar
;; Recurrence is part of do_date node, handled by grammar
;; Completed: %2025-01-20 (no space)
;; ID: #uuid (no space)

;; ------------------------------------------------------------------------------
;; Leaf Nodes - Don't recursively format these
;; ------------------------------------------------------------------------------

;; Links are atomic units [[text|url]]
(link) @leaf

;; UUIDs should not be reformatted
(uuid_value) @leaf

;; Datetimes are formatted by ISO 8601, leave as-is
(datetime) @leaf

;; RRULE syntax is standardized, don't reformat
(rrule_content) @leaf

;; Duration minutes are just numbers
(minutes) @leaf

;; Context tags are comma-separated, leave as-is
(tag) @leaf

;; Text chunks in names and descriptions should not be reformatted
(name_text_chunk) @leaf
(description_text_chunk) @leaf
(link_text) @leaf
(link_url) @leaf
