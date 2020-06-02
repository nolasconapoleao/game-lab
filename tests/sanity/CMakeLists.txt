set(EXECUTABLE_NAME unit_SanityChecks)

set(UT_SOURCES
    unit_SanityChecks.cpp
)

add_executable(
    ${EXECUTABLE_NAME}
        ${UT_SOURCES}
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
)

create_test(${EXECUTABLE_NAME})
