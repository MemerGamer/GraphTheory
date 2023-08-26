//
// Created by hunor on 31.07.2023.
//

#ifndef C___DEPTH_FIRST_SEARCH_H
#define C___DEPTH_FIRST_SEARCH_H

#include "../useful-includes.h"

/**
 * @class DFSGraph
 * Represents a class for performing Depth-First Search (DFS) on a graph.
 */
class DFSGraph {
private:
    int number_of_nodes; /**< The number of nodes in the graph. */
    vector<vector<int>> adjacency_list;  /**< Adjacency list representing the graph. */

public:
    /**
     * Constructor for the DFSGraph class.
     * @param number_of_nodes The number of nodes in the graph.
     */
    DFSGraph(int number_of_nodes);

    /**
     * Add an undirected edge between two nodes in the graph.
     * @param first_node The first node.
     * @param second_node The second node.
     */
    void add_edge_nondirected(int first_node, int second_node);

    /**
    * Add a directed edge from the first node to the second node in the graph.
    * @param first_node The source node.
    * @param second_node The target node.
    */
    void add_edge_directed(int first_node, int second_node);

    /**
    * Perform Depth-First Search (DFS) starting from a specified node.
    * @param start_node The starting node for DFS traversal.
    */
    void depth_first_search(int start_node);

private:
    /**
     * Helper function for the Depth-First Search (DFS) algorithm.
     * @param current_node The current node being visited.
     * @param visited A vector to keep track of visited nodes.
     */
    void dfs_helper(int current_node, vector<bool> &visited);
};


#endif //C___DEPTH_FIRST_SEARCH_H
