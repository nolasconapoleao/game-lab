# unit_Test
set(EXECUTABLE_NAME unit_Test)
add_executable(${EXECUTABLE_NAME} unit_Test.cpp)
create_test(${EXECUTABLE_NAME})

# unit_Namespace
set(EXECUTABLE_NAME unit_Namespace)
add_executable(${EXECUTABLE_NAME} unit_Namespace.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/tests/mocks/RandomMock.cpp
)
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::controller
  Datatype::entity
  Game::gamemath
)
create_test(${EXECUTABLE_NAME})
target_link_libraries(${EXECUTABLE_NAME} Game::gamemath Datatype::entity)
