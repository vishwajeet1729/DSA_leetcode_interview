// Last updated: 1/17/2026, 12:29:30 PM
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int total = 3 * n;
        
        // Step 1: left side (first 2n), store max heap to keep smallest n
        priority_queue<int> maxHeap;
        long long leftSum = 0;
        vector<long long> leftMin(3 * n, 0);
        
        for (int i = 0; i < 2 * n; ++i) {
            leftSum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n)
                leftMin[i] = leftSum;
        }
        
        // Step 2: right side (last 2n), store min heap to keep largest n
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        vector<long long> rightMax(3 * n, 0);
        
        for (int i = 3 * n - 1; i >= n; --i) {
            rightSum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n)
                rightMax[i] = rightSum;
        }

        // Step 3: check minimum difference
        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            if (rightMax[i + 1]) {
                ans = min(ans, leftMin[i] - rightMax[i + 1]);
            }
        }
        return ans;
    }
};
