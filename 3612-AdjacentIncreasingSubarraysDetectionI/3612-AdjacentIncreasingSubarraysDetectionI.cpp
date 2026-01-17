// Last updated: 1/17/2026, 12:26:33 PM
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& v, int k) {
           
    // vector<int>v={1,2,3,4,4,4,4,5,6,7};
    if(k==1)return 1;
    int n=v.size();
    int cur=1,prev=-1;
    int ans=0;   
    // int k=5;
    for(int i=1;i<n;++i){
              if(prev==-1){
                if(v[i-1]<v[i])cur++;
                else {
                    prev=cur;
                    cur=1;
                }
              }
              else {
                  if(v[i-1]<v[i])cur++;
                  else {
                    if((cur>=k&&prev>=k)||cur>=2*k||prev>=2*k){
                    return 1;
                    }
                     else {
                        prev=cur;
                        cur=1;
                    }
                  }
              }
    }

// cout<<0<<endl;
if(k==1||(prev>=k&&cur>=k)||prev>=2*k||cur>=2*k)return 1;
return 0;
    }
};