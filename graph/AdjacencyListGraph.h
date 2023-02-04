#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

typedef std::vector<std::vector<std::pair<int, int>>> AdgacencyListGraph;

class Graph {
public:
    Graph(std::vector<std::vector<int>> &input, int n);

    ~Graph();

    void setNumberOfNodes(int nNodes);

    int getNumberOfNodes();

    AdgacencyListGraph getAdjacents();

    void printGraph();
private:
    AdgacencyListGraph adj;
    int nNodes;
};

#endif
