// Last updated: 1/17/2026, 12:35:18 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());

        set<vector<int>> s;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = -(v[i] + v[j]);

                // Binary search in the range [j + 1, n - 1]
                int idx = lower_bound(v.begin() + j + 1, v.end(), target) - v.begin();
                if (idx < n && v[idx] == target) {
                    s.insert({v[i], v[j], v[idx]});
                }
            }
        }

        return vector<vector<int>>(s.begin(), s.end());
    }
};
