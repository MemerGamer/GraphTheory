//
// Created by hunor on 31.07.2023.
//

#include "depth-first_search.h"

DFSGraph::DFSGraph(int number_of_nodes) : number_of_nodes(number_of_nodes) {
    adjacency_list.resize(number_of_nodes + 1); // Adjust for 1-based indexing
}

void DFSGraph::add_edge_directed(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
}

void DFSGraph::add_edge_nondirected(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
    adjacency_list[second_node].push_back(first_node);
}

void DFSGraph::depth_first_search(int start_node) {
    vector<bool> visited(number_of_nodes + 1, false); // Track visited nodes
    dfs_helper(start_node, visited);
    cout << endl;
}

void DFSGraph::dfs_helper(int current_node, vector<bool> &visited) {
    visited[current_node] = true;
    cout << current_node << " ";
    for (auto neighbor: adjacency_list[current_node]) {
        if (!visited[neighbor]) {
            dfs_helper(neighbor, visited);
        }
    }
}