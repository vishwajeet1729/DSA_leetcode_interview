// Last updated: 1/17/2026, 12:31:33 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        map<int, bool> knows;
        vector<int> trust(n + 1, 0); 

        for (const auto& pair : t) {
            int a = pair[0];
            int b = pair[1];
            knows[a] = true;
            trust[b]++;
        }

        int judge = -1;
        for (int i = 1; i <= n; ++i) {
            if (trust[i] == n - 1 && !knows[i]) {
                if (judge == -1) {
                    judge = i;
                } else { 
                    return -1;
                }
            }
        }

        return judge;
    }
};
