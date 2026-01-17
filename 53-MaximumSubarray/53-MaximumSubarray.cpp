// Last updated: 1/17/2026, 12:34:51 PM
class Solution {
public:
    int maxSubArray(vector<int>& v) {
      int sum=v[0],mx=v[0],st=0,en=0;
int n=v.size();
      for(int i=1;i<n;++i){
            
        if(v[i]+sum>v[i]){
            sum+=v[i];
            
        }
        else sum=v[i];
        mx=max(mx,sum);

      }
      return mx;
    }
};
