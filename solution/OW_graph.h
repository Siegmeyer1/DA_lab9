#ifndef DA_LAB9_OW_GRAPH_H
#define DA_LAB9_OW_GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <limits>

typedef unsigned long long ull;

class ow_graph {
public:
    explicit ow_graph(std::istream& in);
    ull flow_increase();
    bool bfs();
    ull max_flow();
    std::vector<int> path;
private:
    std::vector<std::list<int>> edges;
    std::vector<std::vector<ull>> g_matrix;
    int sink;
};

#endif //DA_LAB9_OW_GRAPH_H
