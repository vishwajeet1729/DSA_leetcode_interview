class Solution {
public:
    int minCost(int n, vector<int>& v) {
        v.push_back(0);
        v.push_back(n);
        sort(v.begin(), v.end());
        int m = v.size();

        vector<vector<int>> dp(m, vector<int>(m, -1)); // DP table initialized to -1

        function<int(int, int)> rec = [&](int l, int r) -> int {
            if (l + 1 == r) return 0; // No cuts possible

            if (dp[l][r] != -1) return dp[l][r]; // Check memoization

            int re = INT_MAX;
            for (int i = l + 1; i < r; ++i) { // Try every possible cut
                int cost = (v[r] - v[l]) + rec(l, i) + rec(i, r);
                re = min(re, cost);
            }
            return dp[l][r] = re;
        };

        return rec(0, m - 1);
    }
};
