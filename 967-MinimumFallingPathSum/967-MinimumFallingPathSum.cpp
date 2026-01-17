// Last updated: 1/17/2026, 12:31:42 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mx) {
         
         int n=mx.size();
         int m=mx[0].size();
         
         vector<int>ans=mx[0];
         
         for(int i=1;i<n;++i){
             vector<int>demo=ans;
             for(int j=0;j<m;++j){
                 int fk=INT_MAX;
                 if(j-1>=0)fk=min(fk,ans[j-1]);
                if(j+1<m)fk=min(fk,ans[j+1]);
                demo[j]=mx[i][j]+min(fk,ans[j]);
             }
             ans=demo;
         }

     return *min_element(ans.begin(),ans.end());
    }
};