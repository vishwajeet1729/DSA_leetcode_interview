// Last updated: 1/17/2026, 12:25:54 PM
class Solution {
public:
    vector<int> transformArray(vector<int>& v) {
        for(int i=0;i<v.size();++i){
            if(v[i]%2)v[i]=1;else v[i]=0;
        }
        sort(v.begin(),v.end());
        return v;
    }
};