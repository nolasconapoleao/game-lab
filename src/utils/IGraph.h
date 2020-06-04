//
// Created by nolasco on 04/06/20.
//

#pragma once

#include <vector>

template <class NodeId, class NodeInfo, class EdgeInfo> class IGraph {
  using Node = std::pair<NodeId, NodeInfo>;
  using Edge = std::tuple<NodeId, NodeId, EdgeInfo>;

public:
  void addNode(const NodeId nodeId, const NodeInfo &node) {
    nodes.emplace_back(nodeId, node);
  }

  void removeNode(const NodeId nodeId) {
    const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };
    const auto findEdgeConnectedToNode = [nodeId](const auto edge) { return edge[0] == nodeId && edge[1] == nodeId; };

    edges.erase(std::remove_if(edges.begin(), edges.end(), findEdgeConnectedToNode), edges.end());
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), findNode), nodes.end());
  }

  NodeInfo at(const NodeId nodeId) {
    const auto findNode = [nodeId](const auto node) { return node.first == nodeId; };

    auto node = find_if(nodes.begin(), nodes.end(), findNode);
    return node.second;
  }

  virtual std::vector<NodeId> neighbours(const NodeId nodeId) = 0;

  virtual void addEdge(const Edge &edge) = 0;
  virtual void removeEdge(const Edge &edge) = 0;

private:
  std::vector<Node> nodes;
  std::vector<Edge> edges;
};
