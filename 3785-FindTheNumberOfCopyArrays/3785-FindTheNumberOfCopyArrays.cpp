// Last updated: 1/17/2026, 12:25:52 PM
class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int n = o.size();
        vector<int> d(n - 1);
        for (int i = 1; i < n; i++) d[i - 1] = o[i] - o[i - 1];

        int l = b[0][0], h = b[0][1];
        for (int i = 1; i < n; i++) {
            int nl = max(b[i][0], l + d[i - 1]);
            int nh = min(b[i][1], h + d[i - 1]);
            if (nl > nh) return 0;
            l = nl, h = nh;
        }
        return h - l + 1;
    }
};