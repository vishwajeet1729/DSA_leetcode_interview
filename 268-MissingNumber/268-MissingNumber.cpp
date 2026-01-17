// Last updated: 1/17/2026, 12:33:11 PM
class Solution {
public:
    int missingNumber(vector<int>& v) { int n=v.size();int sum=0;
        for(int i=0;i<v.size();++i)
            {
            sum+=v[i];
            }
        return n*(n+1)/2-sum;
    }
};