#include <iostream>
#include <queue> // For priority_queue
#include <tuple> // To store (time, row, col)
#include <vector>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();

        std::vector<std::vector<int>> min_time(n, std::vector<int>(n, INT_MAX));

        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,

                            std::greater<std::tuple<int, int, int>>> pq;

        min_time[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (time > min_time[r][c]) {
                continue;
            }

            if (r == n - 1 && c == n - 1) {
                return time;
            }
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    int new_time = std::max(time, grid[nr][nc]);

                    if (new_time < min_time[nr][nc]) {
                        min_time[nr][nc] = new_time;
                        pq.push({new_time, nr, nc});
                    }
                }
            }
        }

        return -1; 
    }
};