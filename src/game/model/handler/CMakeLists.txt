add_subdirectory(include)

target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Aesthetic.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Handler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ItemHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TravelHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ShopHandler.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Handler.h
)
