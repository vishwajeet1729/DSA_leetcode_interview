// Last updated: 1/17/2026, 12:35:00 PM
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    int posIdx = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0) {
            swap(nums[i], nums[posIdx]);
            posIdx++;
        }
    }

    for (int i = posIdx; i < n; i++) 
    {     int x = abs(nums[i]);
        if (x <= n - posIdx && nums[posIdx + x - 1] > 0) {
            nums[posIdx + x - 1] = -nums[posIdx + x - 1];
        }
    }

    for (int i = posIdx; i < n; i++) {
        if (nums[i] > 0) {
            return i - posIdx + 1;
        }
    }

    return n - posIdx + 1;
}

};