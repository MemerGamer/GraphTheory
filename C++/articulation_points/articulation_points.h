//
// Created by hunor on 21.08.2023.
//

#ifndef C___ARTICULATION_POINTS_H
#define C___ARTICULATION_POINTS_H

#include "../useful-includes.h"

class ArticulationPoints {
private:
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    std::vector<int> discTime;
    std::vector<int> lowTime;
    std::vector<int> parent;
    std::vector<bool> isArticulationPoint;
    int time;

    void dfs(int u);
public:
    explicit ArticulationPoints(int V);
    void addEdge(int u, int v);
    void findArticulationPoints();
    void printArticulationPoints();
};


#endif //C___ARTICULATION_POINTS_H
