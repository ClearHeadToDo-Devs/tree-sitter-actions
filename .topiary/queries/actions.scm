;; ==============================================================================
;; Topiary formatting query for .actions files
;;
;; This implements vertical spacing and basic structural formatting.
;; Horizontal spacing is preserved from input (best-effort approach).
;;
;; See formatting_specification.md for details on formatter scope.
;; ==============================================================================

;; ------------------------------------------------------------------------------
;; Vertical Spacing (Enforced)
;; ------------------------------------------------------------------------------

;; Newline before each child marker (separates parent from children)
(depth1_marker) @prepend_hardline
(depth2_marker) @prepend_hardline
(depth3_marker) @prepend_hardline
(depth4_marker) @prepend_hardline
(depth5_marker) @prepend_hardline

;; Newline after leaf actions (those without children)
;; For root actions with children, the hardline comes from the child marker
(root_action) @append_hardline

;; ------------------------------------------------------------------------------
;; Structural Spacing (Best-effort)
;; ------------------------------------------------------------------------------
;;
;; Note: Horizontal spacing is preserved from input due to how the grammar
;; captures whitespace in text chunks. The formatter cannot reliably add or
;; remove spaces at the token level. Users should ensure proper spacing in
;; their input files.

;; ------------------------------------------------------------------------------
;; Leaf Nodes - Preserve these unchanged
;; ------------------------------------------------------------------------------

;; Named leaf nodes
(link) @leaf
(uuid_value) @leaf
(datetime) @leaf
(rrule_content) @leaf
(minutes) @leaf
(tag) @leaf
; Removed @leaf from text chunks to allow whitespace processing
; (name_text_chunk) @leaf
; (description_text_chunk) @leaf
(link_text) @leaf
(link_url) @leaf

;; Priority and story content (now named nodes from grammar refactor)
(priority_level) @leaf
(story_name) @leaf
