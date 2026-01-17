// Last updated: 1/17/2026, 12:34:38 PM
class Solution {
public:
    int climbStairs(int n) {
          
       vector<int>v(n+1,0);
       if(n==1)return 1;
       v[0]=0;
       v[1]=1;
       v[2]=2;
        for(int i=3;i<=n;++i)
             v[i]=v[i-1]+v[i-2];    
        
   return v[n];
    }
};