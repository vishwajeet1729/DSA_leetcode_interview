// Last updated: 1/17/2026, 12:30:26 PM
class Solution {
public:
    int m, n;

    void DFS(vector<vector<int>>& g, int i, int j, vector<vector<int>>& vis) {
        if (i >= m || i < 0 || j >= n || j < 0 || vis[i][j] || g[i][j] == 0) return;
        
        vis[i][j] = 1;
        DFS(g, i + 1, j, vis);
        DFS(g, i, j + 1, vis);
        DFS(g, i - 1, j, vis);
        DFS(g, i, j - 1, vis);
    }

    int is(vector<vector<int>>& g) {
        int land = 0;
        vector<vector<int>> vis(m, vector<int>(n)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1 && !vis[i][j]) {
                    DFS(g, i, j, vis);
                    land++;
                }
                
            }
        }
        return land;
    }

    int minDays(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        int ans = is(g);

        if (ans == 0 || ans > 1) {
            return 0;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1) {
                    g[i][j] = 0;
                    int mi = is(g);
                    if (mi > 1 || mi == 0) {
                        return 1;
                    }
                    g[i][j] = 1;
                }
            }
        }

        return 2;
    }
};
