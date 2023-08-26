//
// Created by hunor on 26.08.2023.
//

#ifndef C___BRIDGE_DETECTION_H
#define C___BRIDGE_DETECTION_H

#include "../useful-includes.h"

class BridgeDetection {
private:
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    std::vector<int> discTime;
    std::vector<int> lowTime;
    std::vector<int> parent;
    std::vector<std::pair<int, int>> bridges;
    int time;

    void dfs(int u);
public:
    explicit BridgeDetection(int V);
    void addEdge(int u, int v);
    void findBridges();
    void printBridges();
};


#endif //C___BRIDGE_DETECTION_H
