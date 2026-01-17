// Last updated: 1/17/2026, 12:31:03 PM
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& v) {
    //   vector<vector<int>>v={{1,1},{3,4},{-1,0}};

  int n=v.size();
int ans=0;
  for(int i=0;i<n-1;++i){

    auto a=v[i];
    int xdiff=abs(v[i][0]-v[i+1][0]);
    int ydiff=abs(v[i][1]-v[i+1][1]);
    int mi=min(ydiff,xdiff);
// ans+=mi;
ans+=max(xdiff,ydiff);



  }
  
//  cout<<ans<<endl;
return ans;    
    }
};