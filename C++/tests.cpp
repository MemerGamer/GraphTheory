//
// Created by hunor on 24.05.2023.
//

#include "tests.h"

void test_breadth_first_search(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    Graph graph(number_of_nodes);

    int first_node, second_node;
    for (int i = 0; i < number_of_nodes; ++i) {
        input_file >> first_node >> second_node;
        graph.add_edge_nondirected(first_node, second_node);
//        graph.add_edge_directed(first_node, second_node); // for directed graph
    }

    int start_node = 1;
    cout << "BFS traversal starting from node " << start_node << ": ";
    graph.breadth_first_search(start_node);
    cout << endl;
    input_file.close();
}
