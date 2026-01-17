// Last updated: 1/17/2026, 12:35:31 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n;
    // string s="kkkpew";
    n=s.size();
    int i=0,j=0;
    map<char,int>m;
    int mx=0;
    while(j<n){
        if(m.find(s[j])!=m.end()) {
            i=max(i,m[s[j]]+1);
        }
        m[s[j]]=j;
        mx=max(mx,j-i+1);
        j++;
    }
    // cout<<mx<<endl;
    return mx;


    }
};