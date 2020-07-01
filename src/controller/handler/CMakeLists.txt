add_subdirectory(include)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TravelHandler.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller.h
)
