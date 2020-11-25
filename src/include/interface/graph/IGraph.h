//
// Created by nolasco on 04/06/20.
//

#pragma once

#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

/// @brief Graph interface template class.
template <class NodeId, class NodeInfo, class EdgeInfo> class IGraph {

public:
  // Auxiliary types definition
  /// @brief Node action containing id and information.
  using Node = std::pair<NodeId, NodeInfo>;
  /// @brief Identifier for edge, contains origin and destination.
  using EdgeId = std::pair<NodeId, NodeId>;
  /// @brief Edge action contains origin, destination and edge info.
  using Edge = std::tuple<NodeId, NodeId, EdgeInfo>;

  // Node operations
  /**
   * @brief Add node to graph.
   * @param nodeId id for insertion of node.
   * @param node information for insertion.
   * @return true if successful insertion, false otherwise.
   */
  [[maybe_unused]] bool addNode(NodeId nodeId, const NodeInfo &node);

  /**
   * @brief Remove node from graph.
   * @param nodeId for deletion.
   */
  void removeNode(NodeId nodeId);

  /**
   * @brief Retrieve read-only node entry, throws exception if id is non existing.
   * @param nodeId for reading.
   * @return node information.
   */
  NodeInfo getNode(NodeId nodeId);

  /**
   * @brief Number of nodes in graph.
   * @return number of nodes in graph.
   */
  size_t numberOfNodes();

  // Edge operations
  /**
   * @brief Add edge.
   * @param edgeId identification of origin and destination nodes.
   * @param edgeInfo information for insertion.
   * @return true if insertion is successful, false otherwise.
   */
  virtual bool addEdge(EdgeId edgeId, const EdgeInfo &edgeInfo) = 0;

  /**
   * Remove edge connection.
   * @param edgeId identification of origin and destination nodes.
   */
  virtual void removeEdge(const EdgeId &edgeId) = 0;

  /**
   * @brief Retrieve read-only edge information.
   * @param edgeId identification of origin and destination nodes.
   * @return edge information for the provided edgeId.
   */
  virtual EdgeInfo getEdge(const EdgeId &edgeId) = 0;

  /**
   * @brief Returns list of distinct neighbour node ids for provided node id.
   * @param nodeId starting node.
   * @return list of neighbour node ids.
   */
  virtual std::unordered_set<NodeId> neighbours(NodeId nodeId) = 0;

protected:
  /**
   * @brief Checks if node exists.
   * @param nodeId to check.
   * @return true if node exists.
   */
  bool nodeExists(NodeId nodeId);

  /// @brief node information for graph.
  std::vector<Node> nodes;
  /// @brief edge information for graph.
  std::vector<Edge> edges;
};

// Method definition
template <class NodeId, class NodeInfo, class EdgeInfo>
bool IGraph<NodeId, NodeInfo, EdgeInfo>::addNode(const NodeId nodeId, const NodeInfo &node) {

  if (nodeExists(nodeId)) {
    std::cerr << "Node id already in use.\n";
    return false;
  }

  nodes.emplace_back(nodeId, node);
  return true;
}

template <class NodeId, class NodeInfo, class EdgeInfo>
void IGraph<NodeId, NodeInfo, EdgeInfo>::removeNode(const NodeId nodeId) {

  const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
  const auto findEdgeConnectedToNode
      = [nodeId](const auto edge) { return std::get<0>(edge) == nodeId || std::get<1>(edge) == nodeId; };

  edges.erase(std::remove_if(edges.begin(), edges.end(), findEdgeConnectedToNode), edges.end());
  nodes.erase(std::remove_if(nodes.begin(), nodes.end(), findNode), nodes.end());
}

template <class NodeId, class NodeInfo, class EdgeInfo>
NodeInfo IGraph<NodeId, NodeInfo, EdgeInfo>::getNode(const NodeId nodeId) {

  const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };

  auto node = std::find_if(nodes.begin(), nodes.end(), findNode);

  if (node == nodes.end()) {
    std::cerr << "Invalid graph node.\n";
    throw std::out_of_range("Invalid node");
  }
  return node->second;
}

template <class NodeId, class NodeInfo, class EdgeInfo> size_t IGraph<NodeId, NodeInfo, EdgeInfo>::numberOfNodes() {
  return nodes.size();
}

template <class NodeId, class NodeInfo, class EdgeInfo>
bool IGraph<NodeId, NodeInfo, EdgeInfo>::nodeExists(const NodeId nodeId) {

  const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
  auto nodeSearched = std::find_if(nodes.begin(), nodes.end(), findNode);

  return nodeSearched != nodes.end();
}
