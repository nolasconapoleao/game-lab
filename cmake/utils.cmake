## macro that handles creation of unit test executable
macro (create_test target)
    ## To allow absolute header paths in includes
    include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${CMAKE_BINARY_DIR}/src
    )

    ## To create a target that can run via ctest
    add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro (create_test)
