// Last updated: 1/17/2026, 12:31:48 PM
#include <vector>
#include <unordered_set> // Using unordered_set for potentially better average case performance for insertion/lookup
#include <set>           // Can also use std::set if strict ordering or guaranteed log complexity is preferred

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        std::unordered_set<int> distinct_ors;
        std::unordered_set<int> current_ors; // Stores ORs of subarrays ending at the previous index

        for (int num : arr) {
            std::unordered_set<int> next_ors;
            // The current number itself is a subarray
            next_ors.insert(num);
            
            // Extend all previous subarrays ending at the previous index with the current number
            for (int prev_or : current_ors) {
                next_ors.insert(prev_or | num);
            }
            
            // Update current_ors for the next iteration
            current_ors = next_ors;
            
            // Add all newly found ORs to the distinct_ors set
            for (int val : current_ors) {
                distinct_ors.insert(val);
            }
        }
        
        return distinct_ors.size();
    }
};