class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j)v.push_back(grid[i][j]);
        }

 sort(v.begin(),v.end());
int med=v[v.size()/2];
int ct=0;
 for(int i=0;i<v.size();++i){
    if(med%x!=v[i]%x)return -1;
    ct+=abs(med-v[i])/x;
 }
 return ct;

    }
};