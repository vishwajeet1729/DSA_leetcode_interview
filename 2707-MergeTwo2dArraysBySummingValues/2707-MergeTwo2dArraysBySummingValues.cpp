// Last updated: 1/17/2026, 12:28:33 PM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
                
               map<int,int>m;
               for(int i=0;i<v1.size();++i)m[v1[i][0]]+=v1[i][1];
                for(int i=0;i<v2.size();++i)m[v2[i][0]]+=v2[i][1];
             vector<vector<int>>ans;
             for(auto it:m)ans.push_back({it.first,it.second});
             return ans;
    }
};