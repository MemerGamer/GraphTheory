//
// Created by hunor on 24.05.2023.
//

#ifndef C___BREADTH_FIRST_SEARCH_H
#define C___BREADTH_FIRST_SEARCH_H

#include "../useful-includes.h"

/**
 * @class BFSGraph
 * Represents a class for performing Breadth-First Search (BFS) on a graph.
 */
class BFSGraph{
private:
    int number_of_nodes; /**< The number of nodes in the graph. */
    vector<vector<int>> adjacency_list; /**< Adjacency list representing the graph. */
public:
    /**
     * Constructor for the BFSGraph class.
     * @param number_of_nodes The number of nodes in the graph.
     */
    BFSGraph(int number_of_nodes);

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
     * Perform Breadth-First Search (BFS) starting from a specified node.
     * @param start_node The starting node for BFS traversal.
     */
    void breadth_first_search(int start_node);
};


#endif //C___BREADTH_FIRST_SEARCH_H
