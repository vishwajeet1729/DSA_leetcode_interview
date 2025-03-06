class Solution {
public:
int n,m;

void rec(int i,int j,vector<vector<int>>&v){
       if(i>=n||j>=m||i<0||j<0||v[i][j]==0)return;
       v[i][j]=0;
       rec(i+1,j,v);
       rec(i,j+1,v);
       rec(i-1,j,v);
       rec(i,j-1,v);
  
}
    int numEnclaves(vector<vector<int>>& v) {

     n=v.size(),m=v[0].size();
    // vector<vector<char>>vis(n,vector<char>(m,0));
     
    for(int i=0;i<n;++i){
            if(v[i][0]==1)rec(i,0,v);
            if(v[i][m-1]==1)rec(i,m-1,v);
    }
    for(int i=0;i<m;++i){
        if(v[0][i]==1)rec(0,i,v);
        if(v[n-1][i]==1)rec(n-1,i,v);
    }
    int ct=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
          if(v[i][j])ct++;
        }
        // line;
    }

// cout<<ct<<endl;
return ct;
    }
};