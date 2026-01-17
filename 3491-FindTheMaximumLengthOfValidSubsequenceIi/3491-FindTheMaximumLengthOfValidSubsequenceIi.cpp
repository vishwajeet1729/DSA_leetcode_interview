// Last updated: 1/17/2026, 12:26:56 PM
class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
      //   int n, k;
   // cin >> n >> k;
    //vector<int> v(n);
    //for (auto &it : v) cin >> it;
  //    int mx=0;
  int n=v.size();

      vector<vector<int>>dp(n,vector<int>(k,0));
int ans=0;
      for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                 int r=(v[i]+v[j])%k;
                 int len=(dp[j][r]>0)?dp[j][r]+1:2;
                 dp[i][r]=max(dp[i][r],len);
                  ans = max(ans, dp[i][r]);
            }
      }
return ans;
     // cout<<ans<<endl;
    }
};