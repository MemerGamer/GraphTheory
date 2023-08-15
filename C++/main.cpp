#include <iostream>
#include <utility>
#include "tests.h"

void tests(string input_file_path, const std::vector<string>& algorithms) {
    for (auto &algorithm: algorithms) {
        if (algorithm == "bfs") {
            test_breadth_first_search(input_file_path);
        } else if (algorithm == "dfs") {
            test_depth_first_search(input_file_path);
        } else if (algorithm == "prufer") {
            test_prufer(input_file_path);
        } else if (algorithm == "kruskal") {
            test_kruskal(input_file_path);
        } else if (algorithm == "all") {
            test_breadth_first_search(input_file_path);
            test_depth_first_search(input_file_path);
            test_prufer(input_file_path);
            test_kruskal(input_file_path);
        } else {
            cout << "Algorithm " << algorithm << " not found!\n";
            cout << "Available algorithms: bfs, dfs, prufer, kruskal, all\n";
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
