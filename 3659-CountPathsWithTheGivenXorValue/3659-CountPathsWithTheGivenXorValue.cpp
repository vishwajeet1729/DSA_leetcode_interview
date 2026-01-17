// Last updated: 1/17/2026, 12:26:09 PM
        int c = 15;
        const int m = 1e9 + 7;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& g, int k) {
        int a = g.size();
        int b = g[0].size();
        int c = 15;

        vector<vector<vector<int>>> dp(a, vector<vector<int>>(b, vector<int>(c + 1, 0)));

        dp[0][0][g[0][0]] = 1;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int x = 0; x < c+1; x++) {
                    if (dp[i][j][x] >=1) {
                        if (j < b-1) {
                            int y = x ^ g[i][j + 1];
                            dp[i][j + 1][y] = (dp[i][j + 1][y] + dp[i][j][x]) % m;
                        }

                        if (i  < a-1) {
                            int y = x ^ g[i + 1][j];
                            dp[i + 1][j][y] = (dp[i + 1][j][y] + dp[i][j][x]) % m;
                        }
                    }
                }
            }
        }

        return dp[a - 1][b - 1][k];
    }
};
