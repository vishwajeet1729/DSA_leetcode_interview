// Last updated: 1/17/2026, 12:35:19 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if (v.empty()) return "";

        sort(v.begin(), v.end());

        string first = v[0];
        string last = v[v.size() - 1];

        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};