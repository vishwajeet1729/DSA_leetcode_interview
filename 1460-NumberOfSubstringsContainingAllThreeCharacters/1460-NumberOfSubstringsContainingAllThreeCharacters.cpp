// Last updated: 1/17/2026, 12:30:52 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
    int i=0,j=0;
    map<char,int>m;
    int ct=0;
    while(j<=n){
          if(m.size()==3){
            ct+=(n-j)+1;
            // cout<<n-j+1<<endl;
            // m[s[i]]--;
            if(--m[s[i]]==0)m.erase(s[i]);
            // j=i+1;
             i++;
         
            
          } 
          else if(j<n){
            m[s[j]]++;j++;
          }
          else break;


    }
//   if(m.size()==3)ct++;
    
// cout<<ct<<endl;

    return ct;
// cout<<ct<<endl; 


    }
};