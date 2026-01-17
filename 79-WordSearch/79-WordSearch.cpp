// Last updated: 1/17/2026, 12:34:30 PM
class Solution {
public:
    bool exist(vector<vector<char>>&grid,string target)
    {
        int n = grid.size(), m = grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
                if(fun(grid,target,i,j,0))
                {
                    return true;
                }
        }
    }
    return false;
    }
    bool fun(vector<vector<char>>& grid, string target,int i,int j,int index) {
        if(index == target.size()) return true;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=target[index])
        {
            return false;
        }
        char c = grid[i][j];
        grid[i][j]='*';
        bool ans = fun(grid,target,i+1,j,index+1) ||
                    fun(grid,target,i-1,j,index+1) ||
                    fun(grid,target,i,j+1,index+1) ||
                    fun(grid,target,i,j-1,index+1);
        grid[i][j]=c;
        return ans;
    }
};