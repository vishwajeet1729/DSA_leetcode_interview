// Last updated: 1/17/2026, 12:28:11 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
vector<int>ans;
         for(int i=0;i<w.size();++i)if(w[i].find(x)!=string::npos)ans.push_back(i);
         return ans;

    }  
};