// Last updated: 1/17/2026, 12:29:53 PM
class Solution {
public:
    int maximumDifference(vector<int>& v) {
        int n=v.size();
        // cin>>n;
//    vector<int>v(n);  
//   for(auto &it:v)cin>>it;
int ans=-1;
// int 
  int mi=v[0];
  for(int i=1;i<n;++i){
    if(v[i]>mi) ans=max(v[i]-mi,ans);
     mi=min(mi,v[i]);
  }
// cout<<ans<<endl;
return ans;
    }
};