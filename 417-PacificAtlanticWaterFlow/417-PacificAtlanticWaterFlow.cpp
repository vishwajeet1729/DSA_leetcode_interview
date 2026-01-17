// Last updated: 1/17/2026, 12:32:46 PM
class Solution {
public:
vector<pair<int,int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;

void bfs(vector<vector<int>>&v,vector<vector<int>>&vis,int turn){
     
    queue<pair<int,int>>q;
      for (int i = 0; i < n; ++i) {
        if (turn == 0) {
            q.push({i, 0});
            vis[i][0] = 1;
        } else {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (turn == 0) {
            q.push({0, j});
            vis[0][j] = 1;
        } else {
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
        }
    }
    while(!q.empty()){
       
    auto it=q.front();q.pop();
int cur_row=it.first,cur_col=it.second;
    for(int i=0;i<4;++i){
        
        int new_row=cur_row+direction[i].first,new_col=cur_col+direction[i].second;
        if(new_row<0||new_row>=n||new_col<0||new_col>=m)continue;
        if(vis[new_row][new_col])continue;
        if(v[new_row][new_col]>=v[cur_row][cur_col]){
            vis[new_row][new_col]=1;
            q.push({new_row,new_col});
        }
    }
     


    }
    
     
}

     vector<vector<int>> solve(vector<vector<int>>&v){
             vector<vector<int>>pacific(n,vector<int>(m,0));
vector<vector<int>>atlantic(n,vector<int>(m,0));
    bfs(v,pacific,0);
    bfs(v,atlantic,1);
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j)cout<<pacific[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    vector<vector<int>>ans;
     for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){//cout<<atlantic[i][j]<<" ";
        if(atlantic[i][j]&&pacific[i][j]){
           ans.push_back({i,j});
        }
        }
        // cout<<endl;
    }

    
   return ans;

     }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        n=v.size(),m=v[0].size();
        return solve(v);
    }
};