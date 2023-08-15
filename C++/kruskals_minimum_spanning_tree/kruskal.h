//
// Created by hunor on 15.08.2023.
//

#ifndef C___KRUSKAL_H
#define C___KRUSKAL_H

#include "../useful-includes.h"

class Kruskal {
    struct Edge {
        int source;
        int destination;
        int weight;
    };

private:
    int number_of_nodes;
    std::vector<Edge> edges;

    std::vector<int> parent;
    std::vector<int> rank;

    int find(int node);

    void union_set(int first_node, int second_node);

    static bool compareEdges(Edge first_edge, Edge second_edge);

public:
    explicit Kruskal(int number_of_nodes);

    void addEdge(int source, int destination, int weight);

    void kruskalMST();
};


#endif //C___KRUSKAL_H
