// Last updated: 1/17/2026, 12:34:34 PM
class Solution {
public:
    void sortColors(vector<int>& v) {
          int n;
        //   vector<int>v={2,0,1};
          n=v.size();


          int i=0,j=0;
          int k=n-1;
            
          while(i<=j&&j<=k&&k>=0&&j<n){
                 
            if(v[i]==0){i++;j++;}
            else if(v[k]==2)k--;
            else if(v[j]==0)swap(v[i],v[j]);
            else if(v[j]==2)swap(v[k],v[j]);
            else j++;

          }
        //   return v;
    }
};