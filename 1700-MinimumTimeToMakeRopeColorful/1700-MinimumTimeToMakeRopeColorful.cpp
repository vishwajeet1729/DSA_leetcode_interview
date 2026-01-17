// Last updated: 1/17/2026, 12:30:24 PM
class Solution {
public:
    int minCost(string color, vector<int>& time) {
          int n = color.size();
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (color[i] == color[i - 1]) {
            if (time[i] < time[i - 1]) {
                ans += time[i];
                time[i] = time[i - 1]; 
            } else {
                ans += time[i - 1];
            }
        }
    }
return ans;
    // cout << ans << endl;
    }
};