class Solution {
public:
    bool divideArray(vector<int>& v) {
         map<int,int>m;
         for(int i=0;i<v.size();++i)m[v[i]]++;

         for(auto it:m)if(it.second%2)return 0;
         return 1;
    }
};