add_subdirectory(include)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/CharacterFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/LocationFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StructureFactory.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/CharacterFactory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityFactory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemFactory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/LocationFactory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/StructureFactory.h
)
