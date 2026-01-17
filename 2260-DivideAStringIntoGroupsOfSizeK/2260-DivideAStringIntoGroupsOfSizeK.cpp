// Last updated: 1/17/2026, 12:29:33 PM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
         int n=s.size();
string ok="";
vector<string>ans;
int sz=0;
         for(int i=0;i<n;++i){
               if(sz==k){
                sz=1;
                     ans.push_back(ok);
                     ok=s[i];
               }
               else {ok+=s[i];sz++;}
         }
        while(ok.size()!=k)ok+=fill;
        ans.push_back(ok);
        return ans;
    }
};