target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Input-Capture.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Input-Capture.h ${CMAKE_CURRENT_SOURCE_DIR}/Signal_Handler.h
)
