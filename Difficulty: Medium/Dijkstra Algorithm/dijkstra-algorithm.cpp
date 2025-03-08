//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &v, int src) {
        // Code here
        int n=v.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0,src});
  vector<int>cost(n,INT_MAX);
  cost[src]=0;
    while(!q.empty()){
           auto it=q.top();
           q.pop();
           int nd=it.second;
           int cur_cost=it.first;
           for(auto xx:v[nd]){
               int negh=xx.first;
               if(cost[negh]>it.first+xx.second){
                 q.push({it.first+xx.second,negh});
                 cost[negh]=it.first+xx.second;
               }
           }

    }
   for(int i=0;i<n;++i)if(cost[i]==INT_MAX)cost[i]=-1;
    // for(auto it:cost)cout<<it<<" ";
    return cost;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends