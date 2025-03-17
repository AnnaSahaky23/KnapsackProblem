#ifndef BOUNDEDKNAPSACK_H
#define BOUNDEDKNAPSACK_H
#include <vector>

class BoundedKnapsack
{
    int capacity;
    std::vector<int> weights;
    std::vector<int> bonuses;
    std::vector<int> quantities;
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
        for(int i = 0; i <= quantities[index - 1]; i++)
        {
            if(i*weights[index - 1] <= w)
            {

                memo[index][w] = std::max(memo[index][w], solve(w - i*weights[index - 1], index - 1)+ i*bonuses[index - 1]) ;
            }
            else
            {
                break;
            }
        }
        return memo[index][w];
    }

public:
    BoundedKnapsack(const int capacity, const std::vector<int>& weights, const std::vector<int>& bonuses, const std::vector<int>& quantities):
        capacity(capacity),
        weights(weights),
        bonuses(bonuses),
        quantities(quantities),
        memo(weights.size() + 1, std::vector<int>(capacity + 1, -1))
    {
        solve(capacity, weights.size());
    }

    int get_max_knapsack_bonus() const
    {
        return memo[weights.size()][capacity];
    }
};
#endif //BOUNDEDKNAPSACK_H
