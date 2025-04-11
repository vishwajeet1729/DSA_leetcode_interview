class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        function<bool(int, int)> rec = [&](int ind1, int ind2) -> bool {
            if (ind1 == n1 && ind2 == n2) return true;  // Both strings are completely matched
            if (ind2 == n2) return false;  // Pattern is exhausted but string is not
            if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

            bool ans = false;

            // Match single character
            bool firstMatch = (ind1 < n1 && (p[ind2] == s[ind1] || p[ind2] == '.'));

            // Handle '*' wildcard
            if (ind2 + 1 < n2 && p[ind2 + 1] == '*') {
                ans = rec(ind1, ind2 + 2) || (firstMatch && rec(ind1 + 1, ind2));
            } else {
                ans = firstMatch && rec(ind1 + 1, ind2 + 1);
            }

            return dp[ind1][ind2] = ans;
        };

        return rec(0, 0);
    }
};
