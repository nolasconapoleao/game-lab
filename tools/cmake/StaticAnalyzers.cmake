# CPP Check
set(CMAKE_CXX_CPPCHECK 
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/tests"
        "-i/${CMAKE_SOURCE_DIR}/external"
        "--enable=warning"
        "--inconclusive"
        "--force" 
        "--inline-suppr"
)

# Include what you use
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${INCLUDE_WHAT_YOU_USE})

# Clang tidy
# TODO(nn): Fix clang tidy warnings and investigate checks
set(CMAKE_CXX_CLANG_TIDY clang-tidy)
