// Last updated: 1/17/2026, 12:27:31 PM
class Solution {
public:
    bool is_prime(int num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int mx = -1, mi = 101; // Initialize with invalid values
        for (int i = 0; i < nums.size(); ++i) {
            if (is_prime(nums[i])) {
                mx = max(mx, i);
                mi = min(mi, i);
            }
        }
        if (mx == -1 && mi == 101) // If no prime numbers found
            return 0;
        return mx - mi;
    }
};