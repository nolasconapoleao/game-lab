add_subdirectory(input)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBrain.cpp
    PUBLIC
           ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBrain.h
)
