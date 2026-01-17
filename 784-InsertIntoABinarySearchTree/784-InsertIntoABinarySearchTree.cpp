// Last updated: 1/17/2026, 12:32:12 PM
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode *node=root;
         if(!node){
             TreeNode * npm=new TreeNode(val);
             return npm; 
         }
        while(1){
            if(node->right&& val>node->val){
                 node=node->right;
            }
            else if(node->left && val<node->val)node=node->left;
            else break;

        }
        TreeNode * npm=new TreeNode(val);
        if(val>node->val)node->right=npm;
        else node->left=npm;
        return root;

    }
};