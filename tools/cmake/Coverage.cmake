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
        ClearCoverageUsages
        COMMAND ${CMAKE_MAKE_PROGRAM} clean
        COMMAND rm -f ${OBJECT_DIR}/*.gcno
        COMMAND rm -f ${OBJECT_DIR}/*.gcda
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
