// Last updated: 1/17/2026, 12:27:07 PM
class Solution {
public:
    string compressedString(string word) {
        string comp;
        int i = 0;
        int n = word.size();

        while (i < n) {
            char current_char = word[i];
            int count = 0;
            
            while (i < n && word[i] == current_char && count < 9) {
                ++i;
                ++count;
            }
            
            comp += to_string(count) + current_char;
        }

        return comp;
    }
};
