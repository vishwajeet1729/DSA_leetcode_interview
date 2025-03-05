class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
           int n=v.size();
       sort(v.begin(),v.end());
       vector<int>dp(n,1);
       vector<int>prev(n,0);
        for(int i=0;i<n;++i)prev[i]=i;
       for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
                if(v[i]%v[j]==0){
                     if(dp[i]<1+dp[j]){
                         dp[i]=1+dp[j];
                         prev[i]=j;
                     }

                }
        }
       }
        int mx=*max_element(dp.begin(),dp.end());
        int ind=0;
        for(int i=0;i<n;++i){
            if(dp[i]==mx){
                ind=i;break;
            }
        }
       vector<int>ans;
       while(prev[ind]!=ind){
         ans.push_back(v[ind]);
         ind=prev[ind];
       }
      ans.push_back(v[ind]);
    //  for(auto it:ans)cout<<it<<" ";line;     
           return ans;

    }
};