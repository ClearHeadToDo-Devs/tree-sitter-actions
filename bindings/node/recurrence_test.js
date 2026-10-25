const assert = require('node:assert/strict');
const { test } = require('node:test');
const Parser = require('tree-sitter');

function parse(text) {
  const parser = new Parser();
  parser.setLanguage(require('.'));
  return parser.parse(text).rootNode;
}

function checkRule(anchor, rule, suffix = '') {
  const root = parse(`[ ] Habit @${anchor} R:${rule}${suffix}\n`);
  assert.equal(root.hasError, false, root.toString());
  const date = root.descendantsOfType('do_date')[0];
  const recurrence = date.childForFieldName('recurrence');
  assert.ok(recurrence, root.toString());
  assert.equal(recurrence.type, 'recurrence');
  assert.equal(recurrence.childForFieldName('rrule').text, rule);
  return root;
}

for (const anchor of [
  '2026-10-25',
  '2026-10-25T09:30',
  '2026-10-25T09:30:15Z',
  '2026-10-25T09:30-04:00',
  '2026-10-25/2026-10-26',
  '2026-10-25T09:30-04:00/2026-10-25T10:00-04:00',
  '2026-10-25D30',
]) {
  test(`recurrence follows @ anchor ${anchor}`, () => checkRule(anchor, 'FREQ=DAILY'));
}

for (const rule of [
  'FREQ=SECONDLY;BYSECOND=0,30',
  'FREQ=MINUTELY;INTERVAL=15',
  'FREQ=HOURLY;BYMINUTE=0,30;COUNT=10',
  'FREQ=DAILY;UNTIL=20261231T235959Z',
  'FREQ=WEEKLY;BYDAY=MO,WE,FR;WKST=SU',
  'FREQ=MONTHLY;BYDAY=+1MO,-1FR;BYMONTHDAY=1,-1;BYSETPOS=-1',
  'FREQ=YEARLY;BYMONTH=1,7;BYYEARDAY=1,-1;BYWEEKNO=1;BYHOUR=9',
  'BYDAY=MO;FREQ=WEEKLY',
  // Parse rule text, not semantic validity: lint owns missing/invalid FREQ,
  // duplicate parts, incompatible bounds and numeric ranges.
  'FREQ=UNKNOWN;COUNT=0;COUNT=2;UNTIL=20261231',
]) {
  test(`RRULE text ${rule}`, () => checkRule('2026-10-25', rule));
}

test('remaining metadata is not consumed by RRULE', () => {
  const root = checkRule('2026-10-25', 'FREQ=WEEKLY;BYDAY=MO,FR',
    ' :2026-10-25T10:00-04:00 !2 *Home +daily %2026-10-26 ^2026-10-20 <prep =habit ~ #01a17112-8887-7701-85ab-6d1f059514c7 $template: morning$');
  const action = root.namedChildren[0];
  assert.deepEqual(action.childrenForFieldName('metadata').map(n => n.type), [
    'do_date', 'due_date', 'priority', 'story', 'context', 'completed_date',
    'created_date', 'predecessor', 'alias', 'sequential', 'id', 'description',
  ]);
  checkRule('2026-10-25', 'FREQ=DAILY', ':2026-10-26!1$details$');
});

test('ordinary R names and description RRULE examples remain text', () => {
  const root = parse('[ ] Review R reports and RRULE examples $R:FREQ=DAILY, literal prose$\n');
  assert.equal(root.hasError, false, root.toString());
  assert.equal(root.descendantsOfType('recurrence').length, 0);
  assert.equal(root.descendantsOfType('name')[0].text, 'Review R reports and RRULE examples');
});

test('habit template children and following roots retain structure', () => {
  const root = parse('[ ] Habit @2026-10-25 R:FREQ=DAILY\n> [ ] First step\n>> [ ] Nested step\n> [ ] Second step\n[ ] Next root\n');
  assert.equal(root.hasError, false, root.toString());
  assert.equal(root.namedChildren.length, 2);
  assert.equal(root.namedChildren[0].childrenForFieldName('child').length, 2);
  assert.equal(root.descendantsOfType('depth2_action').length, 1);
  assert.equal(root.descendantsOfType('recurrence').length, 1);
});

for (const input of ['R:', 'R:FREQ=', 'R:FREQ=DAILY;', 'R:FREQ=DAILY;BYDAY=']) {
  test(`incomplete rule recovers at next action: ${input}`, () => {
    const root = parse(`[ ] Editing @2026-10-25 ${input}\n[ ] Next root\n`);
    assert.equal(root.hasError, true, root.toString());
    assert.ok(root.descendantsOfType('root_action').some(action =>
      action.childForFieldName('name')?.text === 'Next root'), root.toString());
  });
}

test('plain @ dates and ranges still have no recurrence', () => {
  const root = parse('[ ] One @2026-10-25\n[ ] Two @2026-10-25/2026-10-26\n');
  assert.equal(root.hasError, false, root.toString());
  assert.equal(root.descendantsOfType('recurrence').length, 0);
});
