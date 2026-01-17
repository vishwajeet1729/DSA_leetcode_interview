// Last updated: 1/17/2026, 12:34:16 PM
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
    int maxDepth(TreeNode* root)  {
        queue<TreeNode *>q;
         int ct=0;
         if(!root)return 0;
         q.push(root);
        //  ct++;
         while(!q.empty()){
              int n=q.size();
              for(int i=0;i<n;++i){
                   TreeNode *x=q.front();
                   q.pop();
                 
                   if(x->right)q.push(x->right);
                   if(x->left)q.push(x->left);
                
              }
              ct++;
         }
         return ct;
        
    }
};