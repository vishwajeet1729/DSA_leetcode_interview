// Last updated: 1/17/2026, 12:25:28 PM
class Solution {
public:
    // 1. Check if two chars are consecutive (circular alphabet)
    bool areConsecutiveChars(char char1, char char2) {
        return (abs(char1 - char2) == 1) ? true
             : (char1 == 'a' && char2 == 'z') ? true
             : (char1 == 'z' && char2 == 'a') ? true
             : false;
    }

    string manualSubstring(const string& str, int startIdx, int length) {
        string substring = "";
        int offset = 0;
        while (offset < length && (startIdx + offset) < (int)str.size()) {
            substring += str[startIdx + offset];
            ++offset;
        }
        return substring;
    }

    void initializeOkTable(vector<vector<bool>>& canRemove, int strLength) {
        int index = 0;
        while (index <= strLength) {
            canRemove[index][index] = true;
            ++index;
        }
    }

    void fillOkTable(const string& s, vector<vector<bool>>& canRemove, int strLength) {
        int substringLength = 2;
        while (substringLength <= strLength) {
            int leftIndex = 0;
            while (leftIndex + substringLength <= strLength) {
                int rightIndex = leftIndex + substringLength;
                int midIndex = 1 + leftIndex;
                bool foundRemovable = false;
                while (midIndex < rightIndex && !foundRemovable) {
                    if (areConsecutiveChars(s[leftIndex], s[midIndex]) && 
                        canRemove[1 + leftIndex][midIndex] && 
                        canRemove[1 + midIndex][rightIndex]) {
                        foundRemovable = true;
                        canRemove[leftIndex][rightIndex] = true;
                    }
                    ++midIndex;
                }
                ++leftIndex;
            }
            ++substringLength;
        }
    }

    // 5. Compute the lex smallest string starting at position startPos
    string computeBestString(const string& s, const vector<vector<bool>>& canRemove, 
                             const vector<string>& dp, int startPos, int strLength) {
        string bestString = manualSubstring(s, startPos, 1) + dp[1 + startPos];
        int splitPos = 1 + startPos;
        while (splitPos < strLength) {
            if (areConsecutiveChars(s[startPos], s[splitPos]) && canRemove[1 + startPos][splitPos]) {
                bestString = min(bestString, dp[1 + splitPos]);
            }
            ++splitPos;
        }
        return canRemove[startPos][strLength] ? "" : bestString;
    }

    void buildDPArray(const string& s, const vector<vector<bool>>& canRemove, 
                      vector<string>& dp, int strLength) {
        dp[strLength] = "";
        int index = strLength - 1;
        while (index >= 0) {
            dp[index] = computeBestString(s, canRemove, dp, index, strLength);
            --index;
        }
    }

    // 7. Create and initialize the 2D DP boolean table
    vector<vector<bool>> createOkTable(int strLength) {
        return vector<vector<bool>>(strLength + 1, vector<bool>(strLength + 1, false));
    }

    // 8. Orchestrate the solution steps and return the final answer
    string solveProblem(const string& s) {
        int strLength = (int)s.size();
        vector<vector<bool>> canRemove = createOkTable(strLength);
        initializeOkTable(canRemove, strLength);
        fillOkTable(s, canRemove, strLength);

        vector<string> dp(strLength + 1);
        buildDPArray(s, canRemove, dp, strLength);

        return dp[0];
    }

    string lexicographicallySmallestString(string s) {
        return solveProblem(s);
    }

    // 10. Optional absolute difference helper (unused)
    int absoluteDifference(char a, char b) {
        return (a > b) ? (a - b) : (b - a);
    }
};
