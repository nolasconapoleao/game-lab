target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Item.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Weapon.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Item.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Weapon.h
)
