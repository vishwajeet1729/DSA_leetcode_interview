// Last updated: 1/17/2026, 12:26:46 PM
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
         
         

  unordered_map<string, int> wordCount; // To store the count of each word in the message
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end()); // Using a set for quick lookup of banned words
int ct=0;
        // Loop through the message and count occurrences of banned words
        for (const string& word : message) {
            if (bannedSet.count(word)) { // If the word is in the banned list
ct++;                if (ct>= 2) {
                    return true; // If any banned word appears at least twice
                }
            }
        }
        
        return false; // No banned word appears twice

    }
};