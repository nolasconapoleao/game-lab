target_sources(
  controller
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ComputerBrain.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBrain.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ComputerBrain.h ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBrain.h
)
