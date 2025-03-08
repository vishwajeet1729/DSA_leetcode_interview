class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n=v.size(); 
    vector<bool>safe;
vector<bool>vis;
     safe.resize(n,0);
     vis.resize(n,0); 
     function<bool(int)>dfs=[&](int node)->bool{
        if(vis[node])return safe[node];
        bool ans=1;
        vis[node]=1;
        for(auto negh:v[node]){
            ans&=dfs(negh);
        } 
        return safe[node]=ans; 
     };
    for(int i=0;i<n;++i){
        if(!vis[i])dfs(i);
    }
vector<int>ans;
    for(int i=0;i<n;++i)if(safe[i])ans.push_back(i); 
    return ans;
    }
};