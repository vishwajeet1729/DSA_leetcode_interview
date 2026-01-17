// Last updated: 1/17/2026, 12:28:41 PM
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
         if (!root) return -1;

        std::vector<long long> levelSums; // To store the sums of each level
        std::queue<TreeNode*> q; // Queue for level order traversal
        q.push(root);

        while (!q.empty()) {
            long long levelSum = 0; // Sum for the current level
            int levelSize = q.size(); // Number of nodes at the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val; // Add the current node's value to the level sum

                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(levelSum); // Store the sum of the current level
        }

        // Sort the level sums in descending order
        std::sort(levelSums.rbegin(), levelSums.rend());

        // Check if there are at least k levels
        if (k <= levelSums.size()) {
            return levelSums[k - 1]; // Return the k-th largest sum
        }
        
        return -1; // Not enough levels
    }
};