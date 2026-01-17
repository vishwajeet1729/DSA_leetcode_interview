// Last updated: 1/17/2026, 12:27:54 PM
class Solution {
public:
    int minimumPushes(string word) {
       int n = word.size();

        std::unordered_map<char, int> charCount;

        for (char ch : word) {
            charCount[ch] = charCount.find(ch) != charCount.end() ? charCount[ch] + 1 : 1;
        }

        std::vector<std::pair<int, char>> charFrequency;

        for (const auto& entry : charCount) {
            charFrequency.push_back(std::make_pair(entry.second, entry.first));
        }

        std::sort(charFrequency.begin(), charFrequency.end());

        int ans = 0;
        int keys = 0;

        for (const auto& entry : charFrequency) {
            keys++;

            if (keys < 9) {
                ans += entry.first;
            } else if (keys < 17) {
                ans += entry.first * 2;
            } else if (keys < 25) {
                ans += entry.first * 3;
            } else {
                ans += entry.first * 4;
            }
        }

        return ans;
    }
};