class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> m;
        for(int i = 0; i < strs.size(); ++i) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            m[sortedStr].push_back(i);
        }
        vector<vector<string>> v;
        for(auto s : m) {
            vector<string> ans;
            for(auto index : s.second) {
                ans.push_back(strs[index]);
            }
            v.push_back(ans);
        }
        return v;
    }
};