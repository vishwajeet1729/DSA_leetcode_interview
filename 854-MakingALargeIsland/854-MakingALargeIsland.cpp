// Last updated: 1/17/2026, 12:31:59 PM

class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        
        // A map to store the size of each island, identified by its unique ID.
        std::unordered_map<int, int> island_sizes;
        // Start island IDs from 2, since the grid uses 0 and 1.
        int island_id = 2;

        // --- Pass 1: Find, measure, and label all initial islands ---
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // If we find an unvisited '1', it's a new island.
                if (grid[r][c] == 1) {
                    // Perform DFS to find its size and "paint" it with the new island_id.
                    int size = paint(r, c, island_id, grid);
                    island_sizes[island_id] = size;
                    island_id++;
                }
            }
        }

        // Initialize max_size. If there are any islands, it's the largest one.
        // If there are no islands at all, it's 0.
        int max_size = 0;
        if (!island_sizes.empty()) {
             for(auto const& [id, size] : island_sizes) {
                max_size = std::max(max_size, size);
            }
        } else {
             // Grid is all zeros, flipping one makes an island of size 1.
            return 1;
        }


        // --- Pass 2: Evaluate each '0' as a potential bridge ---
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // If the cell is a '0', it's a candidate for flipping.
                if (grid[r][c] == 0) {
                    // Use a set to store the unique IDs of neighboring islands.
                    std::unordered_set<int> neighbor_islands;
                    // Check all 4 directions.
                    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for(auto& dir : directions) {
                        int nr = r + dir[0];
                        int nc = c + dir[1];
                        // If the neighbor is valid and is part of an island (not 0)...
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != 0) {
                            neighbor_islands.insert(grid[nr][nc]);
                        }
                    }

                    // Calculate the potential new size. Start with 1 for the '0' itself.
                    int potential_size = 1;
                    for (int id : neighbor_islands) {
                        potential_size += island_sizes[id];
                    }
                    
                    // Update our overall max size.
                    max_size = std::max(max_size, potential_size);
                }
            }
        }
        
        // Edge case: If the grid was all 1s, the loop for 0s won't run.
        // The max size will be n*n from the first pass.
        // The check at the start for an all-zero grid handles that case.
        return max_size;
    }

private:
    // Helper DFS function to "paint" an island with an ID and return its size.
    int paint(int r, int c, int id, std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        // Base case: Check for out of bounds or if it's not an unvisited '1'.
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) {
            return 0;
        }

        // Mark the current cell with the island ID.
        grid[r][c] = id;
        
        // Count this cell (size=1) and recursively call for its 4 neighbors.
        return 1 + paint(r + 1, c, id, grid)
                 + paint(r - 1, c, id, grid)
                 + paint(r, c + 1, id, grid)
                 + paint(r, c - 1, id, grid);
    }
};