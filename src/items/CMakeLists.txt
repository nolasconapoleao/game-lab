target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Potion.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sword.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/BaseItem.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Potion.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Sword.h
)
