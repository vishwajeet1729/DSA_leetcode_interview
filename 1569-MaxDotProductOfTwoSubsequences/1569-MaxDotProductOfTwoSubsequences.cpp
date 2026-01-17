// Last updated: 1/17/2026, 12:30:41 PM
#define ll long long
class Solution {
public:
    vector<int> v1, v2;
    int n1, n2;
    vector<vector<vector<ll>>> dp;

    ll rec(int i, int j, int taken) {
        if (i == n1 || j == n2) {
            if (taken) return 0;          // valid subsequence ended
            return -1e18;                // invalid (never took anything)
        }

        if (dp[i][j][taken] != -1) return dp[i][j][taken];

        ll skip1 = rec(i+1, j, taken);
        ll skip2 = rec(i, j+1, taken);
        ll take  = (ll)v1[i] * v2[j] + rec(i+1, j+1, 1);

        return dp[i][j][taken] = max({skip1, skip2, take});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        n1 = v1.size();
        n2 = v2.size();

        dp.assign(n1+1, vector<vector<ll>>(n2+1, vector<ll>(2, -1)));
        return (int)rec(0, 0, 0);
    }
};
