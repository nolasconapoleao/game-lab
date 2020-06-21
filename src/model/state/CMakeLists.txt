target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Shutdown.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IdleWorld.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StartWorld.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Shutdown.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.h
        ${CMAKE_CURRENT_SOURCE_DIR}/IdleWorld.h
        ${CMAKE_CURRENT_SOURCE_DIR}/StartWorld.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.h
)
