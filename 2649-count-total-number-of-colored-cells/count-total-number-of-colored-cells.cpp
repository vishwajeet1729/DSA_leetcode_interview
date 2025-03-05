class Solution {
public:
    long long coloredCells(int n) {
         long long back=1;
      for(int i=2;i<=n;++i){
             if(i==n)return back+(i-2)*4+4;
             back=back+(i-2)*4+4;
             
      } 
    return 1;
    }
};