class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& grid, int thresh) {
        vector<vector<pair<int, int>>> v;
          v.resize(n);
         function<int(int)>dijkstra=[&](int node)->int{
              vector<int> cost(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    cost[node] = 0;
    q.push({0, node});

    while (!q.empty()) {
        pair<int, int> it = q.top();
        q.pop();
        int curCost = it.first, curNode = it.second;

        if (curCost > cost[curNode]) continue;  // Skip outdated entries

        for (size_t i = 0; i < v[curNode].size(); i++) {
            pair<int, int> negh = v[curNode][i];
            int newCost = curCost + negh.second;
            if (newCost < cost[negh.first]) {
                cost[negh.first] = newCost;
                q.push({newCost, negh.first});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i != node && cost[i] <= thresh) count++;
    }
    return count;
         };
    v.resize(n);

    for (size_t i = 0; i < grid.size(); i++) {
        int u = grid[i][0], w = grid[i][1], weight = grid[i][2];
        v[u].push_back({w, weight});
        v[w].push_back({u, weight});  // Bidirectional edges
    }

    int minNeighbors = INT_MAX, bestCity = -1;

    for (int i = 0; i < n; ++i) {
        int reachable = dijkstra(i);
        if (reachable < minNeighbors || (reachable == minNeighbors && i > bestCity)) {
            minNeighbors = reachable;
            bestCity = i;
        }
    }
return bestCity;
        
    }
};