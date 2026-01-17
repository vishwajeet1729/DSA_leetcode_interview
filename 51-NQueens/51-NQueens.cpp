// Last updated: 1/17/2026, 12:34:52 PM
class Solution {
public:

          bool safe(int row,int col,vector<string>&board,int n){
               
          for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                  
               if(board[i][j]=='Q'){
                    if(i==row||j==col||abs(i-row)==abs(j-col))return 0;
               }

            }
          }
          return 1;

          }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
          
          if(col==n){ans.push_back(board);return;}
           
           for(int row=0;row<n;++row){
               
               if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';

               }
            

           }

    }
    vector<vector<string>> solveNQueens(int n) {
          
          string s(n,'.');
          vector<vector<string>>ans;
  vector<string>board;
  for(int i=0;i<n;++i)board.push_back(s);
        solve(0,board,ans,n);

return ans;
    }
};