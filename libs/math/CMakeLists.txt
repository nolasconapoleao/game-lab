# TODO (nn): Create libraries for stateless function bundles
target_sources(
  gamemath
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/gamemath.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gamemath.h
)
