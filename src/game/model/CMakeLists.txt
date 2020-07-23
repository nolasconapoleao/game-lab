add_subdirectory(cleaner)
add_subdirectory(factory)
add_subdirectory(giga-brain)
add_subdirectory(handler)
add_subdirectory(lookup)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/World.h
)
