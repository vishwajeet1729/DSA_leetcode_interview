// Last updated: 1/17/2026, 12:32:06 PM
class Solution {
public:
    vector<int> s1, s2, vis;
    vector<vector<int>> v;

    void dfs(int node, bool turn) {
        if (vis[node]) return;
        
        if (turn) s1.push_back(node);
        else s2.push_back(node);
        
        vis[node] = 1;

        for (int neighbor : v[node]) {
            if (!vis[neighbor]) 
                dfs(neighbor, !turn);
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        v = graph;
        int n = v.size();
        vis.assign(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                s1.clear();
                s2.clear();
                dfs(i, true);
                                for (int i = 0; i < s1.size(); ++i) {
                    for (int j = i + 1; j < s1.size(); ++j) {
                        for (int neighbor : v[s1[i]]) {
                            if (neighbor == s1[j]) return false;
                        }
                    }
                }
                for (int i = 0; i < s2.size(); ++i) {
                    for (int j = i + 1; j < s2.size(); ++j) {
                        for (int neighbor : v[s2[i]]) {
                            if (neighbor == s2[j]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
