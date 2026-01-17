// Last updated: 1/17/2026, 12:33:41 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int n=nums.size();
     return nums[n/2] ;      
    }
};