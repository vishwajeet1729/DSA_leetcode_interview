// Last updated: 1/17/2026, 12:33:51 PM
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
         
         rec(node->left);
       
         rec(node->right);
           ans.push_back(node->val);
        return ;
   }
    vector<int> postorderTraversal(TreeNode* root) {
        rec(root);
        return ans;
    }
};