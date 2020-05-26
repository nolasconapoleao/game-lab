cmake_minimum_required(VERSION 3.12)
project(Game_v1)

# Defining compilation flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

option(COMPILE_FOR_NON_UNIX "Compile For Non Unix" OFF)
if(COMPILE_FOR_NON_UNIX)
    # Set the compile flags to statically link the  libgcc dll files, this make a standalone exe
    set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_DEBUG} -static-libgcc -static-libstdc++")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/windows)
    set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.exe)
else ()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/linux)
    set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
endif()

## Compile flags for coverage target
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

# Add cmake scripts
include(cmake/utils.cmake)

## Renderer executable
add_executable(
    ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## Copy resources databases to binary folder
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/databases
    ${CMAKE_CURRENT_BINARY_DIR}/res
)

# Create zip as a standalone
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E tar "cf" "game.zip" --format=zip
    "${BINARY_PATH}"
    "${CMAKE_CURRENT_BINARY_DIR}/res"
    COMMAND echo Game standalone in ${CMAKE_CURRENT_BINARY_DIR}/game.zip
)

add_subdirectory(3rdparty)
add_subdirectory(src)
# To disable tests, comment these two lines
enable_testing()
add_subdirectory(tests)

## To allow absolute header paths in includes
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}/src
)

## Unit tests target
add_custom_target(RunAllTests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMENT "Run all tests"
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

## Documentation target
ADD_CUSTOM_TARGET(Doxygen
    COMMAND doxygen
    COMMENT "Generate documentation"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
)

## Code coverage
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/Game_v1.dir/src)
add_custom_target(CodeCoverage
    COMMAND mkdir -p coverage
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
add_custom_command(TARGET CodeCoverage
    # Generate gcov report
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}

    # create baseline coverage data file
    COMMAND lcov -c -i -q -d ../.. -o base_coverage.info

    # Make test executables and run tests
    COMMAND ${CMAKE_MAKE_PROGRAM} -C .. all
    COMMAND ${CMAKE_MAKE_PROGRAM} -C .. test

    # create test coverage data file
    COMMAND lcov -c -q -d ../.. -o coverage.info

    # Combine baseline and test coverage data
    COMMAND lcov -a base_coverage.info -a coverage.info -o coverage.info

    # Remove external libraries, main.cpp and test folder
    COMMAND lcov -r coverage.info '/usr/*' '9*' '*tests*' '*main.cpp' -o coverage.info
    COMMAND genhtml coverage.info -o out
    COMMAND echo "-- Coverage report files have been output to ${CMAKE_BINARY_DIR}/coverage/out"

    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)
add_dependencies(CodeCoverage ${PROJECT_NAME})

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Resets counters for porject object
add_custom_target(ClearUsages
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
