create_lib(constants Game::constants)
create_lib(Datacontroller Datatype::controller)
create_lib(dataentity Datatype::entity)
create_lib(entity-aux Datatype::entity-aux)
create_lib(event Datatype::event)
create_lib(Datafactory Datatype::factory)
create_lib(logger Datatype::logger)
create_lib(Datalookup Datatype::lookup)
create_lib(types Datatype::types)

add_subdirectory(constants)
add_subdirectory(controller)
add_subdirectory(entity)
add_subdirectory(entity-aux)
add_subdirectory(event)
add_subdirectory(factory)
add_subdirectory(logger)
add_subdirectory(lookup)

target_sources(
  types
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GameTypes.h
)
