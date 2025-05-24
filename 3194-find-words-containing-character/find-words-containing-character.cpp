class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
int ct=0;
int n=w.size();
vector<int>ans;
         for(int i=0;i<n;++i){
               if(w[i].find(x)!=string::npos)ans.push_back(i);

         }
         return ans;

    }  
};