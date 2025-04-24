class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
            //i have three solution O(n^3) with constant spaxe
            // O(n^2) with n*m space
            //can i try more optmizers way ?
            //try there shiuld exist
            // yes we can compute it on this spor
  int ret=0;
            for(int i=0;i<v.size();++i){
    
    for(int j=0;j<v[0].size();++j){
             
             if(v[i][j]!=0){
                  int top = i == 0 ? 0 : v[i - 1][j];
                    int left = j == 0 ? 0 : v[i][j - 1];
                    int diag = (i == 0 || j == 0) ? 0 : v[i - 1][j - 1];

                    // Update cell to represent size of largest square ending at (i, j)
                    v[i][j] += min(min(top, left), diag);
                    
                    // Add updated cell value to total count
                    ret += v[i][j];  

             }

    }

            }
return ret;

    }
};