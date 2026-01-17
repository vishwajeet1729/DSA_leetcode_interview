// Last updated: 1/17/2026, 12:32:17 PM
class Solution {
public:
    
string s1, s2;
int n1=s1.size(), n2=s2.size();
int sum1=0, sum2=0;

vector<vector<int>> dp;

int rec(int i, int j){
    if(i==n1 || j==n2){
        int rem1 = 0, rem2 = 0;
        for(int k=i;k<n1;k++) rem1 += s1[k];
        for(int k=j;k<n2;k++) rem2 += s2[k];
        return rem1 + rem2;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    if(s1[i] == s2[j]){
        ans = rec(i+1, j+1);
    }

    ans = min(ans, s1[i] + rec(i+1, j));
    ans = min(ans, s2[j] + rec(i, j+1));

    return dp[i][j] = ans;
}


    int minimumDeleteSum(string t1, string t2) {
         n1=t1.size();
         n2=t2.size();
         s1=t1,s2=t2;

         dp.resize(n1,vector<int>(n2,-1));
         return rec(0,0);

    }
};