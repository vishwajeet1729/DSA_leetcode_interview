// Last updated: 1/17/2026, 12:26:07 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; ++i) { 
            if (nums[i - 1] + nums[i + 1] == nums[i] / 2.0) {
                ++ct;
            }
        }

        return ct;
    }
};