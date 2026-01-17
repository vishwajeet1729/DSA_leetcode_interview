// Last updated: 1/17/2026, 12:33:49 PM
class Solution {
public:
    int maxProduct(vector<int>& v) {
        int r=v[0];
  int imax=v[0],imin=v[0];
  for(int i=1;i<v.size();i++){
        
        if(v[i]<0)swap(imax,imin);
        imax=max(v[i],imax*v[i]);
        imin=min(v[i],imin*v[i]);
        r=max(r,imax);

  }
  return r;
    }
};