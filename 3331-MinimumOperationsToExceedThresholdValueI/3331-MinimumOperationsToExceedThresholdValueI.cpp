// Last updated: 1/17/2026, 12:27:41 PM
class Solution {
public:
    int minOperations(vector<int>& v, int k) {
       sort(v.begin(),v.end()) ;
        int i=0;
        for(i=0;i<v.size();++i){
            if(v[i]>=k)break;
        }
        // i++;
        if(i>=0)
        return i;
        else return 0;
        
    }
};