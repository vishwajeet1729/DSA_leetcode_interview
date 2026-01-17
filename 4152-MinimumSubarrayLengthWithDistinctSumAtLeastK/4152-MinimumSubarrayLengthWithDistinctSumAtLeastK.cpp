// Last updated: 1/17/2026, 12:25:10 PM
class Solution {
public:
    int minLength(vector<int>& v, int k) {

        map<int, int> m;
        int cur_sum = 0;

        int n = v.size();
        int ans = INT_MAX;

        int ind = 0;
        int left = 0;

        while (ind < v.size()) {

            // FIX 1: add braces
            if (m.find(v[ind]) == m.end()) {
                cur_sum += v[ind];
            }
            m[v[ind]]++;

            // FIX 2: >= instead of >
            while (cur_sum >= k && left < n) {

                ans = min(ans, ind - left + 1);

                m[v[left]]--;
                if (m[v[left]] == 0) {
                    cur_sum -= v[left];
                    m.erase(v[left]);
                }
                left++;
            }

            ind++;
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};
