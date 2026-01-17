// Last updated: 1/17/2026, 12:31:55 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root || p == root || q == root)
            return root;

        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (left && right)
            return root;
        return (left != nullptr) ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // TreeNode *root;

        queue<TreeNode*> q;

        q.push(root);
        TreeNode *start, *end;
        while (!q.empty()) {

            int x = q.size();

            for (int i = 0; i < x; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (i == 0) {
                    start = temp;
                }
                if (i == x-1)
                    end = temp;
               if (temp->left)  q.push(temp->left);
if (temp->right) q.push(temp->right);

            }
        }

        TreeNode* ans = lca(root, start, end);
        //   cout<<ans->val<<endl;

        return ans;
    }
};