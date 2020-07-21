target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/CharacterFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Factory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StructureFactory.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Factory.h
)
