// Last updated: 1/17/2026, 12:31:36 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
   // vector<int> sortedSquares(vector<int>& nums) {
        int maxVal = 0;
        for (int num : nums)
            maxVal = max(maxVal, abs(num));
        
        vector<int> v(maxVal + 1, 0);
        for (int num : nums)
            v[abs(num)]++;
        
        vector<int> re;
        for (int i = 0; i <= maxVal; ++i) {
            if (v[i] != 0) {
                re.insert(re.end(), v[i], i * i);
            }
        }
        return re;
    }
};