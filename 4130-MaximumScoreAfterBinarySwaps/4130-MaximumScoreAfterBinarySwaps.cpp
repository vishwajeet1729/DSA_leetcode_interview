// Last updated: 1/17/2026, 12:25:12 PM
class Solution {
public:
    long long maximumScore(vector<int>& v, string s) {
      // vector<int>v={1,8,8,4,6,2};
    // string s="110100";
int n=v.size();
    long long ans=0;   
priority_queue<int>q;
for(int i=0;i<n;++i){
       q.push(v[i]);
    if(s[i]=='1'){
         
          int mx=q.top();
          q.pop();
          ans+=mx;
    }
//  q.push()


}

// cout<<ans<<endl;
        return ans;
  
    }
};