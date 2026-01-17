// Last updated: 1/17/2026, 12:31:05 PM
class Solution {
public:
    
bool isAnagram(string &a, string &b) {
    if (a.size() != b.size()) return false;
    int freq[26] = {0};
    for (int i = 0; i < a.size(); ++i) {
        freq[a[i] - 'a']++;
        freq[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
        if (freq[i] != 0) return false;
    }
    return true;
}

vector<string> removeAnagrams(vector<string> &words) {
    vector<string> res;
    for (int i = 0; i < words.size(); ++i) {
        if (!res.empty() && isAnagram(res.back(), words[i])) {
            continue;
        }
        res.push_back(words[i]);
    }
    return res;
}

};