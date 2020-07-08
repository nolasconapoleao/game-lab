add_subdirectory(include)

target_sources(${PROJECT_NAME}
        PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Attack.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Empty.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IdleWorld.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Shutdown.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Start.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UseItem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Walk.cpp
        PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Attack.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Empty.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.h
        ${CMAKE_CURRENT_SOURCE_DIR}/IdleWorld.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Shutdown.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Start.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.h
        ${CMAKE_CURRENT_SOURCE_DIR}/UseItem.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Walk.h
        )
