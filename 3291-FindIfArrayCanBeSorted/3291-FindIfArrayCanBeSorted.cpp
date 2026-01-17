// Last updated: 1/17/2026, 12:27:51 PM
class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n=v.size();
        vector<int>s(n);
        for(int i=0;i<n;++i)s[i]=v[i];
        sort(s.begin(),s.end());
        int k=n;
        while(k--){
            for(int i=0;i<n-1;++i){
                if(v[i+1]<v[i]&&__builtin_popcount(v[i])==__builtin_popcount(v[i+1]))swap(v[i],v[i+1]);
            }
        }
        bool re=true;
        for(int i=0;i<n;++i){
            if(s[i]!=v[i])re=false;
        }
        return re;
        
    }
};