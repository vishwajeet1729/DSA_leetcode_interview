// Last updated: 1/17/2026, 12:26:48 PM
class Solution {
public:
    int minFlips(vector<vector<int>>& g) {
         
          int m = g.size();
        int n = g[0].size();
        int hori = 0, verti = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (g[i][j] != g[i][n - 1 - j]) {
                    hori++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                if (g[j][i] != g[m - 1 - j][i]) {
                    verti++;
                }
            }
        }

        return min(hori, verti);
    }
};