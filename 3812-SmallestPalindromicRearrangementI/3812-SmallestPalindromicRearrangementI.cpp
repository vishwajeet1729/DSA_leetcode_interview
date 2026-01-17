// Last updated: 1/17/2026, 12:25:41 PM
class Solution {
public:
    string smallestPalindrome(string s) {
         vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    string half = "";
    char middle = '\0';

    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 == 1) {
            if (middle != '\0') return ""; // More than one odd count: not possible
            middle = i + 'a';
        }
        half += string(freq[i] / 2, i + 'a');
    }

    string rev_half = half;
    reverse(rev_half.begin(), rev_half.end());

    string result = half;
    if (middle != '\0') result += middle;
    result += rev_half;

    return result;
    }
};