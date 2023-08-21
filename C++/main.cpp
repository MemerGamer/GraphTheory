#include <iostream>
#include "tests.h"

void tests(string input_file_path, const std::vector<string> &algorithms) {
    for (auto &algorithm: algorithms) {
        if (algorithm == "bfs") {
            test_breadth_first_search(input_file_path);
        } else if (algorithm == "dfs") {
            test_depth_first_search(input_file_path);
        } else if (algorithm == "check_bipartite") {
            test_check_bipartite(input_file_path);
        } else if (algorithm == "prufer") {
            test_prufer(input_file_path);
        } else if (algorithm == "kruskal") {
            test_kruskal(input_file_path);
        } else if (algorithm == "prim") {
            test_prim(input_file_path);
        } else if (algorithm == "dijkstra") {
            test_dijkstra(input_file_path);
        } else if (algorithm == "bellman_ford") {
            test_bellman_ford(input_file_path);
        } else if (algorithm == "ford_fulkerson") {
            test_ford_fulkerson(input_file_path);
        } else if (algorithm == "floyd_warshall") {
            test_floyd_warshall(input_file_path);
        }
        else if (algorithm == "articulation_points") {
            test_articulation_points(input_file_path);
        }
        else if (algorithm == "all") {
            test_breadth_first_search(input_file_path);
            test_depth_first_search(input_file_path);
            test_check_bipartite(input_file_path);
            test_prufer(input_file_path);
            test_kruskal(input_file_path);
            test_prim(input_file_path);
            test_dijkstra(input_file_path);
            test_bellman_ford(input_file_path);
            test_ford_fulkerson(input_file_path);
            test_floyd_warshall(input_file_path);
            test_articulation_points(input_file_path);
        } else {
            cout << "Algorithm " << algorithm << " not found!\n";
            cout
                    << "Available algorithms: bfs, dfs,check_bipartite, prufer, kruskal, prim, dijkstra, bellman_ford, ford_fulkerson, floyd_warshall, articulation_points, all\n";
        }
    }
}

int main(int argc, char **argv) {
    std::cout << "GraphTheory Algorithms" << std::endl;
    if (argc < 2) {
        cout << "Usage: ./" << argv[0] << " <input_file_path> <ALGORITHM>\n";
        return 1;
    }
    string input_file_path = argv[1];

    // Get the array of algorithms to run
    std::vector<string> algorithms;
    for (int i = 2; i < argc; ++i) {
        algorithms.emplace_back(argv[i]);
    }
    tests(input_file_path, algorithms);
    return 0;
}
