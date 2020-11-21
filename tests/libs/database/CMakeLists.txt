set(EXECUTABLE_NAME
    unit_Database
)

add_executable(
    ${EXECUTABLE_NAME}
    unit_Database.cpp
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src/include/interface/database/Database.h
)

create_test(${EXECUTABLE_NAME})
