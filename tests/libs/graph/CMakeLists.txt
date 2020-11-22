# unit_Graph
set(EXECUTABLE_NAME unit_Graph)
add_executable(${EXECUTABLE_NAME} unit_Graph.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/include/interface/graph/DirectedGraph.h
          ${CMAKE_SOURCE_DIR}/src/include/interface/graph/UndirectedGraph.h
          ${CMAKE_SOURCE_DIR}/src/include/interface/graph/IGraph.h
)
create_test(${EXECUTABLE_NAME})

# unit_DirectedGraph
set(EXECUTABLE_NAME unit_DirectedGraph)
add_executable(${EXECUTABLE_NAME} unit_DirectedGraph.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/include/interface/graph/DirectedGraph.h
          ${CMAKE_SOURCE_DIR}/src/include/interface/graph/IGraph.h
)
create_test(${EXECUTABLE_NAME})

# unit_UndirectedGraph
set(EXECUTABLE_NAME unit_UndirectedGraph)
add_executable(${EXECUTABLE_NAME} unit_UndirectedGraph.cpp)
target_sources(
  ${EXECUTABLE_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/include/interface/graph/IGraph.h
          ${CMAKE_SOURCE_DIR}/src/include/interface/graph/UndirectedGraph.h
)
create_test(${EXECUTABLE_NAME})
