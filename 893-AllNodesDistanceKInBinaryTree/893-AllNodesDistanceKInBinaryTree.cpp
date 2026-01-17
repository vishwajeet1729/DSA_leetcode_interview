// Last updated: 1/17/2026, 12:31:56 PM
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
    map<TreeNode*, TreeNode*> m;

    void dfs(TreeNode* node) {
        if (node == nullptr)
            return;
        //    vis[node]=1;
        if (node->left) {
            m[node->left] = node;
            dfs(node->left);
        }
        if (node->right) {
            m[node->right] = node;
            dfs(node->right);
        }
    }
   vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
    dfs(root);
    unordered_set<TreeNode*> vis;   // ✅ visited nodes, not values
    queue<TreeNode*> q;

    q.push(t);
    vis.insert(t);

    int level = 0;
    while (!q.empty()) {
        if (level == k) {
            vector<int> v;
            while (!q.empty()) {
                v.push_back(q.front()->val);
                q.pop();
            }
            return v;
        }
        int x = q.size();
        while (x--) {
            auto it = q.front(); q.pop();
            if (it->left && !vis.count(it->left)) { q.push(it->left); vis.insert(it->left); }
            if (it->right && !vis.count(it->right)) { q.push(it->right); vis.insert(it->right); }
            if (m[it] && !vis.count(m[it])) { q.push(m[it]); vis.insert(m[it]); }
        }
        level++;
    }
    return {};
}

};