//
// Created by hunor on 24.05.2023.
//

#ifndef C___BREADTH_FIRST_SEARCH_H
#define C___BREADTH_FIRST_SEARCH_H

#include "../useful-includes.h"

class Graph{
private:
    int number_of_nodes;
    vector<vector<int>> adjacency_list;
public:
    Graph(int number_of_nodes);
    void add_edge_nondirected(int first_node, int second_node);
    void add_edge_directed(int first_node, int second_node);
    void breadth_first_search(int start_node);
};


#endif //C___BREADTH_FIRST_SEARCH_H
