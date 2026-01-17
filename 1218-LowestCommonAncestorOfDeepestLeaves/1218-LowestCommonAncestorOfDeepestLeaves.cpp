// Last updated: 1/17/2026, 12:31:17 PM
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
    vector<TreeNode*> moveToParents(vector<TreeNode*> deep, unordered_map<TreeNode*, TreeNode*> umap) {
        vector<TreeNode*> ans;
        for(auto it : deep) {
            ans.push_back(umap[it]);
        }
        return ans;
    }
    TreeNode* fun(vector<TreeNode*> deep, unordered_map<TreeNode*, TreeNode*> umap) {
      TreeNode* initialParent = umap[deep[0]];
      for(int i=1;i<deep.size();i++) {
        if(umap[deep[i]] != initialParent) { // if current node parent is not same as other deepest nodes then move to up across all the deepest nodes
            vector<TreeNode*> moveUp = moveToParents(deep, umap);
            return fun(moveUp, umap);
        }
      }
      return initialParent; // all the deepest nodes have same parent. so return that parent;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> umap; // child -> parent
        queue<pair<TreeNode*,int>> q; // node -> depth for bfs
        if(root) q.push({root,0});
        umap[root] = NULL; // map for root as null as root has no parent
        vector<pair<TreeNode*, int>> nodeDepth;
        int maxDepth = 0;
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* temp = it.first;
            int currDepth = it.second;
            maxDepth = max(maxDepth, currDepth);
            nodeDepth.push_back({temp, currDepth});
            if(temp->left) {
                q.push({temp->left, currDepth+1});
                umap[temp->left] = temp; // child -> parent
            }
            if(temp->right) {
                q.push({temp->right, currDepth+1});
                umap[temp->right] = temp;
            }
        }
        vector<TreeNode*> deepestNodes;
       for(auto it : nodeDepth) {
            if(it.second == maxDepth) {
                deepestNodes.push_back(it.first);
            }
       }
        // has all deepest nodes
        if(deepestNodes.size()==1) return deepestNodes[0];
        TreeNode* subTree = fun(deepestNodes, umap);
        return subTree;
    }
};