// Last updated: 1/17/2026, 12:32:23 PM
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    long long ans = 0;
     if(root)ans=1;
    while (!q.empty())
    {

        int n = q.size();
        
        for (int i = 0; i < n; ++i)
        {
            pair<TreeNode*, long long> it = q.front();
            TreeNode *cur = it.first;

            long long ind = it.second;
            q.pop();

            if (cur->left)
                q.push({cur->left, 2 * ind + 1});
            if (cur->right)
                q.push({cur->right, 2 * ind + 2});
        }

        long long start = q.front().second, end = q.back().second;
       if(!q.empty())  ans = max(ans, end - start + 1);
    }

    return ans;  
    } 
};