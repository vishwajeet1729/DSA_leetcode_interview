// Last updated: 1/17/2026, 12:35:12 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n-1;++i){
  
  if(nums[i]==nums[i+1])continue;
  j++;
  nums[j]=nums[i];

        }
        // if(nums[n-1]!=nums[n-2]){
        //     // j++;
        //     // nums[j]=nums[n-2];
        //     j++;
        //     nums[j]=nums[n-1];
        // }
        // else {
            j++;
            nums[j]=nums[n-1];
        // }
   return j+1;
    }
};