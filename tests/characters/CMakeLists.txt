set(EXECUTABLE_NAME unit_Player)

set(UT_SOURCES
    unit_Player.cpp
)

add_executable(
    ${EXECUTABLE_NAME}
        ${UT_SOURCES}
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/characters/Player.cpp
        ${PROJECT_SOURCE_DIR}/src/utils/MathUtils.cpp
)

create_test(${EXECUTABLE_NAME})
