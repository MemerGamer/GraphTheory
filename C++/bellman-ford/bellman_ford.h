//
// Created by hunor on 21.08.2023.
//

#ifndef C___BELLMAN_FORD_H
#define C___BELLMAN_FORD_H

#include "../useful-includes.h"

class BellmanFord {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
public:
    explicit BellmanFord(int V);

    void addEdge(int u, int v, int w);

    bool bellmanFord(int src);
};

#endif //C___BELLMAN_FORD_H
