//
// Created by hunor on 12.08.2023.
//

#include "prufer.h"


Prufer::Prufer(int number_of_nodes) {
    this->number_of_nodes = number_of_nodes;
    this->adjacency_list = std::vector<std::vector<int>>(number_of_nodes + 1);
}


void Prufer::add_edge_directed(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
}

void Prufer::add_edge_nondirected(int first_node, int second_node) {
    adjacency_list[first_node].push_back(second_node);
    adjacency_list[second_node].push_back(first_node);
}

std::vector<int> Prufer::encodeTree() {
    std::set<int> leafs;
    std::vector<int> degree(number_of_nodes + 1, 0);
    std::vector<bool> isLeafCut(number_of_nodes + 1, false);
    std::vector<int> prufer_sequence(number_of_nodes - 2);

    for (int currentNode = 1; currentNode <= number_of_nodes; ++currentNode) {
        degree[currentNode] = adjacency_list[currentNode].size();
        if (degree[currentNode] == 1) {
            leafs.insert(currentNode);
        }
    }

    for (int currentNode = 0; currentNode < number_of_nodes - 2; ++currentNode) {
        int leaf = *leafs.begin();
        leafs.erase(leaf);
        isLeafCut[leaf] = true;

        int originOfCurrentNode;

        for (auto &currentNeighbour: adjacency_list[leaf]) {
            if (!isLeafCut[currentNeighbour]) {
                originOfCurrentNode = currentNeighbour;
                break;
            }
        }

        prufer_sequence[currentNode] = originOfCurrentNode;
        if (--degree[originOfCurrentNode] == 1) {
            leafs.insert(originOfCurrentNode);
        }
    }

    this->prufer_sequence = prufer_sequence;
    return prufer_sequence;
}

std::vector<std::pair<int, int>> Prufer::decodePruferSequence() {
    std::vector<int> degree(number_of_nodes + 2, 1);

    for (int node: prufer_sequence) {
        degree[node]++;
    }

    std::set<int> leaves;
    for (int i = 1; i <= number_of_nodes + 1; ++i) {
        if (degree[i] == 1) {
            leaves.insert(i);
        }
    }

    std::vector<std::pair<int, int>> edges;

    for (int originOfCurrentNode: prufer_sequence) {
        int leaf = *leaves.begin();
        leaves.erase(leaf);
        edges.emplace_back(originOfCurrentNode, leaf);
        if (--degree[originOfCurrentNode] == 1) {
            leaves.insert(originOfCurrentNode);
        }
    }

    int leaf1 = *leaves.begin();
    leaves.erase(leaf1);
    int leaf2 = *leaves.begin();
    edges.emplace_back(leaf1, leaf2);

    this->decoded_edges = edges;
    return edges;
}
