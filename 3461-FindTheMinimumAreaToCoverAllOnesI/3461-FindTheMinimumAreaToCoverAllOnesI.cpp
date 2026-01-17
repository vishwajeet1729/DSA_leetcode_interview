// Last updated: 1/17/2026, 12:27:04 PM
class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {

        int n = a.size(), m = a[0].size();
        int minI = n, maxI = -1;
        int minJ = m, maxJ = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    minI = min(minI, i);
                    maxI = max(maxI, i);
                    minJ = min(minJ, j);
                    maxJ = max(maxJ, j);
                }
            }
        }
        if (maxI == -1) 
            return 0;

            return (maxI - minI + 1) * (maxJ - minJ + 1);
    }     
    };