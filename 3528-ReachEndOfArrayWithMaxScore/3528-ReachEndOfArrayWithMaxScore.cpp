// Last updated: 1/17/2026, 12:26:47 PM
#define ll long long
class Solution {
public:
    long long findMaximumScore(vector<int>&v) {
         
        ll n=v.size();   
       ll ans=0;
     ll index=0;
     if(n==1){
        // cout<<0<<endl;return;
        return 0;
     }
  for(int i=1;i<n;++i){
       if(v[i]>=v[index]){ans+=(i-index)*v[index];index=i;}
  }

  if(index!=n-1){
       ans+=(n-1-index)*v[index];
  }
//   cout<<ans<<endl;
return ans;


    }
};