//
// Created by hunor on 21.08.2023.
//

#include "articulation_points.h"

ArticulationPoints::ArticulationPoints(int V): V(V) {
    this->adj.resize(V);
    this->visited.resize(V, false);
    this->discTime.resize(V, -1);
    this->lowTime.resize(V, -1);
    this->parent.resize(V, -1);
    this->isArticulationPoint.resize(V, false);
    this->time = 0;
}

void ArticulationPoints::addEdge(int u, int v) {
    this->adj[u].emplace_back(v);
    this->adj[v].emplace_back(u);
}


void ArticulationPoints::dfs(int u) {
    int children = 0;
    this->visited[u] = true;
    this->discTime[u] = this->lowTime[u] = ++this->time;

    for (auto &v: this->adj[u]) {
        if (!this->visited[v]) {
            children++;
            this->parent[v] = u;
            this->dfs(v);
            this->lowTime[u] = std::min(this->lowTime[u], this->lowTime[v]);
            if (this->parent[u] == -1 && children > 1) {
                this->isArticulationPoint[u] = true;
            }
            if (this->parent[u] != -1 && this->lowTime[v] >= this->discTime[u]) {
                this->isArticulationPoint[u] = true;
            }
        } else if (v != this->parent[u]) {
            this->lowTime[u] = std::min(this->lowTime[u], this->discTime[v]);
        }
    }
}

void ArticulationPoints::findArticulationPoints() {
    for (int i = 0; i < this->V; ++i) {
        if (!this->visited[i]) {
            this->dfs(i);
        }
    }
}

void ArticulationPoints::printArticulationPoints() {
    std::cout << "Articulation points: ";
    for (int i = 0; i < this->V; ++i) {
        if (this->isArticulationPoint[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
