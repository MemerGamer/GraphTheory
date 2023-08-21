//
// Created by hunor on 21.08.2023.
//

#ifndef C___CHECK_BIPARTITE_H
#define C___CHECK_BIPARTITE_H

#include "../useful-includes.h"

class CheckBipartite {
private:
    int V;
    std::vector<std::vector<int>> adj;
public:
    CheckBipartite(int V);
    void addEdge(int u, int v);
    bool isBipartite();
};


#endif //C___CHECK_BIPARTITE_H
