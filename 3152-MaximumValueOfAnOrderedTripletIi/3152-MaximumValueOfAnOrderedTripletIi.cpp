// Last updated: 1/17/2026, 12:28:16 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        
      int n=v.size();
    vector<int>back(n);
    back[n-1]=v[n-1];
      for(int i=n-2;i>=0;--i){
          back[i]=max(back[i+1],v[i]);
      }
      int cur_mx=v[0]; 
      long long ans=0;
      for(int i=1;i<=n-2;++i){
           ans=max(ans,(cur_mx-v[i])*(long long)back[i+1]);
            cur_mx=max(cur_mx,v[i]);
      }

      return (ans>=0)?ans:0;

    }
};