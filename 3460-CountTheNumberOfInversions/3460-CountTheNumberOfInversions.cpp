// Last updated: 1/17/2026, 12:27:05 PM
   static const int MOD =1e9+7;
    static const int MAX_INV = 400;
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& reqs) {
           map<int, int> end_to_inv;
        for (int i=0;i<reqs.size();++i) {
            end_to_inv[reqs[i][0] + 1] = reqs[i][1]; 

        }

        vector<vector<long long>> dp(n + 1, vector<long long>(MAX_INV + 1, 0));
        dp[0][0] = 1;

        int len = 1;
        while (len < n+1) {
            int cur_inv = 0;

            while (cur_inv <1+ MAX_INV) {

                int new_pos = 0;
                while (new_pos < len) {

                    int prev_inv = cur_inv - new_pos;
                    if (prev_inv >= 0) 
                        dp[len][cur_inv] = (dp[len][cur_inv] + dp[len - 1][prev_inv]) % MOD;
                    
                    ++new_pos;
                }
                cur_inv+=1;
            }

            if (end_to_inv.count(len) > 0) {
                  int cur_inv = 0;
                int req_inv = end_to_inv[len];
              
                while (cur_inv < MAX_INV+1) {
                    if (cur_inv != req_inv) 
                        dp[len][cur_inv] = 0;
                    
                    cur_inv+=1;
                }
            }

            len+=1;
        }
 int cur_inv = 0;
        long long res = 0;
       
        while (cur_inv < MAX_INV+1) {
            res = (res + dp[n][cur_inv]) % MOD;
            cur_inv+=1;
        }

        return static_cast<int>(res);
    }
};
