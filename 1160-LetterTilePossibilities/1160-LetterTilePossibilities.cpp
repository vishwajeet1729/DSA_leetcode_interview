// Last updated: 1/17/2026, 12:31:21 PM
class Solution {
public:
map<char,int>m;
      int rec(string t){
              
            int ct=0;

            for(auto &it:m){
                if(it.second<=0)continue;   
                 ct++;
                     it.second--;
                 ct+=rec(t);
                 it.second++;

            }
            return ct;

      }
      //time complexity =N!
      //space complexity=no of character;
    int numTilePossibilities(string t) {
         for(auto it:t)m[it]++;
         return rec(t);
    }
};