add_subdirectory(input-prompt)
add_subdirectory(stream)

target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Printer.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Printer.h
)
