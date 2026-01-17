// Last updated: 1/17/2026, 12:32:59 PM
class Solution {
public:
    int coinChange(vector<int>& c, int am) {
                int ct=0;
                queue<int>q;
           q.push(am);
           set<int>vis;
           vis.insert(am);
           while(!q.empty()){
                  int sz=q.size();
               for(int i=0;i<sz;++i){
                   
                   int rem=q.front();
                   q.pop();
                   if(rem==0)return ct;
                   for(auto coin:c){
                        int nw=rem-coin;
                        if(nw>=0&&!vis.count(nw)){
                              q.push(nw);vis.insert(nw);

                        }

                   }
               }
               ct++;
               

           }
        return -1;


    }
};