// Last updated: 1/17/2026, 12:26:50 PM
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());
        
        long long sum = 0;
        int last = INT_MAX;
        
        for (int i = n - 1; i >= 0; i--) {
           
            int currentHeight = min(maximumHeight[i], last - 1);
            
            if (currentHeight < 1) {
                return -1;
            }
            
            sum += currentHeight;
            last = currentHeight;
        }
        
        return sum;
    }
};