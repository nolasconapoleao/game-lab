target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Dungeon.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Saloon.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Shop.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/World.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/BaseRoom.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Dungeon.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Saloon.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Shop.h
        ${CMAKE_CURRENT_SOURCE_DIR}/World.h
)
