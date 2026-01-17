// Last updated: 1/17/2026, 12:27:01 PM
class Solution {
public:
    int minimumOperations(vector<int>& v) {
  int ct=0;
        for(int i=0;i<v.size();++i){
            if(v[i]%3!=0)ct++;
        }
        return ct;
    }
};