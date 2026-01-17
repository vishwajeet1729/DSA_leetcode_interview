// Last updated: 1/17/2026, 12:26:27 PM
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& v) {
         
         int n=v.size();
vector<int>ans;
int ct=1;
         for(int i=1;i<n;++i){
              if(v[i-1]<v[i])ct++;
              else {
                ans.push_back(ct);
                ct=1;

              } 

         }
         ans.push_back(ct);

     int mx=0;
     for(int i=0;i<ans.size()-1;++i){
         
         int a=min(ans[i],ans[i+1]);
          mx=max(mx,a);
        //   if(ans[i]%2==0)
          mx=max(mx,ans[i]/2);

     }
// if(ans[ans.size()-1]%2==0)
 mx=max(ans[ans.size()-1]/2,mx);
 return mx;
    }
};