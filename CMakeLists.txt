cmake_minimum_required(VERSION 3.12)
project(Console-Game)

# Compilation flags definition
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message("## Compile with ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

# Operating system configuration
if(UNIX)
  message("## Compile for unix operating system")
  set(CMAKE_BINARY_DIR ${CMAKE_HOME_DIRECTORY}/build/bin)
elseif(
  WIN32
  OR MINGW
  OR MSYS
  OR CYGWIN
)
  # Set the compile flags to statically link the  libgcc dll files, this makes a standalone exe
  message("## Compile for non unix operating system")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -static-libgcc -static-libstdc++")
  set(CMAKE_BINARY_DIR ${CMAKE_HOME_DIRECTORY}/build/bin)
endif()

# Advanced compilation options
option(ENABLE_TESTS "Compile and run unit tests" ON)
option(ENABLE_DOCUMENTATION "Build documentation target" ON)
option(ENABLE_COVERAGE "Build coverage target" ON)
option(ENABLE_DIAGNOSTIC_TOOLS "Build with diagnostic tools" OFF)

if(ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif()

include(tools/cmake/Libs.cmake)

add_subdirectory(libs)
add_subdirectory(include)

# Game executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_BINARY_DIR}/extras
          ${CMAKE_SOURCE_DIR}/external
          ${CMAKE_SOURCE_DIR}/extras
          ${CMAKE_SOURCE_DIR}/libs
          ${CMAKE_SOURCE_DIR}/include
          ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC Game::controller
         Game::input
         Game::model
         Game::cleaner
         Game::factory
         Game::handler
         Game::lookup
         Game::utils
         Game::view
         Datatype::types
         Datatype::controller
         Datatype::entity
         Datatype::entity-aux
         Datatype::event
         Datatype::factory
         Datatype::logger
         Datatype::lookup
         Game::constants
         Interface::controller
         Interface::database
         Interface::entity
         Interface::graph
         Interface::model
         Game::gamemath
         Random::random
)
add_subdirectory(src)

if(ENABLE_DIAGNOSTIC_TOOLS)
  message("## Enable diagnostic tools in compilation")
  include(tools/cmake/Sanitizers.cmake)
  include(tools/cmake/StaticAnalyzers.cmake)
endif()

if(ENABLE_COVERAGE)
  message("## Enable code coverage target")
  include(tools/cmake/Coverage.cmake)
endif()

if(ENABLE_TESTS)
  message("## Enable unit tests target")
  include(tools/cmake/Tests.cmake)
  enable_testing()
  add_subdirectory(tests)
endif()

if(ENABLE_DOCUMENTATION)
  message("## Enable documentation target")
  include(tools/cmake/Documentation.cmake)
endif()
