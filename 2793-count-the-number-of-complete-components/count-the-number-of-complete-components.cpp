class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
vector<vector<int>>v(n);
         for(auto it:edges){
           v[it[0]].push_back(it[1]);
           v[it[1]].push_back(it[0]);
       }
    function<pair<int,int>(int)>dfs=[&](int node)->pair<int,int>{
         if(vis[node])return {0,0};
      vis[node]=1;
      int ct_node=1;
      int edg=0;
      for(auto it:v[node]){
        edg++;
        if(!vis[it]){
            auto res = dfs(it);
            ct_node+= res.second;
            edg += res.first;
        }
        }
        return {edg, ct_node};
    };
       int ans=0;
       int ct=0;
       for(int i=0;i<n;++i){
          if(!vis[i]){
            auto xnxx=dfs(i);
            int a=xnxx.first,b=xnxx.second;
            a=a/2;
            // if(a*(a-1)==b){
            //     ct++;
            // }
            // // cout<<a/2<<" "<<b<<endl;
            // cout<<a*(a-1)<<" "<<b<<endl;
            if(b*(b-1)/2==a)ct++;

          }
          
       }
return ct;
// cout<<ct<<endl;
    }
};