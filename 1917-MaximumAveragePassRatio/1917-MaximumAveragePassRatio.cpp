// Last updated: 1/17/2026, 12:30:08 PM
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        priority_queue<pair<double, int>> q; 
        for (int i = 0; i < c.size(); ++i) {
            double increase = (double)(c[i][0] + 1) / (c[i][1] + 1) - (double)c[i][0] / c[i][1];
            q.push({increase, i});
        }

        while (e--) {
            auto it = q.top();
            q.pop();
            int index = it.second;
            c[index][0]++;
            c[index][1]++;
            double newIncrease = (double)(c[index][0] + 1) / (c[index][1] + 1) - (double)c[index][0] / c[index][1];
            q.push({newIncrease, index});
        }

        double ans = 0;
        for (int i = 0; i < c.size(); ++i) {
            ans += (double)c[i][0] / c[i][1];
        }
        ans /= c.size();
        return ans;
    }
};