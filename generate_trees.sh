#!/bin/bash

for file in examples/*.actions; do
  basename=$(basename "$file")
  name="${basename%.actions}"
  tree-sitter parse "$file" 2>&1 | tail -n +6 > "test/trees/${name}.sexp"
  echo "Generated test/trees/${name}.sexp"
done
