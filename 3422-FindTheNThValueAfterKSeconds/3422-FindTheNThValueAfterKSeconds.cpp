// Last updated: 1/17/2026, 12:27:21 PM
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
                 int MOD = 1e9 + 7;
        vector<int> a(n, 1);

        for (int t = 0; t < k; ++t) {
            vector<int> pre(n);
            pre[0] = a[0];
            for (int i = 1; i < n; ++i) {
                pre[i] = (pre[i - 1] + a[i]) % MOD;
            }
            for (int i = 0; i < n; ++i) {
                a[i] = pre[i];
            }
        }

        return a[n - 1];

    }
};