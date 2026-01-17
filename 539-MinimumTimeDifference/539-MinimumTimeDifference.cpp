// Last updated: 1/17/2026, 12:32:33 PM
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        auto timeToMinutes = [](const string& time) -> int {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            return hours * 60 + minutes;
        };

        vector<int> minutes;

        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }
        sort(minutes.begin(), minutes.end());
        int min_diff = 24 * 60;

        for (int i = 1; i < minutes.size(); ++i) {
            min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
        }
        min_diff = min(min_diff, 24 * 60 - (minutes.back() - minutes.front()));

        return min_diff;
    }
};
