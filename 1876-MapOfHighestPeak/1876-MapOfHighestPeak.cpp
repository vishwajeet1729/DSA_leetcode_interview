// Last updated: 1/17/2026, 12:30:13 PM
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& is) {
        int n=is.size();
        int m=is[0].size();
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
           queue<pair<int,int>>q;
           for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){if(is[i][j]==0)is[i][j]=-1;else {is[i][j]=0;q.push({i,j});}}
           }


       while(!q.empty()){
                pair<int,int>p=q.front();
                int rw=p.first;
                int cl=p.second;
                int val=is[rw][cl];

                for(int i=0;i<4;++i){
                     int nr=rw+dir[i].first;
                     int nc=cl+dir[i].second;
                     if(nr>=0&&nr<n&&nc>=0&&nc<m&&is[nr][nc]==-1){is[nr][nc]=val+1;q.push({nr,nc}) ; }

                } 
        q.pop();

       }

       
   return is;
    }
};