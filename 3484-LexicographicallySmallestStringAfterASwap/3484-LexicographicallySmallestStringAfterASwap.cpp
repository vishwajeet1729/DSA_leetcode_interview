// Last updated: 1/17/2026, 12:26:58 PM
class Solution {
public:
    string getSmallestString(string s) {
        
        int n=s.size();
        string ans=s;
        for(int i=0;i<n-1;++i){
               string p=s;
               int a=s[i]-'0';
               int b=s[i+1]-'0';
               if((a%2&&b%2)||(!(a%2)&&!(b%2)))
               swap(p[i],p[i+1]);
               if(p<ans)ans=p;
        }
        return ans;
    }
};