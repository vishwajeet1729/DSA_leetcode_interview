// Last updated: 1/17/2026, 12:30:36 PM
class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        int n = v.size();
        map<int, int> m;
        for (int i = 0; i < n; ++i) m[(v[i] % k + k) % k]++;

        for (auto it : m) {
            int remainder = it.first;
            int count = it.second;

            if (remainder == 0) {
                if (count % 2 != 0) return false;
            } else {
                int comp = k - remainder;
                
                if (remainder == comp) {
                    if (count % 2 != 0) return false;
                } else {
                    if (m[comp] != count) return false;
                }
            }
        }

        return true;
    }
};
