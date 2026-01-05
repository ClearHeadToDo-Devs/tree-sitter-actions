(source_file
  (root_action
    state: (state
      open: (state_open)
      value: (state_not_started)
      close: (state_close))
    name: (name
      (name_text_chunk)
      (name_text_chunk))
    metadata: (description
      text: (description_text_chunk)
      text: (description_text_chunk))
    metadata: (priority
      level: (priority_level))
    metadata: (story
      name: (story_name))
    metadata: (context
      tag: (tag)
      tag: (tag))
    metadata: (do_date
      datetime: (datetime)
      duration: (duration
        minutes: (minutes))
      recurrence: (recurrence
        rrule: (rrule_content)))
    metadata: (created_date
      datetime: (datetime))
    metadata: (id
      icon: (id_hash)
      uuid: (uuid_value)))
  (root_action
    state: (state
      open: (state_open)
      value: (state_completed)
      close: (state_close))
    name: (name
      (name_text_chunk)
      (name_text_chunk))
    metadata: (created_date
      datetime: (datetime))
    metadata: (completed_date
      datetime: (datetime))
    metadata: (id
      icon: (id_hash)
      uuid: (uuid_value))
    child: (depth1_action
      marker: (depth1_marker)
      state: (state
        open: (state_open)
        value: (state_completed)
        close: (state_close))
      name: (name
        (name_text_chunk))
      metadata: (created_date
        datetime: (datetime))
      metadata: (completed_date
        datetime: (datetime))
      metadata: (id
        icon: (id_hash)
        uuid: (uuid_value))))
  (root_action
    state: (state
      open: (state_open)
      value: (state_completed)
      close: (state_close))
    name: (name
      (name_text_chunk)
      (name_text_chunk))
    metadata: (description
      text: (description_text_chunk)
      text: (description_text_chunk))
    metadata: (created_date
      datetime: (datetime))
    metadata: (completed_date
      datetime: (datetime))
    metadata: (id
      icon: (id_hash)
      uuid: (uuid_value))
    child: (depth1_action
      marker: (depth1_marker)
      state: (state
        open: (state_open)
        value: (state_not_started)
        close: (state_close))
      name: (name
        (name_text_chunk))
      metadata: (created_date
        datetime: (datetime))
      metadata: (id
        icon: (id_hash)
        uuid: (uuid_value))))
  (root_action
    state: (state
      open: (state_open)
      value: (state_not_started)
      close: (state_close))
    name: (name
      (name_text_chunk)
      (name_text_chunk))
    metadata: (description
      text: (description_text_chunk)
      text: (description_text_chunk))
    metadata: (created_date
      datetime: (datetime))
    metadata: (id
      icon: (id_hash)
      uuid: (uuid_value))
    child: (depth1_action
      marker: (depth1_marker)
      state: (state
        open: (state_open)
        value: (state_completed)
        close: (state_close))
      name: (name
        (name_text_chunk))
      metadata: (created_date
        datetime: (datetime))
      metadata: (completed_date
        datetime: (datetime))
      metadata: (id
        icon: (id_hash)
        uuid: (uuid_value))))
  (root_action
    state: (state
      open: (state_open)
      value: (state_not_started)
      close: (state_close))
    name: (name
      (name_text_chunk)
      (name_text_chunk))
    metadata: (description
      text: (description_text_chunk)
      text: (description_text_chunk))
    metadata: (id
      icon: (id_hash)
      uuid: (uuid_value))))