target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GuessWhat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Example.h
        ${CMAKE_CURRENT_SOURCE_DIR}/GuessWhat.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Tutorial.h
)
