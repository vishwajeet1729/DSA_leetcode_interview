// Last updated: 1/17/2026, 12:25:16 PM
class Solution {
public:
    long long maxAlternatingSum(vector<int>&v) {
        //   vector<int>v={1,-1,2,-2,3,-3};
long long sum=0;
int n=v.size();
for(int i=0;i<n;++i)v[i]=abs(v[i]);
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
for(int i=0;i<n;++i){
   if(i<(n+1)/2) sum+=v[i]*v[i];
   else sum-=v[i]*v[i];
}
// cout<<sum<<endl;
return sum;

    }
};