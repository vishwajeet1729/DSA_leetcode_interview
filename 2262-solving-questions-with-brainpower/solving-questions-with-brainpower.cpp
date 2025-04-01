class Solution {
public:

vector<long long>dp;
vector<vector<int>>v;
int n;
long long rec(int ind) {
    if (ind >= n) return 0; 

    if (dp[ind] != -1) return dp[ind]; 

    long long solve = v[ind][0] + (ind + v[ind][1] + 1 < n ? rec(ind + v[ind][1] + 1) : 0);
    
    long long skip = rec(ind + 1);

    return dp[ind] = max(solve, skip); 
}
    long long mostPoints(vector<vector<int>>& ans) {
        v=ans;
        n=ans.size();
        dp.resize(n,-1);
        return rec(0);
    }
};