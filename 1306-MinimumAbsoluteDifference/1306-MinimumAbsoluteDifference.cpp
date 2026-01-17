// Last updated: 1/17/2026, 12:31:07 PM
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {

        sort(v.begin(), v.end());

        int mi = v[1] - v[0];
        for (int i = 1; i < v.size(); ++i)
            mi = min(mi, v[i] - v[i - 1]);

        vector<vector<int>> ans;
        for (int i = 0; i < v.size() - 1; ++i) {

            if (v[i + 1] - v[i] == mi) {
                ans.push_back({v[i], v[i + 1]});
            }
        }

        return ans;
    }
};