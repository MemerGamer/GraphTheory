//
// Created by hunor on 12.08.2023.
//

#ifndef C___PRUFER_H
#define C___PRUFER_H

#include "../useful-includes.h"

class Prufer {
private:
    int number_of_nodes;
    std::vector<std::vector<int>> adjacency_list;

    std::vector<int> prufer_sequence;
    std::vector<std::pair<int, int>> decoded_edges;
public:
    explicit Prufer(int number_of_nodes);

    void add_edge_nondirected(int first_node, int second_node);

    void add_edge_directed(int first_node, int second_node);

    std::vector<int> encodeTree();

    std::vector<std::pair<int, int>> decodePruferSequence();
};


#endif //C___PRUFER_H
