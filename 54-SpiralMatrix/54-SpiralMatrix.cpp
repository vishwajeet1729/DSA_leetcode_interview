// Last updated: 1/17/2026, 12:34:50 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
          
           int rs=0,re=v.size()-1;
           int cs=0,ce=v[0].size()-1;
vector<int>ans;
           while(rs<=re&&cs<=ce){
                //    if(v[rs][cs]<0)break;
                 for(int i=cs;i<=ce;++i){
                        ans.push_back(v[rs][i]);
                 }

                   rs++;

                   for(int i=rs;i<=re;++i){
                      ans.push_back(v[i][ce]);
                   }
                       ce--;
                        
                        if(rs<=re){
                       for(int i=ce;i>=cs;--i){
                           ans.push_back(v[re][i]);
                       }}
                       re--;
                       if(cs<=ce){
                       for(int i=re;i>=rs;--i){
                          ans.push_back(v[i][cs]);
                       }
                               
                       }cs++;

           }
            
            return ans;
            

    }
};