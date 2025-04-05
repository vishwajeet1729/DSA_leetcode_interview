class Solution {
public:
int backtrack(vector<int>& nums, int index, int xor_sum) {
        if (index == nums.size()) {
            return xor_sum;
        }
        // Include the current element
        int include = backtrack(nums, index + 1, xor_sum ^ nums[index]);
        // Exclude the current element
        int exclude = backtrack(nums, index + 1, xor_sum);
        
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
         return backtrack(nums, 0, 0);
    }
};