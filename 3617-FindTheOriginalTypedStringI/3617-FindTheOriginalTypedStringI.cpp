// Last updated: 1/17/2026, 12:26:29 PM
class Solution {
public:
    int possibleStringCount(string s) {
       int ct=1;
       int i=0;
       int n=s.size();

        while(i<n){
             
                int j=i+1;
                while(j<n){
                      if(s[j]==s[i]){
                        j++;
                      }
                      else break;
                }
                ct+=j-i-1;
                i=j;        }

return ct;
    }
};