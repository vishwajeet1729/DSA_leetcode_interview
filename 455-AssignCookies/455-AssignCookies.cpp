// Last updated: 1/17/2026, 12:32:44 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         sort(g.begin(),g.end());
         sort(s.begin(),s.end());
           reverse (g.begin(),g.end());
           reverse(s.begin(),s.end());

           int i=0,j=0;
           int ct=0;
           while(i<g.size()&&j<s.size()){
             if(s[j]>=g[i]){
                i++;
                j++;
                ct++;
             }
             else {
                  i++;
             }


           }
   return ct;

    }
};