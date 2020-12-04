add_subdirectory(brain)

# unit_GameEngine
set(EXECUTABLE_NAME unit_GameEngine)
add_executable(${EXECUTABLE_NAME} unit_GameEngine.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/controller/DecisionChecker.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/GameEngine.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/MenuHandler.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/SnapshotUtilities.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/brain/ComputerBrain.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/brain/PlayerBrain.cpp
         ${CMAKE_SOURCE_DIR}/src/game/input/capture/InputCapture.cpp
         ${CMAKE_SOURCE_DIR}/src/game/input/print/InputPrompter.cpp
         ${CMAKE_SOURCE_DIR}/src/game/view/Printer.cpp
         ${CMAKE_SOURCE_DIR}/src/game/view/stream/EntityConverter.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Building.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Consumable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Equippable.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Exterior.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Team.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/random/Random.cpp
)
create_test(${EXECUTABLE_NAME})

# unit_SnapshotUtilities
set(EXECUTABLE_NAME unit_SnapshotUtilities)
add_executable(${EXECUTABLE_NAME} unit_SnapshotUtilities.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/controller/SnapshotUtilities.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
)
create_test(${EXECUTABLE_NAME})

# unit_DecisionChecker
set(EXECUTABLE_NAME unit_DecisionChecker)
add_executable(${EXECUTABLE_NAME} unit_DecisionChecker.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/controller/DecisionChecker.cpp
         ${CMAKE_SOURCE_DIR}/src/game/controller/SnapshotUtilities.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
         ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
         ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
)
create_test(${EXECUTABLE_NAME})
