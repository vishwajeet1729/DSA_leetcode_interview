class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& a) {
           int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

         int n = a.size(), m = a[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    vector<vector<int>> c(n, vector<int>(m, INT_MAX));
    
    q.push({0, {0, 0}});
    c[0][0] = 0;

    while (!q.empty()) {
        auto [e, p] = q.top(); q.pop();
        int x = p.first, y = p.second;
        if (x == n - 1 && y == m - 1) return e;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int ne = max(e, abs(a[x][y] - a[nx][ny]));
                if (ne < c[nx][ny]) {
                    c[nx][ny] = ne;
                    q.push({ne, {nx, ny}});
                }
            }
        }
    }

    return -1;
    }
};