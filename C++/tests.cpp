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

    Prim prim(number_of_nodes + 1);

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

    Dijkstra dijkstra(number_of_nodes + 1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        dijkstra.addEdge(first_node, second_node, weight);
    }

    cout << "Dijkstra: " << endl;
    dijkstra.dijkstra(1);
    input_file.close();
}

void test_bellman_ford(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    BellmanFord bellmanFord(number_of_nodes + 1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        bellmanFord.addEdge(first_node, second_node, weight);
    }

    cout << "Bellman-Ford: " << endl;
    bellmanFord.bellmanFord(1);
    input_file.close();

}

void test_ford_fulkerson(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges, source, drain;

    input_file >> number_of_nodes >> number_of_edges >> source >> drain;

    FordFulkerson fordFulkerson(number_of_nodes + 1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        fordFulkerson.addEdge(first_node, second_node, weight);
    }

    cout << "Ford-Fulkerson: " << endl;
    cout << "Max flow: " << fordFulkerson.maxFlow(source, drain) << endl;
    input_file.close();
}

void test_floyd_warshall(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    FloydWarshall floydWarshall(number_of_nodes + 1);

    int first_node, second_node, weight;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node >> weight;
        floydWarshall.addEdge(first_node, second_node, weight);
    }

    cout << "Floyd-Warshall: " << endl;
    floydWarshall.floydWarshall();
    floydWarshall.printShortestPaths();
    input_file.close();

}

void test_check_bipartite(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    CheckBipartite checkBipartite(number_of_nodes + 1);

    int first_node, second_node;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node;
        checkBipartite.addEdge(first_node, second_node);
    }

    if (checkBipartite.isBipartite())
        cout << "The graph is bipartite" << endl;
    else
        cout << "The graph is not bipartite" << endl;
    input_file.close();

}

void test_articulation_points(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    ArticulationPoints articulationPoints(number_of_nodes + 1);

    int first_node, second_node;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node;
        articulationPoints.addEdge(first_node, second_node);
    }

    articulationPoints.findArticulationPoints();
    articulationPoints.printArticulationPoints();
    input_file.close();
}

void test_bridges(const string &input_file_path) {
    ifstream input_file(input_file_path);
    int number_of_nodes, number_of_edges;

    input_file >> number_of_nodes >> number_of_edges;

    BridgeDetection bridgeDetection(number_of_nodes + 1);

    int first_node, second_node;
    for (int i = 0; i < number_of_edges; ++i) {
        input_file >> first_node >> second_node;
        bridgeDetection.addEdge(first_node, second_node);
    }

    bridgeDetection.findBridges();
    bridgeDetection.printBridges();
    input_file.close();

}
