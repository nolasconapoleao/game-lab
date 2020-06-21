target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/HiveMind.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TravelHandler.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityHandler.h
# FIXME: [nn] This is not the best place for HiveMind class
        ${CMAKE_CURRENT_SOURCE_DIR}/HiveMind.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/TravelHandler.h
)
