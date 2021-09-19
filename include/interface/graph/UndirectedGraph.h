//
// Created by nolasco on 04/06/20.
//

#pragma once

#include "IGraph.h"

/// @brief Undirected graph template class.
template <class NodeId, class NodeInfo, class EdgeInfo>
class UndirectedGraph : public IGraph<NodeId, NodeInfo, EdgeInfo> {

public:
  // Auxiliary types definition
  /// @copydoc IGraph::Node
  using Node = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Node;
  /// @copydoc IGraph::EdgeId
  using EdgeId = typename IGraph<NodeId, NodeInfo, EdgeInfo>::EdgeId;
  /// @copydoc IGraph::Edge
  using Edge = typename IGraph<NodeId, NodeInfo, EdgeInfo>::Edge;

  // Edge operations
  /**
   * @brief Add bidirectional edge.
   * @param edgeId identification of origin and destination nodes.
   * @param edgeInfo information for insertion.
   * @return true if insertion is successful, false otherwise.
   */
  bool addEdge(EdgeId edgeId, const EdgeInfo &edgeInfo) override;

  /// @copydoc IGraph::removeEdge()
  void removeEdge(const EdgeId &edgeId) override;

  /// @copydoc IGraph::getEdge()
  EdgeInfo getEdge(const EdgeId &edgeId) override;

  /**
   * @brief Returns list of distinct neighbour node ids that end or start in provided node id.
   * @param nodeId starting node.
   * @return list of neighbour node ids.
   */
  std::unordered_set<NodeId> neighbours(NodeId nodeId) override;

private:
  bool edgeExists(EdgeId edgeId);
};

// Method definition
template <class NodeId, class NodeInfo, class EdgeInfo>
bool UndirectedGraph<NodeId, NodeInfo, EdgeInfo>::addEdge(const EdgeId edgeId, const EdgeInfo &edgeInfo) {

  if (edgeId.first == edgeId.second) {
    std::cerr << "Cannot link node to itself in undirected graph.\n";
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
void UndirectedGraph<NodeId, NodeInfo, EdgeInfo>::removeEdge(const EdgeId &edgeId) {

  const auto findEdge = [edgeId](const auto edge) {
    return (std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second)
           || (std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first);
  };
  this->edges.erase(std::remove_if(this->edges.begin(), this->edges.end(), findEdge), this->edges.end());
}

template <class NodeId, class NodeInfo, class EdgeInfo>
EdgeInfo UndirectedGraph<NodeId, NodeInfo, EdgeInfo>::getEdge(const EdgeId &edgeId) {

  const auto findEdge = [edgeId](const auto edge) {
    return (std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second)
           || (std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first);
  };

  auto edgeFound = std::find_if(this->edges.begin(), this->edges.end(), findEdge);

  if (edgeFound == this->edges.end()) {
    std::cerr << "Invalid graph edge.\n";
    throw std::out_of_range("Invalid edge");
  }

  return std::get<2>(*edgeFound);
}

template <class NodeId, class NodeInfo, class EdgeInfo>
std::unordered_set<NodeId> UndirectedGraph<NodeId, NodeInfo, EdgeInfo>::neighbours(NodeId nodeId) {

  std::unordered_set<NodeId> neighbours;
  for (const auto &edge : this->edges) {
    if (std::get<0>(edge) == nodeId) {
      neighbours.insert(std::get<1>(edge));
    } else if (std::get<1>(edge) == nodeId) {
      neighbours.insert(std::get<0>(edge));
    }
  }

  return neighbours;
}

template <class NodeId, class NodeInfo, class EdgeInfo>
bool UndirectedGraph<NodeId, NodeInfo, EdgeInfo>::edgeExists(const EdgeId edgeId) {

  const auto findEdge = [edgeId](const auto edge) {
    return (std::get<0>(edge) == edgeId.first && std::get<1>(edge) == edgeId.second)
           || (std::get<0>(edge) == edgeId.second && std::get<1>(edge) == edgeId.first);
  };

  auto edge = std::find_if(this->edges.begin(), this->edges.end(), findEdge);
  return edge != this->edges.end();
}
