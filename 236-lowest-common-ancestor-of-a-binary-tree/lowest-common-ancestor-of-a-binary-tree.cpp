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
   TreeNode * ans=nullptr;   
       int dfs( TreeNode * node,TreeNode * p,TreeNode *q){
            if(!node)return 0;
            

           int ct=0;
           ct|=dfs(node->left,p,q);
           ct|=dfs(node->right,p,q);
           if(node==p)ct|=2;
           if(node==q)ct|=1;
           if(ct==3&&!ans){
            ans=node;
           }
           return ct;
      }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          dfs(root,p,q);
          return ans;

    }
};