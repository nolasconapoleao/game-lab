# unit_Graph
set(EXECUTABLE_NAME unit_Graph)
add_executable(${EXECUTABLE_NAME} unit_Graph.cpp)
create_test(${EXECUTABLE_NAME})

# unit_DirectedGraph
set(EXECUTABLE_NAME unit_DirectedGraph)
add_executable(${EXECUTABLE_NAME} unit_DirectedGraph.cpp)
create_test(${EXECUTABLE_NAME})

# unit_UndirectedGraph
set(EXECUTABLE_NAME unit_UndirectedGraph)
add_executable(${EXECUTABLE_NAME} unit_UndirectedGraph.cpp)
create_test(${EXECUTABLE_NAME})
