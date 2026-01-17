// Last updated: 1/17/2026, 12:30:51 PM
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
long long total_sum;
long long ans=0;
long long mod=1e9+7;
long long dfs(TreeNode * root){
    
  if(root==nullptr) return 0;

  long long sum=0;
   sum+= root->val + dfs(root->left) + dfs(root->right);
   ans=max(ans,sum*(total_sum-sum));
    return sum;


}
    int maxProduct(TreeNode* root) {
          total_sum=dfs(root);
        int xx=dfs(root);
        return ans%mod;
    }
};