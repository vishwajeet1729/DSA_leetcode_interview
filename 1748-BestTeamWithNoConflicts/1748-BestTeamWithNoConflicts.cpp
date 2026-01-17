// Last updated: 1/17/2026, 12:30:23 PM
class Solution {
public:
    int bestTeamScore(vector<int>& sc, vector<int>& ag) {
           
            //lCS
            int n=sc.size();
        vector<pair<int,int>>v;
              for(int i=0;i<n;++i){
                  v.push_back({ag[i],sc[i]});
              }
              sort(v.begin(),v.end());
              
              vector<int>dp(n,1);
              for(int i=0;i<n;++i)dp[i]=v[i].second;
              for(int i=0;i<n;++i){
                  
                  for(int j=0;j<i;++j){
                      if(v[j].second<=v[i].second)dp[i]=max(dp[i],dp[j]+v[i].second);

                  }
              }
                  return *max_element(dp.begin(),dp.end());
    } 
};