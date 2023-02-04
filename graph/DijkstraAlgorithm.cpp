#include "AdjacencyListGraph.h"
#include <vector>
#include <queue>
#include <climits>

typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> VertexDistPriorityQueue;

std::pair<std::vector<int>, std::vector<int>> shortestPathWitDijkstra(Graph g, int source) {
    std::vector<int> distanceVector(g.getNumberOfNodes() + 1, INT_MAX);
    std::vector<int> previousVector(g.getNumberOfNodes() + 1, -1);
    std::vector<bool> visited(g.getNumberOfNodes() + 1, false);
    VertexDistPriorityQueue minHeap;
    int nextDist = 0;
    int nextVertex = -1;
    int curDist = 0;
    int curVertex = -1;
    
    distanceVector[source] = 0;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        std::pair<int, int> cur = minHeap.top();
        minHeap.pop();
        curDist = cur.first;
        curVertex = cur.second;

        if (visited[curVertex])
            continue;
        visited[curVertex] = true;

        for (int i=0; i<g.getAdjacents()[curVertex].size(); i++) {
            nextDist = curDist + g.getAdjacents()[curVertex][i].second;
            nextVertex = g.getAdjacents()[curVertex][i].first;
            if (!visited[nextVertex] && nextDist < distanceVector[nextVertex]) {
                distanceVector[nextVertex] = nextDist;
                previousVector[nextVertex] = curVertex;
                minHeap.push({nextDist, nextVertex});
            }
        }
    }
    return {distanceVector, previousVector};
}

int main(void) {
    std::vector<std::vector<int>> nodes;
    
    // 0 ----> 1 with distance 7
    std::vector<int> v0_1;
    v0_1.push_back(0);
    v0_1.push_back(1);
    v0_1.push_back(7);

    // 0 ----> 2 with distance 9
    std::vector<int> v0_2;
    v0_2.push_back(0);
    v0_2.push_back(2);
    v0_2.push_back(9);
    
    // 0 ----> 3 with distance 14
    std::vector<int> v0_3;
    v0_3.push_back(0);
    v0_3.push_back(3);
    v0_3.push_back(14);

    // 1 ----> 2 with distance 10
    std::vector<int> v1_2;
    v1_2.push_back(1);
    v1_2.push_back(2);
    v1_2.push_back(10);
    
    // 2 ----> 3 with distance 2
    std::vector<int> v2_3;
    v2_3.push_back(2);
    v2_3.push_back(3);
    v2_3.push_back(2);

    nodes.push_back(v0_1);
    nodes.push_back(v0_2);
    nodes.push_back(v0_3);
    nodes.push_back(v1_2);
    nodes.push_back(v2_3);

    Graph g (nodes, nodes.size());
    std::pair<std::vector<int>, std::vector<int>> shortest = shortestPathWitDijkstra(g, 0);
    std::cout << "Starting by vertex " << 0 << " arrive to vertex " << 1 << " passing by vertex " << shortest.second[1] << " with distance " << shortest.first[1] << std::endl;
    std::cout << "Starting by vertex " << 0 << " arrive to vertex " << 2 << " passing by vertex " << shortest.second[2] << " with distance " << shortest.first[2] << std::endl;
    std::cout << "Starting by vertex " << 0 << " arrive to vertex " << 3 << " passing by vertex " << shortest.second[3] << " with distance " << shortest.first[3] << std::endl;
}
