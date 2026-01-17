// Last updated: 1/17/2026, 12:34:18 PM
class Solution {
public:
    vector<vector<int>>ans;

    void rec(TreeNode* node, int level) {
        if (node == nullptr)
            return;
            if(ans.size()==level)ans.push_back(vector<int>());
        ans[level].push_back(node->val);
        rec(node->left, level + 1);
        rec(node->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        rec(root, 0);

        vector<vector<int>> v;

        for (int i = 0; i < ans.size(); ++i) {
            if (!ans[i].empty()) {
                if (i % 2 != 0) {
                    reverse(ans[i].begin(), ans[i].end());}
                    v.push_back(ans[i]);
                
            }
        }

        return v;
    }
};