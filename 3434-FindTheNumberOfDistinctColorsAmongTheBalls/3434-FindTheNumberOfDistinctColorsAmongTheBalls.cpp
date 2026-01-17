// Last updated: 1/17/2026, 12:27:15 PM
class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        unordered_map<int, int> m; 
        vector<int> ans; 
        map<int, int> color;
        
        for (int i = 0; i < q.size(); ++i) {
            int a = q[i][0];
            int b = q[i][1];
//[1,2,1,2,1]...
            if (m.find(a) != m.end()) {
                int co = m[a];
                color[co]--;
                if (color[co] == 0) {
                    color.erase(co);
                }
            }
                        m[a] = b;
            color[b]++;

            ans.push_back(color.size());
        }

        return ans;
    }
};