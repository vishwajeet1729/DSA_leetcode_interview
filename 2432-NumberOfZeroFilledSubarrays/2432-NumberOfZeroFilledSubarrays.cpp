// Last updated: 1/17/2026, 12:29:07 PM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
         long long ct=0;
          long long cur=0;
        for(int i=0;i<v.size();){
              
            if(v[i]==0)cur++;
            else {
                  cur=0; 
            }
            ct+=cur;
            i++;

        }
     

     return ct;
    }
};