//
// Created by hunor on 26.08.2023.
//

#ifndef C___BRIDGE_DETECTION_H
#define C___BRIDGE_DETECTION_H

#include "../useful-includes.h"

/**
 * @class BridgeDetection
 * Represents a class for detecting bridges (articulation edges) in an undirected graph.
 */
class BridgeDetection {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<int>> adj; /**< Adjacency list representing the graph. */
    std::vector<bool> visited; /**< Array to keep track of visited vertices. */
    std::vector<int> discTime; /**< Array to store discovery times during DFS traversal. */
    std::vector<int> lowTime; /**< Array to store low values during DFS traversal. */
    std::vector<int> parent; /**< Array to store parent of each vertex in DFS tree. */
    std::vector<std::pair<int, int>> bridges; /**< List of detected bridges (articulation edges). */
    int time; /**< Variable to track time during DFS traversal. */

    /**
    * Depth-First Search (DFS) function for detecting bridges.
    * @param u The current vertex being visited.
    */
    void dfs(int u);
public:
    /**
     * Constructor for the BridgeDetection class.
     * @param V The number of vertices in the graph.
     */
    explicit BridgeDetection(int V);

    /**
    * Add an edge to the undirected graph.
    * @param u The first endpoint of the edge.
    * @param v The second endpoint of the edge.
    */
    void addEdge(int u, int v);

    /**
    * Find and store the bridges (articulation edges) in the graph.
    */
    void findBridges();

    /**
    * Print the detected bridges in the graph.
    */
    void printBridges();
};


#endif //C___BRIDGE_DETECTION_H
