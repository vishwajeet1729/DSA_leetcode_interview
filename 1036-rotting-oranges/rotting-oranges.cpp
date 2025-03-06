class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
         bool spread=0;
        queue<pair<int,int>>q;
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(v[i][j]==2)q.push({i,j});
        int ct=0;
        while(1){
            
            queue<pair<int,int>>demo;
 spread=0;
        while(!q.empty()){
              
               auto it=q.front();
               q.pop();
               int i=it.first ,j=it.second;
               v[i][j]=2;
              if(i+1<n&&v[i+1][j]==1){demo.push({i+1,j});v[i+1][j]=2;spread=1;}
              if(j+1<m&&v[i][j+1]==1){demo.push({i,j+1});v[i][j+1]=2;spread=1;}
              if(i-1>=0&&v[i-1][j]==1){demo.push({i-1,j});v[i-1][j]=2;spread=1;}
              if(j-1>=0&&v[i][j-1]==1){demo.push({i,j-1});v[i][j-1]=2;spread=1;}
             
        }
        if(spread)ct++;
      q=demo;
      
      if(q.empty())break;
    }
    spread=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){if(v[i][j]==1)spread=1;}
    } 
    if(spread)return -1;
    else 
    return ct;
    }
};