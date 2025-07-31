#include <vector>
#include <string>
#include <numeric> // For std::accumulate (though we'll use prefix sums manually)
#include <algorithm> // For std::max

class Solution {
public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();

        // 1. Precompute prefix sums for efficient sum calculation of subarrays.
        // prefixSum[k] stores the sum of stoneValue[0]...stoneValue[k-1]
        std::vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        // Helper to get sum of stones from index 'start' to 'end' (inclusive)
        auto getSum = [&](int start, int end) {
            return prefixSum[end + 1] - prefixSum[start];
        };

        // 2. Initialize DP table.
        // dp[i][j] stores the maximum score Alice can get from stones stoneValue[i...j].
        // All values initialized to 0. Base case: dp[i][i] = 0 (single stone, game ends).
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // 3. Fill DP table for increasing lengths of subarrays.
        // length represents the current number of stones in the subarray (j - i + 1).
        // It starts from 2 because single stone (length 1) is already base case 0.
        for (int length = 2; length <= n; ++length) {
            // i represents the starting index of the subarray.
            for (int i = 0; i <= n - length; ++i) {
                // j represents the ending index of the subarray.
                int j = i + length - 1;

                // Alice tries all possible split points 'k' within the current subarray [i...j].
                // 'k' is the last index of the left partition.
                for (int k = i; k < j; ++k) {
                    long long sum_left = getSum(i, k);
                    long long sum_right = getSum(k + 1, j);

                    int current_round_score = 0;
                    int remaining_game_score = 0;

                    if (sum_left < sum_right) {
                        // Bob throws away right, Alice gets sum_left, game continues with left part [i...k]
                        current_round_score = sum_left;
                        remaining_game_score = dp[i][k];
                    } else if (sum_right < sum_left) {
                        // Bob throws away left, Alice gets sum_right, game continues with right part [k+1...j]
                        current_round_score = sum_right;
                        remaining_game_score = dp[k + 1][j];
                    } else { // sum_left == sum_right
                        // Bob throws away left (per rule), Alice gets sum_right, game continues with right part [k+1...j]
                        current_round_score = sum_right;
                        remaining_game_score = dp[k + 1][j];
                        // An alternative interpretation for tie-breaking:
                        // Alice might try to maximize her future score by choosing which side to keep.
                        // If sums are equal, Bob discards left, so Alice gets sum_right.
                        // However, Alice should then choose the path (left or right) that maximizes her *overall* score.
                        // This means if sums are equal, Alice gets 'sum_left' OR 'sum_right' and can choose to play on either side.
                        // The problem says "Bob throws away the left row" if sums are equal, meaning Alice *always* gets the right part.
                        // Let's stick to the direct interpretation: Bob forces Alice to take the right part.
                        // Update: Re-reading "Bob throws away the left row". This means Alice gets the right part.
                        // If she could choose, it would be max(sum_left + dp[i][k], sum_right + dp[k+1][j]).
                        // But since Bob dictates, it's sum_right + dp[k+1][j].
                        // The problem statement on equal sums: "If the two rows are equal, Bob lets Alice decide which row will be thrown away."
                        // THIS IS CRUCIAL! It means Alice chooses to minimize loss/maximize gain for *herself*.
                        // So, if sums are equal, Alice can choose to keep either the left or the right row.
                        // She will choose the one that gives her a better future score.
                        // Therefore, if sum_left == sum_right, Alice gets sum_left (which is also sum_right),
                        // AND she plays optimally on *either* side.
                        current_round_score = sum_left; // or sum_right, they are equal
                        remaining_game_score = std::max(dp[i][k], dp[k + 1][j]);
                    }
                    
                    dp[i][j] = std::max(dp[i][j], current_round_score + remaining_game_score);
                }
            }
        }

        // The maximum score Alice can obtain from the entire row is dp[0][n-1].
        return dp[0][n - 1];
    }
};