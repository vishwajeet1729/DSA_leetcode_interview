// Last updated: 1/17/2026, 12:33:07 PM
class Solution {
public:
    int countValidNeighbors(const vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, // Left, Right
            {1, -1},  {1, 0},  {1, 1} // Bottom-left, Bottom, Bottom-right
        };

        for (const auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                count += grid[new_i][new_j]; // Add the value of the valid neighbor
            }
        }

        return count;
    }

    void gameOfLife(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> temp(m, vector<int>(n)); // Temporary matrix to store results

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int ct = countValidNeighbors(v, i, j);
                if (v[i][j] == 1) {
                    if (ct < 2)
                        temp[i][j] = 0;
                    else if (ct == 2 || ct == 3)
                        temp[i][j] = 1;
                    else
                        temp[i][j] = 0;
                } else if (v[i][j] == 0 && ct == 3)
                    temp[i][j] = 1;
                else
                    temp[i][j] = 0;
            }
        }
        v = temp;
    }
};
