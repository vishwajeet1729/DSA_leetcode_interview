// Last updated: 1/17/2026, 12:29:45 PM
class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
          //aage wale k times 
          // piche wale k-1 times
        int n=t.size(),sum=0;
          for(int i=0;i<n;++i){
                // if(i==k)continue;
                if(i<=k){
                      if(t[i]>=t[k])sum+=t[k];
                      else sum+=t[i];
                }
                else if(t[i]>=t[k])sum+=t[k]-1;
                else sum+=t[i];

          }
          return sum;
    }
};