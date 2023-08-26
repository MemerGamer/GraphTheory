//
// Created by hunor on 21.08.2023.
//

#include "dijkstra.h"

Dijkstra::Dijkstra(int V) : V(V) {
    this->adj.resize(V);
}

void Dijkstra::addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

void Dijkstra::dijkstra(int src) {
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false);

    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const auto &neighbor: adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source vertex
    std::cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 1; i < V; ++i) {
        std::cout << "Vertex " << i << ": " << dist[i] << std::endl;
    }
}