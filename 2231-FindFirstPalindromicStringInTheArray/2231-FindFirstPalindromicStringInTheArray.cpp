// Last updated: 1/17/2026, 12:29:41 PM
class Solution {
public:
    string firstPalindrome(vector<string>& w) {
     int n = w.size();
     string p="";
     string a="";
        for (int i = 0; i < n; ++i) {
            p = w[i];
            string reversed = p;
            reverse(reversed.begin(), reversed.end());
            if (p == reversed) {
                a=p;
                break;
            }
        }
        return a;
    }
};