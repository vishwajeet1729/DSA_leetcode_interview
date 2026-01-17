// Last updated: 1/17/2026, 12:34:14 PM
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
    
      int rec(TreeNode *node){
           if(node==nullptr)return 0;
            int height=rec(node->left);
            if(height==-1)return -1;
        
            int l=rec(node->right);
            if(l==-1)return -1;
            if(abs(height-l)>1)return -1;
            return max(height,l)+1;
             

      }
    bool isBalanced(TreeNode* root) {
          return rec(root)!=-1;

    }
};