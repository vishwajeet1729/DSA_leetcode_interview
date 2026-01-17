// Last updated: 1/17/2026, 12:31:43 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        int n = v.size();
        int ct = 0;
        unordered_map<int, int> count;
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += v[i];
            if (sum == goal)
                ct++;
            if (count.find(sum - goal) != count.end())
                ct += count[sum - goal];
            count[sum]++;
        }
        
        return ct;
    }
};
