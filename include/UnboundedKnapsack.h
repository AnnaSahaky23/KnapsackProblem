#ifndef UNBOUNDED_KNAPSACK_H
#define UNBOUNDED_KNAPSACK_H
#include <vector>

class UnboundedKnapsack
{
    int capacity;
    std::vector<int> weights;
    std::vector<int> bonuses;
    std::vector<std::vector<int>> memo;

    int solve(const int w, const int index)
    {
        if (w == 0 || index == 0)
        {
            memo[index][w] = 0;
            return 0;
        }
        if (memo[index][w] != -1)
        {
            return memo[index][w];
        }
        if (w >= weights[index - 1])
        {
            memo[index][w] = solve(w - weights[index - 1], index) + bonuses[index - 1];
        }
        memo[index][w] = std::max(memo[index][w], solve(w, index - 1));
        return memo[index][w];
    }

public:
    UnboundedKnapsack(const int capacity, const std::vector<int>& weights, const std::vector<int>& bonuses):
        capacity(capacity),
        weights(weights),
        bonuses(bonuses),
        memo(weights.size() + 1, std::vector<int>(capacity + 1, -1))
    {
        solve(capacity, weights.size());
    }

    int get_max_knapsack_bonus() const
    {
        return memo[weights.size()][capacity];
    }
};

#endif //UNBOUNDED_KNAPSACK_H
