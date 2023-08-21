//
// Created by hunor on 21.08.2023.
//

#include "bellman_ford.h"

BellmanFord::BellmanFord(int V): V(V) {
    this->adj.resize(V);
}

void BellmanFord::addEdge(int u, int v, int w) {
    this->adj[u].emplace_back(std::make_pair(v, w));
}

bool BellmanFord::bellmanFord(int src) {
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto &neighbour : this->adj[u]) {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (const auto &neighbour : this->adj[u]) {
            int v = neighbour.first;
            int weight = neighbour.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains negative weight cycle" << std::endl;
                return false;
            }
        }
    }

    // Print the shortest distances from the source vertex
    std::cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 1; i < V; ++i) {
        std::cout << "Vertex " << i << ": " << dist[i] << std::endl;
    }

    return true;
}