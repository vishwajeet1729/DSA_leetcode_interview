// Last updated: 1/17/2026, 12:35:20 PM
class Solution {
public:
    int romanToInt(string s) {
           
           int n=s.size();
        map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50,m['C']=100,m['D']=500,m['M']=1000;
        int i=0;
        int ct=0;
           while(i<n){ 
               
              if(m[s[i]]<m[s[i+1]]){
                    ct+=m[s[i+1]]-m[s[i]];
                    i+=2;
              }
              else {ct+=m[s[i]];i++;}
             
           }

return ct;
    }
};