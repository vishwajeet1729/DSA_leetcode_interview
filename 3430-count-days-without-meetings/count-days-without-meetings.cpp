class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        if (n == 0) return days; 

        sort(meetings.begin(), meetings.end());

        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        
        for (int i = 1; i < n; ++i) {
            if (meetings[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }

        int ans = 0;

        if (merged[0][0] > 1) {
            ans += merged[0][0] - 1;
        }

        for (int i = 1; i < merged.size(); ++i) {
            ans += merged[i][0] - merged[i-1][1] - 1;
        }

        if (merged.back()[1] < days) {
            ans += days - merged.back()[1];
        }

        return ans;
    }
};