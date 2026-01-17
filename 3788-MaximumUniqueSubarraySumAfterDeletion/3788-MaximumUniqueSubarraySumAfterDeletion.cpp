// Last updated: 1/17/2026, 12:25:51 PM
class Solution {
public:
    int maxSum(vector<int>& v) {
        set<int>s;
        for(int i=0;i<v.size();++i)if(v[i]>=0)s.insert(v[i]);
        
        int sum=0;
        for(auto it:s)sum+=it;
        int mi=*max_element(v.begin(),v.end());
        if(mi<0)return mi;
        return sum;

    }
};