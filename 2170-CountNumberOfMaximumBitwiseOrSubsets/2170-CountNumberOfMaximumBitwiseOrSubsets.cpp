// Last updated: 1/17/2026, 12:29:49 PM
#include <vector>
#include <numeric> // For std::accumulate or similar for initial max_or

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int max_or = 0;
        // Calculate the maximum possible bitwise OR (by ORing all elements)
        for (int num : nums) {
            max_or |= num;
        }

        int count = 0;
        int n = nums.size();

        // Iterate through all possible non-empty subsets using bit manipulation
        // A mask from 1 to (1 << n) - 1 represents each subset.
        // mask = 0 represents the empty set, which we exclude.
        for (int i = 1; i < (1 << n); ++i) {
            int current_or = 0;
            // For each mask, construct the subset and calculate its bitwise OR
            for (int j = 0; j < n; ++j) {
                // If the j-th bit is set in the current mask, include nums[j]
                if ((i >> j) & 1) {
                    current_or |= nums[j];
                }
            }
            // If the current subset's bitwise OR equals the maximum possible OR,
            // increment the count.
            if (current_or == max_or) {
                count++;
            }
        }

        return count;
    }
};