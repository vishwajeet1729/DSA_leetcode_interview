// Last updated: 1/17/2026, 12:34:09 PM
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n); // Resize v to have n rows

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 ||j==i) v[i].push_back(1); // Start with 1
            else {
                int value = v[i - 1][j - 1] + v[i - 1][j];
                v[i].push_back(value);
            }
        }
    }
  return v;
    }
};