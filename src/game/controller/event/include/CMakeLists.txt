target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/CrabDifficulty.h
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform.h
)
