# unit_Test
set(EXECUTABLE_NAME unit_Test)
add_executable(${EXECUTABLE_NAME} unit_Test.cpp)
create_test(${EXECUTABLE_NAME})

# unit_Namespace
set(EXECUTABLE_NAME unit_Namespace)
add_executable(${EXECUTABLE_NAME} unit_Namespace.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/controller/brain/ComputerBrain.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Building.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Consumable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Equippable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Exterior.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Team.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
         ${CMAKE_SOURCE_DIR}/tests/mocks/RandomMock.cpp
)
create_test(${EXECUTABLE_NAME})
