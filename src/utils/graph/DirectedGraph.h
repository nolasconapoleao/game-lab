//
// Created by nolasco on 04/06/20.
//

#pragma once

#include "IGraph.h"

template <class NodeId, class NodeInfo, class EdgeInfo>
class DirectedGraph : public IGraph<NodeId, NodeInfo, EdgeInfo> {

public:
  // Auxiliary types definition
  using Node = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Node;
  using EdgeId = typename IGraph<NodeId, NodeInfo, EdgeInfo>::EdgeId;
  using Edge = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Edge;

  // Edge operations
  bool addEdge(const EdgeId edgeId, const EdgeInfo &edgeInfo) override;
  void removeEdge(const EdgeId &edgeId) override;
  EdgeInfo getEdge(const EdgeId &edgeId) override;
  std::unordered_set<NodeId> neighbours(NodeId nodeId) override;

private:
  bool edgeExists(const EdgeId edgeId);
};

// Method definition
template <class NodeId, class NodeInfo, class EdgeInfo>
bool DirectedGraph<NodeId, NodeInfo, EdgeInfo>::addEdge(const DirectedGraph::EdgeId edgeId, const EdgeInfo &edgeInfo) {

  if (edgeId.first == edgeId.second) {
    std::cerr << "Cannot link node to itself in directed graph.\n";
    return false;
  }

  if (edgeExists(edgeId)) {
    std::cerr << "Graph already has this connection.\n";
    return false;
  }

  if (!this->nodeExists(edgeId.first) || !this->nodeExists(edgeId.second)) {
    std::cerr << "Graph cannot connect non existing node.\n";
    return false;
  }

  this->edges.emplace_back(edgeId.first, edgeId.second, edgeInfo);
  return true;
}

template <class NodeId, class NodeInfo, class EdgeInfo>
void DirectedGraph<NodeId, NodeInfo, EdgeInfo>::removeEdge(const DirectedGraph::EdgeId &edgeId) {

  const auto findEdge
      = [edgeId](const auto edge) { return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second; };
  this->edges.erase(std::remove_if(this->edges.begin(), this->edges.end(), findEdge), this->edges.end());
}

template <class NodeId, class NodeInfo, class EdgeInfo>
EdgeInfo DirectedGraph<NodeId, NodeInfo, EdgeInfo>::getEdge(const DirectedGraph::EdgeId &edgeId) {

  const auto findEdge
      = [edgeId](const auto edge) { return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second; };

  auto edgeFound = std::find_if(this->edges.begin(), this->edges.end(), findEdge);

  if (edgeFound == this->edges.end()) {
    std::cerr << "Invalid graph edge.\n";
    throw std::out_of_range("Invalid edge");
  }

  return std::get<2>(*edgeFound);
}

template <class NodeId, class NodeInfo, class EdgeInfo>
std::unordered_set<NodeId> DirectedGraph<NodeId, NodeInfo, EdgeInfo>::neighbours(NodeId nodeId) {

  std::unordered_set<NodeId> neighbours;
  for (const auto &edge : this->edges) {
    if (std::get<0>(edge) == nodeId) {
      neighbours.insert(std::get<1>(edge));
    }
  }

  return neighbours;
}

template <class NodeId, class NodeInfo, class EdgeInfo>
bool DirectedGraph<NodeId, NodeInfo, EdgeInfo>::edgeExists(const DirectedGraph::EdgeId edgeId) {

  const auto findEdge
      = [edgeId](const auto edge) { return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second; };

  auto edge = std::find_if(this->edges.begin(), this->edges.end(), findEdge);
  return edge != this->edges.end();
}
