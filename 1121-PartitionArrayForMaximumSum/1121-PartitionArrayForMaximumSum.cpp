// Last updated: 1/17/2026, 12:31:24 PM
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
          int n=v.size();    
          vector<int>dp(501,-1);       
      function<int(int)>rec=[&](int ind)->int{
        if(ind>=n)return 0;
        int cost=0;
        int mx=-1;
        int re=INT_MIN;
        if(dp[ind]!=-1)return dp[ind];
    for(int i=ind;i<n&&i<ind+k;++i)
          {   mx=max(mx,v[i]);
              cost=mx*(i-ind+1)+rec(i+1);
             re=max(re,cost);
          }
          return dp[ind]=re;
      };
    return rec(0);
    }
};