// Last updated: 1/17/2026, 12:29:54 PM
class Solution {
public:
    vector<vector<int>> v;
    vector<int> visited;

const int N=10007;

    bool dfs(int vertex, int destination) {
        if(vertex == destination) return true;
        if(visited[vertex]) return false;
        visited[vertex] = 1;
        bool ans = false;
        for(int i = 0; i < v[vertex].size(); ++i) {
            ans = dfs(v[vertex][i], destination);
            if(ans) break; 
        }
        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
          v.resize(n);
        visited.resize(n, 0);
        for(int i = 0; i < edges.size(); ++i) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(source, destination);
    }
};