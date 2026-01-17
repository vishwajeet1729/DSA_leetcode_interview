// Last updated: 1/17/2026, 12:33:21 PM
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
 void dfs(TreeNode *root){
       if(!root)return;
       swap(root->left,root->right);
       dfs(root->right);
       dfs(root->left);
 }
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
dfs(root);
return root;

    }
};