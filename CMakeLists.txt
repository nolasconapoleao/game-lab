cmake_minimum_required(VERSION 3.12)
project(Game_v1)

# Defining compilation flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Defining output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)

set(SOURCES
    main.cpp
    src/game/Game.cpp
)

set(HEADERS
    src/game/Game.h
)

add_executable(
    ${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)
