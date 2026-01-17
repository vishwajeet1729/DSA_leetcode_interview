// Last updated: 1/17/2026, 12:26:51 PM
class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        for (int i = 0; i < 30; ++i) {
            bool bitN = n & (1 << i);
            bool bitK = k & (1 << i);
            if (bitN && !bitK) {
                changes++;
            } else if (!bitN && bitK) {
                return -1;
            }
        }
        return changes;
    }
};
