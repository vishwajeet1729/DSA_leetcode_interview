// Last updated: 1/17/2026, 12:28:01 PM
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
     sort(nums.begin(), nums.end());
        int n = nums.size();

        // If the smallest element is distinct, return 1
        if (n > 2 && nums[0] != nums[1])
            return 1;

        // Calculate the GCD of the array elements
        int arrayGCD = nums[0];
        for (auto num : nums) {
            arrayGCD = std::gcd(arrayGCD, num);
        }

        // Count occurrences of GCD in the array
        int gcdCount = 0;
        for (auto num : nums)
            if (num == arrayGCD)
                gcdCount++;

        // Return the minimum array length based on occurrences of GCD
        return std::max(1, (gcdCount + 1) / 2);
    }
};