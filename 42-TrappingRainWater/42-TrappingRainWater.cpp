// Last updated: 1/17/2026, 12:34:59 PM
class Solution {
public:
    int trap(vector<int>& v) {
            
          int n=v.size();

          int back[n];
          int ans=0;
          back[n-1]=v[n-1];
          for(int i=n-2;i>=0;--i){
                 back[i]=max(v[i],back[i+1]);
          }
          int mx=v[0];
          for(int i=1;i<n-1;++i){
            mx=max(mx,v[i]);
            int mi=min(mx,back[i+1]);
            int tot=mi;
            ans+=(v[i]<mi)?(mi-v[i]):0;


          }
              
        return ans;


    }
};