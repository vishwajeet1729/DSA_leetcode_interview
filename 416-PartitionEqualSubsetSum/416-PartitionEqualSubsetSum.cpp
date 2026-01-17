// Last updated: 1/17/2026, 12:32:48 PM
class Solution {
public:
    bool canPartition(vector<int>& v) {
     int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        unordered_set<int> dp;
        dp.insert(0);

        for (int num : v) {
            unordered_set<int> nextDP = dp;
            for (int t : dp) {
                nextDP.insert(t + num);
            }
            dp = nextDP;
        }

        return dp.find(target) != dp.end();

    }
};