// Last updated: 1/17/2026, 12:30:47 PM
#include <vector>
#include <string>
#include <algorithm> // For std::max

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i] represents the maximum score difference (current player's score - opponent's score)
        // that the current player can achieve when considering stones from index i to n-1.
        // We initialize with a size of n+1 to handle the base case where all stones are taken (dp[n] = 0).
        std::vector<int> dp(n + 1, 0);

        // Iterate from right to left (from n-1 down to 0) to fill the dp array.
        // This ensures that when we calculate dp[i], dp[i+1], dp[i+2], dp[i+3] are already computed.
        for (int i = n - 1; i >= 0; --i) {
            int currentStonesSum = 0;
            int maxScoreDiff = -2e9; // Initialize with a very small number (negative infinity equivalent)

            // Option 1: Take 1 stone
            // Score if 1 stone is taken: stoneValue[i]
            // Opponent's optimal score difference from i+1: dp[i+1]
            // Our score difference: stoneValue[i] - dp[i+1]
            currentStonesSum += stoneValue[i];
            maxScoreDiff = std::max(maxScoreDiff, currentStonesSum - dp[i + 1]);

            // Option 2: Take 2 stones (if available)
            // Score if 2 stones are taken: stoneValue[i] + stoneValue[i+1]
            // Opponent's optimal score difference from i+2: dp[i+2]
            // Our score difference: (stoneValue[i] + stoneValue[i+1]) - dp[i+2]
            if (i + 1 < n) {
                currentStonesSum += stoneValue[i + 1];
                maxScoreDiff = std::max(maxScoreDiff, currentStonesSum - dp[i + 2]);
            }

            // Option 3: Take 3 stones (if available)
            // Score if 3 stones are taken: stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]
            // Opponent's optimal score difference from i+3: dp[i+3]
            // Our score difference: (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]) - dp[i+3]
            if (i + 2 < n) {
                currentStonesSum += stoneValue[i + 2];
                maxScoreDiff = std::max(maxScoreDiff, currentStonesSum - dp[i + 3]);
            }
            
            dp[i] = maxScoreDiff;
        }

        // dp[0] holds the maximum score difference Alice can achieve from the start.
        if (dp[0] >0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};