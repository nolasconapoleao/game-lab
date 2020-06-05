//
// Created by nolasco on 04/06/20.
//

#pragma once

#include "IGraph.h"

template <class NodeId, class NodeInfo, class EdgeInfo>
class UndirectedGraph : public IGraph<NodeId, NodeInfo, EdgeInfo> {
  using Node = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Node;
  using EdgeId = typename IGraph<NodeId, NodeInfo, EdgeInfo>::EdgeId;
  using Edge = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Edge;

public:
  EdgeInfo getEdge(const EdgeId &edgeId) {
    const auto findEdge = [edgeId](const auto edge) {
      return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second
             || std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first;
    };

    auto edgeFound = std::find_if(this->edges.begin(), this->edges.end(), findEdge);

    if (edgeFound == this->edges.end()) {
      std::cerr << "Invalid graph edge.\n";
      throw std::out_of_range("Invalid edge");
    }

    return std::get<2>(*edgeFound);
  }

  std::vector<NodeId> neighbours(NodeId nodeId) override {

    std::vector<NodeId> neighbours;
    for (const auto &edge : this->edges) {
      if (std::get<0>(edge) == nodeId) {
        neighbours.emplace_back(std::get<1>(edge));
      } else if (std::get<1>(edge) == nodeId) {
        neighbours.emplace_back(std::get<0>(edge));
      }
    }

    return neighbours;
  }

  bool addEdge(const EdgeId edgeId, const EdgeInfo &edgeInfo) override {

    if (edgeId.first == edgeId.second) {
      std::cerr << "Cannot link node to itself in undirected graph.\n";
      return false;
    }

    if (edgeExists(edgeId)) {
      std::cerr << "Graph already has this connection.\n";
      return false;
    }

    this->edges.emplace_back(edgeId.first, edgeId.second, edgeInfo);
    return true;
  }

  void removeEdge(const EdgeId &edgeId) override {

    const auto findEdge = [edgeId](const auto edge) {
      return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second
             || std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first;
    };
    this->edges.erase(std::remove_if(this->edges.begin(), this->edges.end(), findEdge), this->edges.end());
  }

private:
  bool edgeExists(const EdgeId edgeId) {
    const auto findEdge = [edgeId](const auto edge) {
      return std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second
             || std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first;
    };

    auto edge = std::find_if(this->edges.begin(), this->edges.end(), findEdge);
    return edge != this->edges.end();
  }
};
