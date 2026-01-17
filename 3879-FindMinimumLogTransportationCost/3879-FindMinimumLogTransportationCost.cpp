// Last updated: 1/17/2026, 12:25:25 PM
class Solution {
public:
   long long minCuttingCost(int n, int m, int k) {
        long long ct = 0;

        if (n > k) {
           ct += (1LL)*(n - k) * k;
        }

        if (m > k) {
           ct += (1LL)*(m - k) * k;
        }

        return ct;
    }

        
    
};