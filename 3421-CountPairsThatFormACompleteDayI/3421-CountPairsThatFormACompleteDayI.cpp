// Last updated: 1/17/2026, 12:27:22 PM
class Solution {
public:
    int countCompleteDayPairs(vector<int>& h) {
        
        int n=h.size();
        int ct=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j)if((h[i]+h[j])%24==0)ct++;
        }
        return ct;
    }
};