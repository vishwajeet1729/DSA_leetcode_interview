// Last updated: 1/17/2026, 12:32:50 PM
class Solution {
public:
    int combinationSum4(vector<int>& v, int t) {
           int n=v.size();
   vector<unsigned long long>dp(t+1,0);
   dp[0]=1;
           for(int i=1;i<=t;++i){
                
           for(int j=0;j<n;++j){
            if(i>=v[j])
               dp[i]+=dp[i-v[j]];
           }

           }
return dp[t];
      
    }
};