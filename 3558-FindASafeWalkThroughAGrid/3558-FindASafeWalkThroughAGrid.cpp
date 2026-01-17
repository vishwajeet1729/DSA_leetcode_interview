// Last updated: 1/17/2026, 12:26:44 PM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& g, int h) {
        int m = g.size();
        int n = g[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, h - g[0][0]});
                  int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0] = h - g[0][0];
        
        while (!q.empty()) {
            auto [p, curH] = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            if (x == m - 1 && y == n - 1 && curH > 0) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int newX = x + d[i][0], newY = y + d[i][1];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
                    int newH = curH - g[newX][newY];
                    if (newH > 0 && newH > vis[newX][newY]) {
                        vis[newX][newY] = newH;
                        q.push({{newX, newY}, newH});
                    }
                }
            }
        }
        
        return false;
    }
};
