add_subdirectory(brain)
add_subdirectory(input)

target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h
)
