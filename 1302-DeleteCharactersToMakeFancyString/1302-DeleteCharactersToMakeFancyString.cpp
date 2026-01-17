// Last updated: 1/17/2026, 12:31:10 PM
class Solution {
public:
    string makeFancyString(string s) {
        
     string ans="";
     for(int i=0;i<s.size();++i){

        int x=ans.size();
        if(x<2)ans+=s[i];
        else if(ans[x-1]==ans[x-2]&&s[i]==ans[x-1])continue;
        else ans+=s[i];
     }
   
   return ans;
    }
};