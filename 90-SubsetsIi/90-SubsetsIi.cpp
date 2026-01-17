// Last updated: 1/17/2026, 12:34:24 PM
class Solution {
public:

   void find(vector<int>&v,int index,vector<int>&cur,vector<vector<int>>&res){
           int n=v.size();
      if(index==v.size()){res.push_back(cur);return;}
           cur.push_back(v[index]);
       find(v,index+1,cur,res);
    //    index++;
         while(index+1<n&&v[index]==v[index+1])index++;
          cur.pop_back();
          find(v,index+1,cur,res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        
        int n=v.size();
            
        sort(v.begin(),v.end());
    vector<vector<int>>ans;
    vector<int>cur;
    find(v,0,cur,ans);
    return ans;    
           
            




    }
};