//
// Created by hunor on 15.08.2023.
//

#ifndef C___KRUSKAL_H
#define C___KRUSKAL_H

#include "../useful-includes.h"

/**
 * @class Kruskal
 * Represents a class for finding the Minimum Spanning Tree (MST) of a graph using Kruskal's algorithm.
 */
class Kruskal {
    struct Edge {
        int source; /**< The source vertex of the edge. */
        int destination; /**< The destination vertex of the edge. */
        int weight; /**< The weight/cost associated with the edge. */
    };

private:
    int number_of_nodes; /**< The number of nodes in the graph. */
    std::vector<Edge> edges; /**< Vector to store graph edges. */

    std::vector<int> parent; /**< Array to maintain the parent of each node in the MST. */
    std::vector<int> rank; /**< Array to store the rank (depth) of each node in the MST. */

    /**
     * Find the set to which a node belongs (with path compression).
     * @param node The node for which to find the set.
     * @return The representative node of the set.
     */
    int find(int node);

    /**
     * Union two sets (with rank-based optimization).
     * @param first_node The first node.
     * @param second_node The second node.
     */
    void union_set(int first_node, int second_node);

    /**
    * Compare function to sort edges by weight in non-decreasing order.
    * @param first_edge The first edge.
    * @param second_edge The second edge.
    * @return True if the weight of the first edge is less than the weight of the second edge, false otherwise.
    */
    static bool compareEdges(Edge first_edge, Edge second_edge);

public:
    /**
     * Constructor for the Kruskal class.
     * @param number_of_nodes The number of nodes in the graph.
     */
    explicit Kruskal(int number_of_nodes);

    /**
     * Add an edge to the graph with a specified weight.
     * @param source The source vertex of the edge.
     * @param destination The target vertex of the edge.
     * @param weight The weight/cost associated with the edge.
     */
    void addEdge(int source, int destination, int weight);

    /**
     * Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
     * */
    void kruskalMST();
};


#endif //C___KRUSKAL_H
