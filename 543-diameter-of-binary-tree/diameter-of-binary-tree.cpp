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
int mx=0; 
   int checkHeight(TreeNode *node){
    if (!node) return 0;  // Base case: Empty tree has height 0

        int leftHeight = checkHeight(node->left);

        int rightHeight = checkHeight(node->right);
        int x=leftHeight,y=rightHeight;
        // if(leftHeight!=0)x++;
        // if(rightHeight!=0)y++;
       mx=max(mx,x+y);
     

        return max(leftHeight,rightHeight)+1;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        checkHeight(root);
        return mx;
    }
};