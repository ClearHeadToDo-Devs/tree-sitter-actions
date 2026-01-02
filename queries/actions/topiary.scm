;; ==============================================================================
;; Topiary formatting query for .actions files
;;
;; This implements basic formatting with proper spacing between elements.
;; Advanced indentation for list mode will be added later.
;; ==============================================================================

;; ------------------------------------------------------------------------------
;; Spacing Rules
;; ------------------------------------------------------------------------------

;; Space after state brackets
(state) @append_space

;; Space before each metadata item (compact mode)
;; In multi-line mode, these become newlines
(description) @prepend_space
(priority) @prepend_space
(story) @prepend_space
(context) @prepend_space
(do_date) @prepend_space
(completed_date) @prepend_space
(id) @prepend_space

;; Space after $ icon in descriptions
(description
  icon: "$" @append_space
)

;; Depth markers: space after each >
(depth1_marker) @append_space
(depth2_marker) @append_space
(depth3_marker) @append_space
(depth4_marker) @append_space
(depth5_marker) @append_space

;; Newline after each action
(root_action) @append_hardline
(depth1_action) @append_hardline
(depth2_action) @append_hardline
(depth3_action) @append_hardline
(depth4_action) @append_hardline
(depth5_action) @append_hardline

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
(name_text_chunk) @leaf
(description_text_chunk) @leaf
(link_text) @leaf
(link_url) @leaf

;; Priority and story content (now named nodes from grammar refactor)
(priority_level) @leaf
(story_name) @leaf
