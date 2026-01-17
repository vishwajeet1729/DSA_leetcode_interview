// Last updated: 1/17/2026, 12:33:43 PM
class Solution {
public:
    vector<int> twoSum(vector<int>v, int op) {
         

         int n=v.size();
         int i=0,j=n-1;
         while(i<j){
             
             if(v[i]+v[j]<op){
                i++;
             }
             else if(v[i]+v[j]>op)j--;
             else return {i+1,j+1};
         }
        return {};
    }
};