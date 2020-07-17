# unit_Graph
############
set(EXECUTABLE_NAME unit_Graph)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_Graph.cpp

        # Headers
        constants.h
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/include/graph/DirectedGraph.h
        ${PROJECT_SOURCE_DIR}/src/include/graph/IGraph.h
        ${PROJECT_SOURCE_DIR}/src/include/graph/UndirectedGraph.h
)

create_test(${EXECUTABLE_NAME})

# unit_DirectedGraph
############
set(EXECUTABLE_NAME unit_DirectedGraph)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_DirectedGraph.cpp

        # Headers
        constants.h
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/include/graph/DirectedGraph.h
        ${PROJECT_SOURCE_DIR}/src/include/graph/IGraph.h
)

create_test(${EXECUTABLE_NAME})

# unit_UndirectedGraph
############
set(EXECUTABLE_NAME unit_UndirectedGraph)

add_executable(
    ${EXECUTABLE_NAME}
        # Sources
        unit_UndirectedGraph.cpp

        # Headers
        constants.h
)

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/include/graph/IGraph.h
        ${PROJECT_SOURCE_DIR}/src/include/graph/UndirectedGraph.h
)

create_test(${EXECUTABLE_NAME})
