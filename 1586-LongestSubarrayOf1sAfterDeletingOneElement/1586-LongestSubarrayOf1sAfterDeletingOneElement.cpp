// Last updated: 1/17/2026, 12:30:39 PM
class Solution {
public:
    int longestSubarray(vector<int>& v) {
         int i = 0, j = 0;
    int zero = 0, ans = 0;
int n=v.size();
    while (j < n) {
        if (v[j] == 0) zero++;

        while (zero > 1) {
            if (v[i] == 0) zero--;
            i++;
        }
        ans = max(ans, j - i);  
        j++;
    }
    return ans;
    }
};