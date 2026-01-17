// Last updated: 1/17/2026, 12:29:40 PM
class Solution {
public:
    long long getDescentPeriods(vector<int>& v) {
          
    // vector<int>v={8,6,7,7};

    int n=v.size();
/*
3 2 1
1 ,
2,
 3
1,2
2,3
1,2,3
*/
    long long ans=0;
    int ct=1;
    for(int i=1;i<n;++i){
        if(v[i]<v[i-1]&&abs(v[i]-v[i-1])==1)ct++;
        else {
              
            ans+=(1LL*ct*(ct+1)/2);
            ct=1;
        }
       
    }

    
   ans+=(1LL*ct*(ct+1)/2);
    // cout<<ans<<endl;
    return ans;
    }
};