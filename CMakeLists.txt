cmake_minimum_required(VERSION 3.12)
project(Game_v1)

# Defining compilation flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Defining output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)

# Add cmake scripts
include(cmake/utils.cmake)

## Game executable
add_executable(
    ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_subdirectory(src)
# To disable tests, comment these two lines
enable_testing()
add_subdirectory(tests)

## Unit tests target
add_custom_target(RunAllTests
    COMMAND ctest --output-on-failure
    COMMENT "Run all tests"
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

## To allow absolute header paths in includes
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)
