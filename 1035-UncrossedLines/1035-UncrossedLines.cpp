// Last updated: 2/1/2026, 10:38:48 AM
1class Solution {
2public:
3    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
4        int n1 = nums1.size();
5        int n2 = nums2.size();
6
7        vector<int> dp(n2 + 1), dpPrev(n2 + 1);
8
9        for (int i = 1; i <= n1; i++) {
10            for (int j = 1; j <= n2; j++) {
11                if (nums1[i - 1] == nums2[j - 1]) {
12                    dp[j] = 1 + dpPrev[j - 1];
13                } else {
14                    dp[j] = max(dp[j - 1], dpPrev[j]);
15                }
16            }
17            dpPrev = dp;
18        }
19
20        return dp[n2];
21    }
22};