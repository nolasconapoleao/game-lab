target_sources(
  input
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/InputCapture.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/InputCapture.h ${CMAKE_CURRENT_SOURCE_DIR}/SignalHandler.h
)
