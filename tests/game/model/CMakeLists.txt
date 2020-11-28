# unit_Main
set(EXECUTABLE_NAME unit_Main)
add_executable(${EXECUTABLE_NAME} unit_Main.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/game/controller/DecisionChecker.cpp
          ${CMAKE_SOURCE_DIR}/src/game/controller/GameEngine.cpp
          ${CMAKE_SOURCE_DIR}/src/game/controller/MenuHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/controller/SnapshotUtilities.cpp
          ${CMAKE_SOURCE_DIR}/src/game/controller/brain/ComputerBrain.cpp
          ${CMAKE_SOURCE_DIR}/src/game/controller/brain/PlayerBrain.cpp
          ${CMAKE_SOURCE_DIR}/src/game/input/capture/Input-Capture.cpp
          ${CMAKE_SOURCE_DIR}/src/game/input/print/Input-Prompter.cpp
          ${CMAKE_SOURCE_DIR}/src/game/view/Printer.cpp
          ${CMAKE_SOURCE_DIR}/src/game/view/stream/StreamConverter.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Building.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Consumable.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Equippable.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Exterior.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Team.cpp
          ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
          ${CMAKE_SOURCE_DIR}/src/include/libs/random/Random.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/cleaner/Cleaner.cpp
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/model/World.h
)
create_test(${EXECUTABLE_NAME})

# unit_Test
set(EXECUTABLE_NAME unit_Test)
add_executable(${EXECUTABLE_NAME} unit_Test.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE
  PUBLIC
)
create_test(${EXECUTABLE_NAME})
