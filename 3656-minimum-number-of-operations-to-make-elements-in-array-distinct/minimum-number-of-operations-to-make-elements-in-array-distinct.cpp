class Solution {
public:
    int minimumOperations(vector<int>& a) {
         unordered_set<int> s;
    int o = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (s.find(a[i]) != s.end()) {
            o++;
            a.erase(a.begin(), a.begin() + min(3, (int)a.size()));
            i = -1;
            s.clear();
        } else {
            s.insert(a[i]);
        }
    }
    return o;
    }
};