target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/StateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MacroState.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/StateMachine.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MacroState.h
)
