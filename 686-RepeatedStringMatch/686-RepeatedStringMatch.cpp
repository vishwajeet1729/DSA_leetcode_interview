// Last updated: 1/17/2026, 12:32:19 PM
#include <string>
#include <numeric> // Not directly used, but good for some math ops like ceil if needed
#include <algorithm> // For std::min, std::max (not directly used here but generally useful)

class Solution {
public:
    int repeatedStringMatch(std::string a, std::string b) {
        int count = 1;
        std::string temp = a; // Start with 'a' repeated once

        // Keep appending 'a' until 'temp' is at least as long as 'b'
        // This covers the minimal repetition needed for b to potentially fit.
        while (temp.length() < b.length()) {
            temp += a;
            count++;
        }

        // Check if 'b' is a substring now
        if (temp.find(b) != std::string::npos) {
            return count;
        }

        // If not found, it's possible that 'b' spans across a boundary
        // such that it needs one more 'a' to fully contain it.
        // For example, if a = "abcd", b = "cdabcdab"
        // After first loop, temp = "abcdabcd", count = 2. "cdabcdab" not found.
        // We append one more 'a'.
        temp += a;
        count++;
        
        // Check again after one more 'a' is added
        if (temp.find(b) != std::string::npos) {
            return count;
        }

        // If still not found, it's impossible.
        return -1;
    }
};