#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;

        // {elevation, x, y}
        pq.push({grid[0][0], 0, 0});
        vector<int> dirs = {0,1,0,-1,0};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n-1 && y == n-1) return t;  // reached destination
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (int k=0; k<4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k+1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; // unreachable (theoretically never happens)
    }
};
