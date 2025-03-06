class Solution {
public:
    int n, m;

    void rec(int i, int j, vector<vector<char>>& v) {
        if (i >= n || j >= m || i < 0 || j < 0 || v[i][j] == 'X' || v[i][j] == 'S') 
            return;
        
        v[i][j] = 'S';
        rec(i + 1, j, v);
        rec(i - 1, j, v);
        rec(i, j + 1, v);
        rec(i, j - 1, v);
    }

    void solve(vector<vector<char>>& v) {
        n = v.size();
        if (n == 0) return;
        m = v[0].size();
        for (int i = 0; i < n; ++i) {
            if (v[i][0] == 'O') rec(i, 0, v);
            if (v[i][m - 1] == 'O') rec(i, m - 1, v);
        }

        for (int i = 0; i < m; ++i) {
            if (v[0][i] == 'O') rec(0, i, v);
            if (v[n - 1][i] == 'O') rec(n - 1, i, v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'O') v[i][j] = 'X';
                if (v[i][j] == 'S') v[i][j] = 'O';
            }
        }
    }
};
