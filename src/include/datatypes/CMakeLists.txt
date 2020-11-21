add_subdirectory(controller)
add_subdirectory(entity)
add_subdirectory(entity-aux)
add_subdirectory(event)
add_subdirectory(factory)
add_subdirectory(logger)
add_subdirectory(lookup)

target_sources(
    ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameTypes.h
)
