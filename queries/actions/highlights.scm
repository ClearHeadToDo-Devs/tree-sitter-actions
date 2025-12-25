; State markers
; Hide brackets and replace the internal character with an icon
(state "[" @conceal)
(state "]" @conceal)
(state_not_started) @conceal (#set! conceal "󰄱")
(state_completed) @conceal (#set! conceal "󰄵")
(state_in_progress) @conceal (#set! conceal "󰄳")
(state_blocked) @conceal (#set! conceal "󰅙")
(state_cancelled) @conceal (#set! conceal "󰪑")

; Action content
(name) @text.title
(description) @text.note

; Metadata
(priority "!" @conceal (#set! conceal "󰀦")) @number
(story "*" @conceal (#set! conceal "󰙨")) @type
(context "+" @conceal (#set! conceal "󰓹")) @tag

(do_date "@" @conceal (#set! conceal "󰃭")) @string.special
(completed_date "%" @conceal (#set! conceal "󰄬")) @string.special

; ID with '#' marker
(id "#" @punctuation.special)
