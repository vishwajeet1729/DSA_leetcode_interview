// Last updated: 1/17/2026, 12:27:20 PM
class Solution {
public:
    int minimumChairs(string s) {
        
      int n=s.size();

      int ct=0;
      int mx=0;
      for(int i=0;i<n;++i){
        if(s[i]=='E')ct++;
        else ct--;
        mx=max(mx,ct);
      }
return mx;

    }
};