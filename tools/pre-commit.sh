#!/bin/bash

function append_eof_newline_if_needed() {
  file="${1}"
  if [[ $(tail -c1 "$file" | wc -l) -eq 0 ]]; then
    echo "" >> "$file"
  fi
}

function format_file() {
  file="${1}"
  if [[ -f $file ]] && [[ $file =~ \.(c|cpp|h|cc)$ ]]; then
    clang-format -i "$file"
    git add "$file"
  elif [[ -f $file ]] && [[ $file =~ \CMakeLists.(txt)$ ]]; then
    cmake-format -i "$file"
    git add "$file"
  fi
}

case $file in
  --about )
    echo "Run clang-format on source and header files"
    ;;
  * )
    for file in $( exec git diff-index --cached --name-only HEAD ); do
      format_file "$file"
      append_eof_newline_if_needed "$file"
    done
    ;;
esac
