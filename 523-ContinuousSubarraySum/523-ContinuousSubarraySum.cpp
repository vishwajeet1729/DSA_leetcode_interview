// Last updated: 1/17/2026, 12:32:34 PM
class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
         int n=v.size();
      map<int,int>m;
      m[0]=-1;
      int pref=0;
      for(int i=0;i<n;++i){
        pref+=v[i];
        int rem=pref%k;
        
        if(m.find(rem)!=m.end()&&i-m[rem]>1){
          return 1;
        }
       if(m.find(rem)==m.end()) m[pref%k]=i;
      }
      return 0;
    }
};