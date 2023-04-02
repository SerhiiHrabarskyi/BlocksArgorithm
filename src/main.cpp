#include <iostream>
#include "algorithm.h"

int main() {
    Blocks blocks = {
        {
            { "gym", false },
            { "school", true },
            { "store", false }
        },
        {
            { "gym", true },
            { "school", false },
            { "store", false }
        },
        {
            { "gym", true },
            { "school", true },
            { "store", false }
        },
        {
            { "gym", false },
            { "school", true },
            { "store", false }
        },
        {
            { "gym", false },
            { "school", true },
            { "store", true }
        }
    };

    Reqs reqs = {"gym", "school", "store"};
    auto optimalBlockIndex = findOptimalBlock(blocks, reqs);
    std::cout << "Optimal block -> " << optimalBlockIndex << std::endl;

    return 0;
}
