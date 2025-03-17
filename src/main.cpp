#include <iostream>
#include "UnboundedKnapsack.h"

int main()
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {3, 6, 9};
    int capacity = 7;

    std::cout
        << "Max Knapsack Bonus: "
        << UnboundedKnapsack(capacity, weights, bonuses).get_max_knapsack_bonus()
        << std::endl;

    return 0;
}
