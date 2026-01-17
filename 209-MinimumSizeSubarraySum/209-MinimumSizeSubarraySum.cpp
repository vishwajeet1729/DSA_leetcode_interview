// Last updated: 1/17/2026, 12:33:29 PM
class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
         int left=0,mi=INT_MAX,sum=0;
         for(int i=0;i<v.size();++i){
            sum+=v[i];
            while(sum>=t){
                 mi=min(mi,i-left+1);
                 sum-=v[left];
                 left++;

            }
         }
return mi!=INT_MAX?mi:0;
    }
};