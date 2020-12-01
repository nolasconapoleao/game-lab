# TODO (nn): Create libraries for stateless function bundles
target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/gamemath.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gamemath.h
)
