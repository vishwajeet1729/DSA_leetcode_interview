// Last updated: 1/17/2026, 12:30:53 PM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // --- Interviewer Explanation ---
        // "This solution uses the Floyd-Warshall algorithm, which is
        // a Dynamic Programming approach to find all-pairs shortest paths."
        
        // "1. Initialize the distance matrix 'dist'.
        // dist[i][j] will store the shortest path from i to j."
        
        // Use 1e9 as 'infinity' (must be > distanceThreshold)
        int INF = 1e9 + 7; 
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // "The distance from a city to itself is 0."
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // "Load the initial-given edges into the matrix."
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        // --- Interviewer Explanation (The DP part) ---
        // "This is the core of the algorithm. We use three
        // nested loops. The 'k' loop represents the
        // 'intermediate' city we are allowed to travel through."
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // "We check if the path from 'i' to 'j'
                    // is shorter if we go through city 'k'."
                    dist[i][j] = min(dist[i][j], 
                                     dist[i][k] + dist[k][j]);
                }
            }
        }

        // "3. After the DP, 'dist' contains all shortest paths.
        // Now, we just count the reachable cities for each node."
        int min_reachable_count = n;
        int result_city = -1;

        for (int i = 0; i < n; ++i) {
            int current_reachable_count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    current_reachable_count++;
                }
            }
            
            // "We apply the same tie-breaking logic as before."
            if (current_reachable_count <= min_reachable_count) {
                min_reachable_count = current_reachable_count;
                result_city = i;
            }
        }

        return result_city;
    }
};