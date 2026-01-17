// Last updated: 1/17/2026, 12:33:57 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=1;i<nums.size();++i){
            nums[i]^=nums[i-1];
        }
        return nums[nums.size()-1];
    }
};