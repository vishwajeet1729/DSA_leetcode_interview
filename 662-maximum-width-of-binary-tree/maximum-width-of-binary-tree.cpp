
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;

        while (!q.empty()) {
            int x = q.size();
            unsigned long long first = q.front().second;  // Normalize indexes
            unsigned long long mi = 0, mx = 0;  // First and last index at each level
            
            for (int i = 0; i < x; ++i) {
                auto [node, num] = q.front();
                q.pop();
                // num -= first;  // Normalize index to prevent overflow
                
                if (i == 0) mi = num;
                if (i == x - 1) mx = num;

                if (node->left) q.push({node->left, 2 * num+1});
                if (node->right) q.push({node->right, 2 * num + 2});
            }
            
            ans = max(ans, mx - mi + 1);
        }

        return ans;
    }
};
