// Last updated: 1/17/2026, 12:32:52 PM
class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        int n1=v1.size();
        int n2=v2.size();
        map<int,int>m;
        for(int i=0;i<n1;++i)m[v1[i]]++;
       map<int,int>ans;
        for(int i=0;i<n2;++i){
             if(m.find(v2[i])!=m.end()&&ans.find(v2[i])==ans.end()){
                 ans[v2[i]]++;
             }
        }
        vector<int>v;
        for(auto it:ans)v.push_back(it.first);
        return v;
    }
};