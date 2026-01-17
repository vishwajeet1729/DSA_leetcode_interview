// Last updated: 1/17/2026, 12:32:42 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //  int n=nums.size();
         int ct=0;int mx=INT_MIN;
         for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                ct++;
            }
            else {
                if(ct>mx)mx=ct;
                ct=0;
            }
         }
         mx=max(mx,ct);
         return mx;
    }
};