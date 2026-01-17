// Last updated: 1/17/2026, 12:27:49 PM
class Solution {
public:
    string lastNonEmptyString(string s) {
        string result;

        // Count occurrences of each character in the input string
        unordered_map<char, int> countMap;
        for (char c : s) {
            countMap[c]++;
        }

        // Find the maximum occurrence count
        int maxCount = 0;
        unordered_set<char> processedChars;
        for (const auto& entry : countMap) {
            maxCount = max(maxCount, entry.second);
        }

        // Append characters with the maximum occurrence count in reverse order
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (countMap[c] == maxCount && !processedChars.count(c)) {
                result.push_back(c);
            }
            processedChars.insert(c);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};