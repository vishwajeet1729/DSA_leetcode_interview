class Solution {
public:
   int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& grid) {

         vector<vector<pair<int, int>>> v(n);
        for (size_t i = 0; i < grid.size(); i++) {
        int u = grid[i][0], w = grid[i][1], weight = grid[i][2];
        v[u].push_back({w, weight});
        v[w].push_back({u, weight});  // Bidirectional edges
    }
vector<long long> ways(n, 0); 
              vector<long long> cost(n, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    cost[0] = 0;
    q.push({0, 0});
// long lomg ans=0;
ways[0]=1;
    while (!q.empty()) {
        pair<long long, long long> it = q.top();
        q.pop();
        long long curCost = it.first, curNode = it.second;

        if (curCost > cost[curNode]) continue; 
           long long x=v[curNode].size();
        for (size_t i = 0; i < x; i++) {
            pair<long long, long long> negh = v[curNode][i];
            long long newCost = ((long long)curCost + (long long)negh.second);
            if (newCost <cost[negh.first]) {
                cost[negh.first] = newCost;
                ways[negh.first]=ways[curNode];
                q.push({newCost, negh.first});
            }
            else if(newCost ==cost[negh.first])ways[negh.first]=(ways[negh.first]+ways[curNode])%mod;
        }
    }

return ways[n-1];
    }
};