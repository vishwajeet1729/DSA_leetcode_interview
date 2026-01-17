// Last updated: 1/17/2026, 12:32:08 PM
class Solution {
public: 
set<string>se;
       void def(string s,int idx){
              
              if(idx==s.size())return;

              if(isalpha(s[idx])){
                    //  se.insert(s);
                     s[idx]^=32;
                     se.insert(s);
                     def(s,idx+1);
                     s[idx]^=32;
                     se.insert(s);

              }def(s,idx+1);
                 
       }  
    vector<string> letterCasePermutation(string s) {
        se.insert(s);
        def(s,0);
           vector<string>v(se.begin(),se.end());
           return v;        

    }
};