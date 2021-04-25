target_sources(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CharacterFactory.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Factory.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/ItemFactory.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/LocationFactory.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/StructureFactory.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Factory.h
)
