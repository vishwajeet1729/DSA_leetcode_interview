class Solution {
public:
    int networkDelayTime(vector<vector<int>>& grid, int n, int k) {
             
           vector<vector<pair<int,int>>>v(n+1);
      
       for(int i=0;i<grid.size();++i){
               v[grid[i][0]].push_back({grid[i][1],grid[i][2]});
       }
    //  price node
    vector<int>cost(n+1,INT_MAX);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        // vector<vector<int,int>>steps;
        // int k=2;
        q.push({0,k});
        cost[k]=0;
       while(!q.empty()){
                 
              auto it=q.top();
              q.pop();

              int cur_cost=it.first,cur_node=it.second;
              if(cur_cost>cost[cur_node])continue;
            //    cost[cur_node]=cur_cost;
              for(auto &[next, weight] : v[cur_node]) {
    if(cur_cost + weight < cost[next]) { 
        cost[next] = cur_cost + weight;
        q.push({cost[next], next});
    }
}
       }
        for(int i=1;i<=n;++i)if(cost[i]==INT_MAX){return -1;}
          return *max_element(cost.begin()+1,cost.end());




    }
};