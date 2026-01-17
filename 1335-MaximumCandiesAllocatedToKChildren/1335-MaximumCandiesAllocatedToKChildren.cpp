// Last updated: 1/17/2026, 12:31:06 PM
class Solution {
public:
vector<int>v;
long long k;
bool check(long long mid){
    long long n=v.size(); 
    long long ans=0;
    for(int i=0;i<n;++i){
           ans+=((long long)v[i]/mid);
     }  
     return ans>=k;

}
    int maximumCandies(vector<int>& candies, long long kk) {
        v=candies;
         long long l=1,h=1e17;
         k=kk;
long long ans=0;
// cout<<"jii";
    while(l<=h){
         long long mid=(l+h)>>1;
         if(check(mid)){
            ans=mid;
            l=mid+1;
         }  
         else h=mid-1;

    }
    // cout<<ans<<endl;
    return ans;

    }
};