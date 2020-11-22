target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/StreamFormatter.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.h
         ${CMAKE_CURRENT_SOURCE_DIR}/StreamFormatter.h
)
