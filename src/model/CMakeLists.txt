add_subdirectory(entity)
add_subdirectory(map)
add_subdirectory(quest)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/World.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/World.h
)
