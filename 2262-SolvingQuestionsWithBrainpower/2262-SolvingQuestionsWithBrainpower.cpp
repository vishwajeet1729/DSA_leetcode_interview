// Last updated: 1/17/2026, 12:29:32 PM
class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
int n=v.size();
         vector<long long>dp(n+1,0);

    for(int i=n-1;i>=0;--i){
          long long cur_ans=0; 
          long long take_cur=0;
          take_cur+=v[i][0];
          if(i+v[i][1]+1<n)take_cur+=dp[i+v[i][1]+1];
          long long take_notCur=0;
        take_notCur+=dp[i+1];
        dp[i]=max(take_cur,take_notCur);
    }
    return dp[0];
    }
};