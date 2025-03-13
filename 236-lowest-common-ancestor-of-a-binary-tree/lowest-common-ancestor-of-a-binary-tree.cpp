/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      TreeNode* ans=nullptr;  

      int dfs(TreeNode* node,int ct,TreeNode* p,TreeNode* q){
          if(!node)return ct;
          if(node==p){
            ct|=(1<<1);
          }
          if(node==q){
            ct|=(1<<0);
          }
         int left= dfs(node->left,0,p,q);
          int right=dfs(node->right,0,p,q);
          ct= ct|left|right;
          if(ct==3&&!ans){
            ans=node; 
          }
           return ct;
          

      }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              
              dfs(root,0,p,q);
         return ans;

    }
};