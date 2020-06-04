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

  [[maybe_unused]] bool addNode(const NodeId nodeId, const NodeInfo &node) {

    const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
    auto nodeSearched = std::find_if(nodes.begin(), nodes.end(), findNode);

    if (nodeSearched != nodes.end()) {
      std::cerr << "Node id already in used.";
      return false;
    }

    nodes.emplace_back(nodeId, node);
    return true;
  }

  void removeNode(const NodeId nodeId) {
    const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
    const auto findEdgeConnectedToNode
        = [nodeId](const auto edge) { return std::get<0>(edge) == nodeId && std::get<1>(edge) == nodeId; };

    edges.erase(std::remove_if(edges.begin(), edges.end(), findEdgeConnectedToNode), edges.end());
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), findNode), nodes.end());
  }

  NodeInfo getNode(const NodeId nodeId) {
    const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };

    auto node = std::find_if(nodes.begin(), nodes.end(), findNode);

    if (node == nodes.end()) {
      std::cerr << "Invalid graph node.";
      throw std::out_of_range("Invalid node");
    }
    return node->second;
  }

  virtual EdgeInfo getEdge(const EdgeId &edgeId) = 0;
  virtual std::vector<NodeId> neighbours(const NodeId nodeId) = 0;

  virtual void addEdge(const EdgeId edgeId, const EdgeInfo &edgeInfo) = 0;
  virtual void removeEdge(const EdgeId &edgeId) = 0;

protected:
  std::vector<Node> nodes;
  std::vector<Edge> edges;
};
