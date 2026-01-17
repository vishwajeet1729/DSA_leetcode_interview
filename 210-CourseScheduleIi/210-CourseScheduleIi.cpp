// Last updated: 1/17/2026, 12:33:28 PM
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        
     vector<int>deg(n,0);
    for(int i=0;i<v.size();++i)deg[v[i][0]]++;
    queue<int>q;
    
    for(int i=0;i<n;++i){if(deg[i]==0)q.push(i);}
    vector<vector<int>>graph(n);
    
    for(int i=0;i<v.size();++i){
       graph[v[i][1]].push_back(v[i][0]);
    }int ct=0;
    vector<int>ans;
    while(!q.empty()){
          int x=q.size();
          
          for(int i=0;i<x;++i){
                ct++;
                int num=q.front();
                q.pop();
                ans.push_back(num);
                
                for(auto neigh:graph[num]){
                    if(--deg[neigh]==0)q.push(neigh);
                }
          }

    }
    // reverse(ans.begin(),ans.end());
    return (ct==n)?ans:vector<int>{};
  
    
    }
};