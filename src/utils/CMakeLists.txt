target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/FileUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MathUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PrintUtils.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/FileUtils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MathUtils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/PrintUtils.h
)
