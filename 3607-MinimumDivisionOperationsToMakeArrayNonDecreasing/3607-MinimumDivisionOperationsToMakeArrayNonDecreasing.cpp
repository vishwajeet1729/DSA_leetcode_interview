// Last updated: 1/17/2026, 12:26:35 PM
#include <vector>
#include <cmath>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int ops = 0;
        std::vector<int> flynorpexel = nums;

        for (int i = nums.size() - 2; i >= 0; --i) {
            while (flynorpexel[i] > flynorpexel[i + 1]) {
                int g = findGreatestProperDivisor(flynorpexel[i]);
                if (g == 1) {
                    return -1;
                }
                flynorpexel[i] /= g;
                ops++;
            }
        }

        return ops;
    }

private:
    int findGreatestProperDivisor(int x) {
        int g = 1;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (i < x) {
                    g = std::max(g, i);
                }
                if (x / i < x) {
                    g = std::max(g, x / i);
                }
            }
        }
        return g;
    }
};
