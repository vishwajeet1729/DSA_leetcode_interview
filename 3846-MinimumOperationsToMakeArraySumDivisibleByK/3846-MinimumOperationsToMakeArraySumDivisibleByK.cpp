// Last updated: 1/17/2026, 12:25:31 PM
class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int sum=accumulate(v.begin(),v.end(),0);
        return sum%k;
    }
};