// Last updated: 1/17/2026, 12:27:44 PM
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        //   vector<vector<int>>v1={{1,1},{1,3},{1,5}},v2={{5,5},{5,7},{5,9}};
   int n=v1.size();
  long long mx=0;
  for(int i=0;i<n-1;++i)
  {

    for(int j=i+1;j<n;++j){
      
           int xleft=max(v1[i][0],v1[j][0]);
           int ybottom=max(v1[i][1],v1[j][1]);
           int xright=min(v2[i][0],v2[j][0]);
           int ytop=min(v2[i][1],v2[j][1]);
           if(xleft<xright&&ybottom<ytop){
            int width  = xright - xleft;
            int height = ytop - ybottom;
            int side = min(width, height);
             mx=max(mx,(long long)side);
           }


    }

  }
  return mx*mx;
//   cout<<mx*mx<<endl;
    }
};