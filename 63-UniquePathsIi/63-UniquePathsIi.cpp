// Last updated: 1/17/2026, 12:34:44 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& O) {
           
           int n=O.size();
           int m=O[0].size();
                   if (O[0][0] == 1 || O[n - 1][m - 1] == 1) return 0;

           
                        O[0][0]=1;

             for(int i=0;i<n;++i){
             
             for(int j=0;j<m;++j){
                   if(i==0&&j==0)continue;
                  if(O[i][j]==1){
                    O[i][j]=0;
                    continue;
                  }
              int sum=0;
                   if(i-1>=0)sum+=O[i-1][j];
                   if(j-1>=0)sum+=O[i][j-1];

                     O[i][j]=sum;

             }
           }

                       return O[n-1][m-1];  

    }
};