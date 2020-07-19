set(EXECUTABLE_NAME unit_Example)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_Example.cpp
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/game/view/Printer.cpp
        ${CMAKE_SOURCE_DIR}/src/game/controller/input/Input.cpp
        ${CMAKE_SOURCE_DIR}/src/game/controller/state/Tutorial.cpp
        ${CMAKE_SOURCE_DIR}/src/include/interface/state-machine/MacroState.cpp
        ${CMAKE_SOURCE_DIR}/src/include/interface/graph/DirectedGraph.h
        ${CMAKE_SOURCE_DIR}/src/include/interface/graph/IGraph.h
        ${CMAKE_BINARY_DIR}/src/config/platformconfig.h
)

create_test(${EXECUTABLE_NAME})
