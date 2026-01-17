// Last updated: 1/17/2026, 12:32:38 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        vector<vector<int>>ans;
bool flag=1;
int n=v.size(),m=v[0].size();
  for(int k=0;k<m;++k){
        
    int i=0,j=k;
    vector<int>temp;
    while(i<n&&j>=0){
           temp.push_back(v[i][j]);
         i++;j--;
    }
    if(flag)reverse(temp.begin(),temp.end());
      ans.push_back(temp);
    flag=!flag;
  }
    
if(m%2==0)flag=1;
else flag=0;
    
for(int k=1;k<n;++k){
        
    int i=k,j=m-1;
      vector<int>temp;
    while(i<n&&j>=0){
          temp.push_back(v[i][j]);
          i++;j--;
    }
    if(flag)reverse(temp.begin(),temp.end());
    ans.push_back(temp);
    flag=!flag;
}
vector<int>d;
for(int i=0;i<ans.size();++i){
         for(int j=0;j<ans[i].size();++j)d.push_back(ans[i][j]);
 }
return d;
    }
};