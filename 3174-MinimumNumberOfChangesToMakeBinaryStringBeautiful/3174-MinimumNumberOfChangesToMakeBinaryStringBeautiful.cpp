// Last updated: 1/17/2026, 12:28:12 PM
class Solution {
public:
    int minChanges(string s) {
            
            int n=s.size();
             int cur=0;
           int i=0;
int ct=0;
int len=1;
           while(i<n){
             
                if(s[i]!=s[i+1]){
                       
                       if(len%2){
                           ct++;
                           i+=2;
                           len=1;
                       }
                       else {
                           len=1;
                           i++;
                       }

                }
                else {len++;
                    i++;
                }


           }
           if(len!=1)ct++;
       
            return ct;
    }
};