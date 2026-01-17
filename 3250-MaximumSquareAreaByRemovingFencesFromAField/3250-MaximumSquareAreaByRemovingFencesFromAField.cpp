// Last updated: 1/17/2026, 12:27:59 PM
class Solution {
public:
    int maximizeSquareArea(int n, int m, vector<int>& href, vector<int>& vref) {
        // int n=4,m=3;
    // vector<int>href={2,3},vref={2};

      href.push_back(1);
      href.push_back(n);
      vref.push_back(1);
      vref.push_back(m);
      sort(href.begin(),href.end());
      sort(vref.begin(),vref.end());
      unordered_set<long long>h,v;
      for(int i=0;i<href.size();++i)for(int j=i+1;j<href.size();++j)h.insert(href[j]-href[i]);

      for(int i=0;i<vref.size();++i)for(int j=i+1;j<vref.size();++j)v.insert(vref[j]-vref[i]);
long long ans=-1;
long long mod=1e9+7;
      for(auto it:v)if(h.find(it)!=h.end())ans=max(ans,it);
      if(ans==-1)return ans;
     return (ans*ans)%mod;
    //   cout<<ans<<endl;
    }
};