;; ==============================================================================
;; Topiary formatting query for .actions files
;;
;; Scope: Vertical spacing only.
;; Horizontal spacing and indentation are preserved by design.
;;
;; See specifications/formatting.md and examples/formatting/README.md for details.
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
