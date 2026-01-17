// Last updated: 1/17/2026, 12:28:27 PM
class Solution {
public:
    int findValueOfPartition(vector<int>& v) {
        sort(v.begin(),v.end());
        int mx=INT_MAX;
        for(int i=0;i<v.size()-1;++i){
            mx=min(mx,abs(v[i]-v[i+1]));
        }
        return mx;
    }
};