// Last updated: 1/17/2026, 12:34:20 PM
class Solution {
public:
    
    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) 
            return true;
        else if (p == nullptr || q == nullptr) 
            return false;
        
        if (p->val != q->val) 
            return false;
        
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* p) {
        if (p == nullptr) 
            return true;
        return dfs(p->left, p->right);
    }
};
