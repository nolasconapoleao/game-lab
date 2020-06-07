add_subdirectory(entity)
add_subdirectory(event)
add_subdirectory(map)
add_subdirectory(quest)
add_subdirectory(strategy)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Game.h
)
