// Last updated: 1/17/2026, 12:28:32 PM
class Solution {
public:
    int countSeniors(vector<string>& d) {
              int ct=0;
              int n=d.size();
              for(int i=0;i<n;++i){
                int a=d[i][11]-'0';
                int b=d[i][12]-'0';
                int x=a*10+b;
                if(x>60)ct++;
              }
   return ct;
    }
};