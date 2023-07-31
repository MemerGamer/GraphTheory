//
// Created by hunor on 31.07.2023.
//

#ifndef C___DEPTH_FIRST_SEARCH_H
#define C___DEPTH_FIRST_SEARCH_H

#include "../useful-includes.h"

class DFSGraph {
private:
    int number_of_nodes;
    vector<vector<int>> adjacency_list;
public:
    DFSGraph(int number_of_nodes);
    void add_edge_nondirected(int first_node, int second_node);
    void add_edge_directed(int first_node, int second_node);
    void depth_first_search(int start_node);
private:
    void dfs_helper(int current_node, vector<bool>& visited);
};


#endif //C___DEPTH_FIRST_SEARCH_H
