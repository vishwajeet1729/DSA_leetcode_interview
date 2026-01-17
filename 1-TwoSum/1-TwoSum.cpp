// Last updated: 1/17/2026, 12:35:33 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
          int n=v.size();
         map<int,int>m;
         for(int i=0;i<n;++i)m[v[i]]=i;
         for(int i=0;i<n;++i){
               
               int rem=t-v[i];
               if(m.find(rem)!=m.end()&&m[rem]!=i)return {i,m[rem]};
         }
return {};
    }
};