// Last updated: 1/17/2026, 12:35:17 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        int n = v.size();
        sort(v.begin(), v.end());

        set<vector<int>> s;

        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum = (long long)v[i] + v[j] + v[l] + v[r];

                    if (sum == target) {
                        s.insert({v[i], v[j], v[l], v[r]});
                        ++l;
                        --r;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }

        return vector<vector<int>>(s.begin(), s.end());
    }
};
