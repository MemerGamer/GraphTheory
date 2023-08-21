//
// Created by hunor on 21.08.2023.
//

#ifndef C___FLOYD_WARSHALL_H
#define C___FLOYD_WARSHALL_H

#include "../useful-includes.h"

class FloydWarshall {
private:
    int V;
    std::vector<std::vector<int>> dist;
public:
    FloydWarshall(int V);

    void addEdge(int u, int v, int w);

    void floydWarshall();

    void printShortestPaths();
};


#endif //C___FLOYD_WARSHALL_H
