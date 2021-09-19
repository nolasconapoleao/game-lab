# unit_ComputerBrain
set(EXECUTABLE_NAME unit_ComputerBrain)
add_executable(${EXECUTABLE_NAME} unit_ComputerBrain.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/tests/mocks/RandomMock.cpp
)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Datatype::entity
  Game::gamemath
)

# unit_PlayerBrain
set(EXECUTABLE_NAME unit_PlayerBrain)
add_executable(${EXECUTABLE_NAME} unit_PlayerBrain.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/tests/mocks/InputCaptureMock.cpp
)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Game::input
  Game::view
  Datatype::entity
  Game::gamemath
)
