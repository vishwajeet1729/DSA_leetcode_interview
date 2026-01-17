// Last updated: 1/17/2026, 12:27:23 PM
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& v, vector<int>& q, int x) {
           
          vector<int>ans;
          for(int i=0;i<v.size();++i)if(v[i]==x)ans.push_back(i);
   vector<int>re;
          for(int i=0;i<q.size();++i){
                 int a=q[i];
                 if(a>ans.size())re.push_back(-1);
                 else re.push_back(ans[a-1]);
          }
          return re;


    }
};