set(EXECUTABLE_NAME unit_Lookup)
add_executable(${EXECUTABLE_NAME} unit_Lookup.cpp)
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
          ${CMAKE_SOURCE_DIR}/src/game/model/factory/CharacterFactory.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/factory/Factory.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/factory/ItemFactory.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/factory/LocationFactory.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/factory/StructureFactory.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/AestheticHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/AttackHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/CreationHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/DestructionHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/Handler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/InventoryHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/ShopHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/handler/TransferenceHandler.cpp
          ${CMAKE_SOURCE_DIR}/src/game/model/lookup/Lookup.cpp
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
