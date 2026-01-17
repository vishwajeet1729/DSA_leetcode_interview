// Last updated: 1/17/2026, 12:28:52 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
         int ans = 0;
        queue<TreeNode*> q; // Queue to hold nodes for level-order traversal.
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level.
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                // Add the left and right children of the current node to the queue.
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            // Process the current level.
            vector<int> nums = currentLevel;
            int le = nums.size();
            map<int, int> map;

            for (int i = 0; i < le; i++)
                map[nums[i]] = i;

            sort(nums.begin(), nums.end());

            // Use a vector instead of a variable-length array.
            vector<bool> visited(le, false);

            // Count minimum swaps.
            for (int i = 0; i < le; i++) {
                if (visited[i] || map[nums[i]] == i)
                    continue;

                int j = i, cycle_size = 0;
                while (!visited[j]) {
                    visited[j] = true;

                    // Move to next node.
                    j = map[nums[j]];
                    cycle_size++;
                }

                // Update answer by adding current cycle.
                if (cycle_size > 0) {
                    ans += (cycle_size - 1);
                }
            }
        }

        return ans;
    }
};