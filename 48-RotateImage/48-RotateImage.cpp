// Last updated: 1/17/2026, 12:34:55 PM
class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        
      int n=v.size(),m=v[0].size();

      for(int i=0;i<n;++i)for(int j=i;j<m;++j)swap(v[i][j],v[j][i]);
    //   return v;
    for(int i=0;i<n;++i)reverse(v[i].begin(),v[i].end());

    }
};