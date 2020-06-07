target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Location.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/World.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Location.h
        ${CMAKE_CURRENT_SOURCE_DIR}/World.h
)
