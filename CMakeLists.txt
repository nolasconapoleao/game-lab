cmake_minimum_required(VERSION 3.12)
project(Game_v1)

# Defining compilation flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Defining output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)

# Add cmake scripts
include(cmake/utils.cmake)

add_subdirectory(src)
# To disable tests, comment these two lines
enable_testing()
add_subdirectory(tests)

#file(
#    GLOB_RECURSE
#    source_files
#        main.cpp
#        src/utils/*
#        src/characters/*
#        src/common/*
#        src/game/*
#        src/items/*
#        src/rooms/*
#        src/utils/*
#)
#list(REMOVE_ITEM source_files ./build/* )
#list(APPEND source_files ./src/game/* )

set(SOURCES
    main.cpp

    src/game/Game.cpp

    src/characters/Player.cpp
    src/characters/Enemy.cpp
    src/characters/Goblin.cpp

    src/common/InteractUtil.cpp

    src/items/BaseItem.cpp
    src/items/Potion.cpp

    src/rooms/Saloon.cpp
    src/rooms/Dungeon.cpp
    src/rooms/World.cpp

    src/utils/MathUtils.cpp
)

set(HEADERS
    src/game/Game.h

    src/characters/Player.h
    src/characters/Enemy.h
    src/characters/Goblin.h

    src/common/InteractUtil.h

    src/items/BaseItem.h
    src/items/Potion.h

    src/rooms/Saloon.h
    src/rooms/Dungeon.h
    src/rooms/World.h

    src/utils/MathUtils.h
)

## Game executable
add_executable(
    ${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)

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