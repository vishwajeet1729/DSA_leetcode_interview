// Last updated: 1/17/2026, 12:29:11 PM
#include <vector>
#include <numeric> // For std::accumulate, though XOR sum is manual
#include <algorithm> // For std::min, std::max

class Solution {
public:
    std::vector<std::vector<int>> adj;
    std::vector<int> subtreeXOR;
    std::vector<int> nums_global; // To make nums accessible in DFS
    std::vector<int> tin, tout; // For ancestry checks (time in, time out)
    int timer;

    // DFS to calculate subtree XOR sums and tin/tout times
    void dfs(int u, int p) {
        tin[u] = timer++;
        subtreeXOR[u] = nums_global[u];

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            subtreeXOR[u] ^= subtreeXOR[v];
        }
        tout[u] = timer++;
    }

    // Helper to check if node 'u' is an ancestor of node 'v'
    bool isAncestor(int u, int v) {
        return tin[u] < tin[v] && tout[u] > tout[v];
    }

    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        nums_global = nums; // Copy nums to a member variable for DFS access

        adj.resize(n);
        subtreeXOR.resize(n);
        tin.resize(n);
        tout.resize(n);
        timer = 0;

        // Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Calculate total XOR sum of all nodes
        int totalXOR = 0;
        for (int x : nums) {
            totalXOR ^= x;
        }

        // Perform DFS from root (0) to calculate subtree XOR sums and tin/tout
        dfs(0, -1); // -1 as parent for root

        int minOverallScore = 2e9; // A sufficiently large value

        // Iterate through all possible pairs of edges to remove
        // An edge (u, v) effectively separates subtree rooted at v (assuming v is child of u)
        // We iterate through all possible 'child' nodes v1 and v2 whose edges to parent are cut.
        for (int i = 1; i < n; ++i) { // v1 (node corresponding to first cut edge's child)
            for (int j = i + 1; j < n; ++j) { // v2 (node corresponding to second cut edge's child)
                int xor1, xor2, xor3;

                // Case 1: v1 is an ancestor of v2 (v2's subtree is inside v1's subtree)
                if (isAncestor(i, j)) {
                    xor1 = subtreeXOR[j];                  // Subtree rooted at j
                    xor2 = subtreeXOR[i] ^ subtreeXOR[j];  // Part of i's subtree not containing j
                    xor3 = totalXOR ^ subtreeXOR[i];       // Rest of the tree
                }
                // Case 2: v2 is an ancestor of v1 (v1's subtree is inside v2's subtree)
                else if (isAncestor(j, i)) {
                    xor1 = subtreeXOR[i];                  // Subtree rooted at i
                    xor2 = subtreeXOR[j] ^ subtreeXOR[i];  // Part of j's subtree not containing i
                    xor3 = totalXOR ^ subtreeXOR[j];       // Rest of the tree
                }
                // Case 3: Subtrees are disjoint (neither is an ancestor of the other)
                else {
                    xor1 = subtreeXOR[i];                  // Subtree rooted at i
                    xor2 = subtreeXOR[j];                  // Subtree rooted at j
                    xor3 = totalXOR ^ subtreeXOR[i] ^ subtreeXOR[j]; // Rest of the tree
                }

                int currentMin = std::min({xor1, xor2, xor3});
                int currentMax = std::max({xor1, xor2, xor3});
                minOverallScore = std::min(minOverallScore, currentMax - currentMin);
            }
        }

        return minOverallScore;
    }
};