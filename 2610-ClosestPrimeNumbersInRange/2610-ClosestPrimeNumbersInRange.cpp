// Last updated: 1/17/2026, 12:28:47 PM
class Solution {
public:
vector<bool> prime;
// vector<int> v;
Solution(){
      prime.resize(1e6+1,1);
      sieve();
}
 
void sieve() {
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i < 1e6; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < 1e6; j += i) {
                prime[j] = 0;
            }
        }
    }

    // for (int i = 2; i < 1e6; ++i) {
    //     if (prime[i]) v.push_back(i);
    // }
}
    vector<int> closestPrimes(int l, int r) {
       sieve();
// cout<<v.size();
    // int l=4,r=6;
   vector<int>ans;
    for(int i=l;i<=r;++i)if(prime[i])ans.push_back(i);
   if(ans.size()<=1){
    // cout<<-1<<" "<<-1<<endl;
    return {-1,-1};
   }
   int mi=1e7;
   int a=-1,b=-1;
   for(int i=0;i<ans.size()-1;++i){
    if(mi>ans[i+1]-ans[i]){
        mi=ans[i+1]-ans[i];
        a=ans[i],b=ans[i+1];
    }
   }
//    cout<<a<<" "<<b<<endl;
return {a,b};
    }
};