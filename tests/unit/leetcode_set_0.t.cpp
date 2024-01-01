#include "leetcode_set_0.h"

// std
#include <vector>

// gtest
#include <gtest/gtest.h>


namespace arondina
{
namespace eng
{

TEST(DestroySequentialTargets, testCasesFirstApproach)
{
    DestroySequentialTargets algo;
    EXPECT_EQ(1, algo.first_approach({3,7,8,1,1,5}, 2));
    EXPECT_EQ(1, algo.first_approach({1,3,5,2,4,6}, 2));
    EXPECT_EQ(2, algo.first_approach({6,2,5}, 100));
    EXPECT_EQ(213, algo.first_approach({741,289,294,213,735}, 2));
}

} // eng
} // arondina