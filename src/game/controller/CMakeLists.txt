add_subdirectory(brain)

target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/MenuHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/DecisionChecker.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/SnapshotUtilities.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.h
         ${CMAKE_CURRENT_SOURCE_DIR}/MenuHandler.h
         ${CMAKE_CURRENT_SOURCE_DIR}/DecisionChecker.h
         ${CMAKE_CURRENT_SOURCE_DIR}/SnapshotUtilities.h
)
