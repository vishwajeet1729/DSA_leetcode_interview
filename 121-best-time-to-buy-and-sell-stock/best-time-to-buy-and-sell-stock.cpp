class Solution {
public:
    int maxProfit(vector<int>& v) {
           int mi=v[0],ans=0;
          for(int i=1;i<v.size();++i){
              mi=min(mi,v[i]);
              ans=max(ans,v[i]-mi);
              
          }
          return ans;
    }
};