// Last updated: 1/17/2026, 12:28:00 PM
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
         int n = s.length();
    std::vector<int> aIndices, bIndices;

    for (int i = 0; i <= n - static_cast<int>(a.length()); ++i) {
        if (s.substr(i, a.length()) == a) {
            aIndices.push_back(i);
        }
    }

    for (int j = 0; j <= n - static_cast<int>(b.length()); ++j) {
        if (s.substr(j, b.length()) == b) {
            bIndices.push_back(j);
        }
    }

    std::set<int> beautiful;

    for (int i : aIndices) {
        auto it = std::lower_bound(bIndices.begin(), bIndices.end(), i);
        int idx = std::distance(bIndices.begin(), it);

        if (idx > 0 && std::abs(bIndices[idx - 1] - i) <= k) {
            beautiful.insert(i);
        }

        if (idx < static_cast<int>(bIndices.size()) && std::abs(bIndices[idx] - i) <= k) {
            beautiful.insert(i);
        }
    }

    return std::vector<int>(beautiful.begin(), beautiful.end());
    }
};