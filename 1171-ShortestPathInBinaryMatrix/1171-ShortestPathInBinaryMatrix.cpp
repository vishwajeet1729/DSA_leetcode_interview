// Last updated: 1/17/2026, 12:31:19 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
           queue<pair<int,int>>q;
    if(v[0][0]!=1)q.push({0,0});
int n=v.size();
     int ct=0;
     vector<vector<int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    while(!q.empty()){
          
          int c=q.size();
          for(int i=0;i<c;++i){
            auto it=q.front();
        
            q.pop();
            int x=it.first,y=it.second;
            if(x==n-1&&y==n-1){
                // cout<<ct+1<<endl;return;
                return ct+1;
            }
             
            for (auto &d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] == 0) {
                    q.push({nx, ny});
                    v[nx][ny] = 1; 
                }
            }
          }
          ct++;
        
    }
//    cout<<-1<<endl;
return -1;
    
    }
};