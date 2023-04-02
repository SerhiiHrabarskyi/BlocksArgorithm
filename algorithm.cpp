#include "algorithm.h"

#include <algorithm>
#include <stdexcept>
#include <limits>

using Distances = std::vector<size_t>;

size_t findOptimalBlock(const Blocks& blocks, const Reqs& reqs)
{
    static const size_t maxDistValue = std::numeric_limits<size_t>::max();

    // Here we can use std::map<std::string, size_t> for distances
    // In this case, the code will be clearer, but it will work much slower
    Distances currDistances(reqs.size(), maxDistValue);
    std::vector<Distances> blocksDistances(blocks.size(), std::vector(reqs.size(), maxDistValue));

    auto processBlock = [&](size_t blockIndex) {
        for (auto& currDistance : currDistances)
            if (currDistance != maxDistValue)
                currDistance++;

        for (size_t i = 0; i < reqs.size(); i++)
        {
            if (blocks[blockIndex].at(reqs[i]))
                currDistances[i] = 0;

            if (currDistances[i] < blocksDistances[blockIndex][i])
                blocksDistances[blockIndex][i] = currDistances[i];
        }
    };

    // process blocks
    for (size_t i = 0; i < blocks.size(); i++)
        processBlock(i);

    if (std::find(currDistances.begin(), currDistances.end(), maxDistValue) != currDistances.end())
        throw std::runtime_error("None of the blocks contain the required buildings");

    // clear currDistances
    std::fill(currDistances.begin(), currDistances.end(), maxDistValue);

    // process blocks in reverse order
    for (size_t i = blocks.size(); i --> 0 ;)
        processBlock(i);

    size_t optimalBlockIndex = 0, minDistance = maxDistValue;

    for (size_t i = 0; i < blocksDistances.size(); i++)
    {
        const auto maxBlockDistance = *std::max_element(blocksDistances[i].begin(), blocksDistances[i].end());
        if (maxBlockDistance < minDistance)
        {
            optimalBlockIndex = i;
            minDistance = maxBlockDistance;
        }
    }

    return optimalBlockIndex;
}