// Last updated: 1/17/2026, 12:34:39 PM
class Solution {
public:
    int mySqrt(int x) {
      int l=0,re=0,r=x;
        if(x<=1)return x;
        while(l<=r){
            
             int mid=l+(r-l)/2;
            if(x/mid>=mid){
                re=mid;
                l=mid+1;
            }
            else r=mid-1;
            
        }
        return re;
        
    }
};