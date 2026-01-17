// Last updated: 1/17/2026, 12:34:43 PM
class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
          
          int n=v.size();
          int m=v[0].size();
             vector<vector<int>>ans(n,vector<int>(m,0));
             ans[0][0]=v[0][0];
          for(int i=0;i<n;++i){

            for(int j=0;j<m;++j){
                 if(i==0&&j==0)continue;
                int rm=INT_MAX,cm=INT_MAX;
                if(i-1>=0)rm=min(rm,ans[i-1][j]);
                if(j-1>=0)cm=min(cm,ans[i][j-1]);  
                ans[i][j]=min(rm,cm)+v[i][j]; 
            }
          }

     return ans[n-1][m-1];

    }
};