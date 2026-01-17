// Last updated: 1/17/2026, 12:34:32 PM
class Solution {
public:
         
         vector<vector<int>>ans;

         void def(vector<int>&demo,int idx,int k,int n){
                if(idx==n+1){
                   if(demo.size()==k){
                        ans.push_back(demo);
                      }
                      return;
                }
                if(demo.size()==k){
                   ans.push_back(demo);
                   return; 
                }
                 demo.push_back(idx);
                 def(demo,idx+1,k,n);
                 demo.pop_back();
                 def(demo,idx+1,k,n);
                   
 
         }
       
    vector<vector<int>> combine(int n, int k) {
                      vector<int>demo;
                      def(demo,1,k,n);
                  return ans;

    }
};