target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StreamFormatter.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/StreamFormatter.h
)
