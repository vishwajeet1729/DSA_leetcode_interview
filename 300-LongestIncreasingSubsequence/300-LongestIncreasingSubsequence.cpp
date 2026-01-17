// Last updated: 1/17/2026, 12:33:03 PM
class Solution {
public:
   int lengthOfLIS(const vector<int>& nums) {
    vector<int> tails; // tails[len] = min tail of increasing subseq of length len+1
    for (int x : nums) {
        // find first element >= x, we want strictly increasing so we use lower_bound
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            // x is larger than any tail -> increase LIS length by 1
            tails.push_back(x);
        } else {
            // replace to keep minimal tail
            *it = x;
        }
    }
    return tails.size();
}
};