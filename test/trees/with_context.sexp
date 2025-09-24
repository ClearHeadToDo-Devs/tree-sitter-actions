(action_list
 (root_action
  (core_action
   (state 
    (completed))
   (name)
   (context_list
    (context_icon)
    (context_text)
    (context_separator)
    (context_text)))))

===============
With Id no dash
===============
(x) id test #01951111cfa6718db303d7107f4005b3

---

(action_list
 (root_action
  (core_action
   (state 
    (completed))
   (name)
   (id
    (id_icon)
    (uuid
     (uuid_time_high)
     (uuid_time_mid)
     (uuid_version_random)
     (uuid_variant_random)
     (uuid_random))))))

=================
With Id with dash
=================
(x) id test #01951111-cfa6-718d-b303-d7107f4005b3

---

(action_list
 (root_action
  (core_action
   (state 
    (completed))
   (name)
   (id
    (id_icon)
    (uuid
     (uuid_time_high)
     (uuid_time_mid)
     (uuid_version_random)
     (uuid_variant_random)
     (uuid_random))))))
