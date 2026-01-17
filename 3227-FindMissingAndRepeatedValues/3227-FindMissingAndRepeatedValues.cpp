// Last updated: 1/17/2026, 12:28:06 PM
class Solution {
public:
   vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        int n = grid.size(); // Get the side length of the square grid.
        long long N_total = (long long)n * n; // Total count of numbers from 1 to n*n.

        // Calculate the expected sum of numbers from 1 to N_total.
        // Formula for sum of first K natural numbers: K * (K + 1) / 2
        long long expected_sum = N_total * (N_total + 1) / 2;

        // Calculate the expected sum of squares of numbers from 1 to N_total.
        // Formula for sum of squares of first K natural numbers: K * (K + 1) * (2K + 1) / 6
        long long expected_sum_sq = N_total * (N_total + 1) * (2 * N_total + 1) / 6;

        long long actual_sum = 0;      // To store the sum of numbers present in the grid.
        long long actual_sum_sq = 0;   // To store the sum of squares of numbers present in the grid.

        // Iterate through the grid to calculate the actual sum and sum of squares.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = grid[i][j]; // Use long long for val to prevent overflow during squaring.
                actual_sum += val;
                actual_sum_sq += val * val;
            }
        }

        // Let 'a' be the repeating number and 'b' be the missing number.
        //
        // Equation 1 (from sums):
        // (Sum of numbers in grid) = (Expected sum of numbers from 1 to N_total) - b + a
        // actual_sum = expected_sum - b + a
        // a - b = actual_sum - expected_sum
        long long diff_sum = actual_sum - expected_sum;

        // Equation 2 (from sums of squares):
        // (Sum of squares in grid) = (Expected sum of squares from 1 to N_total) - b^2 + a^2
        // actual_sum_sq = expected_sum_sq - b^2 + a^2
        // a^2 - b^2 = actual_sum_sq - expected_sum_sq
        long long diff_sum_sq = actual_sum_sq - expected_sum_sq;

        // We know that a^2 - b^2 = (a - b)(a + b).
        // Substitute from our equations:
        // diff_sum_sq = (diff_sum) * (a + b)
        //
        // Since 'a' is repeating and 'b' is missing, 'a' cannot be equal to 'b'.
        // Therefore, diff_sum (a - b) will not be zero, and we can safely divide.
        // a + b = diff_sum_sq / diff_sum
        long long sum_ab = diff_sum_sq / diff_sum;

        // Now we have a system of two linear equations:
        // 1) a - b = diff_sum
        // 2) a + b = sum_ab

        // To find 'a': Add Equation 1 and Equation 2
        // (a - b) + (a + b) = diff_sum + sum_ab
        // 2a = diff_sum + sum_ab
        // a = (diff_sum + sum_ab) / 2
        int a = (int)((diff_sum + sum_ab) / 2);

        // To find 'b': Subtract Equation 1 from Equation 2
        // (a + b) - (a - b) = sum_ab - diff_sum
        // 2b = sum_ab - diff_sum
        // b = (sum_ab - diff_sum) / 2
        int b = (int)((sum_ab - diff_sum) / 2);

        // Return the repeating number 'a' and the missing number 'b'.
        return {a, b};
    }
};