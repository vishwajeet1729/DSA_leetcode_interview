// Last updated: 1/17/2026, 12:25:17 PM
class Solution {
public:
    int MOD = 1e9 + 7;
    int n, m;
    int memo[151][151];     
    bool vis[151][151];      

    int rec(int row, int cur_gcd, vector<vector<int>>& mat) {
        if (row == n) {
            return (cur_gcd == 1) ? 1 : 0;
        }

        if (vis[row][cur_gcd]) return memo[row][cur_gcd];
        vis[row][cur_gcd] = true;

        int ways = 0;
        for (int j = 0; j < m; ++j) {
            int new_gcd = (cur_gcd == 0 ? mat[row][j] : __gcd(cur_gcd, mat[row][j]));
            ways = (ways + rec(row + 1, new_gcd, mat)) % MOD;
        }

        return memo[row][cur_gcd] = ways;
    }

    int countCoprime(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        memset(vis, 0, sizeof(vis));
        memset(memo, 0, sizeof(memo));
        return rec(0, 0, mat);
    }
};
