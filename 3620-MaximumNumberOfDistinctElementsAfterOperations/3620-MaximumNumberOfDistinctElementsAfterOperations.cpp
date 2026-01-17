// Last updated: 1/17/2026, 12:26:27 PM
class Solution {
public:
    int maxDistinctElements(vector<int>& n, int k) {
          int a = n[0], b = n[0];
        for (auto x : n) {
            if (x < a) a = x;
            if (x > b) b = x;
        }
        
        int r = b - a + 1;
        int c[r];
        for (int i = 0; i < r; ++i) c[i] = 0;

        for (auto x : n) c[x - a]++;

        int d = 0, l = -2147483648;  // INT_MIN replacement.

        for (int i = 0; i < r; ++i) {
            while (c[i] > 0) {
                int x = i + a;
                int s = (x - k > l + 1) ? x - k : l + 1;
                if (s <= x + k) {
                    l = s;
                    d++;
                    c[i]--;
                } else {
                    break;
                }
            }
        }

        return d;
    }
};