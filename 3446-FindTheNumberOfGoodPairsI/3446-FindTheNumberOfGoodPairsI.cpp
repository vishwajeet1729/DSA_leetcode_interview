// Last updated: 1/17/2026, 12:27:10 PM
class Solution {
public:
    int numberOfPairs(vector<int>& v1, vector<int>& v2, int k) {
            
            int n=v1.size();
             int m=v2.size();
             int ct=0;
             for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    if(v1[i]%(v2[j]*k)==0)ct++;
                }
             }
   return ct;

    }
};