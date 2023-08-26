//
// Created by hunor on 21.08.2023.
//

#include "prim.h"

Prim::Prim(int V) : V(V) {
    this->adj.resize(V);
}

void Prim::addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

void Prim::primMST() {
    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);

    key[1] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (const auto &neighbor: adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Print the MST edges and their weights
    for (int i = 2; i < V; ++i) {
        std::cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << std::endl;
    }
    std::cout << std::endl;
}
