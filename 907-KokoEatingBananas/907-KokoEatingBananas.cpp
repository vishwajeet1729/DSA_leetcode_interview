// Last updated: 1/17/2026, 12:31:53 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& v, int hour) {
         int n=v.size();
//   int hour=8;
  int l=0;
    int h = *max_element(v.begin(), v.end());
     int k=h;

     auto check=[&](int mid){

        // if(mid==0)return true;
        int ct=0;
        for(int i=0;i<n;++i){
              int x=v[i]/mid;
              ct+=x;
              if(v[i]%mid)ct++;
        }
       return ct<=hour;
     };
  while(l<=h){
       
    int mid=(l+h)/2;
  if(mid==0)break;
    if(check(mid)){
        k=mid;
        h=mid-1;
    }
    else l=mid+1;
  }
    if(k==0)return 1;
return k;
    }
};