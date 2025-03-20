class Solution {
public:
     
     
int n;
vector<vector<pair<int,int>>>v;

vector<int>vis;
vector<int>parent;
int dfs(int node,int cur_cst,int src){
         
    if(vis[node])return cur_cst;
    vis[node]=1;
    
    int ans=INT_MAX;
     parent[node]=src;
    for(auto it:v[node]){
    ans=ans&dfs(it.first,cur_cst&it.second,src);   
        }
    return ans;
        
}

    
    vector<int> minimumCost(int np, vector<vector<int>>& graph, vector<vector<int>>& queries) {
      n=np;
        v.resize(n);
        vis.assign(n,0);
        parent.resize(n,-1);
         for(int i=0;i<graph.size();++i){
                int dest=graph[i][1],src=graph[i][0],cst=graph[i][2];
                v[src].push_back({dest,cst});
                v[dest].push_back({src,cst});
     }

     vector<int>ans(n,0);
     for(int i=0;i<n;++i){
        if(vis[i])continue;
        // cout<<i<<" "<<endl;
         int cur=dfs(i,INT_MAX,i);
        //  cout<<cur<<endl;
         ans[i]=cur;
     }
//    for(auto it:parent)cout<<it<<" ";line; 
  for(int i=0;i<n;++i){
      int pr=parent[i];
      ans[i]=ans[pr];
  }
    // for(auto it:ans)cout<<it<<" ";line;
//   vector<vector<int>>queries={{0,3},{3,4}};
  vector<int>ct;
  for(int i=0;i<queries.size();++i){
          int src=queries[i][0],dest=queries[i][1];
          if(parent[src]!=parent[dest])ct.push_back(-1);
          else ct.push_back(ans[src]);
      
  }
//   line;
return ct;
    }
};