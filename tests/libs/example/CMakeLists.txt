set(EXECUTABLE_NAME unit_Example)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_Example.cpp
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ../../../src/game/view/Printer.cpp
        ../../../src/game/controller/input/Input.cpp
        ../../../src/game/controller/state/Tutorial.cpp
        ${PROJECT_SOURCE_DIR}/src/include/state-machine/MacroState.cpp
        ${PROJECT_SOURCE_DIR}/src/include/graph/DirectedGraph.h
        ${PROJECT_SOURCE_DIR}/src/include/graph/IGraph.h
        ${CMAKE_BINARY_DIR}/src/config/platformconfig.h
)

create_test(${EXECUTABLE_NAME})
