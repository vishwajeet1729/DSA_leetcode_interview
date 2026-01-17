// Last updated: 1/17/2026, 12:33:27 PM
class Solution {
public:
    int lp(const string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int j = 0; 

        for (int i = 1; i < n; ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1]; 
            }
            if (s[i] == s[j]) {
                j++;
            }
            lps[i] = j;
        }
        return lps[n - 1];
    }

    string shortestPalindrome(string s) {
        string sp = s;
        reverse(sp.begin(), sp.end());
        string combined = s + "#" + sp; 
        int lps_value = lp(combined);
        return sp.substr(0, sp.size() - lps_value) + s;
    }
};
