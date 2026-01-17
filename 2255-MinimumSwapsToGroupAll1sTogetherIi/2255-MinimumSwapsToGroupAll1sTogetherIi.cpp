// Last updated: 1/17/2026, 12:29:34 PM
class Solution {
public:
    int minSwaps(vector<int>& v) {
          
          int n=v.size();
           vector<int>s=v;
              int k=0;
              for(int i=0;i<n;++i)k+=v[i];
              for(int i=0;i<k;++i)s.push_back(v[i]);
         int ans=0;
               for(int i=0;i<k;++i)ans+=v[i];
                int mx=ans;

                for(int i=k;i<s.size();++i){
                     ans+=s[i];
                     ans-=s[i-k];
                     mx=max(ans,mx);

                }
                      return k-mx;
    }
};