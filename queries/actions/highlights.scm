;; ============================================================================
;; State Icons - Replace entire state based on type
;; ============================================================================

; Conceal brackets (hide completely)
((state_open) @conceal (#set! conceal ""))
((state_close) @conceal (#set! conceal ""))

; Conceal state value and replace with icon based on type
((state_not_started) @conceal (#set! conceal "󰄱"))
((state_completed) @conceal (#set! conceal "󰄵"))
((state_in_progress) @conceal (#set! conceal "󰄳"))
((state_blocked) @conceal (#set! conceal "󰅙"))
((state_cancelled) @conceal (#set! conceal "󰪑"))


;; ============================================================================
;; Child Markers - Make completely invisible
;; ============================================================================

; Depth markers: >, >>, >>>, etc. -> invisible
((depth1_marker) @conceal (#set! conceal ""))
((depth2_marker) @conceal (#set! conceal ""))
((depth3_marker) @conceal (#set! conceal ""))
((depth4_marker) @conceal (#set! conceal ""))
((depth5_marker) @conceal (#set! conceal ""))


;; ============================================================================
;; ID - Replace # with icon and hide UUID
;; ============================================================================

; Replace # with icon
((id_hash) @conceal (#set! conceal "🆔"))

; Hide the UUID completely
((uuid_value) @conceal (#set! conceal ""))


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
