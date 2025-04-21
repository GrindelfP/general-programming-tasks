#include "container-utils.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    std::vector<int> vec = {1, 2, 3, 4, 4, 4, 5, 6, 7};
    auto start = vec.begin();
    auto fin = vec.end();

    // ============ //
    // DREMOVE TEST //
    // ============ //
    auto dremovedVector = dremove(start, fin, 4);
    std::cout << *dremovedVector << std::endl;

    return 0;
}
