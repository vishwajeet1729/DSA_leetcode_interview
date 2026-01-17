// Last updated: 1/17/2026, 12:25:15 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int duplicateCount = 0;
        for (auto &p : freq) {
            if (p.second > 1) duplicateCount++;
        }

        int ops = 0;
        int i = 0, n = nums.size();

        while (i < n && duplicateCount > 0) {
            for (int k = 0; k < 3 && i < n; k++, i++) {
                int val = nums[i];
                freq[val]--;
                if (freq[val] == 1) {
                    duplicateCount--;  
                }
            }
            ops++;
        }

        if (i < n) return ops;
        return ops + (i == n && ops == 0 ? 1 : 0);
    }
};