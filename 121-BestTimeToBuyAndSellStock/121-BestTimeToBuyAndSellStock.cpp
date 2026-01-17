// Last updated: 1/17/2026, 12:34:05 PM
class Solution {
public:
    int maxProfit(vector<int>& v) {
          int ans=0;
          int mi=v[0];
          for(int i=1;i<v.size();++i){
               mi=min(mi,v[i]);
               ans=max(ans,v[i]-mi);

          }
          return ans;
    }
};