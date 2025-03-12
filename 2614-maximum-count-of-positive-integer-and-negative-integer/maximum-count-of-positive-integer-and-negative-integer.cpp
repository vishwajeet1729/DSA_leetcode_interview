class Solution {
public:
    int maximumCount(vector<int>& v) {
        int pos=0,neg=0;
        for(int i=0;i<v.size();++i)if(v[i]>0)pos++;else if(v[i]<0)neg++;
        return max(pos,neg);
    }
};