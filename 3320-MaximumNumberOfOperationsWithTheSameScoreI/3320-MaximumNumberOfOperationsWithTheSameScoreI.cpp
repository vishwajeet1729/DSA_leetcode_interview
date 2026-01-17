// Last updated: 1/17/2026, 12:27:46 PM
class Solution {
public:
    int maxOperations(vector<int>& v) {
        int n=v.size();
        int r=v[0]+v[1];
        int ct=0;
        for(int i=0;i<n;i+=2){
            if(v[i]+v[i+1]==r)ct++;
            else break;
        }
        
        return ct;
    }
};