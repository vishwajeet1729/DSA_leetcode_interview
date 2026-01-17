// Last updated: 1/17/2026, 12:34:31 PM
class Solution {
public:
     vector<vector<int>>ans;

     void def(vector<int>&v,int idx,vector<int>demo){
            if(idx==v.size()){
                ans.push_back(demo);
                return;
            }
            demo.push_back(v[idx]);
            def(v,idx+1,demo);
            demo.pop_back();
            def(v,idx+1,demo);

     }
    vector<vector<int>> subsets(vector<int>& v) {
             vector<int>demo;
               def(v,0,demo);return ans;
    }
};