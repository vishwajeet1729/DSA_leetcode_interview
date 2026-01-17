// Last updated: 1/17/2026, 12:32:39 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
        int offset = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * offset + 1, -1)); 
        function<int(int, int)> rec = [&](int ind, int sum) -> int {
            if (ind == n) {
                return sum == target ? 1 : 0;
            }
            if (dp[ind][sum + offset] != -1) return dp[ind][sum + offset];

            return dp[ind][sum + offset] = rec(ind + 1, sum + nums[ind]) + rec(ind + 1, sum - nums[ind]);
        };

        return rec(0, 0);
    }
};