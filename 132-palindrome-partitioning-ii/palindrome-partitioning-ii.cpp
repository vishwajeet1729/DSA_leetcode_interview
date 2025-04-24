
class Solution {
public:
    string s;
    int n;
    vector<int> dp;

    bool isPalindrome(int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    int minCuts(int start) {
        if (start == n) return 0;
        if (dp[start] != -1) return dp[start];

        int min_cut = INT_MAX;

        for (int end = start; end < n; ++end) {
            if (isPalindrome(start, end)) {
                // No cut needed if the whole substring from start is a palindrome
                if (end == n - 1)
                    min_cut = 0;
                else
                    min_cut = min(min_cut, 1 + minCuts(end + 1));
            }
        }

        return dp[start] = min_cut;
    }

    int minCut(string str) {
        s = str;
        n = s.length();
        dp = vector<int>(n, -1);
        return minCuts(0);
    }
};