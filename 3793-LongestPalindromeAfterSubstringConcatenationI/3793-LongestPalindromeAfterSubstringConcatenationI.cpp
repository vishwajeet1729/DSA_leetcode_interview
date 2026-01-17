// Last updated: 1/17/2026, 12:25:47 PM
class Solution {
public:
    bool p(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    
    int longestPalindrome(string s, string t) {
        int mx = 0, n = s.size(), m = t.size();
        vector<string> a, b;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                a.push_back(s.substr(i, j - i + 1));
            }
        }
        a.push_back("");

        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                b.push_back(t.substr(i, j - i + 1));
            }
        }
        b.push_back("");

        for (const string &x : a) {
            for (const string &y : b) {
                string c = x + y;
                if (p(c)) mx = max(mx, (int)c.size());
            }
        }
        return mx;
    }
};
