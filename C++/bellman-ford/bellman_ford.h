//
// Created by hunor on 21.08.2023.
//

#ifndef C___BELLMAN_FORD_H
#define C___BELLMAN_FORD_H

#include "../useful-includes.h"

/**
 * @class BellmanFord
 * Represents a class for solving the single-source shortest path problem using the Bellman-Ford algorithm.
 */
class BellmanFord {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<std::pair<int, int>>> adj; /**< Adjacency list representing the graph with edge weights. */

public:
    /**
     * Constructor for the BellmanFord class.
     * @param V The number of vertices in the graph.
     */
    explicit BellmanFord(int V);

    /**
     * Add an edge to the graph with a specified weight.
     * @param u The source vertex of the edge.
     * @param v The target vertex of the edge.
     * @param w The weight/cost associated with the edge.
     */
    void addEdge(int u, int v, int w);

    /**
     * Perform the Bellman-Ford algorithm to find the shortest paths from a source vertex.
     * @param src The source vertex from which to find shortest paths.
     * @return True if no negative weight cycles are present, false otherwise.
     */
    bool bellmanFord(int src);
};

#endif //C___BELLMAN_FORD_H
