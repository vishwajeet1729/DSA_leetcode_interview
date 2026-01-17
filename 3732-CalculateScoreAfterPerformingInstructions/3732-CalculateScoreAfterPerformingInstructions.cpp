// Last updated: 1/17/2026, 12:26:05 PM
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
    int i = 0;           // starting index
    long long score = 0;
    unordered_set<int> visited;

    while (i >= 0 && i < n && visited.find(i) == visited.end()) {
        visited.insert(i);
        if (instructions[i] == "add") {
            score += values[i];
            i += 1;
        } else if (instructions[i] == "jump") {
            i += values[i];
        }
    }

    return score;
    }
};