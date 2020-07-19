## macro that handles creation of unit test executable
macro (create_test target)
    ## To allow absolute header paths in includes
    include_directories(
        ${CMAKE_BINARY_DIR}/extras
        ${CMAKE_SOURCE_DIR}/external
        ${CMAKE_SOURCE_DIR}/extras
        ${CMAKE_SOURCE_DIR}/src/game
        ${CMAKE_SOURCE_DIR}/src/include
    )

    ## To create a target that can run via ctest
    add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro (create_test)
