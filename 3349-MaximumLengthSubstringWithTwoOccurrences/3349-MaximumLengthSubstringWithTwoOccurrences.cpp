// Last updated: 1/17/2026, 12:27:35 PM
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx=INT_MIN;
         int n=s.size();
        for(int i=0;i<n;++i){
            map<char,int>m;
            int x=0;
            for(int j=i;j<n;++j){
                if(m[s[j]]==2)break;
                else {m[s[j]]++;x++;}
            }
        
            mx=max(mx,x);
            x=0;
            
        }
        return mx;
        
    }
};