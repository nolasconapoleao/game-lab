add_subdirectory(include)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Item.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Location.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Structure.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Item.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Location.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Structure.h
)
