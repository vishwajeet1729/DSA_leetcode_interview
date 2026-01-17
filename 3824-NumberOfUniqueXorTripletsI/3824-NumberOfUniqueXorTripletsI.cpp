// Last updated: 1/17/2026, 12:25:37 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n; // There are no triplets if there are fewer than 3 numbers
        }

        int msb = 1;
        int temp = n;
        while (temp > 0) {
            temp >>= 1;
            msb++;
        }

        // You can safely return an integer value here
        return (1 << (msb - 1)); // 2^(msb - 1) without using `pow`
    }
};
