//
// Created by hunor on 21.08.2023.
//

#ifndef C___DIJKSTRA_H
#define C___DIJKSTRA_H

#include "../useful-includes.h"

class Dijkstra {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
public:
    explicit Dijkstra(int V);

    void addEdge(int u, int v, int w);

    void dijkstra(int src);
};


#endif //C___DIJKSTRA_H
