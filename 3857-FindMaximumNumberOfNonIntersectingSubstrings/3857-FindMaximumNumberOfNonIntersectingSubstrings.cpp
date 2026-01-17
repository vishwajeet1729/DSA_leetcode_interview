// Last updated: 1/17/2026, 12:25:30 PM
class Solution {
public:
 
 int maxSubstrings(string w) {
       int n = w.length();
        if (n < 4) return 0;

      vector<int> dp(n + 1, 0);
        vector<int> m(26, -1); 

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];

            if (i >= 4) {
                char c = w[i - 4];
                int x = c - 'a';
                if (m[x] == -1) m[x] = dp[i - 4];
                else m[x] = max(m[x], dp[i - 4]);
            }

            char c = w[i - 1];
            int x = c - 'a';
            if (m[x] != -1) {
                dp[i] = std::max(dp[i], 1 + m[x]);
            }
        }
        return dp[n];
    }
};