target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Consumable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Equipable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Exterior.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Interior.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Structure.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Character.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Consumable.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Equipable.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Exterior.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Interior.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Structure.h
)
