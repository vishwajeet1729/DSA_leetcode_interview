// Last updated: 1/17/2026, 12:30:56 PM
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};