// Last updated: 1/17/2026, 12:27:02 PM
class Solution {
public:
    int minOperations(vector<int>&nums) {
          int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                operations += 1;
            }
        }

        for (int i = n - 2; i < n; ++i) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return operations;

    }
};