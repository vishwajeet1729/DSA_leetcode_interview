// Last updated: 1/17/2026, 12:35:30 PM
class Solution {
public:

   string partition(int i,int j,string s){
            
           while(i>=0&&j<s.size()&&s[i]==s[j]){
            i--;
            j++;
           }
           return s.substr(i+1,j-i-1);
   }
    string longestPalindrome(string s) {
         
           int n=s.size();
            string ans="";int mx=1;
            ans+=s[0];
           for(int i=0;i<n-1;++i){ 

               string one=partition(i,i+1,s);
               if(one.size()>mx){
                mx=one.size();ans=one;
               }      
               one=partition(i,i,s);
               if(one.size()>mx){
                mx=one.size();ans=one;
               }
              
           }

           return ans;

    }
};