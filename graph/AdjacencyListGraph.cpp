#include "AdjacencyListGraph.h"

Graph::Graph(std::vector<std::vector<int>> &input, int n) {
    this->setNumberOfNodes(n);
    adj.resize(this->nNodes + 1);
    for (int i = 0; i < input.size(); i++) {
        adj[input[i][0]].push_back({input[i][1], input[i][2]});
    }
}

void Graph::setNumberOfNodes(int nNodes) {
    this->nNodes = nNodes;
}

int Graph::getNumberOfNodes() {
    return this->nNodes;
}

AdgacencyListGraph Graph::getAdjacents() {
    return this->adj;
}

Graph::~Graph() {
    adj.clear();
}

void Graph::printGraph() {
    for (int i=0; i<getNumberOfNodes(); i++) {
        std::cout << "Printing adjagents of node " << i << std::endl;
        for (int j=0; j<adj[i].size(); j++) {
            std::cout << "Vertex: " << adj[i][j].first << " distance " << adj[i][j].second << std::endl;
        }
    }
}
