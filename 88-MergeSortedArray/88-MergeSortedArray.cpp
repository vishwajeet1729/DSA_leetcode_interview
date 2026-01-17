// Last updated: 1/17/2026, 12:34:25 PM
class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        
//   vector<int>re;
int j=0;
  for(int i=m;i<v1.size()&&j<n;++i){
      if(v1[i]==0){
          v1[i]=v2[j];
          j++;
      }
  }
  sort(v1.begin(),v1.end());
    }
};