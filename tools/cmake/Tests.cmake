# Macro that handles creation of unit test executable
macro(create_test target)
  # To allow absolute header paths in includes
  include_directories(
    ${CMAKE_BINARY_DIR}/extras
    ${CMAKE_SOURCE_DIR}/external
    ${CMAKE_SOURCE_DIR}/extras
    ${CMAKE_SOURCE_DIR}/src/game
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/tests
  )

  # To create a target that can run via ctest
  add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

# Unit tests target
# ##################################################################################################
add_custom_target(
        RunUnitTests
        # Make test executables and run tests
        COMMAND ${CMAKE_MAKE_PROGRAM} all
        COMMENT "Run all tests"
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
