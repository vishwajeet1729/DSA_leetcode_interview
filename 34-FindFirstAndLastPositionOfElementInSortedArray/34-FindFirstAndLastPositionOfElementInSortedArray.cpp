// Last updated: 1/17/2026, 12:35:08 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         auto lb = lower_bound(nums.begin(), nums.end(), target);   // first >= target
        if (lb == nums.end() || *lb != target)
            return {-1, -1};  // target not found

        auto ub = upper_bound(nums.begin(), nums.end(), target);   // first > target

        int start = lb - nums.begin();
        int end = ub - nums.begin() - 1;  // last index where nums[i] == target

        return {start, end};
    }
};