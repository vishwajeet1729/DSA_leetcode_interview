// Last updated: 1/17/2026, 12:27:55 PM
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
       
         std::vector<int> result(n, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int distance = std::min(std::abs(i - j), std::min(std::abs(i - x) + 1 + std::abs(y - j), std::abs(i - y) + 1 + std::abs(x - j)));
                result[distance - 1] += 2;
            }
        }

        return result;
    }
};