class Solution {
public:
    int countLargestGroup(int n) {
          
          unordered_map<int,int>m;
          for(int i=1;i<=n;++i){
              int sum=0;
              int x=i;
              while(x){
               sum+=x%10;
               x=x/10;
              }
              m[sum]++;
          }
          int mx=0;
          for(auto it:m)mx=max(mx,it.second);
          int ct=0;
          for(auto it:m)if(it.second==mx)ct++;
          return ct;
    }
};