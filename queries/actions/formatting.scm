;; ==============================================================================
;; Topiary formatting query for .actions files
;;
;; Scope: Vertical spacing only.
;; Horizontal spacing and indentation preserved from input.
;; The format is whitespace-insensitive by design.
;;
;; See specifications/formatting.md for details.
;; ==============================================================================

;; ------------------------------------------------------------------------------
;; Vertical Spacing
;; ------------------------------------------------------------------------------

;; Each root action ends with a newline
(root_action) @append_hardline

;; Child actions start on new lines
(depth1_action) @prepend_hardline
(depth2_action) @prepend_hardline
(depth3_action) @prepend_hardline
(depth4_action) @prepend_hardline
(depth5_action) @prepend_hardline

;; ------------------------------------------------------------------------------
;; Leaf Nodes - Preserve content unchanged
;;
;; Mark all the internal nodes as leaves so their content (including any
;; whitespace) is preserved exactly as written.
;; ------------------------------------------------------------------------------

;; Depth markers preserve their formatting (including any leading indent)
(depth1_marker) @leaf
(depth2_marker) @leaf
(depth3_marker) @leaf
(depth4_marker) @leaf
(depth5_marker) @leaf

;; State and metadata preserved unchanged
(state) @leaf
(name) @leaf
(description) @leaf
(priority) @leaf
(story) @leaf
(context) @leaf
(do_date) @leaf
(duration) @leaf
(recurrence) @leaf
(completed_date) @leaf
(created_date) @leaf
(predecessor) @leaf
(id) @leaf
(link) @leaf
