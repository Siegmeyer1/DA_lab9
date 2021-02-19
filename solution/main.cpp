#include <iostream>
#include "OW_graph.h"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ow_graph graph(std::cin);
    std::cout << graph.max_flow() << '\n';

    return 0;
}