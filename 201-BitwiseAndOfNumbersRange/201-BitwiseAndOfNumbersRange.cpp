// Last updated: 1/17/2026, 12:33:34 PM
class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        // Initialize result
        int result = 0;
        
        // Find the common leftmost bits between l and r
        while (l != r) {
            // Right shift both l and r
            l >>= 1;
            r >>= 1;
            
            // Increment result to count the number of right shifts
            result++;
        }
        
        // Left shift l by the count of right shifts to restore the common leftmost bits
        return l << result;
    }
};
