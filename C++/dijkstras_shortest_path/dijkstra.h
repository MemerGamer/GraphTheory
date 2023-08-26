//
// Created by hunor on 21.08.2023.
//

#ifndef C___DIJKSTRA_H
#define C___DIJKSTRA_H

#include "../useful-includes.h"

/**
 * @class Dijkstra
 * Represents a class for solving the single-source shortest path problem using Dijkstra's algorithm.
 */
class Dijkstra {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<std::pair<int, int>>> adj; /**< Adjacency list representing the graph with edge weights. */

public:
    /**
     * Constructor for the Dijkstra class.
     * @param V The number of vertices in the graph.
     */
    explicit Dijkstra(int V);

    /**
     * Add an edge to the graph with a specified weight.
     * @param u The source vertex of the edge.
     * @param v The target vertex of the edge.
     * @param w The weight/cost associated with the edge.
     */
    void addEdge(int u, int v, int w);

    /**
     * Perform Dijkstra's algorithm to find the shortest paths from a source vertex.
     * @param src The source vertex from which to find shortest paths.
     */
    void dijkstra(int src);
};


#endif //C___DIJKSTRA_H
