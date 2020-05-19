target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Goblin.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Shopkeeper.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/BaseCharacter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Goblin.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Player.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Shopkeeper.h
)
