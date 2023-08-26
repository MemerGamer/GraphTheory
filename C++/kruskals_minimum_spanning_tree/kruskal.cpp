//
// Created by hunor on 15.08.2023.
//

#include "kruskal.h"


Kruskal::Kruskal(int number_of_nodes) {
    parent.resize(number_of_nodes + 1);
    rank.resize(number_of_nodes + 1, 0);
    for (int i = 0; i <= number_of_nodes; ++i) {
        parent[i] = i;
    }
}

void Kruskal::addEdge(int source, int destination, int weight) {
    edges.push_back({source, destination, weight});
}

int Kruskal::find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

void Kruskal::union_set(int first_node, int second_node) {
    int first_node_parent = find(first_node);
    int second_node_parent = find(second_node);

    if (rank[first_node_parent] > rank[second_node_parent]) {
        parent[second_node_parent] = first_node_parent;
    } else if (rank[first_node_parent] < rank[second_node_parent]) {
        parent[first_node_parent] = second_node_parent;
    } else {
        parent[first_node_parent] = second_node_parent;
        rank[second_node_parent]++;
    }
}

bool Kruskal::compareEdges(Edge first_edge, Edge second_edge) {
    return first_edge.weight < second_edge.weight;
}

void Kruskal::kruskalMST() {
    std::vector<Edge> mst;
    std::sort(edges.begin(), edges.end(), compareEdges);

    for (auto &edge: edges) {
        if (find(edge.source) != find(edge.destination)) {
            mst.push_back(edge);
            union_set(edge.source, edge.destination);
        }
    }

    for (auto &edge: mst) {
        std::cout << edge.source << " " << edge.destination << " " << edge.weight << std::endl;
    }
}
