// Last updated: 1/17/2026, 12:31:09 PM
class Solution {
public:
 


    string longestDiverseString(int a, int b, int c) {
           
           priority_queue<pair<int,char>>pq;
           if(a>0)pq.push({a,'a'});
           if(b>0)pq.push({b,'b'});
           if(c>0)pq.push({c,'c'});
   string s="";


           while(!pq.empty()){
               
              pair<int,char>p1=pq.top();
              pq.pop();
              if(s.size()>=2&&s[s.size()-2]==p1.second&&s.back()==p1.second){
                  if(pq.empty())break;
                  
                  pair<int,char>p2=pq.top();
                  pq.pop();
                   
                   s+=p2.second;
                   p2.first--;
                  if(p2.first>0) pq.push({p2.first,p2.second});

                   

                        pq.push({p1.first,p1.second});
              }
              else {
                  s+=p1.second;
                  p1.first--;
                  if(p1.first>0)pq.push({p1.first,p1.second});
              }
                   

           }
            
        
return s;

    }
};