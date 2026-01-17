// Last updated: 1/17/2026, 12:30:07 PM
class Solution {
public:
    int minPairSum(vector<int>& v) {
         sort(v.begin(),v.end());

         int i=0,j=v.size()-1;
         int mx=0;
         while(i<j){
            mx=max(mx,v[i]+v[j]);
            i++;j--;
         }
         return mx;
    }
};