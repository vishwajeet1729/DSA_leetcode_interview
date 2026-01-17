// Last updated: 1/17/2026, 12:34:49 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
          //i=intevwal
        vector<vector<int>>ans;
          sort(v.begin(),v.end());
         vector<int>cur={v[0][0],v[0][1]};
          int ct=0;
          int n=v.size();
          for(int i=1;i<n;++i){
                 
                if(cur[1]>=v[i][0]){
                    int a=cur[0],b=max(v[i][1],cur[1]);
                    cur={a,b};
                    if(i==n-1)ans.push_back(cur);
                    continue;
                }

                // ct++;
                ans.push_back(cur);
                cur={v[i][0],v[i][1]};
                if(i==n-1)ans.push_back(cur);
                // if()
          }
          if(ans.empty())ans.push_back(cur);
          return ans;
           
    }
};