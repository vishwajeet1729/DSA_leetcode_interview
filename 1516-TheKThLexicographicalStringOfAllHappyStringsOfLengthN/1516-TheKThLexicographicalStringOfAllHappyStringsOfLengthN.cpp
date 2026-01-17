// Last updated: 1/17/2026, 12:30:48 PM
class Solution {
public:  
    string ans="";
    int count=0;
    void rec(int n,int k,string s){
         
         if(s.size()==n){
            count++;
            if(count==k)ans=s;return;
         }
         if(!ans.empty())return;

              
              for(auto it:{'a','b','c'}){
                  if((s.empty()||s.back()!=it)){
                    rec(n,k,s+it);
                  }
               
           }
  
              
    }
    string getHappyString(int n, int k) {
            rec(n,k,"");
            if(ans.empty())return "";
            return ans;
    }
};