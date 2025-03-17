#include <gtest/gtest.h>
#include "BoundedKnapsack.h"

TEST(BoundedKnapsackTest, BasicCase)
{
    std::vector<int> weights = {1, 2, 3, 6};
    std::vector<int> bonuses = {1, 2, 15, 20};
    std::vector<int> quantities = {1, 1, 2, 1};
    int capacity = 6;
    BoundedKnapsack knapsack(capacity, weights, bonuses, quantities);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 30);
}

TEST(BoundedKnapsackTest, SingleItemMultipleTimes)
{
    std::vector<int> weights = {2};
    std::vector<int> bonuses = {5};
    std::vector<int> quantities = {2};
    int capacity = 8;
    BoundedKnapsack knapsack(capacity, weights, bonuses, quantities);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 10);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
