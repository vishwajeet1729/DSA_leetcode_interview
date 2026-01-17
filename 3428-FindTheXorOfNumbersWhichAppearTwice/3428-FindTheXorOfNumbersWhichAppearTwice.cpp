// Last updated: 1/17/2026, 12:27:19 PM
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& v) {
        int x=0;
        map<int,int>m;
        for(int i=0;i<v.size();++i)m[v[i]]++;
        for(auto it:m)if(it.second==2)x^=it.first;
        return x;
    }
};