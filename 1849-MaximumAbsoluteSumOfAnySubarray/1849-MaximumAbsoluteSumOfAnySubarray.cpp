// Last updated: 1/17/2026, 12:30:14 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
              int sum=0;
              int n=v.size();
               int mx1=0,mx2=0;
               int s1=0,s2=0;
              for(int i=0;i<n;++i){          
                    if(s1<0)s1=0;              
                    if(s2<0)s2=0;
                    s1+=v[i];
                    mx1=max(mx1,s1);
                    s2=s2+(-1)*v[i];
                    mx2=max(mx2,s2);
              }
return max(mx1,mx2);

    }
};