// Last updated: 1/17/2026, 12:27:13 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int i, vector<int>& nums, vector<long long>& freq, vector<long long>& dp) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        long long take = 1LL * nums[i] * freq[i];

        // use lower_bound to find next index j where nums[j] > nums[i] + 2
        int j = lower_bound(nums.begin(), nums.end(), nums[i] + 3) - nums.begin();

        take += solve(j, nums, freq, dp);

        long long skip = solve(i + 1, nums, freq, dp);

        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> freqMap;
        for (int x : power) freqMap[x]++;

        vector<int> nums;
        vector<long long> freq;
        for (auto& [x, f] : freqMap) {
            nums.push_back(x);
            freq.push_back(f);
        }

        int n = nums.size();
        vector<long long> dp(n, -1);

        return solve(0, nums, freq, dp);
    }
};

// int main() {
//     Solution s;
//     vector<int> power = {5,9,2,10,2,7,10,9,3,8};
//     cout << s.maximumTotalDamage(power) << endl;
// }
