//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     bool isCyclic(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        
        // Compute in-degrees of all nodes
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Push nodes with in-degree 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If count of visited nodes is not equal to V, cycle exists
        return count != V;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends