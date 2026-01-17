// Last updated: 1/17/2026, 12:34:45 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
         
        vector<vector<int>> a(m, vector<int>(n, 0));
         a[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j - 1 >= 0) a[i][j] += a[i][j - 1];
                if (i - 1 >= 0) a[i][j] += a[i - 1][j];
            }
        }
        return a[m - 1][n - 1];
    }
};