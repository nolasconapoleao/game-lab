# unit_Test
set(EXECUTABLE_NAME unit_Test)
add_executable(${EXECUTABLE_NAME} unit_Test.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE
  PUBLIC
)
create_test(${EXECUTABLE_NAME})
