// Last updated: 1/17/2026, 12:26:57 PM
class Solution {
public:
    static int maximumLength(vector<int>& nums) {
        int n = nums.size();

        // If there are only 2 elements, the answer is always 2
        if (n == 2) return 2;

        // Check if the first number is odd or even
        bool firstIsOdd = nums[0] % 2;

        // Initialize counters
        int evenCount = firstIsOdd ? 0 : 1;
        int oddCount = firstIsOdd ? 1 : 0;
        int alternateCount = 1; // at least one number in alternating sequence

        bool lastParity = firstIsOdd;

        for (int i = 1; i < n; ++i) {
            bool currentIsOdd = nums[i] % 2;

            // Count how many even and odd numbers
            if (currentIsOdd)
                oddCount++;
            else
                evenCount++;

            // Count alternating parity sequence
            if (currentIsOdd != lastParity) {
                alternateCount++;
                lastParity = currentIsOdd;
            }
        }

        // Return the maximum length among even, odd, and alternating sequence
        return max({evenCount, oddCount, alternateCount});
    }
};
