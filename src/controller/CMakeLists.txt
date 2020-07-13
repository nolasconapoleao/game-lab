add_subdirectory(input)
add_subdirectory(factory)
add_subdirectory(handler)
add_subdirectory(state)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h
)