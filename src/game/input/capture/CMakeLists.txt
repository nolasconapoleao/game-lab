target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/InputCapture.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/InputCapture.h ${CMAKE_CURRENT_SOURCE_DIR}/SignalHandler.h
)
