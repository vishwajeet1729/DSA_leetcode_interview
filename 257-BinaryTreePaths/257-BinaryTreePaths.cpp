// Last updated: 1/17/2026, 12:33:12 PM
class Solution {
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }

    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            result.push_back(path);
        } else {
            dfs(node->left, path + "->", result);
            dfs(node->right, path + "->", result);
        }
    }
};