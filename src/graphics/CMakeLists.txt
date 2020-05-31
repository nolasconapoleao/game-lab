target_sources(${PROJECT_NAME}
    PRIVATE
        # Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/OptionList.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Renderer.cpp
    PUBLIC
        # Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/OptionList.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Renderer.h
)
