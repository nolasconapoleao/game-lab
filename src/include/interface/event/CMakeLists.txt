target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/EventManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/EventManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.h
)
