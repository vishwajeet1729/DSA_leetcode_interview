// Last updated: 1/17/2026, 12:27:30 PM
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
 
        long long sum=0;
        long long ct=1;
        int i=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){ct++;i++;}
            else {
                i++;
                sum+=ct*(ct+1)/2;
                ct=1;
            }
        }
        if(ct!=1)sum+=ct*(ct+1)/2;
        if(ct==1)sum++;
        return sum;


    }
};