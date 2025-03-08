//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& v, int src) {
        // code here
           int n=v.size();
    vector<bool>vis;
      vis.resize(n,0);
       vector<int>ans(n,-1);
// int src=0;
       queue<int>q;
       q.push(src);
      int ct=-1;vis[src]=1;
       while(!q.empty()){
          
        int x=q.size();ct++;
        for(int i=0;i<x;++i){
            int num=q.front();
            ans[num]=ct;
            // vis[num]=1;
            q.pop();
            for(auto negh:v[num]){ if(!vis[negh]){q.push(negh);vis[negh]=1;}}
        }

       }
    //   for(int i=0;i<n;++i){cout<<ans[i]<<" ";}
   return ans;

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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends