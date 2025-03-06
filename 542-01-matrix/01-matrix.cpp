class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
         int n=v.size(),m=v[0].size();
    vector<vector<int>>ans(n,vector<int>(m,0));
    
    

     for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
               if(v[i][j]==0)ans[i][j]=0;
               else ans[i][j]=1e9; 
                if (i < n - 1) ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                if (j < m - 1) ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);            
        }

    }  
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(j>0)ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
            if(i>0)ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
            // cout<<ans[i][j]<<" ";
        }
        
     }  
return ans;

    }
};