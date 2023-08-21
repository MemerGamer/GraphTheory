//
// Created by hunor on 21.08.2023.
//

#ifndef C___FORD_FULKERSON_H
#define C___FORD_FULKERSON_H

#include "../useful-includes.h"

class FordFulkerson {
private:
    int V;
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> residualCapacity;
    std::vector<bool> visited;
    std::vector<int> parent;

    bool bfs(int source, int drain);

    int minCapacityOnPath(int u, int v);

    void updateResidualCapacity(int u, int v, int flow);

public:
    FordFulkerson(int V);
    void addEdge(int u, int v, int capacity);
    int maxFlow(int source, int drain);
};


#endif //C___FORD_FULKERSON_H
