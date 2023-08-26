//
// Created by hunor on 21.08.2023.
//

#ifndef C___CHECK_BIPARTITE_H
#define C___CHECK_BIPARTITE_H

#include "../useful-includes.h"

/**
 * @class CheckBipartite
 * Represents a class for checking if an undirected graph is bipartite.
 */
class CheckBipartite {
private:
    int V; /**< The number of vertices in the graph. */
    std::vector<std::vector<int>> adj; /**< Adjacency list representing the graph. */
public:
    /**
     * Constructor for the CheckBipartite class.
     * @param V The number of vertices in the graph.
     */
    CheckBipartite(int V);

    /**
    * Add an edge to the graph.
    * @param u The source vertex of the edge.
    * @param v The target vertex of the edge.
    */
    void addEdge(int u, int v);

    /**
     * Check if the graph is bipartite.
     * @return True if the graph is bipartite, false otherwise.
     */
    bool isBipartite();
};


#endif //C___CHECK_BIPARTITE_H
