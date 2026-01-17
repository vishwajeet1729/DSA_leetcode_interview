// Last updated: 1/17/2026, 12:30:58 PM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n%2)v.push_back(0);
        int i=1;
      while(i<=n/2){
         v.push_back(-i);v.push_back(i);
         i++;
      }
      return v;
    }
};