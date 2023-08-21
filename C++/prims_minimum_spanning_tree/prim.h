//
// Created by hunor on 21.08.2023.
//

#ifndef C___PRIM_H
#define C___PRIM_H

#include "../useful-includes.h"

class Prim {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
public:
    explicit Prim(int V);

    void addEdge(int u, int v, int w);

    void primMST();
};


#endif //C___PRIM_H
