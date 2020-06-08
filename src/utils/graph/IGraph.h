//
// Created by nolasco on 04/06/20.
//

#pragma once

#include <iostream>
#include <vector>

template <class NodeId, class NodeInfo, class EdgeInfo> class IGraph {

public:
  using Node = std::pair<NodeId, NodeInfo>;
  using EdgeId = std::pair<NodeId, NodeId>;
  using Edge = std::tuple<NodeId, NodeId, EdgeInfo>;

  // Node operations
  [[maybe_unused]] bool addNode(const NodeId nodeId, const NodeInfo &node);
  void removeNode(const NodeId nodeId);
  NodeInfo getNode(const NodeId nodeId);

  // Edge operations
  virtual bool addEdge(const EdgeId edgeId, const EdgeInfo &edgeInfo) = 0;
  virtual void removeEdge(const EdgeId &edgeId) = 0;
  virtual EdgeInfo getEdge(const EdgeId &edgeId) = 0;
  virtual std::vector<NodeId> neighbours(const NodeId nodeId) = 0;

protected:
  bool nodeExists(const NodeId nodeId);
  std::vector<Node> nodes;
  std::vector<Edge> edges;
};

// Method definition
template <class NodeId, class NodeInfo, class EdgeInfo>
bool IGraph<NodeId, NodeInfo, EdgeInfo>::addNode(const NodeId nodeId, const NodeInfo &node) {

  if (nodeExists(nodeId)) {
    std::cerr << "Node id already in used.\n";
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

template <class NodeId, class NodeInfo, class EdgeInfo>
bool IGraph<NodeId, NodeInfo, EdgeInfo>::nodeExists(const NodeId nodeId) {

  const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
  auto nodeSearched = std::find_if(nodes.begin(), nodes.end(), findNode);

  return nodeSearched != nodes.end();
}
