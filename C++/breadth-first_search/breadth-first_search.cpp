//
// Created by hunor on 24.05.2023.
//

#include "breadth-first_search.h"

Graph::Graph(int number_of_nodes) : number_of_nodes(number_of_nodes) {
    adjacency_list.resize(number_of_nodes + 1); // Adjust for 1-based indexing
}

void Graph::add_edge_directed(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
}

void Graph::add_edge_nondirected(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
    adjacency_list[second_node].push_back(first_node);
}

void Graph::breadth_first_search(int start_node) {
    vector<bool> visited(number_of_nodes + 1, false); // Track visited nodes
    queue<int> node_queue;
    node_queue.push(start_node);
    visited[start_node] = true;

    while (!node_queue.empty()) {
        int current_node = node_queue.front();
        cout << current_node << " ";
        node_queue.pop();
        for (auto neighbor : adjacency_list[current_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                node_queue.push(neighbor);
            }
        }
    }
    cout << endl;
}



