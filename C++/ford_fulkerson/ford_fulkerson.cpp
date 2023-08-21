//
// Created by hunor on 21.08.2023.
//

#include "ford_fulkerson.h"

FordFulkerson::FordFulkerson(int V) : V(V) {
    this->capacity.resize(V, std::vector<int>(V, 0));
    residualCapacity.resize(V, std::vector<int>(V, 0));
    visited.resize(V, false);
    parent.resize(V, -1);
}

void FordFulkerson::addEdge(int u, int v, int capacity) {
    this->capacity[u][v] = capacity;
}

bool FordFulkerson::bfs(int source, int drain) {
    std::fill(visited.begin(), visited.end(), false);
    std::queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualCapacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[drain];
}

int FordFulkerson::minCapacityOnPath(int u, int v) {
    int minCapacity = INT_MAX;
    int current = v;
    while (current != u) {
        int previous = parent[current];
        minCapacity = std::min(minCapacity, residualCapacity[previous][current]);
        current = previous;
    }
    return minCapacity;
}

void FordFulkerson::updateResidualCapacity(int u, int v, int flow) {
    residualCapacity[u][v] -= flow;
    residualCapacity[v][u] += flow;
}

int FordFulkerson::maxFlow(int source, int drain) {
    // Initialize residual capacity
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            residualCapacity[u][v] = capacity[u][v];
        }
    }

    int maxFlow = 0;
    while (bfs(source, drain)) {
        int flow = minCapacityOnPath(source, drain);
        maxFlow += flow;
        int current = drain;
        while (current != source) {
            int previous = parent[current];
            updateResidualCapacity(previous, current, flow);
            current = previous;
        }
    }

    return maxFlow;
}
