target_sources(
  handler
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/AestheticHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/AttackHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/CreationHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/DestructionHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Handler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/InventoryHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/ShopHandler.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/TransferenceHandler.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Handler.h
)
