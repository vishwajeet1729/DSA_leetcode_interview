// Last updated: 1/17/2026, 12:33:39 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};