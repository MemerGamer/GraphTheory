//
// Created by hunor on 21.08.2023.
//

#ifndef C___FORD_FULKERSON_H
#define C___FORD_FULKERSON_H

#include "../useful-includes.h"

/**
 * @class FordFulkerson
 * Represents a class for finding the maximum flow in a flow network using the Ford-Fulkerson algorithm.
 */
class FordFulkerson {
private:
    int V; /**< The number of vertices in the flow network. */
    std::vector<std::vector<int>> capacity; /**< 2D array representing the capacities of edges in the flow network. */
    std::vector<std::vector<int>> residualCapacity; /**< 2D array representing the residual capacities of edges in the flow network. */
    std::vector<bool> visited; /**< Array to keep track of visited vertices during BFS traversal. */
    std::vector<int> parent; /**< Array to store parent vertices during path traversal. */

    /**
     * Breadth-First Search (BFS) to find augmenting paths in the residual graph.
     * @param source The source vertex.
     * @param drain The drain (sink) vertex.
     * @return True if an augmenting path is found, false otherwise.
     */
    bool bfs(int source, int drain);

    /**
     * Find the minimum capacity on an augmenting path.
     * @param u The source vertex of the path.
     * @param v The target vertex of the path.
     * @return The minimum capacity on the path.
     */
    int minCapacityOnPath(int u, int v);

    /**
     * Update the residual capacities of edges on an augmenting path.
     * @param u The source vertex of the path.
     * @param v The target vertex of the path.
     * @param flow The flow through the path.
     */
    void updateResidualCapacity(int u, int v, int flow);

public:
    /**
     * Constructor for the FordFulkerson class.
     * @param V The number of vertices in the flow network.
     */
    FordFulkerson(int V);

    /**
     * Add an edge to the flow network with a specified capacity.
     * @param u The source vertex of the edge.
     * @param v The target vertex of the edge.
     * @param capacity The capacity of the edge.
     */
    void addEdge(int u, int v, int capacity);

    /**
     * Find the maximum flow in the flow network from a source to a drain (sink).
     * @param source The source vertex.
     * @param drain The drain (sink) vertex.
     * @return The maximum flow in the network.
     */
    int maxFlow(int source, int drain);
};


#endif //C___FORD_FULKERSON_H
