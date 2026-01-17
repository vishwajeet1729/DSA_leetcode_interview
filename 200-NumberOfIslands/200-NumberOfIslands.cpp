// Last updated: 1/17/2026, 12:33:35 PM
class Solution {
public:
   void dfs(vector<vector<char>>& v,int i,int j){

        if(j<0||i<0||i>=v.size()||j>=v[0].size()||v[i][j]=='0')return ;
        v[i][j]='0'; 
        dfs(v,i+1,j);
      dfs(v,i-1,j);
       dfs(v,i,j+1);
     dfs(v,i,j-1);
     

   }
    int numIslands(vector<vector<char>>& v) {
    int ct=0;
         for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j]=='1'){
                    ct++;
                    dfs(v,i,j);
                }
            }
         } 
         return ct; 
    }
};