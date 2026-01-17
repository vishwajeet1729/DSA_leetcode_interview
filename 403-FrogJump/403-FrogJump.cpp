// Last updated: 1/17/2026, 12:32:49 PM
class Solution {
public:
    bool canCross(vector<int>& s) {
   int n = s.size();
        unordered_map<int, set<int>> m; 
        unordered_map<int, int> ex;   
        
        m[s[0]].insert(0); 
        for (int i = 0; i < n; ++i) ex[s[i]]++;
        
        for (int i = 0; i < n; ++i) {
            set<int> demo = m[s[i]]; 
            for (int jump : demo) {
                if (ex.find(s[i] + jump + 1) != ex.end()) {
                    m[s[i] + jump + 1].insert(jump + 1);
                }
                if (ex.find(s[i] + jump) != ex.end()) {
                    m[s[i] + jump].insert(jump);
                }
                if (jump - 1 > 0 && ex.find(s[i] + jump - 1) != ex.end()) {
                    m[s[i] + jump - 1].insert(jump - 1);
                }
            }
        }
        
        return !m[s[n - 1]].empty();

    }
};