target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/InteractUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Match.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/InteractUtils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Match.h
)
