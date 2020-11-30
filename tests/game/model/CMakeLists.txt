# unit_Lookup
set(EXECUTABLE_NAME unit_Lookup)
add_executable(${EXECUTABLE_NAME} unit_Lookup.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/game/model/lookup/Lookup.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Building.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Character.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Consumable.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Equippable.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Exterior.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Structure.cpp
          ${CMAKE_SOURCE_DIR}/src/include/datatypes/entity/Team.cpp
          ${CMAKE_SOURCE_DIR}/src/include/libs/random/Random.cpp
          ${CMAKE_SOURCE_DIR}/src/include/libs/math/gamemath.cpp
  PUBLIC ${CMAKE_SOURCE_DIR}/src/game/model/World.h
)
create_test(${EXECUTABLE_NAME})
