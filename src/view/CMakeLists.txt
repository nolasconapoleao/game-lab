add_subdirectory(stream)

target_sources(
  view
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Printer.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Printer.h
)
