set(EXECUTABLE_NAME unit_Database)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_Database.cpp
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/utils/database/Database.h
)

create_test(${EXECUTABLE_NAME})
