class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int dp[1005][1005];
    memset(dp, -1, sizeof(dp));
    function<int(int,int)>rec=[&](int ind1,int ind2)->int{
        if (ind1 == s1.size() || ind2 == s2.size()) return 0;
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2]; 
        if (s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1 + rec( ind1 + 1, ind2 + 1); 
         else return dp[ind1][ind2] = max(rec( ind1 + 1, ind2), rec( ind1, ind2 + 1));
        
    };
    return rec(0,0);
    }
};