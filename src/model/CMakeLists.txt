create_lib(cleaner Game::cleaner)
create_lib(factory Game::factory)
create_lib(handler Game::handler)
create_lib(lookup Game::lookup)

add_subdirectory(cleaner)
add_subdirectory(factory)
add_subdirectory(handler)
add_subdirectory(lookup)

target_sources(
  model
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/World.h
)
