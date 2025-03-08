//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q; // (current_node, parent_node)
        q.push({start, -1});
        visited[start] = true;
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } 
                else if (neighbor != parent) {
                    // If the neighbor is already visited and it's not the parent, a cycle exists.
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends