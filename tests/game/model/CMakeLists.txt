# unit_Cleaner
set(EXECUTABLE_NAME unit_Cleaner)
add_executable(${EXECUTABLE_NAME} unit_Cleaner.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::cleaner
  Datatype::entity
  Game::gamemath
  Random::random
)

# unit_Factory
set(EXECUTABLE_NAME unit_Factory)
add_executable(${EXECUTABLE_NAME} unit_Factory.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::factory
  Datatype::entity
  Game::gamemath
  Random::random
)

# unit_Handler
set(EXECUTABLE_NAME unit_Handler)
add_executable(${EXECUTABLE_NAME} unit_Handler.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::handler
  Datatype::entity
  Game::gamemath
  Random::random
)

# unit_Lookup
set(EXECUTABLE_NAME unit_Lookup)
add_executable(${EXECUTABLE_NAME} unit_Lookup.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  Game::lookup
  Datatype::entity
  Game::gamemath
  Random::random
)
