target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Building.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Character.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Consumable.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Equippable.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Exterior.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Structure.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Team.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Building.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Character.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Consumable.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Equippable.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Exterior.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Structure.h
         ${CMAKE_CURRENT_SOURCE_DIR}/Team.h
)
