// Last updated: 1/17/2026, 12:34:07 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
     int n = v.size();
        vector<int> ans = v.back(); // Initialize ans with the last row of the triangle

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < v[i].size(); ++j) {
                ans[j] = min(ans[j] + v[i][j], ans[j + 1] + v[i][j]);
            }
        }

        return ans[0];
    }
};