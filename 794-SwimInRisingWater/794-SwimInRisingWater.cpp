// Last updated: 1/17/2026, 12:32:10 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
   int n=g.size(),m=g[0].size();
 vector<vector<int>>vis(n,vector<int>(m));
 priority_queue<vector<int>,vector<vector<int>>,greater<>>q;
 q.push({g[0][0],0,0});
 int d[5]={0,1,0,-1,0};
 while(!q.empty()){
  auto t=q.top();q.pop();
  int h=t[0],x=t[1],y=t[2];
  if(x==n-1&&y==m-1)return h;
  if(vis[x][y])continue;
  vis[x][y]=1;
  for(int k=0;k<4;k++){
   int nx=x+d[k],ny=y+d[k+1];
   if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny])
    q.push({max(h,g[nx][ny]),nx,ny});
  }
 }
 return -1;}
};
