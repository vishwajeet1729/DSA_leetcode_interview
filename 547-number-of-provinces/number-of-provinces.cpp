class Solution {
public:
    int findCircleNum(vector<vector<int>>& v  ) {
        int n=v.size();
       vector<int>vis(n+1,0);
       function<void(int)>dfs=[&](int ind)->void{
        vis[ind]=1;
        for(int i=0;i<n;++i){
             if(v[ind-1][i]==1&&!vis[i+1])dfs(1+i);
        }   
       };
       int ct=0;
       for(int i=1;i<=n;++i){
           if(!vis[i]){dfs(i);ct++;}
       }
//    cout<<ct<<endl;  
return ct;
    }
};