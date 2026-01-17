// Last updated: 1/17/2026, 12:28:45 PM
#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& v, int k) {
                  
         priority_queue<ll>q;
        // fr(i,0,n)q.push(v[i]);
        int n=v.size();
        for(int i=0;i<n;++i)q.push(v[i]);
   ll sum=0;
        while(!q.empty()&&k>0){
              
            ll x=q.top();
            q.pop();
          sum+=x;
          x=x/3+(x%3!=0);
          q.push(x);
          k--;

        }
        return sum; 
    }
};