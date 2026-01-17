// Last updated: 1/17/2026, 12:31:45 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
         int open=0,close=0;
int n=s.size();
int ans=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(')open++;
            else if(s[i]==')')open--;
            if(open<0){
                ans++;
                open=0;
            }
        }

return ans+open;
    }
};