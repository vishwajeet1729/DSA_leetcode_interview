// Last updated: 1/17/2026, 12:26:06 PM
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& a, int k) {
        int n = a.size(), s = 0;

    for (int i = 0; i < n; i++) {
        int l = (i - k >= 0) ? a[i - k] : INT_MIN;
        int r = (i + k < n) ? a[i + k] : INT_MIN;

        if (a[i] > l && a[i] > r) {
            s += a[i];
        }
    }

    return s;
    }
};