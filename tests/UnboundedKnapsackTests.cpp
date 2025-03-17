#include <gtest/gtest.h>
#include "UnboundedKnapsack.h"

TEST(UnboundedKnapsackTest, BasicCase)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {3, 6, 9};
    int capacity = 7;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 21);
}

TEST(UnboundedKnapsackTest, SingleItemMultipleTimes)
{
    std::vector<int> weights = {2};
    std::vector<int> bonuses = {5};
    int capacity = 8;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 20);
}

TEST(UnboundedKnapsackTest, NoItems)
{
    std::vector<int> weights = {};
    std::vector<int> bonuses = {};
    int capacity = 10;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 0);
}

TEST(UnboundedKnapsackTest, ZeroCapacity)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {3, 6, 9};
    int capacity = 0;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 0);
}

TEST(UnboundedKnapsackTest, ExactMatch)
{
    std::vector<int> weights = {2, 3, 5};
    std::vector<int> bonuses = {10, 20, 30};
    int capacity = 5;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 30);
}

TEST(UnboundedKnapsackTest, OptimalSelection)
{
    std::vector<int> weights = {3, 4, 5};
    std::vector<int> bonuses = {30, 40, 50};
    int capacity = 8;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 80);
}

TEST(UnboundedKnapsackTest, LargeCapacitySmallItems)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {1, 2, 3};
    int capacity = 100;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 100);
}

TEST(UnboundedKnapsackTest, LargeNumbers)
{
    std::vector<int> weights = {10, 20, 30, 40, 50};
    std::vector<int> bonuses = {100, 200, 300, 400, 500};
    int capacity = 1000;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 10000);
}

TEST(UnboundedKnapsackTest, ManySmallItems)
{
    std::vector<int> weights(100, 1);
    std::vector<int> bonuses(100, 1);
    int capacity = 500;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 500);
}

TEST(UnboundedKnapsackTest, RandomizedCase)
{
    std::vector<int> weights = {2, 5, 7, 8};
    std::vector<int> bonuses = {5, 11, 13, 17};
    int capacity = 50;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);

    int result = knapsack.get_max_knapsack_bonus();
    EXPECT_GE(result, 100);
    EXPECT_LE(result, 500);
}

// Edge case where weights and bonuses are equal
TEST(UnboundedKnapsackTest, WeightsEqualBonuses)
{
    std::vector<int> weights = {2, 4, 6};
    std::vector<int> bonuses = {2, 4, 6};
    int capacity = 12;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 12);
}

TEST(UnboundedKnapsackTest, OneItemDominates)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {1, 10, 2};
    int capacity = 10;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 50);
}

TEST(UnboundedKnapsackTest, PerformanceTest)
{
    int n = 1000;
    std::vector<int> weights(n);
    std::vector<int> bonuses(n);
    for (int i = 0; i < n; ++i)
    {
        weights[i] = (i % 10) + 1;
        bonuses[i] = (i % 20) + 5;
    }
    int capacity = 5000;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);

    int result = knapsack.get_max_knapsack_bonus();
    EXPECT_GT(result, 50000);
}

TEST(UnboundedKnapsackTest, SmallestCase)
{
    std::vector<int> weights = {1};
    std::vector<int> bonuses = {1};
    int capacity = 1;
    UnboundedKnapsack knapsack(capacity, weights, bonuses);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
