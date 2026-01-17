// Last updated: 1/17/2026, 12:28:26 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //n^2logn eeasy solution 
        // can we optmize it
        //we can optmzie it using unorderes map like n^2
        //can we again optmize it

        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;
       int left=0,right=0,res=0;
        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                res += nums.size() - i;  
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return res;


    }
};