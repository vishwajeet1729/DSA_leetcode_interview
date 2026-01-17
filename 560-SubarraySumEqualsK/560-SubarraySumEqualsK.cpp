// Last updated: 1/17/2026, 12:32:28 PM
class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0, count = 0;

        for (int num : v) {
            sum += num;
            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }
};
