// Last updated: 1/17/2026, 12:30:31 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0"; 

        while (s.size() < k) {
            string re = s;
            for (int i = 0; i < re.size(); ++i) {
                re[i] = (re[i] == '0') ? '1' : '0';
            }
            reverse(re.begin(), re.end());
            s = s + "1" + re;
        }
        
        return s[k - 1];
    }
};
