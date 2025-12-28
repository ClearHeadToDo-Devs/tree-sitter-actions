; State markers - hide brackets using fields
(state open: "[" @conceal)
(state close: "]" @conceal)
(state_not_started) @conceal (#set! conceal "󰄱")
(state_completed) @conceal (#set! conceal "󰄵")
(state_in_progress) @conceal (#set! conceal "󰄳")
(state_blocked) @conceal (#set! conceal "󰅙")
(state_cancelled) @conceal (#set! conceal "󰪑")

; Child markers - using field queries
(depth1_action marker: ">" @conceal (#set! conceal "├"))
(depth2_action marker: ">>" @conceal (#set! conceal "│├"))
(depth3_action marker: ">>>" @conceal (#set! conceal "││├"))
(depth4_action marker: ">>>>" @conceal (#set! conceal "│││├"))
(depth5_action marker: ">>>>>" @conceal (#set! conceal "││││├"))

; Action content - make name bold
(name) @markup.strong
(description) @text.note

; Metadata icons - using field queries
(priority icon: "!" @conceal (#set! conceal "󰀦")) @number
(story icon: "*" @conceal (#set! conceal "󰙨")) @type
(context icon: "+" @conceal (#set! conceal "󰓹")) @tag
(description icon: "$" @conceal (#set! conceal "💬"))

(do_date icon: "@" @conceal (#set! conceal "󰃭")) @string.special
(completed_date icon: "%" @conceal (#set! conceal "󰄬")) @string.special

; ID - show icon, hide UUID
(id icon: "#" @conceal (#set! conceal "🆔"))
(id uuid: (uuid_value) @conceal)
