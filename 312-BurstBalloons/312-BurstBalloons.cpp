// Last updated: 1/17/2026, 12:33:01 PM
class Solution {
public://same problem minimum cost to cut the stick 1547 reminder
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        function<int(int, int)> solve = [&](int i, int j) -> int {
            if (i + 1 == j) return 0;
            if (dp[i][j] != -1) return dp[i][j];

            int maxCoins = 0;
            for (int k = i + 1; k < j; k++) {
                maxCoins = max(maxCoins, nums[i] * nums[k] * nums[j] + solve(i, k) + solve(k, j));
            }
            return dp[i][j] = maxCoins;
        };

        return solve(0, n + 1);
    }
};