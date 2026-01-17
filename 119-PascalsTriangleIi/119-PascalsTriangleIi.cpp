// Last updated: 1/17/2026, 12:34:08 PM
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> row(n + 1, 1); // Initialize the row with n+1 elements, all set to 1

        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1]; // Calculate the next row based on the previous row
            }
        }

        return row;
    }
};
