// Last updated: 1/17/2026, 12:26:32 PM
#define db double
#define psd pair<string,db>
class Solution {
public:
   
    
    unordered_map<string, vector<psd>> build(vector<vector<string>>& p, vector<db>& r) {
        unordered_map<string, vector<psd>> g;
        for (int i = 0; i < p.size(); ++i) {
            string a = p[i][0], b = p[i][1];
            db x = r[i];
            g[a].push_back({b, x});
            g[b].push_back({a, 1.0 / x});
        }
        return g;
    }

    unordered_map<string, db> bfs(unordered_map<string, vector<psd>>& g, string s) {
        queue<psd> q;
        unordered_map<string, db> d;
        
        q.push({s, 1.0});
        d[s] = 1.0;

        while (!q.empty()) {
            auto [u, x] = q.front(); q.pop();
            for (auto& [v, y] : g[u]) {
                db z = x * y;
                if (z > d[v]) {
                    d[v] = z;
                    q.push({v, z});
                }
            }
        }
        return d;
    }

    double maxAmount(string s, vector<vector<string>>& p1, vector<db>& r1, vector<vector<string>>& p2, vector<db>& r2) {
        auto g1 = build(p1, r1);
        auto d1 = bfs(g1, s);
        
        auto g2 = build(p2, r2);
        db res = 0.0;

        for(auto it:d1){
              auto d2=bfs(g2,it.first);
            res=max(res,it.second*d2[s]);
        }
        return res;
    }
};