cmake_minimum_required(VERSION 3.12)
project(Console-Game)

# Compilation flags definition
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")

# Operating system configuration
option(UNIX_COMPILATION "Compile For Unix systems" ON)
if(UNIX_COMPILATION)
  message("## Compile for unix operating system")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/linux)
  set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
else()
  # Set the compile flags to statically link the  libgcc dll files, this makes a standalone exe
  message("## Compile for non unix operating system")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -static-libgcc -static-libstdc++")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/windows)
  set(BINARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.exe)
endif()

# Diagnostic tools
option(ENABLE_DIAGNOSTIC_TOOLS "Build with diagnostic tools" OFF)
if(ENABLE_DIAGNOSTIC_TOOLS)
  message("## Enable diagnostic tools in compilation")
  set(CMAKE_CXX_CLANG_TIDY clang-tidy)
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

# Advanced compilation options
option(ENABLE_TESTS "Compile and run unit tests" ON)
option(ENABLE_DOCUMENTATION "Build documentation target" ON)
option(ENABLE_COVERAGE "Build coverage target" ON)

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
