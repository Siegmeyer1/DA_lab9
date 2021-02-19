#include "OW_graph.h"
#include <queue>
#include <algorithm>

ow_graph::ow_graph(std::istream& in) {          // Храним граф следующим образом: рёбра и их веса хранятся отдельно.
    int n, m, begin, end;                       // Для рёбер заводим вектор списков, каждый елемент соответсвует началь-
    ull cap;                                    // ному узлу (соответствие по индексу), а список, хранящийся в этом
    in >> n >> m;                               // элементе - узлам на концах рёбер, вышедших из i-го узла.
    sink = n;
    g_matrix.resize(sink+1);           // Веса хранятся в матрице смежности для упрощения доступа (не надо бегать ли-
    for (int i = 0; i < n+1; ++i) {             // шний раз по спискам).
        g_matrix[i].resize(sink+1);
    }
    edges.resize(n+1);
    path.resize(n+1);
    for (int i = 0; i < m; i++) {
        in >> begin >> end;
        in >> cap;
        edges[begin].push_back(end);
        g_matrix[begin][end] = cap;
        edges[end].push_back(begin);
    }
}

bool ow_graph::bfs() {
    bool visited[sink+1];
    std::fill(visited, visited + sink + 1, false);
    std::queue<int> queue;
    visited[1] = true;
    path[1] = -1;
    queue.push(1);
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (auto & next_vertice : edges[v]) {
            if (!visited[next_vertice] && g_matrix[v][next_vertice]) {
                visited[next_vertice] = true;
                queue.push(next_vertice);
                path[next_vertice] = v;
            }
        }
        if (visited[sink]) break;
    }
    return visited[sink];
}

ull ow_graph::flow_increase() {
    int u;
    ull res = std::numeric_limits<unsigned long long>::max();
    for (int v = sink; v != 1; v = path[v]) {
        u = path[v];
        res = std::min(res, g_matrix[u][v]);
    }
    for (int v = sink; v != 1; v = path[v]) {
        u = path[v];
        g_matrix[u][v] -= res;
        g_matrix[v][u] += res;
    }
    return res;
}

ull ow_graph::max_flow() {
    ull res = 0;
    while(bfs()) {
        res += flow_increase();
    }
    return res;
}