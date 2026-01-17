// Last updated: 1/17/2026, 12:27:56 PM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
         int n=nums.size();
        int a=nums[0];
        sort(nums.begin()+1,nums.end());
        return a+nums[1]+nums[2];
        
    }
};