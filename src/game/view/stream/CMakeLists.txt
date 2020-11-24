target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GeneralUtilities.h
         ${CMAKE_CURRENT_SOURCE_DIR}/PrintConstants.h ${CMAKE_CURRENT_SOURCE_DIR}/StreamConverter.h
)
