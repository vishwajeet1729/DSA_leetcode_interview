// Last updated: 1/17/2026, 12:31:35 PM
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
  vector<tuple<int, int, int>> nodes;  // Stores (column, row, value)

    void dfs(TreeNode* node, int row, int col) {
        if (!node) return;
        nodes.push_back({col, row, node->val}); 
        dfs(node->left, row + 1, col - 1); 
        dfs(node->right, row + 1, col + 1); 
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0); // Start DFS at root (row=0, col=0)
        sort(nodes.begin(), nodes.end());
        map<int, vector<int>> mp;
        for (auto [col, row, val] : nodes) {
            mp[col].push_back(val);
        }
        vector<vector<int>> result;
        for (auto &[col, vals] : mp) {
            result.push_back(vals);
        }
        return result;
    }
};