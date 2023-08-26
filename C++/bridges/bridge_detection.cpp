//
// Created by hunor on 26.08.2023.
//

#include "bridge_detection.h"

BridgeDetection::BridgeDetection(int V): V(V) {
    this->adj.resize(V);
    this->visited.resize(V, false);
    this->discTime.resize(V, -1);
    this->lowTime.resize(V, -1);
    this->parent.resize(V, -1);
    this->time = 0;
}

void BridgeDetection::dfs(int u) {
    this->visited[u] = true;
    this->discTime[u] = this->lowTime[u] = ++this->time;

    for (auto &v: this->adj[u]) {
        if (!this->visited[v]) {
            this->parent[v] = u;
            this->dfs(v);
            this->lowTime[u] = std::min(this->lowTime[u], this->lowTime[v]);
            if (this->lowTime[v] > this->discTime[u]) {
                this->bridges.emplace_back(u, v);
            }
        } else if (v != this->parent[u]) {
            this->lowTime[u] = std::min(this->lowTime[u], this->discTime[v]);
        }
    }
}

void BridgeDetection::addEdge(int u, int v) {
    this->adj[u].emplace_back(v);
    this->adj[v].emplace_back(u);
}

void BridgeDetection::findBridges() {
    for(int i = 0; i < this->V; ++i) {
        if (!this->visited[i]) {
            this->dfs(i);
        }
    }
}

void BridgeDetection::printBridges() {
    std::cout << "Bridges: ";
    for (auto &bridge: this->bridges) {
        std::cout << "(" << bridge.first << ", " << bridge.second << ") ";
    }
    std::cout << std::endl;
}
