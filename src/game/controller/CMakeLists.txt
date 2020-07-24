add_subdirectory(player-brain)
add_subdirectory(comuter-brain)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h
)