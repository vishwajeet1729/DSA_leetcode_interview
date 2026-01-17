// Last updated: 1/17/2026, 12:27:18 PM
class Solution {
public:
    bool isArraySpecial(vector<int>&v) {
        for(int i=0;i<v.size()-1;++i)
if(v[i]%2==v[i+1]%2)return 0;        
        return 1;
    }
};