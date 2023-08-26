//
// Created by hunor on 12.08.2023.
//

#ifndef C___PRUFER_H
#define C___PRUFER_H

#include "../useful-includes.h"

/**
 * @class Prufer
 * Represents a class for encoding and decoding trees using Prufer sequences.
 */
class Prufer {
private:
    int number_of_nodes; /**< The number of nodes in the tree. */
    std::vector<std::vector<int>> adjacency_list; /**< Adjacency list representing the tree. */

    std::vector<int> prufer_sequence; /**< The Prufer sequence used for encoding. */
    std::vector<std::pair<int, int>> decoded_edges; /**< The decoded edges obtained from the Prufer sequence. */
public:
    /**
    * Constructor for the Prufer class.
    * @param number_of_nodes The number of nodes in the tree.
    */
    explicit Prufer(int number_of_nodes);

    /**
     * Add an undirected edge between two nodes in the tree.
     * @param first_node The first node.
     * @param second_node The second node.
     */
    void add_edge_nondirected(int first_node, int second_node);

    /**
     * Add a directed edge from the first node to the second node in the tree.
     * @param first_node The source node.
     * @param second_node The target node.
     */
    void add_edge_directed(int first_node, int second_node);

    /**
     * Encode the tree into a Prufer sequence.
     * @return The Prufer sequence.
     */
    std::vector<int> encodeTree();

    /**
     * Decode a Prufer sequence to obtain the tree's edges.
     * @return The decoded edges.
     */
    std::vector<std::pair<int, int>> decodePruferSequence();
};


#endif //C___PRUFER_H
