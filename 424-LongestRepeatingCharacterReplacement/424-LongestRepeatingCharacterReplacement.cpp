// Last updated: 1/17/2026, 12:32:45 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        // int k=1;
    int n=s.size();
    int i=0,j=0;
    map<char,int>m;
    int cur_mx=1;
    
    int ans=0;
    while(j<n){
         m[s[j]]++;
        cur_mx=max(cur_mx,m[s[j]]);

        while(j-i+1-cur_mx>k){
            m[s[i]]--;   
            i++;
            cur_mx=1;
            for(auto it:m)cur_mx=max(cur_mx,it.second);
        }
        ans=max(ans,j-i+1);
       j++;
    
    }
return ans;
//   cout<<ans<<endl;
    }
};