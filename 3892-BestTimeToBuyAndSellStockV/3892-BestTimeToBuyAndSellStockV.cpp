// Last updated: 1/17/2026, 12:25:24 PM
class Solution {
public:
  
    int n;
    vector<int> v;
    int K;

    vector<vector<vector<long long>>> dp;

  long long rec(int ind, int k, int state) {

    if (ind == n) {
        if (state != 0) return LLONG_MIN / 4;
        return 0;
    }

    if (k == 0) {
        if (state != 0) return LLONG_MIN / 4;
        return 0;
    }

    if (dp[ind][k][state] != -1)
        return dp[ind][k][state];

    long long price = v[ind];
    long long ans;

    if (state == 0) {
        ans = max({
            rec(ind + 1, k, 0),
            -price + rec(ind + 1, k, 1),
             price + rec(ind + 1, k, 2)
        });
    }
    else if (state == 1) {
        ans = max(
            rec(ind + 1, k, 1),
            price + rec(ind + 1, k - 1, 0)
        );
    }
    else {
        ans = max(
            rec(ind + 1, k, 2),
            -price + rec(ind + 1, k - 1, 0)
        );
    }

    return dp[ind][k][state] = ans;
}


    long long maximumProfit(vector<int>& prices, int k) {
        K = k;
        v = prices;
        n = v.size();

        dp.resize(
            n + 1,
            vector<vector<long long>>(K + 1, vector<long long>(3, -1))
        );

        return rec(0, K, 0);
    }
};
