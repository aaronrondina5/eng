// std
#include <algorithm>
#include <queue>
#include <vector>


// gtest
#include <gtest/gtest.h>

namespace arondina
{
namespace eng
{

TEST(priorityQueueTest, minQueue)
{
    std::vector<int> unordered_v{8, 2, 3, 9, 1, 0, 5, 4, 7, 6};

    auto compare0 = [](int a, int b){ return a > b; };
    std::priority_queue<int, std::vector<int>, decltype(compare0)> pq(compare0);

    for(const int& val : unordered_v)
    {
        pq.push(val);
    }

    std::vector<int> actual(10, -1);
    int i = 0;
    while(!pq.empty())
    {
        actual[i++] = pq.top();
        pq.pop();
    }
    
    std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(expected, actual);
}

TEST(priorityQueueTest, maxQueue)
{
    std::vector<int> unordered_v{8, 2, 3, 9, 1, 0, 5, 4, 7, 6};

    auto compare0 = [](int a, int b){ return a < b; };
    std::priority_queue<int, std::vector<int>, decltype(compare0)> pq(compare0);

    for(const int& val : unordered_v)
    {
        pq.push(val);
    }

    std::vector<int> actual(10, -1);
    int i = 0;
    while(!pq.empty())
    {
        actual[i++] = pq.top();
        pq.pop();
    }
    
    std::vector<int> expected{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(expected, actual);
}

TEST(vectorTest, sortAscending)
{
    std::vector<int> unordered_v{8, 2, 3, 9, 1, 0, 5, 4, 7, 6};
    std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto compare = [](int a, int b){ return a < b; };

    std::sort(unordered_v.begin(), unordered_v.end(), compare);
  
    EXPECT_EQ(expected, unordered_v);
}

TEST(vectorTest, sortDescending)
{
    std::vector<int> unordered_v{8, 2, 3, 9, 1, 0, 5, 4, 7, 6};
    std::vector<int> expected{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    auto compare = [](int a, int b){ return a > b; };

    std::sort(unordered_v.begin(), unordered_v.end(), compare);
  
    EXPECT_EQ(expected, unordered_v);
}

} // eng
} // arondina