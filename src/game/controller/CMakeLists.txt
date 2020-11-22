add_subdirectory(brain-player)
add_subdirectory(brain-computer)

target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h
)
