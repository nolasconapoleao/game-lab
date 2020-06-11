set(EXECUTABLE_NAME unit_Example)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_Example.cpp
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/view/Printer.cpp
        ${PROJECT_SOURCE_DIR}/src/controller/Controller.cpp
        ${PROJECT_SOURCE_DIR}/src/model/state/Tutorial.cpp
        ${PROJECT_SOURCE_DIR}/src/utils/state-machine/MacroState.cpp
        ${PROJECT_SOURCE_DIR}/src/utils/graph/DirectedGraph.h
        ${PROJECT_SOURCE_DIR}/src/utils/graph/IGraph.h
        ${CMAKE_BINARY_DIR}/src/config/cmakeconfig.h
)

create_test(${EXECUTABLE_NAME})
