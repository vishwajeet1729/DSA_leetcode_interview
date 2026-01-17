// Last updated: 1/17/2026, 12:33:52 PM
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
 vector<int>ans;
   void rec(TreeNode *node){
         
         if(node==nullptr)return ;
           ans.push_back(node->val);
         rec(node->left);
       
         rec(node->right);
        return ;
   }
    vector<int> preorderTraversal(TreeNode* root) {
           rec(root);
           return ans;

    }
};