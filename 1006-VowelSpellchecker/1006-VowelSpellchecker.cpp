// Last updated: 1/17/2026, 12:31:38 PM
class Solution {
public:
    vector<string> spellchecker(vector<string>& wl, vector<string>& q) {
        auto devowel = [](const string &s) {
            string t;
            for (char c : s) {
                char x = tolower(c);
                if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') t.push_back('*');
                else t.push_back(x);
            }
            return t;
        };

        unordered_set<string> exact(wl.begin(), wl.end());
        unordered_map<string, string> lower, vowel;

        for (auto &w : wl) {
            string lw;
            lw.reserve(w.size());
            for (char c : w) lw.push_back(tolower(c));
            if (!lower.count(lw)) lower[lw] = w;
            string vw = devowel(w);
            if (!vowel.count(vw)) vowel[vw] = w;
        }

        vector<string> ans;
        ans.reserve(q.size());
        for (auto &s : q) {
            if (exact.count(s)) { ans.push_back(s); continue; }

            string ls;
            ls.reserve(s.size());
            for (char c : s) ls.push_back(tolower(c));

            if (lower.count(ls)) ans.push_back(lower[ls]);
            else {
                string vs = devowel(s);
                if (vowel.count(vs)) ans.push_back(vowel[vs]);
                else ans.push_back("");
            }
        }
        return ans;
    }
};