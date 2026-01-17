// Last updated: 1/17/2026, 12:27:48 PM
class Solution {
public:
    int countKeyChanges(string s) {
          int n=s.size();
        map<char,int>m;
        int ct=0;
        for(int i=1;i<n;++i){
            char c= tolower(s[i-1]);
            // m[c]++;
            char c1=tolower(s[i]);
            if(c1!=c)ct++;
        }
        return ct;
    }
};