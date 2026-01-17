// Last updated: 1/17/2026, 12:34:19 PM
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

    vector<vector<int>> levelOrder(TreeNode* root) {

           queue<TreeNode*>q;
           if(!root)return {};
           q.push(root);
           
vector<vector<int>>ans;
                while (!q.empty()) {
            int n = q.size();
            vector<int> mid;
           
            for (int i = 0; i < n; ++i) {
                TreeNode* x = q.front();
                q.pop(); // Remove node immediately after accessing

                mid.push_back(x->val);

                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }

            ans.push_back(mid);
        }

        return ans;

    }
};