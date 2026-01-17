// Last updated: 1/17/2026, 12:29:58 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& v) {
           int n=v.size(),m=v[0].size();
//    cin>>n>>m;

//   vector<vector<int>>v(n,vector<int>(m));
long long mi=LLONG_MAX ;
long long ct=0;
long long sum=0;
for(int i=0;i<n;++i)for(int j=0;j<n;++j){
    mi=min(mi,(long long)abs(v[i][j]));
    sum+=abs(v[i][j]);
    if(v[i][j]<0)ct++;
  }
   
  if(ct%2==0)return sum;
 return sum-2*mi;

    }
};