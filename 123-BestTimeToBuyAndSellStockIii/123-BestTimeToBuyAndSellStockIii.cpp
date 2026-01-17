// Last updated: 1/17/2026, 12:34:03 PM
#include <vector>
#include <algorithm> // Required for std::max and std::min

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();

        // Base case: If there are no prices or only one price, no profit can be made.
        if (n <= 1) {
            return 0;
        }

        // left_max_profit[i] stores the maximum profit achievable with at most one transaction
        // in the sub-array prices[0...i].
        std::vector<int> left_max_profit(n, 0);
        int min_price = prices[0]; // Keep track of the minimum price encountered from the left

        for (int i = 1; i < n; ++i) {
            min_price = std::min(min_price, prices[i]);
            left_max_profit[i] = std::max(left_max_profit[i - 1], prices[i] - min_price);
        }

        // right_max_profit[i] stores the maximum profit achievable with at most one transaction
        // in the sub-array prices[i...n-1].
        std::vector<int> right_max_profit(n, 0);
        int max_price = prices[n - 1]; // Keep track of the maximum price encountered from the right

        for (int i = n - 2; i >= 0; --i) {
            max_price = std::max(max_price, prices[i]);
            right_max_profit[i] = std::max(right_max_profit[i + 1], max_price - prices[i]);
        }

        // Combine the results:
        // Iterate through all possible split points 'i'.
        // left_max_profit[i] represents the profit from the first transaction ending at or before 'i'.
        // right_max_profit[i] represents the profit from the second transaction starting at or after 'i'.
        // The maximum sum of these two profits across all 'i' will be our answer.
        int total_max_profit = 0;
        for (int i = 0; i < n; ++i) {
            total_max_profit = std::max(total_max_profit, left_max_profit[i] + right_max_profit[i]);
        }

        return total_max_profit;
    }
};