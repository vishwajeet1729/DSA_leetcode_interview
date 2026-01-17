// Last updated: 1/17/2026, 12:31:25 PM
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int answerLevel = 1;
        int currentLevel = 1;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                answerLevel = currentLevel;
            }

            currentLevel++;
        }

        return answerLevel;
    }
};
