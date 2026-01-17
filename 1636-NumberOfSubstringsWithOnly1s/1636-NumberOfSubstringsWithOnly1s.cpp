// Last updated: 1/17/2026, 12:30:34 PM
class Solution {
public:
    int M = 1e9 + 7;
    
    int numSub(string s) {
        int n = s.size();
        long long ct = 0;
        long long ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') {
                ct++;
            } else {
                ans = (ans + (ct * (ct + 1) / 2) % M) % M;
                ct = 0;
            }
        }
        
        ans = (ans + (ct * (ct + 1) / 2) % M) % M;
        
        return ans % M;
    }
};
