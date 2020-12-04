# unit_ComputerBrain
set(EXECUTABLE_NAME unit_ComputerBrain)
add_executable(${EXECUTABLE_NAME} unit_ComputerBrain.cpp)
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

# unit_PlayerBrain
set(EXECUTABLE_NAME unit_PlayerBrain)
add_executable(${EXECUTABLE_NAME} unit_PlayerBrain.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/controller/brain/PlayerBrain.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/MenuHandler.cpp
         ${CMAKE_SOURCE_DIR}/src/game/input/print/InputPrompter.cpp
         ${CMAKE_SOURCE_DIR}/src/game/view/Printer.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/SnapshotUtilities.cpp
         ${CMAKE_SOURCE_DIR}/src/game/view/stream/EntityConverter.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Building.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Consumable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Equippable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Exterior.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Team.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
         ${CMAKE_SOURCE_DIR}/tests/mocks/InputCaptureMock.cpp
)
create_test(${EXECUTABLE_NAME})
