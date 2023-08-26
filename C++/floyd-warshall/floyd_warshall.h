//
// Created by hunor on 21.08.2023.
//

#ifndef C___FLOYD_WARSHALL_H
#define C___FLOYD_WARSHALL_H

#include "../useful-includes.h"

/**
 * @class FloydWarshall
 * Represents a class for solving the all-pairs shortest path problem using Floyd-Warshall algorithm.
 */
class FloydWarshall {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<int>> dist; /**< 2D array to store shortest path distances between all pairs of vertices. */
public:
    /**
    * Constructor for the FloydWarshall class.
    * @param V The number of vertices in the graph.
    */
    FloydWarshall(int V);

    /**
    * Add an edge to the graph with a specified weight.
    * @param u The source vertex of the edge.
    * @param v The target vertex of the edge.
    * @param w The weight/cost associated with the edge.
    */
    void addEdge(int u, int v, int w);

    /**
     * Perform the Floyd-Warshall algorithm to compute all-pairs shortest paths.
     */
    void floydWarshall();

    /**
     * Print the computed shortest paths between all pairs of vertices.
     */
    void printShortestPaths();
};


#endif //C___FLOYD_WARSHALL_H
