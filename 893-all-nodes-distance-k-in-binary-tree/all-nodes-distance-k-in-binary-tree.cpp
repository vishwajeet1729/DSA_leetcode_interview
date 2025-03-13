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
map<TreeNode*,TreeNode*>m;

   void dfs(TreeNode *node){
       if(node==nullptr)return;
    //    vis[node]=1;
       if(node->left){
        m[node->left]=node;
        dfs(node->left);
       }
       if(node->right){
        m[node->right]=node;
        dfs(node->right);
       }
   }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<bool>vis(501);
          dfs(root);
       queue<TreeNode *>q;
int level=0;
vis[t->val]=1;
q.push(t);
       while(!q.empty()){
        
            if(level==k){
               vector<int>v;
               int x=q.size();
               for(int i=0;i<x;++i){
                  auto it=q.front();
                  q.pop();
                  v.push_back(it->val); 
               }
               return v;
           }
           level++;
         
           int x=q.size();

           while(x--){
               auto it=q.front();
               q.pop();
               if(it->left&&!vis[it->left->val]){q.push(it->left);vis[it->left->val]=1; }
               if(it->right&&!vis[it->right->val]){q.push(it->right);vis[it->right->val]=1;  }
               if(m[it]&&!(vis[m[it]->val])){q.push(m[it]); vis[m[it]->val]=1;  }
           } 

       }
       return vector<int>{};

    }
};