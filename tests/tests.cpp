#include <iostream>
#include <gtest/gtest.h>

#include "../src/algorithm.h"

TEST(FindOptimalBlockTest, OneRelevantBlock) 
{
    Blocks blocks = {
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", true }, { "school", false }, { "store", false } },
        { { "gym", true }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", true } }
    };
    Reqs reqs = { "gym" };
    EXPECT_EQ(findOptimalBlock(blocks, reqs), 1);
}

TEST(FindOptimalBlockTest, MultipleRelevantBlocks) 
{
    Blocks blocks = {
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", true }, { "school", false }, { "store", false } },
        { { "gym", true }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", true } }
    };
    Reqs reqs = {"gym", "school"};
    EXPECT_EQ(findOptimalBlock(blocks, reqs), 2);
}

TEST(FindOptimalBlockTest, AllRelevantBlocks) 
{
    Blocks blocks = {
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", true }, { "school", false }, { "store", false } },
        { { "gym", true }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", false } },
        { { "gym", false }, { "school", true }, { "store", true } }
    };
    Reqs reqs = {"gym", "school", "store"};
    EXPECT_EQ(findOptimalBlock(blocks, reqs), 3);
}

TEST(FindOptimalBlockTest, BlocksDoNotContainReqs)
{
    Blocks blocks = {
        {{"gym", true}, {"school", false}, {"store", true}},
        {{"gym", false}, {"school", false}, {"store", false}},
        {{"gym", false}, {"school", false}, {"store", false}}
    };
    Reqs reqs = {"gym", "cafe"};

    EXPECT_THROW(findOptimalBlock(blocks, reqs), std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}