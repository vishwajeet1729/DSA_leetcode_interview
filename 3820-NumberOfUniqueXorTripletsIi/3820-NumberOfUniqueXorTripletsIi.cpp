// Last updated: 1/17/2026, 12:25:38 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> uniqueTriplets;
    int n = nums.size();
    unordered_set<int> pairXors;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            pairXors.insert(nums[i] ^ nums[j]);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int px : pairXors) {
            uniqueTriplets.insert(px ^ nums[k]);
        }
    }

    return uniqueTriplets.size();
    }
};