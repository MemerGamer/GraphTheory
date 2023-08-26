//
// Created by hunor on 21.08.2023.
//

#ifndef C___PRIM_H
#define C___PRIM_H

#include "../useful-includes.h"

/**
 * @class Prim
 * Represents a class for finding the Minimum Spanning Tree (MST) of a graph using Prim's algorithm.
 */
class Prim {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<std::pair<int, int>>> adj; /**< Adjacency list representing the graph with edge weights. */
public:
    /**
     * Constructor for the Prim class.
     * @param V The number of vertices in the graph.
     */
    explicit Prim(int V);

    /**
     * Add an edge to the graph with a specified weight.
     * @param u The source vertex of the edge.
     * @param v The target vertex of the edge.
     * @param w The weight/cost associated with the edge.
     */

    void addEdge(int u, int v, int w);

    /**
     * Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
     */
    void primMST();
};


#endif //C___PRIM_H
