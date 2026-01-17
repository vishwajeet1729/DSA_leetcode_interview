// Last updated: 1/17/2026, 12:31:02 PM
class Solution {
public:
    int countServers(vector<vector<int>>& g) {
            
            int n=g.size();
            int m=g[0].size();
              map<int,int>r,c;

              for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                      if(g[i][j]==1){r[i]++;c[j]++;}
                }
              }
int ct=0;
          for(int i=0;i<n;++i)for(int j=0;j<m;++j){
                     
                     if(g[i][j]==1&&(r[i]>=2||c[j]>=2)){
                        ct++;
                     }
          }
    return ct;
    }
};