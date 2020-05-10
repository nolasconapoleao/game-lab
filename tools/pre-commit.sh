#!/bin/bash

format_file() {
  file="${1}"
  if [[ -f $file ]] && [[ "$file" =~ \.(c|cpp|h|cc)$ ]]; then
    clang-format -i ${1}
    git add ${1}
  fi
}

case "${1}" in
  --about )
    echo "Run clang-format on source and header files"
    ;;
  * )
    for file in `git diff-index --cached --name-only HEAD` ; do
      format_file "${file}"
    done
    ;;
esac
