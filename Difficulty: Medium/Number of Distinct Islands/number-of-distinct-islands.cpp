//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
     void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& shape, int basei, int basej, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) 
            return;
        
        vis[i][j] = 1;
        shape.push_back({i - basei, j - basej}); // Normalize coordinates

        // Move in 4 directions
        dfs(i + 1, j, grid, shape, basei, basej, vis); // Down
        dfs(i - 1, j, grid, shape, basei, basej, vis); // Up
        dfs(i, j + 1, grid, shape, basei, basej, vis); // Right
        dfs(i, j - 1, grid, shape, basei, basej, vis); // Left
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> uniqueShapes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, shape, i, j, vis);
                    uniqueShapes.insert(shape); // Store unique island shape
                }
            }
        }
        return uniqueShapes.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends