//
// Created by hunor on 21.08.2023.
//

#include "check_bipartite.h"

CheckBipartite::CheckBipartite(int V) : V(V) {
    this->adj.resize(V);
}

void CheckBipartite::addEdge(int u, int v) {
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

bool CheckBipartite::isBipartite() {
    std::vector<int> color(this->V, -1);
    std::queue<int> q;

    for (int i = 0; i < V; ++i) {
        if (color[i] != -1) continue; // Skip already colored vertices

        color[i] = 0; // Assign the first color to the source vertex
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u]; // Assign the opposite color
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false; // Found an edge between vertices with the same color, not bipartite
                }
            }
        }
    }
    return true;
}
