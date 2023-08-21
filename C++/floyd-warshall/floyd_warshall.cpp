//
// Created by hunor on 21.08.2023.
//

#include "floyd_warshall.h"

FloydWarshall::FloydWarshall(int V) : V(V) {
    dist.resize(V, std::vector<int>(V, INT_MAX));
    for (int i = 0; i < V; ++i) {
        dist[i][i] = 0;
    }
}

void FloydWarshall::addEdge(int u, int v, int w) {
    dist[u][v] = w;
}

void FloydWarshall::floydWarshall() {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void FloydWarshall::printShortestPaths() {
    for (int i = 1; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
