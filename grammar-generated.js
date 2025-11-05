module.exports = {
  id: ($) => seq(field('icon', '#'), field('value', /[0-9a-f]{8}-[0-9a-f]{4}-7[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}/)),
  name: ($) => field('text', $.safe_text),
  priority: ($) => seq(field('icon', '!'), field('number', choice('1', '2', '3', '4'))),
  state: ($) => choice(seq('[', ' ', ']'), seq('[', 'x', ']'), seq('[', '-', ']'), seq('[', '=', ']'), seq('[', '_', ']')),
  context: ($) => seq(field('icon', '+'), sep1(field('value', /@[a-zA-Z0-9_-]+(,@[a-zA-Z0-9_-]+)*/), ',')),
  description: ($) => seq(field('icon', '$'), field('text', $.safe_text)),
  project: ($) => seq(field('icon', '*'), field('text', $.safe_text)),
  depth: ($) => $.depth,
  do_date_or_time: ($) => seq(field('icon', '@'), field('value', choice($.iso_date_time, $.iso_date, $.iso_time))),
  completed_date: ($) => seq(field('icon', '%'), field('value', choice($.iso_date_time, $.iso_date, $.iso_time))),
  duration: ($) => seq(field('icon', 'D'), field('minutes', /d+/)),
  recurrence: ($) => seq(field('icon', 'R'), field('number', choice('DAILY', 'WEEKLY', 'MONTHLY', 'YEARLY'))),
  recurrence_interval: ($) => seq(field('icon', 'I'), field('minutes', /d+/)),
  recurrence_count: ($) => seq(field('icon', 'C'), field('minutes', /d+/)),
  recurrence_until: ($) => seq(field('icon', 'U'), field('value', choice($.iso_date_time, $.iso_date, $.iso_time)))
};