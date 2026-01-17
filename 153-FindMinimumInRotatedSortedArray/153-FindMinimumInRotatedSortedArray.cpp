// Last updated: 1/17/2026, 12:33:48 PM
class Solution {
public:
    int findMin(vector<int>& v) {
           
           int l=0,r=v.size()-1;
     int mi=INT_MAX;
           while(l<=r){
             
             int mid=(l+r)>>1;
             mi=min(mi,v[mid]);

             if(v[l]<=v[mid]){
                mi=min(mi,v[l]);
                l=mid+1;
             }
             else if(v[mid]<=v[r]){
                mi=min(mi,v[mid]);
                r=mid-1;
             }
             else l=mid+1;


           }
           return mi;

    }
};