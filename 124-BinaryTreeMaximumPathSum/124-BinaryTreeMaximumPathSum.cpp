// Last updated: 1/17/2026, 12:34:02 PM
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
    // vector<*treeNode>cost;
    int mx=INT_MIN;
    int rec(TreeNode* root){
          if(root==nullptr)return 0;
           int left=max(0,rec(root->left));
           int right=max(0,rec(root->right));
           if(mx==INT_MIN)mx=root->val;
           else
           mx=max(mx,left+right+root->val);
           return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        rec(root);      
     return mx==INT_MIN?0:mx;


    }
};