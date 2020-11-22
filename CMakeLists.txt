cmake_minimum_required(VERSION 3.12)
project(Console-Game)

# Compilation flags definition
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")

# Operating system configuration
option(UNIX_COMPILATION "Compile For Unix systems" ON)
if(UNIX_COMPILATION)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/linux)
  set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
else()
  # Set the compile flags to statically link the  libgcc dll files, this makes a standalone exe
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -static-libgcc -static-libstdc++")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/windows)
  set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.exe)
endif()

# Game executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_BINARY_DIR}/extras
          ${CMAKE_SOURCE_DIR}/external
          ${CMAKE_SOURCE_DIR}/extras
          ${CMAKE_SOURCE_DIR}/src/game
          ${CMAKE_SOURCE_DIR}/src/include
)
add_subdirectory(src)
add_subdirectory(extras)
add_subdirectory(tools/cmake)

# Advanced compilation options
option(ENABLE_TESTS "Compile and run unit tests" ON)
option(ENABLE_DOCUMENTATION "Build documentation target" ON)
option(ENABLE_COVERAGE "Build coverage target" ON)

if(ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Unit tests target
# ##################################################################################################
add_custom_target(
  RunUnitTests
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  COMMENT "Run all tests"
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# Documentation target
# ##################################################################################################
set(DOCUMENTATION_TARGET Documentation)
add_custom_target(
  ${DOCUMENTATION_TARGET}
  COMMAND doxygen
  COMMENT "Generate documentation"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
)

# Code coverage target
# ##################################################################################################
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(COVERAGE_TARGET Coverage)
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/src)
add_custom_target(
  ${COVERAGE_TARGET}
  COMMAND mkdir -p coverage
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
add_custom_command(
  TARGET ${COVERAGE_TARGET}
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
  COMMAND genhtml coverage.info -o ../../coverage
  COMMAND echo "-- Coverage report saved to ${CMAKE_BINARY_DIR}/../coverage"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)
add_dependencies(${COVERAGE_TARGET} ${PROJECT_NAME})

# Make sure to clean up the coverage folder
set_property(
  DIRECTORY
  APPEND
  PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage
)

# Target to reset coverage counters
add_custom_target(
  ClearUsages
  COMMAND ${CMAKE_MAKE_PROGRAM} clean
  COMMAND rm -f ${OBJECT_DIR}/*.gcno
  COMMAND rm -f ${OBJECT_DIR}/*.gcda
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
