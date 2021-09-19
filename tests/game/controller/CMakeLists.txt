add_subdirectory(brain)

# unit_GameEngine
set(EXECUTABLE_NAME unit_GameEngine)
add_executable(${EXECUTABLE_NAME} unit_GameEngine.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Game::view
  Game::input
  Datatype::entity
  Game::gamemath
  Random::random
)

# unit_SnapshotUtilities
set(EXECUTABLE_NAME unit_SnapshotUtilities)
add_executable(${EXECUTABLE_NAME} unit_SnapshotUtilities.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Datatype::entity
  Game::gamemath
)

# unit_DecisionChecker
set(EXECUTABLE_NAME unit_DecisionChecker)
add_executable(${EXECUTABLE_NAME} unit_DecisionChecker.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Datatype::entity
  Game::gamemath
)
