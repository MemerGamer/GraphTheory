//
// Created by hunor on 21.08.2023.
//

#ifndef C___ARTICULATION_POINTS_H
#define C___ARTICULATION_POINTS_H

#include "../useful-includes.h"

/**
 * @class ArticulationPoints
 * Represents a class for finding articulation points in a graph.
 */
class ArticulationPoints {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<int>> adj;  /**< Adjacency list representing the graph. */
    std::vector<bool> visited; /**< Array to keep track of visited vertices. */
    std::vector<int> discTime; /**< Array to store discovery times during DFS traversal. */
    std::vector<int> lowTime; /**< Array to store low values during DFS traversal. */
    std::vector<int> parent; /**< Array to store parent of each vertex in DFS tree. */
    std::vector<bool> isArticulationPoint; /**< Array to mark vertices as articulation points. */
    int time; /**< Variable to track time during DFS traversal. */

    /**
     * Depth-First Search (DFS) function for finding articulation points.
     * @param u The current vertex being visited.
     */
    void dfs(int u);

public:
    /**
     * Constructor for the ArticulationPoints class.
     * @param V The number of vertices in the graph.
     */
    explicit ArticulationPoints(int V);

    /**
     * Add an edge to the graph.
     * @param u The source vertex of the edge.
     * @param v The target vertex of the edge.
     */
    void addEdge(int u, int v);

    /**
     * Find articulation points in the graph.
     */
    void findArticulationPoints();

    /**
    * Print the articulation points found in the graph.
    */
    void printArticulationPoints();
};


#endif //C___ARTICULATION_POINTS_H
