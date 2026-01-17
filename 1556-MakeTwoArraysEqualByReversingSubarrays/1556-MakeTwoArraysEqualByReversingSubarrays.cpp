// Last updated: 1/17/2026, 12:30:42 PM
class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        map<int,int>m;
        int n=t.size();
        for(int i=0;i<n;++i)m[a[i]]++;
        map<int,int>m2;
        for(int i=0;i<n;++i)m2[t[i]]++;
        for(auto it:m)if(it.second!=m2[it.first])return 0;

        return ((m.size()==m2.size())&1);
    }
};