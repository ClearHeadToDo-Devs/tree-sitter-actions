;; ============================================================================
;; State Icons - Replace entire state based on type
;; ============================================================================

; Not started: [ ] -> 󰄱
(state (state_not_started)) @conceal (#set! conceal "󰄱")

; Completed: [x] -> 󰄵
(state (state_completed)) @conceal (#set! conceal "󰄵")

; In progress: [-] -> 󰄳
(state (state_in_progress)) @conceal (#set! conceal "󰄳")

; Blocked: [=] -> 󰅙
(state (state_blocked)) @conceal (#set! conceal "󰅙")

; Cancelled: [_] -> 󰪑
(state (state_cancelled)) @conceal (#set! conceal "󰪑")


;; ============================================================================
;; Child Markers - Make completely invisible
;; ============================================================================

; Depth markers: >, >>, >>>, etc. -> invisible
(depth1_action ">" @conceal)
(depth2_action ">>" @conceal)
(depth3_action ">>>" @conceal)
(depth4_action ">>>>" @conceal)
(depth5_action ">>>>>" @conceal)


;; ============================================================================
;; ID - Replace entire ID (# + UUID) with single icon
;; ============================================================================

(id) @conceal (#set! conceal "🆔")


;; ============================================================================
;; Other Highlighting
;; ============================================================================

; Action content - make name bold
(name) @markup.strong
(description) @text.note

; Metadata icons - replace markers with icons
(priority "!" @conceal (#set! conceal "󰀦"))
(story "*" @conceal (#set! conceal "󰙨"))
(context "+" @conceal (#set! conceal "󰓹"))
(description "$" @conceal (#set! conceal "💬"))
(do_date "@" @conceal (#set! conceal "󰃭"))
(completed_date "%" @conceal (#set! conceal "󰄬"))
