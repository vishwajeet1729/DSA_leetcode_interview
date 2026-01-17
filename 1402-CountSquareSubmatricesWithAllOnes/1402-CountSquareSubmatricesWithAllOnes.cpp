// Last updated: 1/17/2026, 12:31:01 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
  int ret=0;
            for(int i=0;i<v.size();++i){
    
    for(int j=0;j<v[0].size();++j){
             
             if(v[i][j]!=0){
                  int top = i == 0 ? 0 : v[i - 1][j];
                    int left = j == 0 ? 0 : v[i][j - 1];
                    int diag = (i == 0 || j == 0) ? 0 : v[i - 1][j - 1];

                    v[i][j] += min(min(top, left), diag);
                    
                    // Add updated cell value to total count
                    ret += v[i][j];  

             }

    }

            }
return ret;

    }
};