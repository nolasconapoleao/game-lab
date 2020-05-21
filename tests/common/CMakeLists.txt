set(EXECUTABLE_NAME unit_Inventory)

set(UT_SOURCES
    unit_Inventory.cpp
)

add_executable(
    ${EXECUTABLE_NAME}
        ${UT_SOURCES}
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common/Inventory.cpp
        ${PROJECT_SOURCE_DIR}/src/items/BaseItem.h
)

create_test(${EXECUTABLE_NAME})
