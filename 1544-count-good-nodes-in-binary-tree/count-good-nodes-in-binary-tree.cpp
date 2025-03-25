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
int ct=0;
   void dfs(TreeNode * node,int mx){
    if(!node)return;
    
    if(mx<=node->val)ct++;
    mx=max(mx,node->val);
    dfs(node->left,mx);
    dfs(node->right,mx);
     

   }
    int goodNodes(TreeNode* root) {
         dfs(root,root->val);
         return ct;    

    }
};