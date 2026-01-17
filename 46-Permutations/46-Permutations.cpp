// Last updated: 1/17/2026, 12:34:56 PM
class Solution {
public:
    // first secure good jib then get to meet her
  void recu(vector<vector<int>>&v,vector<int>&ori,int ind){
          
          if(ind==ori.size()){
            v.push_back(ori);
            return;
          }

    for(int i=ind;i<ori.size();++i){
          
          swap(ori[ind],ori[i]);
          recu(v,ori,ind+1);
          swap(ori[ind],ori[i]);
    }
          
          


   }
    vector<vector<int>> permute(vector<int>& nums) {
           
    vector<vector<int>>an;recu(an,nums,0);

    return an;
        



    }
};