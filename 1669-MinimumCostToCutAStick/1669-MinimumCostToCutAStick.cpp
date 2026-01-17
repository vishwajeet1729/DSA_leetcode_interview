// Last updated: 1/17/2026, 12:30:29 PM
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; ++len) {
            for (int l = 0; l + len < m; ++l) {
                int r = l + len;
                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; ++i) {
                    int cost = cuts[r] - cuts[l] + dp[l][i] + dp[i][r];
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }
        return dp[0][m-1];
    }
};
