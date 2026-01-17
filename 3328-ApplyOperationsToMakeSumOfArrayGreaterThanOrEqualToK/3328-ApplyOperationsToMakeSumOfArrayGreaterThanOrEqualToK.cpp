// Last updated: 1/17/2026, 12:27:43 PM
class Solution {
public:
    int minOperations(int k) {
    if (k == 1) return 0;
        
        int ans = 1e9;
        
        for (int i = 1; i <= k / 2; i++) {
            int temp = ceil(k / static_cast<double>(i));
            int m = (i - 1) + (temp - 1);
            ans = std::min(m, ans);
        }
        
        return ans;

    }
};