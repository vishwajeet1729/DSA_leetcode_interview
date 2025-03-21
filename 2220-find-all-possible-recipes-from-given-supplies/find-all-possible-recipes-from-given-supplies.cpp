class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, int> recipeIndex;
        
        for (int i = 0; i < recipes.size(); ++i) {
            recipeIndex[recipes[i]] = i;
            q.push(recipes[i]);
        }
        
        while (!q.empty()) {
            int x = q.size();  
            for (int i = 0; i < x; ++i) {
                string s = q.front();
                q.pop();
                
                if (recipeIndex.find(s) == recipeIndex.end()) {
                    continue;
                }
                
                int idx = recipeIndex[s];
                bool all = true;
                for (int k = 0; k < ingredients[idx].size(); ++k) {
                    if (supplySet.find(ingredients[idx][k]) == supplySet.end()) {
                        q.push(s);
                        all = false;
                        break;
                    }
                }
                
                if (all) {
                    supplies.push_back(s);
                    supplySet.insert(s);
                    ans.push_back(s);
                }
            }
            if (q.size() == x) {
                break;
            }
        }
        
        return ans;
    }
};
