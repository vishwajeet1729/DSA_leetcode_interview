// Last updated: 1/17/2026, 12:26:53 PM
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
         int n = s.length();
        int result = 0;

        // Iterate over all starting points of substrings
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;
            // Iterate over all ending points of substrings starting from i
            for (int j = i; j < n; ++j) {
                freq[s[j]]++;  // Increment the frequency of the current character
                
                // Check if any character appears at least k times in this substring
                bool valid = false;
                for (auto& entry : freq) {
                    if (entry.second >= k) {
                        valid = true;
                        break;  // Stop checking further, as the condition is satisfied
                    }
                }
                
                if (valid) {
                    result++;  // Count the valid substring
                }
            }
        }

        return result;
    // }
    }
};