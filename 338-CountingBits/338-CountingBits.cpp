// Last updated: 1/17/2026, 12:32:57 PM
class Solution {
public:
    vector<int> countBits(int n) {
         vector<int>ans;
         for(int i=0;i<=n;++i)ans.push_back(__builtin_popcount(i));
         return ans;
    }
};