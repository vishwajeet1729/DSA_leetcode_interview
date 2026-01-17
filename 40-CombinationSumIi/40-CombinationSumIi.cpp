// Last updated: 1/17/2026, 12:35:01 PM
class Solution {
public:
    int targ;
    void find(vector<int>& v, int sum, int index, vector<int>& cur,
              vector<vector<int>>& res) {
        int n = v.size();
        if (sum == targ) {
            res.push_back(cur);
            return;
        }
        if (index == n || sum > targ)
            return;
        cur.push_back(v[index]);
        find(v, sum + v[index], index+1, cur, res);
        while(index+1<n&&v[index]==v[index+1])index++;
        cur.pop_back();

        find(v, sum, index + 1, cur, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int val) {
   int n=v.size();
     int sum=0;
     sort(v.begin(),v.end());
     targ=val;
     vector<int>cur;
       vector<vector<int>>ans;find(v,0,0,cur,ans);

       return ans;

    }
};