//
// Created by hunor on 24.05.2023.
//

#include "tests.h"

void test_breadth_first_search(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    BFSGraph graph(number_of_nodes);

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

void test_depth_first_search(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    DFSGraph graph(number_of_nodes);

    int first_node, second_node;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node;
        graph.add_edge_nondirected(first_node, second_node);
    }

    int start_node = 1;
    cout << "DFS traversal starting from node " << start_node << ": ";
    graph.depth_first_search(start_node);
    cout << endl;
    input_file.close();
}

void test_prufer(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    Prufer prufer(number_of_nodes);

    int first_node, second_node;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node;
        prufer.add_edge_nondirected(first_node, second_node);
    }

    cout << "Prufer sequence: ";
    vector<int> prufer_sequence = prufer.encodeTree();
    for (auto node: prufer_sequence) {
        cout << node << " ";
    }
    cout << endl;

    cout << "Decoded Prufer sequence: ";
    vector<pair<int, int>> decoded_prufer_sequence = prufer.decodePruferSequence();
    for (auto edge: decoded_prufer_sequence) {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;
    input_file.close();
}

void test_kruskal(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    Kruskal kruskal(number_of_nodes);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        kruskal.addEdge(first_node, second_node, weight);
    }

    cout << "Kruskal MST: " << endl;
    kruskal.kruskalMST();
    input_file.close();
}

void test_prim(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    Prim prim(number_of_nodes+1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        prim.addEdge(first_node, second_node, weight);
    }

    cout << "Prim MST: " << endl;
    prim.primMST();
    input_file.close();
}

void test_dijkstra(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    Dijkstra dijkstra(number_of_nodes+1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        dijkstra.addEdge(first_node, second_node, weight);
    }

    cout << "Dijkstra: " << endl;
    dijkstra.dijkstra(1);
    input_file.close();
}
