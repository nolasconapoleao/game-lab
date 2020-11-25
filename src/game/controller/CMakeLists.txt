add_subdirectory(brain)
add_subdirectory(input)

target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp ${CMAKE_CURRENT_SOURCE_DIR}/MenuHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/DecisionChecker.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h ${CMAKE_CURRENT_SOURCE_DIR}/MenuHandler.h
         ${CMAKE_CURRENT_SOURCE_DIR}/DecisionChecker.h
)
