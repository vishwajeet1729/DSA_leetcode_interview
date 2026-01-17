// Last updated: 1/17/2026, 12:29:05 PM
class Solution {
public:
    string smallestNumber(string p) {
          
stack<char>st;string ans="";
          for(int i=0;i<=p.size();++i){
              st.push(i+1);
              if(i==p.size()||p[i]=='I'){
                while(!st.empty()){
                     ans+=(st.top()+'0');
                     st.pop();
                }
              }
          }
          return ans;
    }
};