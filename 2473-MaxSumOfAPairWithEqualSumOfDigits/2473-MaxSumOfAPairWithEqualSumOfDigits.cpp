// Last updated: 1/17/2026, 12:29:03 PM
class Solution {
public:
    int maximumSum(vector<int>& v) {
          
          vector<vector<int>>ans(90);

           for(int i=0;i<v.size();++i){
                
                int x=v[i];
                int sum=0;
                while(x){
                    sum+=x%10;
                    x/=10;
                } 
                ans[sum].push_back(v[i]);       
           }
         int maxi=-1;
         for(int i=0;i<90;++i){
              if(ans[i].empty()||ans[i].size()<=1)continue;
           sort(ans[i].begin(),ans[i].end());
               int x=ans[i].size();
               
               maxi=max(maxi,ans[i][x-2]+ans[i][x-1]);
                       }

                       return maxi;
             
    }
};