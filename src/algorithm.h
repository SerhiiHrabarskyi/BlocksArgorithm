#ifndef BLOCKSALGORITHM_ALGORITHM_H
#define BLOCKSALGORITHM_ALGORITHM_H

#include <map>
#include <string>
#include <vector>

using Block = std::map<std::string, bool>;
using Blocks = std::vector<Block>;
using Reqs = std::vector<std::string>;

size_t findOptimalBlock(const Blocks& blocks, const Reqs& reqs);

#endif //BLOCKSALGORITHM_ALGORITHM_H
