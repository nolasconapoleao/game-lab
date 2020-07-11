target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Caterpillar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/State.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform.h
        ${CMAKE_CURRENT_SOURCE_DIR}/CrabDifficulty.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Substate.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Caterpillar.h
        ${CMAKE_CURRENT_SOURCE_DIR}/KingCrab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Menu.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Transition.h
)
