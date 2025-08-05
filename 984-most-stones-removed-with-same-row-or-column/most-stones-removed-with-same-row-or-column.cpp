#include <iostream>
#include <vector>
#include <numeric> // For std::iota
#include <unordered_map>
#include <unordered_set>

// A standard Disjoint Set Union (DSU) or Union-Find implementation.
class DSU {
public:
    // The parent array stores the root of each element's set.
    std::vector<int> parent;
    
    // Initialize the DSU. Each element is its own parent initially.
    DSU(int n) {
        parent.resize(n);
        // std::iota fills the vector with 0, 1, 2, ...
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Find the root of the set containing element 'i', with path compression.
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        // Path Compression: Set the parent of 'i' directly to the root.
        return parent[i] = find(parent[i]);
    }

    // Union the sets containing elements 'i' and 'j'.
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // A simple union: make root of i point to root of j.
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        // The maximum coordinate is 10000. We need space for rows (0-10000)
        // and columns (we'll map them to 10001-20001).
        // So, a size of 20002 is sufficient.
        DSU dsu(20002);

        // --- Step 1: Union rows and columns for each stone ---
        for (const auto& stone : stones) {
            int row = stone[0];
            // Map column to a different range to avoid collisions with row numbers.
            int col = stone[1] + 10001; 
            dsu.unite(row, col);
        }

        // --- Step 2: Count the number of distinct components (islands) ---
        // We only care about components that actually contain stones.
        // We find the root of each stone's component and count the unique roots.
        std::unordered_set<int> unique_components;
        for (const auto& stone : stones) {
            // A stone at (row, col) belongs to the component identified by the root of its row.
            // (The root of its column would be the same after the union operation).
            unique_components.insert(dsu.find(stone[0]));
        }

        int num_islands = unique_components.size();
        int total_stones = stones.size();

        // --- Step 3: Calculate the final answer ---
        // Max removable stones = Total Stones - Number of Islands
        return total_stones - num_islands;
    }
};