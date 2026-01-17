// Last updated: 1/17/2026, 12:28:03 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
       int n=v.size(); 
        map<int,int>m;
        int mx=INT_MIN;
        for(int i=0;i<n;++i)m[v[i]]++;
        for(auto it:m)mx=max(mx,it.second);
        int ct=0;
        for(auto it:m){
            if(it.second==mx)ct++;
        }
        return mx*ct;
    }
};