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
int ans=0;
 int dfs(TreeNode* node){
      
      if(!node)return 0;
       
      int ct=0;
   int L=dfs(node->left);
   int R=dfs(node->right);
   int x=0,y=0;
   if(node->left&&node->val==node->left->val)x=L+1;
   if(node->right&&node->val==node->right->val)y=R+1;
   ans=max(ans,x+y);
   return max(x,y);

 }
    int longestUnivaluePath(TreeNode* root) {
dfs(root); 
         return ans;

    }
};