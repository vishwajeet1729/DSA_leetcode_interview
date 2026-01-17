// Last updated: 1/17/2026, 12:33:36 PM
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
      int mx=-1;
 vector<int>ans;
    void rec(TreeNode *node,int level){
          
          if(node==nullptr)return;

        if(level>mx){
            ans.push_back(node->val);
            mx++;
        }
        rec(node->right,level+1);
        rec(node->left,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {

      rec(root,0);
      return ans;
         

    }
};