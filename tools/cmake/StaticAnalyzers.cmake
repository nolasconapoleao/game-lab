# CPP Check
set(CMAKE_CXX_CPPCHECK
  cppcheck
    --suppress=missingInclude
    --enable=all
    --inline-suppr
   --inconclusive
)

# Include what you use
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${INCLUDE_WHAT_YOU_USE})

# Clang tidy
# TODO(nn): Fix clang tidy warnings and investigate checks
set(CMAKE_CXX_CLANG_TIDY clang-tidy)
