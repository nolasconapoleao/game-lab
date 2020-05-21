target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/InteractUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.h
)
