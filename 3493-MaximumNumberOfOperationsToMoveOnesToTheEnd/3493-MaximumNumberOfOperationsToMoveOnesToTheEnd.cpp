// Last updated: 1/17/2026, 12:26:55 PM
class Solution {
public:
    int maxOperations(string s) {
        
        int n=s.size();

        int ct=0,cur=0;
        for(int i=0;i<n-1;++i){
              if(s[i]=='1'&&s[i+1]!='1'){
                 cur++;
                 ct+=cur;
              }
              else if(s[i]=='1')cur++;
        }
       return ct;
    }
};