set(EXECUTABLE_NAME unit_Character)

set(UT_SOURCES
    unit_Character.cpp
)

add_executable(
    ${EXECUTABLE_NAME}
        ${UT_SOURCES}
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/characters/Character.cpp
        ${PROJECT_SOURCE_DIR}/src/utils/MathUtils.cpp
        ${PROJECT_SOURCE_DIR}/src/common/Inventory.cpp
)

create_test(${EXECUTABLE_NAME})
