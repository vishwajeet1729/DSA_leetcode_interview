// Last updated: 1/17/2026, 12:26:03 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
         int n = nums.size();

    int count = 1; // At least one element will be taken
    int last = nums[0]; // First element is always taken

    for (int i = 1; i < n; ++i) {
        if (nums[i] >= last) {
            // We must take it (merge what came before if needed)
            count++;
            last = nums[i];
        }
        // else: nums[i] < last => can't take this, will be merged
    }

    return count;
    }
};