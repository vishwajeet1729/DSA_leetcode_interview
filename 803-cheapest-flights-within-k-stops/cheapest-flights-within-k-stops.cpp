class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& grid, int src, int dst, int k) {
        vector<vector<pair<int, int>>> v(n);

  v.resize(n); 
    for (size_t i = 0; i < grid.size(); i++) {
        int u = grid[i][0], w = grid[i][1], weight = grid[i][2];
        v[u].push_back({w, weight});
    }
      
    vector<int>cost(n,INT_MAX),stop(n,INT_MAX);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;

    
    q.push({0,{src,0}});
    while(!q.empty()){
          
        auto it=q.top();
        q.pop();
int node=it.second.first;
int cur_cost=it.first;
int st=it.second.second;
        if(node==dst){return it.first;}
        if(st>k)continue;
        // if(cost[node]<cur_cost)continue;
        if(stop[node]<=st)continue;
        // cost[node]=cur_cost;
        stop[node]=st;
        for(auto it:v[node]){
             q.push({cur_cost+it.second,{it.first,st+1}});
        }

}

//   cout<<cost[2];
          

return -1;


        
    }
};