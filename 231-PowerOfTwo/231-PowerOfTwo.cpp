// Last updated: 1/17/2026, 12:33:19 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)return 0;
        return !(n&(n-1));
    }
};