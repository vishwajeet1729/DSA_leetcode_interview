// Last updated: 1/17/2026, 12:32:20 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
         int n=v.size();
   vector<int>dp(n,1);
   vector<int>ct(n,1);
   
   for(int i=0;i<n;++i){
       for(int j=0;j<i;++j){
          
        if(v[i]>v[j]){
             if(dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                  ct[i]=ct[j];
             }
             else if(dp[i]==dp[j]+1)ct[i]+=ct[j];
        }      
       }
   }
   int cc=0;
   int mx=*max_element(dp.begin(),dp.end());
   for(int i=0;i<n;++i)if(dp[i]==mx)cc+=ct[i];
//    cout<<cc<<endl;
      return cc;
    }
};