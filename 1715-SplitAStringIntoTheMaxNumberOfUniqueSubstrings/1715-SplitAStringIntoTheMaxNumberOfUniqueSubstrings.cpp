// Last updated: 1/17/2026, 12:30:25 PM
class Solution {
public:
  int mx=0;
      
      void rec(string s,int ind,set<string>m){
           
         if(ind==s.size()){
            mx=max(mx,(int)m.size());
            return;
         }
         
         string dem="";
         
         for(int i=ind;i<s.size();++i){
               
               string dem=s.substr(ind,i-ind+1);

               if(m.find(dem)==m.end()){
                //    m[dem]++;
                m.insert(dem);
                   rec(s,i+1,m);
                   m.erase(dem);
               }


         }




      }

    int maxUniqueSplit(string s) {
         set<string>m;
         rec(s,0,m);
         return mx;
    }
};